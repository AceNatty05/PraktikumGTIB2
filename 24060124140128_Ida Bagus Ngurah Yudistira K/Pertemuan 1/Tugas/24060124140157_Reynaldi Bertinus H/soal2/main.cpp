#include <GL/glut.h>
#include <cmath>

const float PI = 3.14;

void display(){

    glClear(GL_COLOR_BUFFER_BIT);

    // LINE STRIP
    glColor3f(1,0,0);
    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.9,0.7);
    glVertex2f(-0.7,0.8);
    glVertex2f(-0.5,0.6);
    glVertex2f(-0.3,0.75);
    glEnd();

    // LINE LOOP
    glColor3f(0,1,0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(0.2,0.6);
    glVertex2f(0.4,0.8);
    glVertex2f(0.6,0.6);
    glVertex2f(0.4,0.4);
    glEnd();

    // TRIANGLE FAN
    glColor3f(1,1,0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(-0.6,0.0);
    for(int i=0;i<=20;i++){
        float angle = 2*PI*i/20;
        glVertex2f(-0.6 + 0.2*cos(angle), 0.0 + 0.2*sin(angle));
    }
    glEnd();

    // TRIANGLE STRIP
    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(0,0,1);
    glVertex2f(0.0,0.2);
    glVertex2f(0.1,-0.1);
    glVertex2f(0.3,0.2);
    glVertex2f(0.4,-0.1);
    glVertex2f(0.6,0.2);
    glVertex2f(0.7,-0.1);
    glEnd();

    // QUADS
    glColor3f(1,0,1);
    glBegin(GL_QUADS);
    glVertex2f(-0.8,-0.4);
    glVertex2f(-0.5,-0.4);
    glVertex2f(-0.5,-0.7);
    glVertex2f(-0.8,-0.7);
    glEnd();

    // QUAD STRIP
    glBegin(GL_QUAD_STRIP);
    glColor3f(0,1,1);
    glVertex2f(0.1,-0.4);
    glVertex2f(0.1,-0.7);

    glVertex2f(0.3,-0.4);
    glVertex2f(0.3,-0.7);

    glVertex2f(0.5,-0.4);
    glVertex2f(0.5,-0.7);
    glEnd();

    glFlush();
}

int main(int argc, char** argv){

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800,600);
    glutCreateWindow("Primitive OpenGL");

    glClearColor(0.1,0.1,0.1,1);

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
