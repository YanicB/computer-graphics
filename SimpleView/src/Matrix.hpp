#ifndef CMATRIX_H
#define CMATRIX_H

#include <GL/gl.h>
#include <iostream>

class Matrix {
	public:
		GLfloat mat[4][4];
		Matrix(); //constructor
		~Matrix(){};
		void loadIdentity();
		void matrixPreMultiply(Matrix* m);
		void transpose();
		void multiplyVector(GLfloat* v);
		void normalize();
		void rotateMatrix(GLfloat x, GLfloat y, GLfloat z, GLfloat angle);
};

#endif 
