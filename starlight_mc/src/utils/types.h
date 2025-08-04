#pragma once
#include <iostream>

struct vec2 {
	float x;
	float y;

    vec2(float _x, float _y) : x(_x), y(_y) {}
    vec2(double _x, double _y) : x(_x), y(_y) {}
};

struct vec3 {
	float x = 0;
	float y = 0;
	float z = 0;

    vec3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
    vec3(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}

    vec3 operator-(const vec3& other) const {
        return vec3(x - other.x, y - other.y, z - other.z);
    }

    vec3 operator+(const vec3& other) const {
        return vec3(x + other.x, y + other.y, z + other.z);
    }

    vec3 operator*(const vec3& other) const {
        return vec3(x * other.x, y * other.y, z * other.z);
    }

    vec3 operator*(const float& other) const {
        return vec3(x * other, y * other, z * other);
    }

    static float distance(const vec3& a, const vec3& b) {
        return std::sqrt(std::pow(b.x - a.x, 2) + std::pow(b.y - a.y, 2) + std::pow(b.z - a.z, 2));
    }

    float distance() const {
        return std::sqrt(x * x + y * y + z * z);
    }
};