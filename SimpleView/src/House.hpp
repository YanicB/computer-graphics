
#ifndef CHOUSE_H
#define CHOUSE_H

#include <GL/glut.h>
#include "Shape.hpp"
#include "Cube.hpp"
#include "Pyramid.hpp"

class House : public Shape {
protected:
    Cube cube;
    Pyramid pyramid;
public:
    House();
    void draw();
};

#endif
