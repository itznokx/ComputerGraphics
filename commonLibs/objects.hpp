#pragma once
#include <iostream>
#include <algorithm>
#include "vector.hpp"
#include "ray.hpp"
#include "light.hpp"
using namespace std; 

class Object {
public:
	Vec4 color;
	string type;
	void setColor(int r,int g,int b,int a){
		this->color = Vec4(r,g,b,a);
	}
	virtual float intersects(Ray* ray);
	virtual Vec4 returnColor(float ti,Ray* ray,Light* lp,Light* amb);
};
float Object::intersects(Ray* ray){
	cout << "Obj intersects" << "\n";
	return -404.404f;
}
Vec4 Object::returnColor(float ti,Ray* ray,Light* lp,Light* amb){
	float dotti = dot(ray->Origin,lp->pF);
	float dotaux = dot(amb->pF,ray->Origin);
	float aux = ti*dotti*dotaux;
	cout << "Color objs" << "\n";
	return Vec4(0.0f*aux,0.0f,0.0f,1.0f);
}
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
												colorAmb(normalize(color)),
												colorDif(normalize(color)),
												colorEsp(normalize(color)),
												type("Sphere"),
												center(_center), 
												m(_m),
												r(_r)
	{}
	float intersects(Ray* ray);
	Vec4 returnColor(float ti,Ray* ray,Light* lp,Light* amb);
};
float Sphere::intersects(Ray* ray){
		Vec3 v = ray->Origin - this->center;
		float a = dot(ray->dr,ray->dr);
		float b = 2.0f*(dot(v,ray->dr));
		float c = (dot(v,v)) - pow(this->r,2);
		float delta = b*b - 4.0f*a*c;
		if (delta < 0){
				return -1.0f;
		}
		else{
			float t2 = (-b-sqrt(delta))/(2.0f*a);
			return t2;
		}
	}
Vec4 Sphere::returnColor(float ti,Ray* ray,Light* lp,Light* amb){
		Vec3 pI = (ray->Origin + (ray->dr*ti));
		Vec3 v = normalize(ray->Origin - pI);
		Vec3 l = normalize(lp->pF - pI);
		Vec3 n = normalize(this->center - pI);
		Vec3 r = normalize(2.0f*((dot(l,n))*n - l));
		float fd = dot(l,n);
		float fe = pow(dot(v,r),this->m);
		Vec4 c1 = (ats(this->colorAmb,amb->intensity));
		cout << "FD: "<<fd << " "<< "FE: " << fe << endl;
		Vec4 c2 = (ats(this->colorDif,lp->intensity)*fd);
		if (fd < 0)
			return c1;
		Vec4 c3 = (ats(this->colorEsp,lp->intensity)*fe);
		return (c1+c2+c3);

	}
//Plane
class Plane : public Object{
	Vec3 anchorPoint;
	Vec3 normal;
	Vec4 color;
	string type;
	Plane (Vec3 nP,Vec3 _normal,Vec4 _color):anchorPoint(nP),normal(_normal),color(_color),type("Plane"){}
	Plane (Vec3 p1,Vec3 p2,Vec3 p3,Vec4 _color):color(_color),type("Plane"){
		Vec3 w = cross((p2-p1),(p3-p1));
		this->normal = normalize(w); 
	}
	float intersects(Ray* ray){
		Vec3 v = ray->Origin - this->anchorPoint;
		float ti = (dot(v,this->normal)*(-1))/(dot(ray->dr,this->normal));
		return ti;
	}
};