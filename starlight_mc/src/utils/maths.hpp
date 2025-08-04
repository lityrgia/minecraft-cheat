#pragma once
#include "types.h"

namespace math {
	double cropAngle180(double angle);
	vec2 getYawPitch(vec3 playerPos, vec3 facingPos);
}