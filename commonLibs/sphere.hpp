#include <iostream>
#include "objects.hpp"
//Sphere
class Sphere : public Object{
public:
	Vec4 colorAmb;
	Vec4 colorDif;
	Vec4 colorEsp;
	string type;
	Vec3 center;
	float m;
	float r;
	Sphere(Vec3 _center,float _r,Vec4 _colorDif,Vec4 _colorEsp,Vec4 _colorAmb,float _m) : 
												colorAmb(_colorAmb),
												colorDif(_colorDif),
												colorEsp(_colorEsp),
												type("Sphere"),
												center(_center), 
												m(_m),
												r(_r)
	{}
	Sphere(Vec3 _center,float _r,Vec4 color,float _m) : 
												colorAmb(color),
												colorDif(color),
												colorEsp(color),
												type("Sphere"),
												center(_center), 
												m(_m),
												r(_r)
	{}
	float intersects(Ray* ray);
	Vec4 returnColor(float ti,Ray* ray,Light* lp,Light* amb,vector<Object*> objs);
};
float Sphere::intersects(Ray* ray){
	Vec3 oc = this->center - ray->origin;
	auto a = dot(ray->dr,ray->dr);
	auto b = -2.0f * dot(ray->dr,oc);
	auto c = dot (oc,oc) - (this->r*this->r);
	auto delta = b*b - (4*a*c);
	if (delta < 0)
		return -1.0f;
	else {
		return (-b -sqrt(delta) ) / (2.0*a);
	}
}
Vec4 Sphere::returnColor(float ti,Ray* ray,Light* lp,Light* amb,vector<Object*> objs){
		Vec3 n = normalize(ray->at(ti) - this->center);
		//return Vec4(1.0f,0.0f,0.0f,1.0f);
		return (0.5f)*Vec4(n.x+1.0f,n.y+1.0f,n.z+1.0f,1.0f);
	
}