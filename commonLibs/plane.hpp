#pragma once
#include "objects.hpp"
#include <vector>
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
		this->normal = (w);
	}
	float intersects(Ray* ray);
	Vec4 returnColor(float ti,Ray* ray,Light* lp,Light* amb,vector<Object*> objs);

};
float Plane::intersects(Ray* ray) {
	Vec3 v = (ray->origin - this->anchorPoint);
	float ti = (-dot(v,this->normal))/(dot(ray->dr,this->normal));
	return ti;
}
Vec4 Plane::returnColor(float ti,Ray* ray,Light* lp,Light* amb,vector<Object*> objs){
	Vec3 pI = ray->at(ti);
	Vec4 iAmb = (ats(amb->intensity,this->colorAmb));
	for (Object *obj : objs){
		Ray rayAux = Ray(pI,lp->pF-pI);
		float tiAux = obj->intersects(&rayAux);
		if(tiAux > 0.0f && tiAux < 1.0f && obj!=this){
			return (iAmb);
		}
	}
	Vec3 n = this->normal;
	Vec3 l = normalize(lp->pF-pI);
	Vec3 v = normalize(ray->dr*(-1.0f));
	Vec3 r = ((2.0f*(dot(l,n)*n))-l);
	float fd = dot(l,n);
	float fe = pow(dot(r,v),this->m);
	Vec4 iDif = (ats(lp->intensity,this->colorDif)*fd);
	Vec4 iEsp = (ats(lp->intensity,this->colorEsp)*fe);
	Vec4 finalColor;
	if (fd < 0.0f){
		finalColor = (iAmb+iEsp);
		finalColor = Vec4(	finalColor.x,
							finalColor.y,
							finalColor.z,
							1.0f
						);
		//cout << finalColor << endl;
		return finalColor;
	}
	if (fe < 0.0f){
		finalColor = (iAmb+iDif);
		finalColor = Vec4(	finalColor.x,
							finalColor.y,
							finalColor.z,
							1.0f
						);
		//cout << finalColor << endl;
		return finalColor;
	}
	finalColor = (iAmb+iDif+iEsp);
	finalColor = Vec4(	min(finalColor.x,1.0f),
						min(finalColor.y,1.0f),
						min(finalColor.z,1.0f),
						1.0f
					);
	return finalColor;
}
