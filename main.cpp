/*
 * TextureBMP.cpp
 *
 * Loosely based on the example checker.c
 * (Example 9-1, OpenGL Programming Guide, 3rd edition)
 *
 * Read an image from a bitmap (.bmp) file, and draw it as a texture
 * map on a quad.  A cpp class RgbImage is used to read a texture
 * map from a bitmap (.bmp) file.
 *
 * Author: Samuel R. Buss
 *
 * Software accompanying the book.
 *		3D Computer Graphics: A Mathematical Introduction with OpenGL,
 *		by S. Buss, Cambridge University Press, 2003.
 *
 * Software is "as-is" and carries no warranty.  It may be used without
 *   restriction, but if you modify it, please change the filenames to
 *   prevent confusion between different versions.
 * Bug reports: Sam Buss, sbuss@ucsd.edu.
 * Web page: http://math.ucsd.edu/~sbuss/MathCG
 *
 */

#include <stdlib.h>
#include <GL/glut.h>
#include <iostream>
#include "RgbImage.h"
#include "Pacman.h"
#include "Fantasma.h"

using namespace std;

//se define la cantidad de texturas que se manejaran
#define NTextures 2
GLuint	texture[NTextures];

char* filename5="verde.bmp";
char* filename4 = "morado.bmp";
char* filename3 = "azul.bmp";
char* filename2 = "rojo.bmp";
char* filename1 = "ppp.bmp";
char* filename = "mazeee.bmp";
float points[4][2]={{0.0,0.0},{0.0,496.0},{448.0,496.0},{448.0,0.0}};
float points2[4][2]={{0.0,0.0},{0.0,15.0},{15.0,15.0},{15.0,0.0}};
Pacman pacman(texture);
Fantasma fantasma (texture);
Fantasma fantasma1 (texture);
Fantasma fantasma2 (texture);
Fantasma fantasma3 (texture);


//char* filename = "RedLeavesTexture.bmp";

/*
 * Read a texture map from a BMP bitmap file.
 */
#include <stdlib.h>
#include <GL/glut.h> //#include <glut.h> para visual studio

