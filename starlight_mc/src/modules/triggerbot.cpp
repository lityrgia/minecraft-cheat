#include "modules.hpp"
#include <random>
#include "classes/java_classes.hpp"
#include "gui/options.h"
#include "classes/references.hpp"

int get_random(int min, int max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

bool triggerbot::check_entity(c_entity& entity) {
    if (entity.is_dead()) return false;
    if (c_player::instance().get_attack_str(0.5f) <= 0.90f) return false;

    if (this->maxDistance != 4.f) {
        vec3 entityPos = entity.get_pos();

        vec3 playerPos = c_player::instance().get_pos();

        float distance = vec3::distance(entityPos, playerPos) - 1;

        if (distance > this->maxDistance) return false;
    }

    if ((cheat::jni->IsInstanceOf(entity.obj, refs::mob_entity::cls) && this->attackMobs) ||
        (cheat::jni->IsInstanceOf(entity.obj, refs::player_entity::cls) && this->attackPlayers)) {

        if (entity.is_invicible() && this->attackInvisibles || !entity.is_invicible()) {

            if (c_player::instance().is_fallng() && this->onlyCrits) {
                return true;
            }
            if (!this->onlyCrits) {
                return true;
            }
        }
    }

    return false;
}

void triggerbot::run() {
    if (options::menu::isMenuVisible || !enabled) return;
    c_minecraft& mc = c_minecraft::instance();

    c_entity entity(mc.get_entityCrosshair());
    if (entity.obj && check_entity(entity)) {

        POINT pt;
        GetCursorPos(&pt);
        ScreenToClient(options::menu::my_wnd, &pt);

        LPARAM lParam = (pt.y << 16) | (pt.x & 0xFFFF);

        Sleep(get_random(0, randomFactorMs));
        PostMessage(options::menu::my_wnd, WM_LBUTTONDOWN, MK_LBUTTON, lParam);
        PostMessage(options::menu::my_wnd, WM_LBUTTONUP, 0, lParam);
    }
} 