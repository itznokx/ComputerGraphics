#include <iostream>
#include "ray.hpp"
using namespace std; 

class Object {
public:
	Vec4 color;
	string type;
	void setColor(int r,int g,int b,int a){
		this->color = Vec4(r,g,b,a);
	}
	virtual float intersects(Ray* ray);
};
float Object::intersects(Ray* ray){
	return -404.404f;
}
//Sphere
class Sphere : public Object{
public:
	Vec4 color;
	string type;
	Vec3 center;
	float r;
	Sphere(Vec3 _center,float _r,Vec4 _color) : type("Sphere"), r(_r), center(_center), color(_color)
	{}
	float intersects(Ray* ray){
		Vec3 v = Vec3(ray->Origin.x,ray->Origin.y,ray->Origin.z) - this->center;
		float a = dot(ray->dr,ray->dr);
		float b = 2*(dot(v,ray->dr));
		float c = (dot(v,v)) - pow(this->r,2);
		float delta = pow(b,2) - 4*a*c;
		return delta;
	}
};