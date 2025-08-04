#include "java_classes.hpp"
#include "references.hpp"

float c_timer::get_ticks() {
	return cheat::jni->GetFloatField(get_obj(), refs::timer::partial_tick);
}