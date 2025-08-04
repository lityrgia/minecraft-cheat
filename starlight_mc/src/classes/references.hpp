#pragma once
#include "utils/valueObfuscation.h"

namespace refs {

	// ENTITY METHODS
	namespace entity {
		inline jclass cls = nullptr;

		inline jmethodID get_x = nullptr;
		inline jmethodID get_y = nullptr;
		inline jmethodID get_z = nullptr;

		inline jfieldID last_x = nullptr;
		inline jfieldID last_y = nullptr;
		inline jfieldID last_z = nullptr;

		inline jmethodID is_alive = nullptr;
		inline jmethodID is_invisible = nullptr;
		inline jmethodID get_eye_height = nullptr;

		inline jfieldID rotation_yaw = nullptr;
		inline jfieldID rotation_pitch = nullptr;
		inline jfieldID ticks_existed = nullptr;
		inline jfieldID bouding_box = nullptr;
	}

	namespace timer {
		inline jclass cls = nullptr;

		inline jfieldID partial_tick = nullptr;
	}

	namespace world {
		inline jclass cls = nullptr;

		inline jfieldID players = nullptr;
	}

	namespace mob_entity {
		inline jclass cls = nullptr;
	}

	namespace player_entity {
		inline jclass cls = nullptr;
	}

	namespace aabb {
		inline jclass cls = nullptr;

		inline jfieldID min_x = nullptr;
		inline jfieldID min_y = nullptr;
		inline jfieldID min_z = nullptr;
		inline jfieldID max_x = nullptr;
		inline jfieldID max_y = nullptr;
		inline jfieldID max_z = nullptr;
	}

	// VEC3
	namespace vec3 {
		inline jclass cls = nullptr;
		inline jfieldID y = nullptr;
	}

	// PLAYER METHODS
	namespace player {
		inline jclass cls = nullptr;

		inline jmethodID get_attack_strength = nullptr;
		inline jfieldID on_ground = nullptr;
		inline jfieldID delta_mov = nullptr;
	}

	namespace minecraft {
		inline jclass cls = nullptr;

		inline jfieldID the_minecraft = nullptr;
		inline jfieldID the_player = nullptr;
		inline jfieldID the_world = nullptr;
		inline jfieldID hit_result = nullptr;
		inline jfieldID the_timer = nullptr;
	}

	// ENTITY HIT RESULT FIELDS
	namespace hit_result {
		inline jclass cls = nullptr;

		inline jfieldID entity = nullptr;
	}

	// MAIN INIT FLAG
	inline bool initialized = false;

