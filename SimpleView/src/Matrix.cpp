#include "Matrix.hpp"
#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

// Constructor Function
Matrix::Matrix() {
	loadIdentity();
}

// Initial Matrix
void Matrix::loadIdentity() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == j) mat[i][j] = 1; 
			else mat[i][j] = 0;
		}
	}
}

void Matrix::matrixPreMultiply(Matrix* m) {
	GLfloat temp[4][4]; 
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			temp[i][j] = m->mat[i][0] * mat[0][j] + m->mat[i][1] * mat[1][j] +
			m->mat[i][2] * mat[2][j] + m->mat[i][3] * mat[3][j];
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			mat[i][j] = temp[i][j];
		}
	}
}

void Matrix::transpose() {
	GLfloat temp;
	for (int i = 0; i < 4; i++) {
		for (int j = i + 1; j < 4; j++) {
			temp = mat[i][j];
			mat[i][j] = mat[j][i];
			mat[j][i] = temp;
		}
	}
}


void Matrix::multiplyVector(GLfloat* v) {
	GLfloat temp[4] = {0};
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			temp[i] += mat[i][j] * v[j];
		}
	}

	for (int i = 0; i < 4; i++) {
		v[i] = temp[i];
	}
}


void Matrix::normalize() {
	for (int i = 0; i < 3; i++) {
		GLfloat length = sqrt(mat[0][i] * mat[0][i] + mat[1][i] * mat[1][i] +
		mat[2][i] * mat[2][i]);

		if (length == 0) continue;

		for (int j = 0; j < 3; j++) {
			mat[i][j] /= length;
		}
	}
}

void Matrix::rotateMatrix(GLfloat x, GLfloat y, GLfloat z, GLfloat angle) {
	GLfloat radianAngle = angle * 3.1415926/180;
	GLfloat axisVectLength = sqrt(x*x + y*y + z*z);
	GLfloat cosA = cos(radianAngle);
	GLfloat oneC = 1 - cosA;
	GLfloat sinA = sin(radianAngle);
	GLfloat ux = x / axisVectLength;
	GLfloat uy = y / axisVectLength;
	GLfloat uz = z / axisVectLength;

	mat[0][0] = ux*ux*oneC + cosA; 
	mat[0][1] = ux*uy*oneC - uz*sinA;
	mat[0][2] = ux*uz*oneC + uy*sinA;
	mat[0][3] = 0;
	mat[1][0] = uy*ux*oneC + uz*sinA; 
	mat[1][1] = uy*uy*oneC + cosA;
	mat[1][2] = uy*uz*oneC - ux*sinA;
	mat[1][3] = 0;
	mat[2][0] = uz*ux*oneC - uy*sinA;
	mat[2][1] = uz*uy*oneC + ux*sinA;
	mat[2][2] = uz*uz*oneC + cosA;
	mat[2][3] = 0;
	mat[3][0] = 0;
	mat[3][1] = 0;
	mat[3][2] = 0;
	mat[3][3] = 1;	
}




