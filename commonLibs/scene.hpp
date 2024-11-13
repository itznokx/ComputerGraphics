#pragma once
#include <iostream>
#include <vector>
#include "sphere.hpp"
#include "plane.hpp"
#include "light.hpp"
#include <memory>
using namespace std;

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
			int index = 0; 
			float tiAux;
			float tiMin = 9999.99f;
			bool find = false;
			for (Object *obj : this->objs){
				tiAux = obj->intersects(ray);
				if(tiAux >= 0.0f){
					find = true;
					if(tiAux < tiMin){
						tiMin = tiAux;
						o = obj;
					}

				}
			}
			if (find == false){
				return bgColor;
			}
			else{
				return (o->returnColor(tiMin,ray,lights[0],ambLight,this->objs));
			}

		}

	private:

};