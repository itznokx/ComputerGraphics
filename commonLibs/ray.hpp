#pragma once
#include <iostream>
#include "Vector.hpp"

using namespace std;

class Ray {
public:
	Vec3 Origin;
	Vec3 dr;
	Ray(Vec3 _Origin,Vec3 _dr) : Origin(_Origin)
	{
		Vec3 aux = (_dr) - (_Origin);
		aux = (normalize(aux));
		this->dr = aux;
	}
};