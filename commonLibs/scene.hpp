#include <iostream>
#include <vector>
#include "objects.hpp"

using namespace std;

class Scene {
	public:
		Scene(){
			sceneObjects = new Objects[10];
		}
		Scene(int n){
			sceneObjects = new Objects[n];
		}
	private:
		Objects* sceneObjects;

};