#include "modules.hpp"
#include "classes/java_classes.hpp"
#include "gui/options.h"
#include "classes/references.hpp"
#include "utils/types.h"
#include "utils/timer.hpp"
#include "utils/maths.hpp"

void aimassist::run() {
    if (options::menu::isMenuVisible || !enabled) {
        prev_selected_target.obj = nullptr;
        return;
    }

    c_minecraft& mc = c_minecraft::instance();
    c_player& local_player = c_player::instance();
    c_world& world = c_world::instance();
    c_timer& c_timer = c_timer::instance();

    vec3 localPlayer_pos = local_player.get_pos();
    localPlayer_pos.y += local_player.get_eye_height();

    vec2 localPlayer_rotation = local_player.get_rotation();
    double cropped_localPlayer_yaw = math::cropAngle180(localPlayer_rotation.x);
    double cropped_localPlaye_pitch = localPlayer_rotation.y;

    c_entity selected_target{};
    double selected_target_YawToAdd = 0.0;
    double selected_target_PitchToAdd = 0.0;

    for (auto& target : world.players) {
        c_aabb bounding_box = target.get_bbox();
        vec3 target_pos{
            bounding_box.get_min_x() + (bounding_box.get_max_x() - bounding_box.get_min_x()) / 2.0f,
            bounding_box.get_min_y() + (bounding_box.get_max_y() - bounding_box.get_min_y()) / 2.0f,
            bounding_box.get_min_z() + (bounding_box.get_max_z() - bounding_box.get_min_z()) / 2.0f
        };
        target_pos = target_pos + target.get_mov_vector(c_timer.get_ticks());

        // Добавление небольшого случайного смещения для имитации неточности прицеливания
        std::uniform_real_distribution<double> offset_dist(-0.1, 0.1);
        target_pos.x += offset_dist(cheat::gen);
        target_pos.y += offset_dist(cheat::gen);
        target_pos.z += offset_dist(cheat::gen);

        vec2 target_required_rotation = math::getYawPitch(localPlayer_pos, target_pos);
        double yawToAdd = target_required_rotation.x - cropped_localPlayer_yaw;
        double pitchToAdd = target_required_rotation.y - cropped_localPlaye_pitch;
        yawToAdd = math::cropAngle180(yawToAdd);
        double target_distance = (target_pos - localPlayer_pos).distance();
        if (target_distance <= this->maxDistance && target_distance > 0.5 && std::abs(yawToAdd) <= this->maxAngle)
        {
            if (prev_selected_target.get_obj() && cheat::jni->IsSameObject(prev_selected_target.get_obj(), target.get_obj()))
            {
                selected_target = target;
                selected_target_YawToAdd = yawToAdd;
                selected_target_PitchToAdd = pitchToAdd;
                break;
            }
            if (!selected_target.get_obj() || std::abs(yawToAdd) < std::abs(selected_target_YawToAdd))
            {
                selected_target = target;
                selected_target_YawToAdd = yawToAdd;
                selected_target_PitchToAdd = pitchToAdd;
            }
        }
        else if (prev_selected_target.get_obj() && cheat::jni->IsSameObject(prev_selected_target.get_obj(), target.get_obj()))
        {
            prev_selected_target.obj = nullptr;
        }
    }
    if (selected_target.obj)
    {
        prev_selected_target = selected_target;
        vec3 selected_target_mvmt_vec = selected_target.get_mov_vector(c_timer.get_ticks());
        c_aabb selected_target_bb = selected_target.get_bbox();
        double center_y = selected_target_bb.get_min_y() + (selected_target_bb.get_max_y() - selected_target_bb.get_min_y()) / 2.0f;
        vec3 positionsToCheck[] =
        {
            vec3(selected_target_bb.get_min_x(), center_y, selected_target_bb.get_max_z()) + selected_target_mvmt_vec,
            vec3(selected_target_bb.get_max_x(), center_y, selected_target_bb.get_min_z()) + selected_target_mvmt_vec,
            vec3(selected_target_bb.get_max_x(), center_y, selected_target_bb.get_max_z()) + selected_target_mvmt_vec,
            vec3(selected_target_bb.get_min_x(), center_y, selected_target_bb.get_min_z()) + selected_target_mvmt_vec
        };
        double minYaw = 361.0, maxYaw = -1.0;
        for (const vec3& position : positionsToCheck)
        {
            vec2 YawPitch = math::getYawPitch(localPlayer_pos, position);
            double Yaw = YawPitch.x;
            if (Yaw < 0.0) Yaw += 360.0;
            if (Yaw < minYaw) minYaw = Yaw;
            if (Yaw > maxYaw) maxYaw = Yaw;
        }

        if (minYaw > 180.0) minYaw -= 360.0;
        if (maxYaw > 180.0) maxYaw -= 360.0;

        double maxDelta = std::abs(math::cropAngle180((maxYaw - minYaw))) / 2.0;
        double difference = std::abs(selected_target_YawToAdd) - maxDelta;
        if (std::abs(selected_target_YawToAdd) > maxDelta)
        {
            if (difference < 2.0)
            {
                constexpr double min_step = 0.01;
                constexpr double max_step = 0.3;
                constexpr double smooth_factor = 0.2;

                double step = difference * smooth_factor;
                step = std::clamp(step, min_step, max_step);
                localPlayer_rotation.x += step * (selected_target_YawToAdd > 0.0 ? 1.0 : -1.0);
            }
            else if (difference >= 16.0)
            {
                std::uniform_real_distribution<double> distr(4.0 * this->multiYaw, 8.0 * this->multiYaw);
                localPlayer_rotation.x += (distr(cheat::gen) / 10.0) * (selected_target_YawToAdd > 0.0 ? 1.0 : -1.0);
            }
            else if (difference >= 8.0)
            {
                std::uniform_real_distribution<double> distr(2.5 * this->multiYaw, 4.0 * this->multiYaw);
                localPlayer_rotation.x += (distr(cheat::gen) / 10.0) * (selected_target_YawToAdd > 0.0 ? 1.0 : -1.0);
            }
            else if (difference >= 4.0)
            {
                std::uniform_real_distribution<double> distr(1.0 * this->multiYaw, 2.0 * this->multiYaw);
                localPlayer_rotation.x += (distr(cheat::gen) / 10.0) * (selected_target_YawToAdd > 0.0 ? 1.0 : -1.0);
            }
            else
            {
                std::uniform_real_distribution<double> distr(0.25 * this->multiYaw, 1.0 * this->multiYaw);
                localPlayer_rotation.x += (distr(cheat::gen) / 10.0) * (selected_target_YawToAdd > 0.0 ? 1.0 : -1.0);
            }
        }

        if (this->usePitch) {
            double difference = std::abs(selected_target_PitchToAdd);
            if (difference < 2.0) {
                constexpr double min_step = 0.01;
                constexpr double max_step = 0.3;
                constexpr double interpolation_factor = 0.15;

                double step = difference * interpolation_factor;
                step = std::clamp(step, min_step, max_step);
                localPlayer_rotation.y += step * (selected_target_PitchToAdd > 0.0 ? 1.0 : -1.0);
            }
            else if (difference >= 16.0) {
                std::uniform_real_distribution<double> distr(4.0 * this->multiPitch, 8.0 * this->multiPitch);
                localPlayer_rotation.y += (distr(cheat::gen) / 10.0) * (selected_target_PitchToAdd > 0.0 ? 1.0 : -1.0);
            }
            else if (difference >= 8.0) {
                std::uniform_real_distribution<double> distr(2.5 * this->multiPitch, 4.0 * this->multiPitch);
                localPlayer_rotation.y += (distr(cheat::gen) / 10.0) * (selected_target_PitchToAdd > 0.0 ? 1.0 : -1.0);
            }
            else if (difference >= 4.0) {
                std::uniform_real_distribution<double> distr(1.0 * this->multiPitch, 2.0 * this->multiPitch);
                localPlayer_rotation.y += (distr(cheat::gen) / 10.0) * (selected_target_PitchToAdd > 0.0 ? 1.0 : -1.0);
            }
            else {
                std::uniform_real_distribution<double> distr(0.25 * this->multiPitch, 1.0 * this->multiPitch);
                localPlayer_rotation.y += (distr(cheat::gen) / 10.0) * (selected_target_PitchToAdd > 0.0 ? 1.0 : -1.0);
            }
        }
        local_player.set_rotation(localPlayer_rotation);
    }
}