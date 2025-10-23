
#ifndef CPYRAMID_H
#define CPYRAMID_H

#include <GL/glut.h>
#include "Shape.hpp"
#include "Vector.hpp"

class Pyramid : public Shape {
protected:
    GLfloat vertex[5][3];
    GLint base[4];
    GLint side[4][3];
    GLfloat r, g, b; // color
public:
    Pyramid();
    void draw();
    void drawFace(int i);
};

#endif
