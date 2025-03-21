#pragma once
#include <iostream>
#include <vector>
#include "vector.hpp"
#include "ray.hpp"
#include "light.hpp"
using namespace std;

class Object {
public:
	Vec4 color;
	string type;
	virtual void setColor(int r,int g,int b,int a){
		this->color = Vec4(r,g,b,a);
	}
	virtual float intersects(Ray* ray);
	virtual Vec4 returnColor(float ti,Ray* ray,Light* lp,Light* amb,vector<Object*> objs);
};
//Generic Implementation
float Object::intersects(Ray* ray){
	cout << "Obj intersects" << "\n";
	return -404.404f;
}
//Generic Implementation
Vec4 Object::returnColor(float ti,Ray* ray,Light* lp,Light* amb,vector<Object*> objs){
	float dotti = dot(ray->origin,lp->pF);
	float dotaux = dot(amb->pF,ray->origin);
	float aux = ti*dotti*dotaux;
	cout << "Color objs" << "\n";
	return Vec4(0.0f*aux,0.0f,0.0f,1.0f);
}
