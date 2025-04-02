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
	float a = dot((ray->dr));
	//cout << a << endl;
	float b = (-2.0f)*dot(ray->dr,oc);
	//cout << b << endl;
	float c = dot(oc,oc) - (this->radius*this->radius);
	//cout << c << endl;
	float delta = (b*b)-4*a*c;
	
	if (delta < 0)
		return -1.0f;
	else {

		return (-b - sqrt(delta) ) / (2.0f*a);
	}
}
Vec4 Sphere::returnColor(float ti,Ray* ray,Light* lp,Light* amb,vector<Object*> objs){
		Vec3 pI = ray->at(ti*coefError);
		Vec4 iAmb = (ats(amb->intensity,this->colorAmb));
		for (Object *obj : objs){
			Ray* rayAux = new Ray(pI,lp->pF-pI);
			float tiAux = obj->intersects(rayAux);
			if(tiAux >= 0.0f && tiAux < 1.0f){
				return clamp(iAmb);
			}
		}
		Vec3 n = normalize(pI - this->center);
		Vec3 l = normalize(lp->pF-pI);
		Vec3 v = normalize(ray->dr*(-1.0f));
		//Vec3 v = normalize(pI - ray->origin);
		Vec3 r = ((2.0f*(dot(l,n)*n))-l);
		float fd = dot(l,n);
		float fe = pow(dot(r,v),this->m);
		Vec4 iDif = (ats(lp->intensity,this->colorDif)*fd);
		Vec4 iEsp = (ats(lp->intensity,this->colorEsp)*fe);
		if (fd <= 0.0f && fe <= 0.0f)
			return iAmb;
		//cout << "fd: "<< fd << endl << "fe: "<< fe << endl;
		//cout << "iDif: "<< iDif << endl << "iEsp: "<< iEsp << endl;
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
		//return (0.5f)*Vec4(n.x+1.0f,n.y+1.0f,n.z+1.0f,1.0f);
	
}