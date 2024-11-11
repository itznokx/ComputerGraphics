#pragma once
#include <iostream>
#include <vector>
#include "objects.hpp"
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
			Vec4(0.0f,0.0f,0.0f,0.0f);
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
			unsigned long int index; 
			float tiMin,tiAux;
			bool find = false;
			for (unsigned long int i=0;i<this->objs.size();i++){
				tiAux = this->objs[i]->intersects(ray);
				if(tiAux >= 0.0f){
					find = true;
					if(tiAux < tiMin){
						tiMin = tiAux;
						index = i;
					}

				}
			}
			if (find == false){
				return bgColor;
			}
			else{
				return (this->objs[index]->returnColor(tiMin,ray,lights[0],ambLight));
			}

		}

	private:

};