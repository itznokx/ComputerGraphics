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
		Vec3 pI = ray->at(ti);
		Vec3 n = normalize(pI - this->center);
		Vec3 l = normalize(lp->pF-pI);
		Vec3 v = ray->dr*(-1.0f);
		Vec3 r = (2.0f*(dot(l,n)*n))-l;
		Vec4 iAmb = ats(amb->intensity,this->colorAmb);
		float fd = dot(l,n);
		if (fd < 0.0f)
			fd = 0.0f;
		Vec4 iDif = ats(lp->intensity,this->colorDif)*fd;
		float fe = pow(dot(r,v),this->m);
		if (fe < 0.0f)
			fe = 0.0f;
		Vec4 iEsp = ats(lp->intensity,this->colorEsp)*fe;
		Vec4 finalColor = iAmb+iDif+iEsp;
		cout << finalColor << endl;
		return finalColor;
		//return Vec4(1.0f,0.0f,0.0f,1.0f);
		//return (0.5f)*Vec4(n.x+1.0f,n.y+1.0f,n.z+1.0f,1.0f);
	
}