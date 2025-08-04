#include "java_classes.hpp"
#include "cheat.hpp"
#include "utils/valueObfuscation.h"
#include "classes/references.hpp"

jobject c_minecraft::get_mc() {
	jobject temp_obj = cheat::jni->GetStaticObjectField(refs::minecraft::cls, refs::minecraft::the_minecraft);
	if (temp_obj) obj = cheat::jni->NewGlobalRef(temp_obj);
	return get_obj();
}

jobject c_minecraft::get_localPlayer() {
	jobject res = cheat::jni->GetObjectField(get_obj(), refs::minecraft::the_player);

	return res;
}

jobject c_minecraft::get_world() {
	jobject res = cheat::jni->GetObjectField(get_obj(), refs::minecraft::the_world);

	return res;
}

jobject c_minecraft::get_entityCrosshair() {
	jobject obj_pos = cheat::jni->GetObjectField(get_obj(), refs::minecraft::hit_result);
	if (obj_pos && cheat::jni->IsInstanceOf(obj_pos, refs::hit_result::cls)) {
		return cheat::jni->GetObjectField(obj_pos, refs::hit_result::entity);
	}
	return nullptr;
}

jobject c_minecraft::get_timer() {
	jobject res = cheat::jni->GetObjectField(get_obj(), refs::minecraft::the_timer);

	return res;
}