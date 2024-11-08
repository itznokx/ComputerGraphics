#include <iostream>
#include <vector>
#include "objects.hpp"
#include "light.hpp"
using namespace std;

class Scene {
	vector<Object*> objs;
	vector<Light*> lights;
	Vec4 bgColor;
	public:
		Scene(){
			sceneObjects = new Object[10];
		}
		Scene(int n){
			sceneObjects = new Object[n];
		}
		void insert(Object* o){

		}
	private:
		Object* sceneObjects;

};