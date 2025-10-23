#include "Pyramid.hpp"

Pyramid::Pyramid()
{
    vertex[0][0] = -1; vertex[0][1] = -1; vertex[0][2] = 0; 
    vertex[1][0] = 1;  vertex[1][1] = -1; vertex[1][2] = 0;
    vertex[2][0] = 1;  vertex[2][1] = 1;  vertex[2][2] = 0;
    vertex[3][0] = -1; vertex[3][1] = 1;  vertex[3][2] = 0;
    vertex[4][0] = 0;  vertex[4][1] = 0;  vertex[4][2] = 1.5;

    base[0] = 0; base[1] = 1; base[2] = 2; base[3] = 3;
    
    side[0][0] = 0; side[0][1] = 1; side[0][2] = 4; // front
    side[1][0] = 1; side[1][1] = 2; side[1][2] = 4; // right
    side[2][0] = 2; side[2][1] = 3; side[2][2] = 4; // back
    side[3][0] = 3; side[3][1] = 0; side[3][2] = 4; // left
    
    r = 1.0; g = 1.0; b = 0.0;
}

void Pyramid::drawFace(int i)
{
    if (i == 0) {
        glBegin(GL_LINE_LOOP);
        for (int k = 0; k < 4; k++) {
            int vi = base[k];
            glVertex3fv(vertex[vi]);
        }
        glEnd();
    } else if (i >= 1 && i <= 4) {
        int si = i - 1;
        glBegin(GL_LINE_LOOP);
        for (int k = 0; k < 3; k++) {
            int vi = side[si][k];
            glVertex3fv(vertex[vi]);
        }
        glEnd();
    }
}

void Pyramid::draw()
{
    glPushMatrix();
    this->ctmMultiply();
    glScalef(s, s, s);
    
    glColor3f(r, g, b);
    
    for (int i = 0; i < 5; i++) {
        drawFace(i);
    }

    glPopMatrix();
}