GLint xi = 0;
GLint yi = 0;
int xG=0, yG=0;
float s = 40.0, sfactor = 1.0;
int X[448];
int Y[496];
int MatAdy[10][10];
//float points[3][3]={{0.0,0.0,1.0},{1.0,0.0,1.0},{0.5,1.0,1.0}};
void init_MatAdy(){
        /*MatAdy[0][0] = 10; MatAdy[0][1] = 0; MatAdy[0][2] = 21; MatAdy[0][3] = 0; MatAdy[0][4] = 11; MatAdy[0][5] = 10; MatAdy[0][6] = 0; MatAdy[0][7] = 21; MatAdy[0][8] = 0; MatAdy[0][9] = 11;
        MatAdy[1][0] = 24; MatAdy[1][1] = 0; MatAdy[1][2] = 25; MatAdy[1][3] = 21; MatAdy[1][4] = 23; MatAdy[1][5] = 23; MatAdy[1][6] = 21; MatAdy[1][7] = 25; MatAdy[1][8] = 0; MatAdy[1][9] = 22;
        MatAdy[2][0] = 12; MatAdy[2][1] = 0; MatAdy[2][2] = 22; MatAdy[2][3] = 12; MatAdy[2][4] = 11; MatAdy[2][5] = 10; MatAdy[2][6] = 13; MatAdy[2][7] = 24; MatAdy[2][8] = 0; MatAdy[2][9] = 13;
        MatAdy[3][0] = 0; MatAdy[3][1] = 0; MatAdy[3][2] = 0; MatAdy[3][3] = 10; MatAdy[3][4] = 23; MatAdy[3][5] = 23; MatAdy[3][6] = 11; MatAdy[3][7] = 0; MatAdy[3][8] = 0; MatAdy[3][9] = 0;
        MatAdy[4][0] = 26; MatAdy[4][1] = 0; MatAdy[4][2] = 25; MatAdy[4][3] = 22; MatAdy[4][4] = 0; MatAdy[4][5] = 0; MatAdy[4][6] = 24; MatAdy[4][7] = 25; MatAdy[4][8] = 0; MatAdy[4][9] = 27;
        MatAdy[5][0] = 0;MatAdy[5][1] = 0; MatAdy[5][2] = 0; MatAdy[5][3] = 24; MatAdy[5][4] = 0; MatAdy[5][5] = 0; MatAdy[5][6] = 22; MatAdy[5][7] = 0; MatAdy[5][8] = 0; MatAdy[5][9] = 0;
        MatAdy[6][0] = 10; MatAdy[6][1] = 0; MatAdy[6][2] = 25; MatAdy[6][3] = 23; MatAdy[6][4] = 11; MatAdy[6][5] = 10; MatAdy[6][6] = 23; MatAdy[6][7] = 25; MatAdy[6][8] = 0; MatAdy[6][9] = 11;
        MatAdy[7][0] = 12; MatAdy[7][1] = 11; MatAdy[7][2] = 24; MatAdy[7][3] = 21; MatAdy[7][4] = 23; MatAdy[7][5] = 23; MatAdy[7][6] = 21; MatAdy[7][7] = 22; MatAdy[7][8] = 10; MatAdy[7][9] = 13;
        MatAdy[8][0] = 10; MatAdy[8][1] = 23; MatAdy[8][2] = 13; MatAdy[8][3] = 12; MatAdy[8][4] = 11; MatAdy[8][5] = 10; MatAdy[8][6] = 13; MatAdy[8][7] = 12; MatAdy[8][8] = 23; MatAdy[8][9] = 11;
        MatAdy[9][0] = 12; MatAdy[9][1] = 0; MatAdy[9][2] = 0; MatAdy[9][3] = 0; MatAdy[9][4] = 23; MatAdy[9][5] = 23; MatAdy[9][6] = 0; MatAdy[9][7] = 0; MatAdy[9][8] = 0; MatAdy[9][9] = 13;*/

        MatAdy[9][0] = 10; MatAdy[9][1] = 0; MatAdy[9][2] = 21; MatAdy[9][3] = 0; MatAdy[9][4] = 11; MatAdy[9][5] = 10; MatAdy[9][6] = 0; MatAdy[9][7] = 21; MatAdy[9][8] = 0; MatAdy[9][9] = 11;
        MatAdy[8][0] = 24; MatAdy[8][1] = 0; MatAdy[8][2] = 25; MatAdy[8][3] = 21; MatAdy[8][4] = 23; MatAdy[8][5] = 23; MatAdy[8][6] = 21; MatAdy[8][7] = 25; MatAdy[8][8] = 0; MatAdy[8][9] = 22;
        MatAdy[7][0] = 12; MatAdy[7][1] = 0; MatAdy[7][2] = 22; MatAdy[7][3] = 12; MatAdy[7][4] = 11; MatAdy[7][5] = 10; MatAdy[7][6] = 13; MatAdy[7][7] = 24; MatAdy[7][8] = 0; MatAdy[7][9] = 13;
        MatAdy[6][0] = 0; MatAdy[6][1] = 0; MatAdy[6][2] = 0; MatAdy[6][3] = 10; MatAdy[6][4] = 23; MatAdy[6][5] = 23; MatAdy[6][6] = 11; MatAdy[6][7] = 0; MatAdy[6][8] = 0; MatAdy[6][9] = 0;
        MatAdy[5][0] = 26; MatAdy[5][1] = 0; MatAdy[5][2] = 25; MatAdy[5][3] = 22; MatAdy[5][4] = 0; MatAdy[5][5] = 0; MatAdy[5][6] = 24; MatAdy[5][7] = 25; MatAdy[5][8] = 0; MatAdy[5][9] = 27;
        MatAdy[4][0] = 0;MatAdy[4][1] = 0; MatAdy[4][2] = 0; MatAdy[4][3] = 24; MatAdy[4][4] = 0; MatAdy[4][5] = 0; MatAdy[4][6] = 22; MatAdy[4][7] = 0; MatAdy[4][8] = 0; MatAdy[4][9] = 0;
        MatAdy[3][0] = 10; MatAdy[3][1] = 0; MatAdy[3][2] = 25; MatAdy[3][3] = 23; MatAdy[3][4] = 11; MatAdy[3][5] = 10; MatAdy[3][6] = 23; MatAdy[3][7] = 25; MatAdy[3][8] = 0; MatAdy[3][9] = 11;
        MatAdy[2][0] = 12; MatAdy[2][1] = 11; MatAdy[2][2] = 24; MatAdy[2][3] = 21; MatAdy[2][4] = 23; MatAdy[2][5] = 23; MatAdy[2][6] = 21; MatAdy[2][7] = 22; MatAdy[2][8] = 10; MatAdy[2][9] = 13;
        MatAdy[1][0] = 10; MatAdy[1][1] = 23; MatAdy[1][2] = 13; MatAdy[1][3] = 12; MatAdy[1][4] = 11; MatAdy[1][5] = 10; MatAdy[1][6] = 13; MatAdy[1][7] = 12; MatAdy[1][8] = 23; MatAdy[1][9] = 11;
        MatAdy[0][0] = 12; MatAdy[0][1] = 0; MatAdy[0][2] = 0; MatAdy[0][3] = 0; MatAdy[0][4] = 23; MatAdy[0][5] = 23; MatAdy[0][6] = 0; MatAdy[0][7] = 0; MatAdy[0][8] = 0; MatAdy[0][9] = 13;

        for(int i = 0; i<448;i++){
            X[i] = -1;
        }
        for(int i = 0; i<496;i++){
            Y[i] = -1;
        }

    X[18] = 0;
    X[48] = 1;
    X[98] = 2;
    X[145] = 3;
    X[192] = 4;
    X[242] = 5;
    X[288] = 6;
    X[336] = 7;
    X[388] = 8;
    X[415] = 9;

    Y[15] = 0;
    Y[64] = 1;
    Y[113] = 2;
    Y[160] = 3;
    Y[209] = 4;
    Y[258] = 5;
    Y[306] = 6;
    Y[354] = 7;
    Y[401] = 8;
    Y[465] = 9; //471
}

