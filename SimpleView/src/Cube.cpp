/*
 * Description: SimpleView reference design
 * Author: HBF
 * Version: 2025-09-30
 */
#include "Cube.hpp"

Cube::Cube()
{
	// set set cordinate values for all vertices
    // other faces
    r = 1.0;
    g = 1.0;
    b = 1.0;
}

void Cube::drawFace(int i)
{
// draw face i
}

void Cube::draw()
{
    glPushMatrix();
    this->ctmMultiply();
     glScalef(s, s, s);
 // set color
 // draw all faces
    glPopMatrix();
}

