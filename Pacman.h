#ifndef PACMAN_H_INCLUDED
#define PACMAN_H_INCLUDED

#include <stdlib.h>
#include <GL/glut.h>
#include "RgbImage.h"

class Pacman: public RgbImage{
private:

public:
    Pacman(GLuint texture[]);
    void dibujarp();
    void update();
    void update_Dir(int);
    void pos_ini();
    void MatAdy(int[][10], int[] , int[]);
    float Posicion[2];
    float Direction[2];
    int DirId;
    int *MZ[10],*X,*Y;
    GLuint *texture;
    float speed;
    int bufferDir;
    GLfloat xf;
    GLfloat yf;
};

#endif // PACMAN_H_INCLUDED
