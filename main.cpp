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

#include <bits/stdc++.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <stdlib.h>
#include <windows.h>

void display();
void reshape(int,int);
void timer(int);
void init(){
    glClearColor(0.0,0.0,0.0,1.0);
}
double zeroth=15,first=10,second=5,third=0,forth=-5;
int flag=0;
int main(int argc,char**argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

    glutInitWindowPosition(((0.5*GLUT_SCREEN_WIDTH)+500),((0.5*GLUT_SCREEN_HEIGHT)));
    glutInitWindowSize(500,500);

    glutCreateWindow("Road");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0,timer,0);


    init();

    glutMainLoop();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();



    glLineWidth(10.0f);

    glBegin(GL_LINES);

    //road sides
    glVertex2d(-3,10);
    glVertex2d(-5,-10);
    glVertex2d(3,10);
    glVertex2d(5,-10);
    //stripes
    glVertex2d(0,zeroth);
    glVertex2d(0,zeroth-4);

    glVertex2d(0,first);
    glVertex2d(0,first-4);

    glVertex2d(0,second);
    glVertex2d(0,second-4);

    glVertex2d(0,third);
    glVertex2d(0,third-4);

    glVertex2d(0,forth);
    glVertex2d(0,forth-4);

    glEnd();
    if(zeroth<-9.9)zeroth=15;
    if(first<-9.9)first=15;
    if(second<-9.9)second=15;
    if(third<-9.9)third=15;
    if(forth<-9.9)forth=15;

    zeroth=zeroth-0.1;
    first=first-0.1;
    second=second-0.1;
    third=third-0.1;
    forth=forth-0.1;

    glutSwapBuffers();

}
void reshape(int w,int h){
    glViewport((GLint)0,(GLint)0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-10,10,-10,10);
    glMatrixMode(GL_MODELVIEW);
}
void timer(int){
    glutPostRedisplay();
    glutTimerFunc(1000/60,timer,0);

}


