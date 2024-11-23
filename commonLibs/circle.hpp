#pragma once
#include "vector.hpp"
#include "objects.hpp" 

using namespace std;

class CirclePlane{
public:
	Vec3 center;
	Vec3 normal;
	float radius;
	Vec4 colorAmb;
	Vec4 colorDif;
	Vec4 colorEsp;
	float m;
	CirclePlane () {}
	CirclePlane(Vec3 _center,Vec3 _normal,float _radius) : 		center(_center), 
																normal(_normal), 
																radius(_radius)
	{}
};
