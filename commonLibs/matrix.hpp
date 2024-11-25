#pragma once
#include "vector.hpp"
#include <cmath>
#include <iostream>

using namespace std;

// class for 3x3 matrix only
/*
x1 x2 x3
x4 x5 x6
x7 x8 x9
*/
class Matrix3 {
public:
	float x[9];
	Matrix3(){
		zeroMatrix();
	}
	Matrix3(float x0,float x1,float x2,float x3,float x4,float x5,float x6,float x7,float x8)
	{
		x[0] = (x0);
		x[1] = (x1);
		x[2] = (x2);
		x[3] = (x3);
		x[4] = (x4);
		x[5] = (x5);
		x[6] = (x6);
		x[7] = (x7);
		x[8] = (x8);
	}
	Matrix3(float z[]){
		int size = sizeof(z)/sizeof(float);
		for (int i = 0; i < size;i++){
			x[i] = z[i];
		}
	}
	void zeroMatrix(){
		for (int i = 0; i < 9; i++){
			x[i] = 0;
		}
	}
	void makeIdentity(){
		for (int i = 0; i < 9; i++){
			if (i%4==0)
				x[i] = 1;
			else
				x[i] = 0;
		}
	}
	void print(){
		cout 	<< "| " << x[0] << " , " << x[1] << " , " << x[2] << " |" << "\n"
				<< "| " << x[3] << " , " << x[4] << " , " << x[5] << " |" << "\n"
				<< "| " << x[6] << " , " << x[7] << " , " << x[8] << " |" << "\n";
	}
} ;
// Header operators
Matrix3 operator+(Matrix3,Matrix3);
Matrix3 operator-(Matrix3,Matrix3);
Vec3 operator*(Matrix3,Vec3);
// Headers implementation

Matrix3 operator+(Matrix3 m1,Matrix3 m2){
	float z[9];
	for (int i=0;i<9;i++){
		z[i] = m1.x[i]+m2.x[i];
	}
	return Matrix3(z);
 }
