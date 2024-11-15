#include "objects.hpp"
#include <iostream>
//Plane
class Plane : public Object{
public:
	Vec3 anchorPoint;
	Vec3 normal;
	Vec4 colorAmb;
	Vec4 colorDif;
	Vec4 colorEsp;
	string type;
	float m;
	Plane (Vec3 nP,Vec3 _normal,Vec4 _color,float _m):anchorPoint(nP),
											 normal(_normal),
											 colorAmb(_color),
											 colorDif(_color),
											 colorEsp(_color),
											 type("Plane"),
											 m(_m){}
	Plane (Vec3 p1,Vec3 p2,Vec3 p3,Vec4 _color,float _m):colorAmb(_color),
											 	colorDif(_color),
											 	colorEsp(_color),
												type("Plane"),
												m(_m)
												{
		Vec3 w = cross((p2-p1),(p3-p1));
		this->normal = normalize(w); 
	}
	float intersects(Ray* ray);
	Vec4 returnColor(float ti,Ray* ray,Light* lp,Light* amb,vector<Object*> objs);

};
float Plane::intersects(Ray* ray){
	Vec3 v = ray->origin - this->anchorPoint;
	float ti = (dot(v,this->normal)*(-1))/(dot(ray->dr,this->normal));
	return ti;
}
Vec4 Plane::returnColor(float ti,Ray* ray,Light* lp,Light* amb,vector<Object*> objs){
	return Vec4(0.0f,1.0f,0.0f,1.0f);
}