void ArrowKey(int key, int x, int y){
switch (key){
/*case GLUT_KEY_RIGHT:
xi += 1.5;
break;
case GLUT_KEY_LEFT:
xi -= 1.5;
break;
case GLUT_KEY_UP:
yi += 1.5;
break;
case GLUT_KEY_DOWN:
yi -= 1.5;
break;*/
case GLUT_KEY_UP:
    pacman.update_Dir(0);
break;
case GLUT_KEY_DOWN:
    pacman.update_Dir(2);
break;
case GLUT_KEY_LEFT:
    pacman.update_Dir(3);
break;
case GLUT_KEY_RIGHT:
    pacman.update_Dir(1);
break;
}
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
        case 27:
            exit(0);
            break;
        default:
            break;
}
}
void loadTextureFromFile(char *filename, int id)
{
	glClearColor (0.0, 0.0, 0.0, 0.0); //completamente oscuro
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);

	RgbImage theTexMap( filename );

    //generate an OpenGL texture ID for this texture
    glGenTextures(1, &texture[id]); //se va  ahacer ues e
    glGenTextures(2, &texture[id]); //se va  ahacer ues e

    //bind to the new texture ID
    glBindTexture(GL_TEXTURE_2D, texture[id]);


    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, theTexMap.GetNumCols(), theTexMap.GetNumRows(), 0,
                     GL_RGB, GL_UNSIGNED_BYTE, theTexMap.ImageData());
    theTexMap.Reset();
}

/*
 * Draw the texture in the OpenGL graphics window
 */

