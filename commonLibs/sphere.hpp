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
	float radius;
	Sphere(Vec3 _center,float _r,Vec4 _colorDif,Vec4 _colorEsp,Vec4 _colorAmb,float _m) : 
												colorAmb(_colorAmb),
												colorDif(_colorDif),
												colorEsp(_colorEsp),
												type("Sphere"),
												center(_center), 
												m(_m),
												radius(_r)
	{}
	Sphere(Vec3 _center,float _r,Vec4 color,float _m) : 
												colorAmb(color),
												colorDif(color),
												colorEsp(color),
												type("Sphere"),
												center(_center), 
												m(_m),
												radius(_r)
	{}
	float intersects(Ray* ray);
	Vec4 returnColor(float ti,Ray* ray,Light* lp,Light* amb,vector<Object*> objs);
};
float Sphere::intersects(Ray* ray){
	Vec3 oc = this->center - ray->origin;
	//cout << ray->dr << endl;
	auto a = dot((ray->dr));
	//cout << a << endl;
	auto b = (-2.0f)*dot(ray->dr,oc);
	//cout << b << endl;
	auto c = dot(oc,oc) - (this->radius*this->radius);
	//cout << c << endl;
	auto delta = (b*b)-4*a*c;
	
	if (delta < 0)
		return -1.0f;
	else {

		return (-b - sqrt(delta) ) / (2.0f*a);
	}
}
Vec4 Sphere::returnColor(float ti,Ray* ray,Light* lp,Light* amb,vector<Object*> objs){
		Vec3 pI = ray->at(ti*1.f);
		Vec4 iAmb = (ats(amb->intensity,this->colorAmb));
		/*
		for (Object *obj : objs){
			Ray* rayAux = new Ray(pI,lp->pF-pI);
			float tiAux = obj->intersects(rayAux);
			if(tiAux >= 0.0f && tiAux < tMax){
				return iAmb;
			}
		}*/
		Vec3 n = normalize(pI - this->center);
		Vec3 l = normalize(lp->pF-pI);
		Vec3 v = ray->dr*(-1.0f);
		//Vec3 v = normalize(pI - ray->origin);
		Vec3 r = (2.0f*(dot(l,n)*n))-l;
		float fd = dot(l,n);
		Vec4 iDif = (ats(lp->intensity,this->colorDif)*fd);
		float fe = pow(dot(r,v),this->m);
		Vec4 iEsp = (ats(lp->intensity,this->colorEsp)*fe);
		Vec4 finalColor;
		cout << "fd: "<< fd << endl;
		cout << "fe: "<< fe << endl;
		if (fd < 0.0f)
			finalColor = iAmb+iEsp;
		if (fe < 0.0f)
			finalColor = iAmb+iDif;
		if (fe < 0.0f && fd < 0.0f)
			finalColor = iAmb;
		if (fe > 0.0f && fd > 0.0f)
			finalColor = iAmb+iDif+iEsp;
		//cout << finalColor << endl;
		return finalColor;
		//return (0.5f)*Vec4(n.x+1.0f,n.y+1.0f,n.z+1.0f,1.0f);
	
}