	// INIT FUNCTION
	inline bool init() {
		if (initialized) return true;

		using namespace cheat;
		auto& m = mapp;

		// === CLASS NAMES ===
		std::string entity_cls_str = m[XOR_STR("entity")][XOR_STR("obfuscated")];
		std::string entity_sig = m[XOR_STR("entity")][XOR_STR("signature")];
		std::string player_cls_str = m[XOR_STR("playerEntity")][XOR_STR("obfuscated")];
		std::string mc_cls_str = m[XOR_STR("minecraft")][XOR_STR("obfuscated")];
		std::string world_cls_str = m[XOR_STR("world")][XOR_STR("obfuscated")];
		std::string world_cls_sig = m[XOR_STR("world")][XOR_STR("signature")];
		std::string mc_sig = m[XOR_STR("minecraft")][XOR_STR("signature")];
		std::string my_player_sig = m[XOR_STR("myPlayer")][XOR_STR("signature")];
		std::string hit_result_sig = m[XOR_STR("hitResult")][XOR_STR("signature")];
		std::string entity_hit_cls_str = m[XOR_STR("entityHitResult")][XOR_STR("obfuscated")];
		std::string mob_entity_cls_str = m[XOR_STR("mobEntity")][XOR_STR("obfuscated")];
		std::string player_entity_cls_str = m[XOR_STR("otherPlayer")][XOR_STR("obfuscated")];
		std::string vec3_cls_str = m[XOR_STR("vec3")][XOR_STR("obfuscated")];
		std::string aabb_cls_str = m[XOR_STR("axisAligned")][XOR_STR("obfuscated")];
		std::string aabb_cls_sig = m[XOR_STR("axisAligned")][XOR_STR("signature")];
		std::string timer_cls_str = m[XOR_STR("timer")][XOR_STR("obfuscated")];
		std::string timer_cls_sig = m[XOR_STR("timer")][XOR_STR("signature")];

		// === LOAD CLASSES ===
		entity::cls = find_cls(entity_cls_str);
		player::cls = find_cls(player_cls_str);
		world::cls = find_cls(world_cls_str);
		minecraft::cls = find_cls(mc_cls_str);
		hit_result::cls = find_cls(entity_hit_cls_str);
		mob_entity::cls = find_cls(mob_entity_cls_str);
		player_entity::cls = find_cls(player_entity_cls_str);
		aabb::cls = find_cls(aabb_cls_str);
		vec3::cls = find_cls(vec3_cls_str);
		timer::cls = find_cls(timer_cls_str);

		if (!timer::cls || !entity::cls || !player::cls || !minecraft::cls || !hit_result::cls || !mob_entity::cls || !player_entity::cls || !vec3::cls || !world::cls || !aabb::cls)
			return false;

		// === ENTITY METHODS ===
		entity::get_x = jni->GetMethodID(entity::cls, get_obf_mid(m, entity_cls_str, XOR_STR("getX")).c_str(), XOR_STR("()D"));
		entity::get_y = jni->GetMethodID(entity::cls, get_obf_mid(m, entity_cls_str, XOR_STR("getY")).c_str(), XOR_STR("()D"));
		entity::get_z = jni->GetMethodID(entity::cls, get_obf_mid(m, entity_cls_str, XOR_STR("getZ")).c_str(), XOR_STR("()D"));
		entity::is_alive = jni->GetMethodID(entity::cls, get_obf_mid(m, entity_cls_str, XOR_STR("isAlive")).c_str(), XOR_STR("()Z"));
		entity::is_invisible = jni->GetMethodID(entity::cls, get_obf_mid(m, entity_cls_str, XOR_STR("isInvisible")).c_str(), XOR_STR("()Z"));
		entity::get_eye_height = jni->GetMethodID(entity::cls, get_obf_mid(m, entity_cls_str, XOR_STR("getEyeHeight")).c_str(), XOR_STR("()F"));
		player::on_ground = jni->GetFieldID(entity::cls, get_obf_fid(m, entity_cls_str, XOR_STR("onGround")).c_str(), XOR_STR("Z"));
		player::delta_mov = jni->GetFieldID(entity::cls, get_obf_fid(m, entity_cls_str, XOR_STR("deltaMovement")).c_str(), get_sig_fid(m, entity_cls_str, XOR_STR("deltaMovement")).c_str());
		entity::rotation_yaw = jni->GetFieldID(entity::cls, get_obf_fid(m, entity_cls_str, XOR_STR("rotationYaw")).c_str(), XOR_STR("F"));
		entity::rotation_pitch = jni->GetFieldID(entity::cls, get_obf_fid(m, entity_cls_str, XOR_STR("rotationPitch")).c_str(), XOR_STR("F"));
		entity::bouding_box = jni->GetFieldID(entity::cls, get_obf_fid(m, entity_cls_str, XOR_STR("boundingBox")).c_str(), aabb_cls_sig.c_str());
		entity::last_x = jni->GetFieldID(entity::cls, get_obf_fid(m, entity_cls_str, XOR_STR("lastTickX")).c_str(), XOR_STR("D"));
		entity::last_y = jni->GetFieldID(entity::cls, get_obf_fid(m, entity_cls_str, XOR_STR("lastTickY")).c_str(), XOR_STR("D"));
		entity::last_z = jni->GetFieldID(entity::cls, get_obf_fid(m, entity_cls_str, XOR_STR("lastTickZ")).c_str(), XOR_STR("D"));

		// === WORLD ===
		world::players = jni->GetFieldID(world::cls, get_obf_fid(m, world_cls_str, XOR_STR("entityList")).c_str(), get_sig_fid(m, world_cls_str, XOR_STR("entityList")).c_str());

		// === AABB ===
		aabb::min_x = jni->GetFieldID(aabb::cls, get_obf_fid(m, aabb_cls_str, XOR_STR("minX")).c_str(), XOR_STR("D"));
		aabb::min_y = jni->GetFieldID(aabb::cls, get_obf_fid(m, aabb_cls_str, XOR_STR("minY")).c_str(), XOR_STR("D"));
		aabb::min_z = jni->GetFieldID(aabb::cls, get_obf_fid(m, aabb_cls_str, XOR_STR("minZ")).c_str(), XOR_STR("D"));
		aabb::max_x = jni->GetFieldID(aabb::cls, get_obf_fid(m, aabb_cls_str, XOR_STR("maxX")).c_str(), XOR_STR("D"));
		aabb::max_y = jni->GetFieldID(aabb::cls, get_obf_fid(m, aabb_cls_str, XOR_STR("maxY")).c_str(), XOR_STR("D"));
		aabb::max_z = jni->GetFieldID(aabb::cls, get_obf_fid(m, aabb_cls_str, XOR_STR("maxZ")).c_str(), XOR_STR("D"));

		// === PLAYER METHODS ===
		player::get_attack_strength = jni->GetMethodID(player::cls, get_obf_mid(m, player_cls_str, XOR_STR("getAttackStrength")).c_str(), XOR_STR("(F)F"));

		// === MINECRAFT ===
		minecraft::the_minecraft = jni->GetStaticFieldID(minecraft::cls, get_obf_fid(m, mc_cls_str, XOR_STR("theMinecraft")).c_str(), mc_sig.c_str());
		minecraft::the_player = jni->GetFieldID(minecraft::cls, get_obf_fid(m, mc_cls_str, XOR_STR("thePlayer")).c_str(), my_player_sig.c_str());
		minecraft::the_world = jni->GetFieldID(minecraft::cls, get_obf_fid(m, mc_cls_str, XOR_STR("theWorld")).c_str(), world_cls_sig.c_str());
		minecraft::hit_result = jni->GetFieldID(minecraft::cls, get_obf_fid(m, mc_cls_str, XOR_STR("hitResult")).c_str(), hit_result_sig.c_str());
		minecraft::the_timer = jni->GetFieldID(minecraft::cls, get_obf_fid(m, mc_cls_str, XOR_STR("theTimer")).c_str(), timer_cls_sig.c_str());

		// === ENTITY HIT RESULT ===
		hit_result::entity = jni->GetFieldID(hit_result::cls, get_obf_fid(m, entity_hit_cls_str, XOR_STR("entity")).c_str(), entity_sig.c_str());

		// VEC3 FIELDS
		vec3::y = jni->GetFieldID(vec3::cls, get_obf_fid(m, vec3_cls_str, XOR_STR("y")).c_str(), XOR_STR("D"));

		// TIMER FIELDS
		timer::partial_tick = jni->GetFieldID(timer::cls, get_obf_fid(m, timer_cls_str, XOR_STR("partialTick")).c_str(), XOR_STR("F"));

		// === CHECK SUCCESS ===
		initialized =
			entity::get_x && entity::get_y && entity::get_z && entity::last_x && entity::last_y && entity::last_z &&
			entity::is_alive && entity::is_invisible && entity::bouding_box && entity::get_eye_height &&
			player::get_attack_strength && aabb::min_x && aabb::min_y && aabb::min_z && aabb::max_x && aabb::max_y && aabb::max_z &&
			minecraft::the_minecraft && timer::partial_tick &&
			minecraft::the_player && minecraft::hit_result && world::players && minecraft::the_timer &&
			hit_result::entity && player::on_ground && player::delta_mov && vec3::y && entity::rotation_pitch && entity::rotation_yaw;

		return initialized;
	}

}
