#include <stdlib.h>
#include <iostream>
#include <GL/glut.h>
#include "Fantasma.h"


using namespace std;

Fantasma :: Fantasma(GLuint texture[]){
    speed = 1.0;
    Posicion[0] = 0.0; Posicion[1] = 0.0;
    Direction[0] = 1.0*speed; Direction[1] = 0.0;
    DirectionId = 1;
    texture = texture;
}

void Fantasma::MatAdy(int a[][10], int vx[],int vy[]){
    for(int i = 0; i<10;i++){
        MZ[i]=a[i];
    }

    X = vx;
    Y = vy;

}

void Fantasma::pos_ini(int i,int j){
    Posicion[0] = i;
    Posicion[1] = j;
}

void Fantasma::update_Dir(){

    int xnow, ynow;
    int celda;
    int valR;

    xnow = int(Posicion[0]);
    ynow = int(Posicion[1]);
  if((X[xnow] == -1) || (Y[ynow] == -1)){ //Pasillo normal
    }
    else{

     if((X[xnow] == -1) || (Y[ynow] == -1)){ //Pasillo normal
    }
    else{
        if((X[xnow] != -1) && (Y[ynow] != -1)){
            celda = MZ[Y[ynow]][X[xnow]];   cout<<celda<<endl;
            switch(celda){ //tecla que movio el usuario

                case 10:
                    if(DirectionId==3){
                        DirectionId=2;
                        Direction[1] = -1.0 * speed; //arriba-abajo
                        Direction[0] = 0.0; //derecha - izquierda
                    }
                    else{
                        DirectionId=1;
                        Direction[1] = 0.0;
                        Direction[0] = 1.0 * speed;
                    }
                    break;

                case 11:
                    if(DirectionId==1){
                        DirectionId=2;
                        Direction[1] = -1.0 * speed; //arriba-abajo
                        Direction[0] = 0.0; //derecha - izquierda
                    }
                    else{
                        DirectionId=3;
                        Direction[1] = 0.0;
                        Direction[0] = -1.0 * speed;
                    }
                    break;
                case 12:
                    if(DirectionId==2){
                        DirectionId=1;
                        Direction[1] = 0.0;
                        Direction[0] = 1.0 * speed;
                    }
                    else{
                        DirectionId=0;
                        Direction[1] = 1.0 * speed;
                        Direction[0] = 0.0;
                    }
                    break;

                case 13:
                    if(DirectionId==2){
                        DirectionId=3;
                        Direction[1] = 0.0;
                        Direction[0] = -1.0 * speed;
                    }
                    else{
                        DirectionId=0;
                        Direction[1] = 1.0 * speed;
                        Direction[0] = 0.0;
                    }
                    break;


                case 21: cout<<"pase el 21"<<endl;
                    valR=rand()%2; //Solo puede tomar 0 y 1
                    switch(DirectionId){
                        case 0:
                            if (valR==0){ //indica que va a izq o der
                                DirectionId=3;
                                Direction[1]=0.0;
                                Direction[0]=-1.0*speed;
                            }
                            else{
                                DirectionId=1;
                                Direction[1]=0.0;
                                Direction[0]=1.0*speed;
                            }
                            break;

                        case 1:
                            if (valR==1){
                                DirectionId=2;
                                Direction[1]=-1.0*speed;
                                Direction[0]=0.0;
                            }
                        break;

                        case 3:
                            if (valR==1){
                                DirectionId=2;
                                Direction[1]=-1.0*speed;
                                Direction[0]=0.0;
                            }

                        break;
                    }
                    break;

                case 22:   cout<<"pase el 22"<<endl;
                    valR=rand()%2; //Solo puede tomar 0 y 1
                    switch(DirectionId){
                        case 0:
                            if (valR==0){ //indica que va a izq o der
                                DirectionId=3;
                                Direction[1]=0.0;
                                Direction[0]=-1.0*speed;
                            }
                            break;

                        case 1:
                            if (valR==1){
                                DirectionId=2;
                                Direction[1]=-1.0*speed;
                                Direction[0]=0.0;
                                }
                            else{
                                DirectionId=0;
                                Direction[1]= 1.0*speed;
                                Direction[0]=0.0;
                            }
                        break;

                        case 2:
                            if (valR==1){
                                DirectionId=3;
                                Direction[1]= 0.0;
                                Direction[0]=-1.0*speed;
                            }
                        break;
                    }
                    break;

                case 23: cout<<"pase por el 23"<<endl;
                    valR=rand()%2; //Solo puede tomar 0 y 1
                    switch(DirectionId){
                        case 1:
                            if (valR==0){ //indica que va a izq o der
                                DirectionId=0;
                                Direction[1]=1.0*speed;
                                Direction[0]=0.0;
                            }
                           break;

                        case 2:
                            if (valR==1){
                                DirectionId=1;
                                Direction[1]= 0.0;
                                Direction[0]=1.0*speed;
                                }
                            else{
                                DirectionId=3;
                                Direction[1]=0.0;
                                Direction[0]=-1.0*speed;
                            }
                          break;

                        case 3:
                            if (valR==1){
                                DirectionId=0;
                                Direction[1]= 1.0*speed;
                                Direction[0]=0.0;
                            }
                    }
                         break;

                break;

                case 24:   cout<<"pase el 24"<<endl;
                    valR=rand()%2; //Solo puede tomar 0 y 1
                    switch(DirectionId){
                        case 0:
                            if (valR==0){ //indica que va a izq o der
                                DirectionId=1;
                                Direction[1]=0.0;
                                Direction[0]=1.0*speed;
                            }
                            break;

                        case 2:
                           if (valR==0){ //indica que va a izq o der
                                DirectionId=1;
                                Direction[1]=0.0;
                                Direction[0]=1.0*speed;
                            }
                            break;


                        case 3:
                            if (valR==1){
                                DirectionId=0;
                                Direction[1]= 1.0*speed;
                                Direction[0]=0.0;
                                }
                            else{
                                DirectionId=2;
                                Direction[1]=-1.0*speed;
                                Direction[0]=0.0;
                            }
                        break;
                    }
                    break;

               case 25:  cout<<"pase el 25"<<endl;
                    valR=rand()%3;//Solo puede tomar 0,1,2
                    switch(DirectionId){
                        case 0:
                              if (valR==0){ //indica que va a izq o der
                                DirectionId=3;
                                Direction[1]= 0.0;
                                Direction[0]= -1.0*speed;
                            }
                            else if(valR==1){ //indica que va a izq o der
                                DirectionId=1;
                                Direction[1]= 0.0;
                                Direction[0]= 1.0*speed;
                            }
                            break;
                        case 1:
                               if (valR==0){ //indica que va a izq o der
                                DirectionId=0;
                                Direction[1]= 1.0*speed;
                                Direction[0]=0.0;
                            }
                            else if(valR==1){ //indica que va a izq o der
                                DirectionId=2;
                                Direction[1]= -1.0*speed;
                                Direction[0]= 0.0;
                            }
                            break;
                        case 2:
                             if (valR==0){ //indica que va a izq o der
                                DirectionId=3;
                                Direction[1]= 0.0;
                                Direction[0]= -1.0*speed;
                            }
                            else if(valR==1){ //indica que va a izq o der
                                DirectionId=1;
                                Direction[1]= 0.0;
                                Direction[0]= 1.0*speed;
                            }
                            break;
                        case 3:
                               if (valR==0){ //indica que va a izq o der
                                DirectionId=0;
                                Direction[1]= 1.0*speed;
                                Direction[0]=0.0;
                            }
                            else if(valR==1){ //indica que va a izq o der
                                DirectionId=2;
                                Direction[1]= -1.0*speed;
                                Direction[0]= 0.0;
                            }
                            break;
                    }
                     break;

                    case 26:
                        DirectionId=1;
                        Direction[1] = 0.0;
                        Direction[0] = 1.0 * speed;
                        break;

                    case 27:
                        DirectionId=3;
                        Direction[1] = 0.0;
                        Direction[0] = -1.0 * speed;
                        break;


                break;

            }

            }
        }
    }

}

void Fantasma::update(){
    update_Dir();
    Posicion[0]=Posicion[0]+Direction[0];
    Posicion[1]=Posicion[1]+Direction[1];

}



