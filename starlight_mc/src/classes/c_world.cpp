#include "java_classes.hpp"
#include "references.hpp"

void c_world::get_players() {
	jobject list_obj = cheat::jni->GetObjectField(get_obj(), refs::world::players);

	jmethodID toArray_mid = cheat::jni->GetMethodID(cheat::jni->GetObjectClass(list_obj), XOR_STR("toArray"), XOR_STR("()[Ljava/lang/Object;"));
	jobjectArray array = (jobjectArray)cheat::jni->CallObjectMethod(list_obj, toArray_mid);

	players.clear();
	jsize size = cheat::jni->GetArrayLength(array);
	for (jsize i = 0; i < size; ++i) {
		jobject player = cheat::jni->GetObjectArrayElement(array, i);
		if (player && !cheat::jni->IsSameObject(player, c_player::instance().obj)) {
			players.push_back(c_entity(player));
		}
	}
}