#include <iostream>
#include "../commonLibs/window.hpp"
#include "../commonLibs/scene.hpp"

using namespace std;

int main (void){
	float rSphere = 5.0f;
	float dJanela = 5.0f;
	Scene cena;
	Sphere s1 = Sphere(Vec3(0,0,(20.0f+rSphere)),rSphere,Vec4(255,0,0,255),1.0f);
	Sphere s2 = Sphere(Vec3(20,0,(20.0f+rSphere)),rSphere,Vec4(0,255,0,255),1.0f);
	Sphere s3 = Sphere(Vec3(-20,0,(20.0f+rSphere)),rSphere,Vec4(0,0,255,255),1.0f);
	std::cout << "Sphere created\n";
	cena.insert(&s1);
	cena.insert(&s2);
	cena.insert(&s3);
	WindowSDL janela = WindowSDL(500,500);
	Vec4** matrix = colorMatrix(s1,5.0f,5.0f,
								500,500,dJanela);
	std::cout << "Matrix of color created\n";
	janela.renderScene(matrix);
	std::cout << "Scene rendered\n";
	return 0;
}