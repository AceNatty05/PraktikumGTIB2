#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // GL_LINE_STRIP
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINE_STRIP);
        glVertex2f(-0.8, 0.7);
        glVertex2f(-0.6, 0.9);
        glVertex2f(-0.4, 0.7);
        glVertex2f(-0.2, 0.9);
    glEnd();

    // GL_LINE_LOOP
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(0.2, 0.7);
        glVertex2f(0.4, 0.9);
        glVertex2f(0.6, 0.7);
        glVertex2f(0.4, 0.5);
    glEnd();

    // GL_TRIANGLE_FAN
    glColor3f(1.0, 0.5, 0.0);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(-0.6, 0.2);
        glVertex2f(-0.7, 0.0);
        glVertex2f(-0.6, -0.2);
        glVertex2f(-0.4, -0.2);
        glVertex2f(-0.3, 0.0);
    glEnd();

    // GL_TRIANGLE_STRIP
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_TRIANGLE_STRIP);
        glVertex2f(-0.1, 0.2);
        glVertex2f(0.0, -0.2);
        glVertex2f(0.2, 0.2);
        glVertex2f(0.3, -0.2);
    glEnd();

    // GL_QUADS
    glColor3f(0.7, 0.3, 0.7);
    glBegin(GL_QUADS);
        glVertex2f(0.4, 0.2);
        glVertex2f(0.6, 0.2);
        glVertex2f(0.6, -0.2);
        glVertex2f(0.4, -0.2);
    glEnd();

    // GL_QUAD_STRIP
    glColor3f(0.0, 0.8, 0.8);
    glBegin(GL_QUAD_STRIP);
        glVertex2f(-0.8, -0.5);
        glVertex2f(-0.7, -0.7);

        glVertex2f(-0.6, -0.5);
        glVertex2f(-0.5, -0.7);

        glVertex2f(-0.4, -0.5);
        glVertex2f(-0.3, -0.7);
    glEnd();

    glFlush();
}

void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Tugas 2 - Primitive OpenGL");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

