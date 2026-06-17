#include <GL/glut.h>

void display() {

    glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(8);
    glBegin(GL_POINTS);
        glVertex2f(-0.9, 0.8);
        glVertex2f(-0.8, 0.7);
        glVertex2f(-0.7, 0.8);
    glEnd();
    glFlush();

    glBegin(GL_LINES);
        glVertex2f(-0.6, 0.8);
        glVertex2f(-0.4, 0.6);

        glVertex2f(-0.4, 0.8);
        glVertex2f(-0.6, 0.6);
    glEnd();
    glFlush();

    glBegin(GL_LINE_STRIP);
        glVertex2f(-0.2, 0.8);
        glVertex2f(-0.1, 0.6);
        glVertex2f(0.0, 0.8);
        glVertex2f(0.1, 0.6);
    glEnd();
    glFlush();

    glBegin(GL_LINE_LOOP);
        glVertex2f(0.3, 0.8);
        glVertex2f(0.5, 0.8);
        glVertex2f(0.5, 0.6);
        glVertex2f(0.3, 0.6);
    glEnd();
    glFlush();

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(-0.8, 0.2);
        glVertex2f(-0.9, 0.0);
        glVertex2f(-0.7, 0.0);
        glVertex2f(-0.6, 0.2);
        glVertex2f(-0.7, 0.4);
        glVertex2f(-0.9, 0.4);
    glEnd();
    glFlush();

    glBegin(GL_TRIANGLE_STRIP);
        glVertex2f(-0.4, 0.0);
        glVertex2f(-0.3, 0.3);
        glVertex2f(-0.2, 0.0);
        glVertex2f(-0.1, 0.3);
        glVertex2f(0.0, 0.0);
    glEnd();
    glFlush();

    glBegin(GL_QUADS);
        glVertex2f(0.2, 0.3);
        glVertex2f(0.4, 0.3);
        glVertex2f(0.4, 0.1);
        glVertex2f(0.2, 0.1);
    glEnd();
    glFlush();

    glBegin(GL_QUAD_STRIP);
        glVertex2f(0.6, 0.3);
        glVertex2f(0.6, 0.1);

        glVertex2f(0.7, 0.3);
        glVertex2f(0.7, 0.1);

        glVertex2f(0.8, 0.3);
        glVertex2f(0.8, 0.1);

        glVertex2f(0.9, 0.3);
        glVertex2f(0.9, 0.1);
    glEnd();
    glFlush();
}

void init() {
    glClearColor(1,1,1,1);
    glColor3f(0,0,0);
    gluOrtho2D(-1,1,-1,1);
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600,480);
    glutCreateWindow("Primitive OpenGL");

    init();
    glutDisplayFunc(display);

    glutMainLoop();
}
