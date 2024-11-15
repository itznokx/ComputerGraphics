#pragma once
#include <iostream>
#include "vector.hpp"
using namespace std;

class Ray {
public:
	Vec3 origin;
	Vec3 dr;
	Ray(Vec3 _origin,Vec3 _dr) : origin(_origin),
								 dr(_dr)
	{}
	Vec3 at (float ti) const {
		return origin + (ti*dr);
	}
};