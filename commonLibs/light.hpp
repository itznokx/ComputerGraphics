#pragma once
#include <iostream>
#include "vector.hpp"

class Light {
public:
	Vec3 pF;
	Vec4 intensity;
	string type;
	Light(Vec3 _pF,Vec4 i) : pF(_pF),
							intensity(i),
							type("pontual") 
	{}
};
