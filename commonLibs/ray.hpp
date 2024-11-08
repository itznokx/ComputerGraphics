#pragma once
#include <iostream>
#include "vector.hpp"

using namespace std;

class Ray {
public:
	Vec3 Origin;
	Vec3 dr;
	Ray(Vec3 _Origin,Vec3 _dr) : Origin(_Origin)
	{
		this->dr = (normalize(_dr));
		if (dr.z > 0)
			dr.print();
	}
};