/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */


#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <stdlib.h>
#include <windows.h>

void display();
void reshape(int,int);
void init(){
    glClearColor(0.0,0.0,0.0,1.0);
}
double xy=-5,yx=-10;
int main(int argc,char**argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowPosition(((0.5*GLUT_SCREEN_WIDTH)+500),((0.5*GLUT_SCREEN_HEIGHT)));
    glutInitWindowSize(500,500);

    glutCreateWindow("Road");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    init();

    glutMainLoop();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();



    glLineWidth(10.0f);
    glBegin(GL_LINES);


    glVertex2d(xy,5);
    glVertex2d(yx,-5);

    glVertex2d(xy+1,4);
    glVertex2d(yx+1,4);

    xy++;
    yx++;
    glEnd();

    glFlush();
    if(xy<=10){
        Sleep(1000);
        display();
    }
}
void reshape(int w,int h){
    glViewport((GLint)0,(GLint)0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-10,10,-10,10);
    glMatrixMode(GL_MODELVIEW);
}


