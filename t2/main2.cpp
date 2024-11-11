#include <iostream>
#include "../commonLibs/window.hpp"
#include "../commonLibs/scene.hpp"

using namespace std;

int main (void){
	float rSphere = 5.0f;
	float dJanela = 5.0f;
	Scene cena;
	Sphere s1 = Sphere(Vec3(0,0,-(10.0f+dJanela+rSphere)),rSphere,Vec4(255.0f,0.0f,0.0f,255.0f),1.0f);
	//Sphere s2 = Sphere(Vec3(20,0,-(dJanela+rSphere)),rSphere,Vec4(0,255,0,255),1.0f);
	//Sphere s3 = Sphere(Vec3(-20,0,-(dJanela+rSphere)),rSphere,Vec4(0,0,255,255),1.0f);
	Light l1 = Light(Vec3(0.0f,5.0f,0.0f),Vec4(179,179,179,255));
	cena.insertLight(&l1);
	cena.setAmbientLight(Vec4(76,76,76,255));
	std::cout << "Sphere created\n";
	cena.insertObj(&s1);
	//cena.insertObj(&s2);
	//cena.insertObj(&s3);
	WindowSDL janela = WindowSDL(500,500);
	Vec4** matrix = colorMatrix(cena,5.0f,5.0f,
								500,500,dJanela);
	std::cout << "Matrix of color created\n";
	janela.renderScene(matrix);
	std::cout << "Scene rendered\n";
	return 0;
}