#pragma once
#include <iostream>
#include <vector>
#include "sphere.hpp"
#include "plane.hpp"
#include "light.hpp"
#include <memory>
using namespace std;

#define tMax 9999.9f

class Scene {
	vector<Object*> objs;
	vector<Light*> lights;
	Light* ambLight;
	Vec4 bgColor;
	public:
		Scene(){
			this->objs.reserve(10);
			this->lights.reserve(2);
			this->bgColor = Vec4(0.0f,0.0f,0.0f,0.0f);
		}
		Scene(int n){
			this->objs.reserve(n);
			this->lights.reserve(n);
			this->bgColor = Vec4(0.0f,0.0f,0.0f,0.0f);
		}
		~Scene(){
			this->objs.clear();
			this->lights.clear();
		}
		void insertObj(Object* o){
			this->objs.push_back(o);
		}
		void setAmbientLight(Vec4 l){
			this->ambLight = new Light(Vec3(0.0f,0.0f,0.0f),l);
		}
		void insertLight(Light* li){
			this->lights.push_back(li);
		}
		Vec4 returnColorScene (Ray* ray){
			Object* o;
			float tiAux;
			float tiMin = tMax-1;
			bool find = false;
			for (Object *obj : this->objs){
				tiAux = obj->intersects(ray);
				if(tiAux >= 0.0f && tiAux < tMax){
					find = true;
					if(tiAux < tiMin){
						tiMin = tiAux;
						o = obj;
					}

				}
			}
			if (find == false){
				Vec3 normal = normalize(ray->dr);
				float a = 0.5f*(normal.y+1.0f);
				Vec4 finalColor = (1.0-a)*Vec4(1.0f,1.0f,1.0f,1.0f) + a*Vec4(0.5f,0.7f,1.0f,1.0f);
				//cout << finalColor << endl;
				return finalColor;
			}
			else{
				Vec4 finalColor = (o->returnColor(tiMin,ray,lights[0],ambLight,this->objs));
				//cout << finalColor << endl;
				return finalColor;
			}

		}

};