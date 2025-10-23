#include "House.hpp"

House::House()
{
}

void House::draw()
{
    glPushMatrix();
    
    this->ctmMultiply();
    glScalef(s, s, s);
    
    glPushMatrix();
    cube.draw();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.5, 0.5, 1.0);  
    glScalef(0.5, 0.5, 0.5);      
    pyramid.draw();
    glPopMatrix();
    
    glPopMatrix();
}
