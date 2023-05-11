#include <stdlib.h>
#include <iostream>
#include <GL/glut.h>
#include "Pacman.h"


using namespace std;

Pacman :: Pacman(GLuint texture[]){
    speed = 1.0;
    Posicion[0] = 0.0; Posicion[1] = 0.0;
    Direction[0] = 1.0*speed; Direction[1] = 0.0*speed;
    DirId = 1;
    texture = texture;
    bufferDir = -1;
}
void Pacman::MatAdy(int a[][10], int vx[],int vy[]){
    for(int i = 0; i<10;i++){
        MZ[i]=a[i];
    }

    X = vx;
    Y = vy;

}

void Pacman::pos_ini(){
    Posicion[0] = 18;
    Posicion[1] = 15;
}


void Pacman::dibujarp(){
    float points2[4][2]={{0.0,0.0},{0.0,25.0},{25.0,25.0},{25.0,0.0}};
    glPushMatrix();
    glTranslatef(xf,yf,0.0);
    glBindTexture(GL_TEXTURE_2D, *texture);
    glEnable(GL_TEXTURE_2D);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0, 0.0);
        glVertex2fv(points2[0]);

        glTexCoord2f(0.0, 1.0);
        glVertex2fv(points2[1]);


        glTexCoord2f(1.0, 1.0);
        glVertex2fv(points2[2]);


        glTexCoord2f(1.0, 0.0);
        glVertex2fv(points2[3]);

    glEnd();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}

void Pacman::update_Dir(int dir){

    int xnow, ynow;
    int celda;


    xnow = int(Posicion[0]);
    ynow = int(Posicion[1]);




    if((X[xnow] == -1) || (Y[ynow] == -1)){ //Pasillo normal
        switch(DirId){ //variable entera arriba,abajo,derecha
        case 0:
            if(dir==2){
                Direction[0] = -1.0 *speed;
                Direction[1] =  0.0;//abajo
                DirId = 2;
            }
            else
                bufferDir = dir;
            break;
        case 1:
            if(dir==3){
                Direction[0] = 0.0; //izquierda
                Direction[1] = -1.0 *speed;
                DirId = 3;
            }
            else
                bufferDir = dir;
            break;
        case 2:
            if(dir == 0){
                Direction[0] = 1.0 * speed;
                Direction[1] = 0.0; //arriba
                DirId = 0;
            }
            else
                bufferDir = dir;
            break;

        case 3:
            if(dir == 1){
                Direction[0] = 0.0;//derecha
                Direction[1] = 1.0 * speed;
                DirId = 1;
            }
            else
                bufferDir = dir;
            break;
        }
    }
    else{

        if((X[xnow] != -1) && (Y[ynow] != -1)){
            celda = MZ[Y[ynow]][X[xnow]];
            switch(dir){ //tecla que movio el usuario
            case 0:
                switch(celda){ //celda en matriz
                    case 12:
                    case 13:
                    case 22:
                    case 23:
                    case 24:
                    case 25:
                        //cout<<' '<<celda<<endl;
                        Direction[0] = 0.0;
                        Direction[1] = 1.0 * speed; // arriba //Importante!!!
                        DirId = 0;
                        bufferDir = -1;
                        break;
                }
                break;
            case 1:
                switch(celda){
                    case 10:
                    case 12:
                    case 21:
                    case 23:
                    case 24:
                    case 25:
                    case 26:
                        Direction[0] = 1.0*speed; //derecha
                        Direction[1] = 0.0;
                        DirId = 1;
                        bufferDir = -1;
                        break;
                }
                break;
            case 2:
                switch(celda){
                    case 11:
                    case 10:
                    case 21:
                    case 22:
                    case 24:
                    case 25:
                        Direction[0] = 0.0;
                        Direction[1] = -1.0*speed; //abajo
                        DirId = 2;
                        bufferDir = -1;
                        break;
                }
                break;
            case 3:
                switch(celda){
                    case 11:
                    case 13:
                    case 21:
                    case 22:
                    case 23:
                    case 25:
                    case 27:
                        Direction[0] = -1.0*speed; //izquierda
                        Direction[1] = 0.0;
                        DirId = 3;
                        bufferDir = -1;
                        break;
                }
                break;

            }
        }

    }
}

void Pacman::update(){
    int xnow,ynow;

    int celda;
    if(bufferDir != -1){ //flecha capturada --> para detectar una interseccion
        update_Dir(bufferDir);
    }

    xnow = int(Posicion[0]);
    ynow = int(Posicion[1]);

    if((X[xnow] == -1) || (Y[ynow] == -1)){ //Se pregunta en pasillo
        Posicion[0] = Posicion[0]+Direction[0];
        Posicion[1] = Posicion[1]+Direction[1];
    }
    else{
        celda = MZ[Y[ynow]][X[xnow]];//donde esta el objeto
        switch(DirId){ //¿cual es la direccion actual
        case 0:  //va hacia arriba
            //cout<<celda<<' '<<Direction[0]<<' '<<Direction[1]<<endl;
            switch(celda){
                    case 0: //falsas intercepciones
                    case 12:
                    case 13:
                    case 22:
                    case 23:
                    case 24:
                    case 25:
                        Posicion[0] = Posicion[0]+Direction[0];
                        Posicion[1] = Posicion[1]+Direction[1];
                        break;
            }
            break;
        case 1:
        //cout<<xnow <<' ' << ynow << ' ' << X[xnow]<<' '<<Y[ynow]<<' '<<' '<<celda<<endl;
                switch(celda){
                    case 0:
                    case 10:
                    case 12:
                    case 21:
                    case 23:
                    case 24:
                    case 25:
                    case 26:
                        Posicion[0] = Posicion[0]+Direction[0];
                        Posicion[1] = Posicion[1]+Direction[1];
                        break;
                }
                break;
        case 2:
                switch(celda){
                    case 0:
                    case 10:
                    case 11:
                    case 21:
                    case 22:
                    case 24:
                    case 25:
                        Posicion[0] = Posicion[0]+Direction[0];
                        Posicion[1] = Posicion[1]+Direction[1];
                        break;
                }
                break;
        case 3:
                switch(celda){
                    case 0:
                    case 11:
                    case 13:
                    case 21:
                    case 22:
                    case 23:
                    case 25:
                    case 27:
                        Posicion[0] = Posicion[0]+Direction[0];
                        Posicion[1] = Posicion[1]+Direction[1];
                        break;
                }
                break;

        }


    }

}
