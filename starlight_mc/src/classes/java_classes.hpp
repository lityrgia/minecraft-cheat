#pragma once
#include "cheat.hpp"
#include "utils/macros.h"
#include "utils/singleton.h"
#include "utils/types.h"

class java_class {
public:
	jclass cls = nullptr;
	jobject obj = nullptr;
	std::string name = "NOT SPECIFIED";

public:
	java_class() = default;
	java_class(jobject object, std::string_view class_name)
		: cls(nullptr), obj(object), name(class_name) {}

	jclass get_cls() {
		if (cls != nullptr) return cls;
		if (obj != nullptr) return cls = cheat::jni->GetObjectClass(obj);
		_DEBUG(printf("Failed to find class %s\n"), name.c_str());
		return nullptr;
	}

	jobject get_obj() const {
		if (obj != nullptr) return obj;
		_DEBUG(printf("Failed to get obj class %s\n"), name.c_str());
		return nullptr;
	}
};

class c_aabb : public java_class
{
public:
	c_aabb() : java_class(nullptr, "c_aabb") {}
	c_aabb(jobject _obj) : java_class(_obj, "c_aabb") {}

	double get_min_x();
	double get_min_y();
	double get_min_z();
	double get_max_x();
	double get_max_y();
	double get_max_z();
};

class c_entity : public java_class
{
public:
	c_entity() : java_class(nullptr, "c_entity") {}
	c_entity(jobject _obj) : java_class(_obj, "c_entity") {}

	vec3 get_last_pos() const;
	vec3 get_pos() const;
	bool is_dead() const;
	bool is_invicible() const;
	c_aabb get_bbox() const;
	float ticks_existed() const;
	vec3 get_mov_vector(float partialTicks) const;
};

class c_minecraft : public java_class, public singleton<c_minecraft>
{
public:
	c_minecraft() : java_class(nullptr, "c_minecraft") {}

	jobject get_localPlayer();
	jobject get_mc();
	jobject get_entityCrosshair();
	jobject get_world();
	jobject get_timer();
};

class c_player : public java_class, public singleton<c_player>
{
public:
	c_player() : java_class(nullptr, "c_player") {}

	bool get_onGround();
	vec3 get_pos();
	vec2 get_rotation();
	float get_attack_str(float);
	bool is_fallng();
	float get_eye_height();
	void set_rotation(vec2 rotation);
};

class c_timer : public java_class, public singleton<c_timer>
{
public:
	c_timer() : java_class(nullptr, "c_timer") {}

	float get_ticks();
};

class c_world : public java_class, public singleton<c_world>
{
public:
	c_world() : java_class(nullptr, "c_world") {}

	void get_players();

	std::vector<c_entity> players;
};