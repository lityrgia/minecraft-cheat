#include "java_classes.hpp"
#include "references.hpp"

double c_aabb::get_min_x() {
	return cheat::jni->GetDoubleField(get_obj(), refs::aabb::min_x);
}

double c_aabb::get_min_y() {
	return cheat::jni->GetDoubleField(get_obj(), refs::aabb::min_y);
}

double c_aabb::get_min_z() {
	return cheat::jni->GetDoubleField(get_obj(), refs::aabb::min_z);
}

double c_aabb::get_max_x() {
	return cheat::jni->GetDoubleField(get_obj(), refs::aabb::max_x);
}

double c_aabb::get_max_y() {
	return cheat::jni->GetDoubleField(get_obj(), refs::aabb::max_y);
}

double c_aabb::get_max_z() {
	return cheat::jni->GetDoubleField(get_obj(), refs::aabb::max_z);
}