#ifndef FANTASMA_H_INCLUDED
#define FANTASMA_H_INCLUDED

#include <stdlib.h>
#include <GL/glut.h>
#include "RgbImage.h"

class Fantasma: public RgbImage{
private:

public:
    Fantasma(GLuint texture[]);
    void dibujar();
    void update();
    void update_Dir();
    void pos_ini(int,int);
    void MatAdy(int[][10], int[] , int[]);
    float Posicion[2];
    float Direction[2];
    int DirectionId;
    int *MZ[10],*X,*Y;
    GLuint *texture;
    float speed;
};

#endif // FANTASMA_H_INCLUDED
