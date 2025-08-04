#include "maths.hpp"
#include <cmath>

constexpr double pi = 3.14159265;

double math::cropAngle180(double angle)
{
	while (angle <= -180.0) angle += 360.0;
	while (angle > 180.0) angle -= 360.0;
	return angle;
}

vec2 math::getYawPitch(vec3 playerPos, vec3 facingPos)
{
	vec3 delta = facingPos - playerPos;

	double hypxz = std::sqrt(delta.x * delta.x + delta.z * delta.z);

	double pitchRad = std::atan(-delta.y / hypxz);

	double yawDeg = 0.0;
	double pitchDeg = pitchRad * (180.0 / pi);

	if (delta.x != 0.0)
	{
		double yawRad = std::atan2(delta.z, delta.x) - pi / 2;
		yawDeg = yawRad * (180.0 / pi);
	}

	return vec2(yawDeg, pitchDeg);
}