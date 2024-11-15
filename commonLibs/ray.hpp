#pragma once
#include <iostream>
#include "vector.hpp"
using namespace std;

class Ray {
public:
	Vec3 origin;
	Vec3 dr;
	Ray(Vec3 rayOrigin,Vec3 direction) : 	origin(rayOrigin),
								 			dr(direction)
	{}
	Vec3 at (float ti) const {
		return origin + (ti*dr);
	}
};