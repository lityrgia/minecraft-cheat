#include "java_classes.hpp"
#include "utils/valueObfuscation.h"
#include "cheat.hpp"
#include "classes/references.hpp"

bool c_player::get_onGround() {
	return cheat::jni->GetBooleanField(get_obj(), refs::player::on_ground);
}

vec3 c_player::get_pos() {
	vec3 res{ cheat::jni->CallDoubleMethod(get_obj(), refs::entity::get_x)
		, cheat::jni->CallDoubleMethod(get_obj(), refs::entity::get_y)
		, cheat::jni->CallDoubleMethod(get_obj(), refs::entity::get_z) };

	return res;
}

float c_player::get_attack_str(float ticks) {
	return cheat::jni->CallFloatMethod(get_obj(), refs::player::get_attack_strength, ticks);
}

float c_player::get_eye_height() {
	return cheat::jni->CallFloatMethod(get_obj(), refs::entity::get_eye_height);
}

bool c_player::is_fallng() {
	jobject delta_mov_obj = cheat::jni->GetObjectField(get_obj(), refs::player::delta_mov);
	if (!delta_mov_obj) return false;
	return !get_onGround() && (cheat::jni->GetDoubleField(delta_mov_obj, refs::vec3::y) < 0.0);
}

vec2 c_player::get_rotation() {
	vec2 res{ cheat::jni->GetFloatField(get_obj(), refs::entity::rotation_yaw)
		, cheat::jni->GetFloatField(get_obj(), refs::entity::rotation_pitch)};

	return res;
}

void c_player::set_rotation(vec2 rotation) {
	cheat::jni->SetFloatField(get_obj(), refs::entity::rotation_yaw, rotation.x);
	cheat::jni->SetFloatField(get_obj(), refs::entity::rotation_pitch, rotation.y);
}