#include "java_classes.hpp"
#include "utils/valueObfuscation.h"
#include "cheat.hpp"
#include "references.hpp"

vec3 c_entity::get_pos() const {
	vec3 res{ cheat::jni->CallDoubleMethod(get_obj(), refs::entity::get_x)
		, cheat::jni->CallDoubleMethod(get_obj(), refs::entity::get_y)
		, cheat::jni->CallDoubleMethod(get_obj(), refs::entity::get_z) };

	return res;
}

vec3 c_entity::get_last_pos() const {
	vec3 res{ cheat::jni->GetDoubleField(get_obj(), refs::entity::last_x)
		, cheat::jni->GetDoubleField(get_obj(), refs::entity::last_y)
		, cheat::jni->GetDoubleField(get_obj(), refs::entity::last_z) };

	return res;
}

bool c_entity::is_dead() const {
	bool is_alive = cheat::jni->CallBooleanMethod(get_obj(), refs::entity::is_alive);

	return !is_alive;
}

bool c_entity::is_invicible() const {
	bool res = cheat::jni->CallBooleanMethod(get_obj(), refs::entity::is_invisible);

	return res;
}

float c_entity::ticks_existed() const {
	bool res = cheat::jni->GetFloatField(get_obj(), refs::entity::ticks_existed);

	return res;
}

c_aabb c_entity::get_bbox() const {
	return cheat::jni->GetObjectField(get_obj(), refs::entity::bouding_box);
}

vec3 c_entity::get_mov_vector(float partialTicks) const
{
	return (get_pos() - get_last_pos()) * partialTicks;
}