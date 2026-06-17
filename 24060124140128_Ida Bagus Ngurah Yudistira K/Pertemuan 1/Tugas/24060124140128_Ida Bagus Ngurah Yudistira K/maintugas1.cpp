//Nama : Ida Bagus Ngurah Yudistira K
//NIM  : 24060124140128
//Lab  : B2

#include <GL/glut.h>

void display() {

    glClear(GL_COLOR_BUFFER_BIT);

    //POINT
    glPointSize(8.0);
    glBegin(GL_POINTS);
        glColor3f(1,0,0);
        glVertex2f(-0.5,0.5);

        glColor3f(0,1,0);
        glVertex2f(0.0,0.5);

        glColor3f(0,0,1);
        glVertex2f(0.5,0.5);
    glEnd();


    //LINES
    glLineWidth(3);
    glBegin(GL_LINES);
        glColor3f(1,1,0);
        glVertex2f(-0.5,0.0);
        glVertex2f(0.5,0.0);

        glVertex2f(-0.5,-0.5);
        glVertex2f(0.5,-0.5);
    glEnd();


    //LINE STRIP
    glBegin(GL_LINE_STRIP);
        glColor3f(1,0,0);
        glVertex2f(-0.9,0.8);
        glVertex2f(-0.7,0.6);
        glVertex2f(-0.5,0.8);
        glVertex2f(-0.3,0.6);
    glEnd();


    //LINE LOOP
    glBegin(GL_LINE_LOOP);
        glColor3f(0,1,0);
        glVertex2f(-0.2,0.8);
        glVertex2f(0.0,0.6);
        glVertex2f(0.2,0.8);
        glVertex2f(0.0,1.0);
    glEnd();


    //TRIANGLE FAN
    glBegin(GL_TRIANGLE_FAN);
        glColor3f(0,0,1);
        glVertex2f(-0.7,0.0);
        glVertex2f(-0.9,-0.3);
        glVertex2f(-0.7,-0.5);
        glVertex2f(-0.5,-0.3);
    glEnd();


    //TRIANGLE STRIP
    glBegin(GL_TRIANGLE_STRIP);
        glColor3f(1,1,0);
        glVertex2f(-0.2,0.0);
        glVertex2f(0.0,-0.3);
        glVertex2f(0.2,0.0);
        glVertex2f(0.4,-0.3);
    glEnd();


    //QUADS
    glBegin(GL_QUADS);
        glColor3f(0,1,1);
        glVertex2f(-0.2,-0.7);
        glVertex2f(0.0,-0.7);
        glVertex2f(0.0,-0.5);
        glVertex2f(-0.2,-0.5);
    glEnd();


    //QUAD STRIP
    glBegin(GL_QUAD_STRIP);
        glColor3f(1,0,1);
        glVertex2f(0.2,-0.7);
        glVertex2f(0.2,-0.5);
        glVertex2f(0.4,-0.7);
        glVertex2f(0.4,-0.5);
        glVertex2f(0.6,-0.7);
        glVertex2f(0.6,-0.5);
    glEnd();

    glFlush();
}


void init(){
    glClearColor(0,0,0,1);
}


int main(int argc,char** argv){

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(700,700);
    glutCreateWindow("Tugas 1 dan 2");

    init();
    glutDisplayFunc(display);

    glutMainLoop();
}