void init()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 448, 0, 496);
    loadTextureFromFile(filename, 0);
    loadTextureFromFile(filename1, 1);
    loadTextureFromFile(filename2, 2);
    loadTextureFromFile(filename3, 3);
    loadTextureFromFile(filename4, 4);
    loadTextureFromFile(filename5, 5);

    init_MatAdy();
    pacman.MatAdy(MatAdy,X,Y);
    pacman.pos_ini();
    fantasma.MatAdy(MatAdy,X,Y);
    fantasma1.MatAdy(MatAdy,X,Y);
    fantasma2.MatAdy(MatAdy,X,Y);
    fantasma3.MatAdy(MatAdy,X,Y);
    fantasma2.pos_ini(415,465);
    fantasma1.pos_ini(18,465);
    fantasma.pos_ini(415,15);
    fantasma3.pos_ini(18,15);



    /*for(i=0;1<4;i++){
        fantasma[i]=now Fantasma (texture,i+2);
        fantasma[i]->MatAdy(MatAdy,X,Y)
    }

    fantasma[0]->start(23,471,1);
    fantasma[1]->start(424,24,0);
    fantasma[2]->start(424,471,3);
    fantasma[3]->start(199,213,1); */

}

void dibujap(void){
    glPushMatrix();
    //cout<<pacman.Posicion[0]<<' '<<pacman.Posicion[1]<<endl;
    glTranslatef(pacman.Posicion[0],pacman.Posicion[1],0.0);
    //glTranslatef(fantasma.Posicion[0],fantasma.Posicion[1],0.0);

    glBindTexture(GL_TEXTURE_2D, texture[1]);
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


void dibujaf(int n){
    glPushMatrix();
    //cout<<fantasma.Posicion[0]<<' '<<fantasma.Posicion[1]<<endl;
    glTranslatef(fantasma.Posicion[0],fantasma.Posicion[1],0.0);

    glBindTexture(GL_TEXTURE_2D, texture[2]);
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


void dibujaf1(int n){
    glPushMatrix();
    //cout<<fantasma.Posicion[0]<<' '<<fantasma.Posicion[1]<<endl;
    glTranslatef(fantasma1.Posicion[0],fantasma1.Posicion[1],0.0);

    glBindTexture(GL_TEXTURE_2D, texture[3]);
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

void dibujaf2(int n){
    glPushMatrix();
    //cout<<fantasma.Posicion[0]<<' '<<fantasma.Posicion[1]<<endl;
    glTranslatef(fantasma2.Posicion[0],fantasma2.Posicion[1],0.0);

    glBindTexture(GL_TEXTURE_2D, texture[4]);
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

void dibujaf3(int n){
    glPushMatrix();
    //cout<<fantasma.Posicion[0]<<' '<<fantasma.Posicion[1]<<endl;
    glTranslatef(fantasma3.Posicion[0],fantasma3.Posicion[1],0.0);

    glBindTexture(GL_TEXTURE_2D, texture[5]);
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

void dibujaPoligono(void)
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
     //activa la textura

    // --> Se activa la maquina de estados
    //en el array se guarda las direcciones de memoria

    glBegin(GL_QUADS);
        glTexCoord2f(0.0, 0.0);
        glVertex2fv(points[0]);

        glTexCoord2f(0.0, 1.0);
        glVertex2fv(points[1]);


        glTexCoord2f(1.0, 1.0);
        glVertex2fv(points[2]);


        glTexCoord2f(1.0, 0.0);
        glVertex2fv(points[3]);

    glEnd();
   glDisable(GL_TEXTURE_2D);
}
void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    dibujap();
    dibujaf(2);
    dibujaf1(3);
    dibujaf2(4);
    dibujaf3(5);

    pacman.update();//posicion del objeto
    fantasma.update();
    fantasma1.update();
    fantasma2.update();
    fantasma3.update();



    dibujaPoligono();
    glFlush();
    Sleep(10);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(448, 496);
	glutInitWindowPosition(100, 100);
    glutCreateWindow("Proyecto");
    init();
	glutDisplayFunc(display);
	//glutReshapeFunc(drawScene);
    //glutReshapeFunc(reshape);
    glutIdleFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(ArrowKey);

	glutMainLoop();
}
