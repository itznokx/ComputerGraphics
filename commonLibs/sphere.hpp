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
		Vec3 v = ray->Origin - this->center;
		float a = dot(ray->dr,ray->dr);
		float b = 2.0f*(dot(v,ray->dr));
		float c = (dot(v,v)) -  (this->r*this->r);
		float delta = b*b - 4.0f*a*c;
		if (delta < 0){
				return -1.0f;
		}
		else{
			float t1 = (-b+sqrt(delta))/(2.0f*a);
			float t2 = (-b-sqrt(delta))/(2.0f*a);
			if (t1 < 0.0f || t2 < 0.0f)
				return (max(t1,t2));
			else
				return (min(t1,t2));
		}
	}
Vec4 Sphere::returnColor(float ti,Ray* ray,Light* lp,Light* amb,vector<Object*> objs){
	Vec3 pI = (ray->Origin - (ray->dr*ti));
	cout <<"pI: ";pI.print();
	Ray* rayAux = new Ray(pI,lp->pF-pI);
	for (int i=0;i<objs.size();i++){
		float tiAux;
		tiAux = objs[i]->intersects(rayAux);
			if(tiAux >= 0.0f){
				//cout << tiAux << endl;
				Vec4 iAmb = (ats(this->colorAmb,amb->intensity))*255.0f;
				return iAmb;
		}
	}
	//Vec3 v = (ray->Origin-pI);
	Vec3 v = (ray->dr)*(-1.0f);
	Vec3 l = normalize(lp->pF - pI);
	Vec3 n = normalize(this->center-pI);
	float fd = dot(n,l);
	if (fd < 0.0f){
		fd = 0.0f;
	}
	Vec3 r = (2.0f*fd*n)-l;
	float fe = pow(dot(r,l),this->m);
	//cout << fe << endl;
	if (fe < 0.0f)
		fe = 0.0f;
	//cout << "FD: "<< fd << " "<< "FE: " << fe << " | ";
	Vec4 iAmb = (ats(this->colorAmb,amb->intensity));
	//cout <<"iAmb: ";iAmb.print();
	Vec4 iDif = (ats(this->colorDif,lp->intensity)*fd);
	//cout <<"iDif: ";iDif.print();
	Vec4 iEsp = (ats(this->colorEsp,lp->intensity)*fe);
	// cout <<"iEsp: ";iEsp.print();
	Vec4 final = (iAmb+iDif+iEsp);
	final = final*255.0f;
	final = Vec4(min(final.x,255.0f),
				min(final.y,255.0f),
				min(final.z,255.0f),
				255.0f
				);
	//cout <<"final: ";final.print();
	return final;

}