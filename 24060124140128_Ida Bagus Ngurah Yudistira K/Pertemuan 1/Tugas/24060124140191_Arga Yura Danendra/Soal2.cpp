#include <GL/glut.h>

void background() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void Display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // GL_LINE_STRIP
    glLineWidth(2.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINE_STRIP);
        glVertex2f(-3.5f,  3.5f);
        glVertex2f(-2.5f,  3.0f);
        glVertex2f(-1.5f,  3.5f);
        glVertex2f(-0.5f,  3.0f);
    glEnd();

    // GL_LINE_LOOP
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINE_LOOP);
        glVertex2f( 1.0f,  3.5f);
        glVertex2f( 2.0f,  3.5f);
        glVertex2f( 2.5f,  3.0f);
        glVertex2f( 1.5f,  2.7f);
        glVertex2f( 0.5f,  3.0f);
    glEnd();

    // GL_TRIANGLE_FAN
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(-3.0f,  1.5f); 
        glVertex2f(-3.5f,  2.2f);
        glVertex2f(-2.5f,  2.2f);
        glVertex2f(-2.0f,  1.5f);
        glVertex2f(-2.5f,  0.8f);
        glVertex2f(-3.5f,  0.8f);
        glVertex2f(-4.0f,  1.5f);
    glEnd();

    // GL_TRIANGLE_STRIP
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_STRIP);
        glVertex2f( 0.0f,  2.2f);
        glVertex2f( 0.5f,  0.8f);
        glVertex2f( 1.0f,  2.2f);
        glVertex2f( 1.5f,  0.8f);
        glVertex2f( 2.0f,  2.2f);
        glVertex2f( 2.5f,  0.8f);
        glVertex2f( 3.0f,  2.2f);
    glEnd();

    // GL_QUADS
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
        // kotak 1
        glVertex2f(-3.5f, -0.2f);
        glVertex2f(-2.5f, -0.2f);
        glVertex2f(-2.5f, -1.2f);
        glVertex2f(-3.5f, -1.2f);
        // kotak 2
        glVertex2f(-2.0f, -0.2f);
        glVertex2f(-1.0f, -0.2f);
        glVertex2f(-1.0f, -1.2f);
        glVertex2f(-2.0f, -1.2f);
    glEnd();

    // GL_QUAD_STRIP
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUAD_STRIP);
        glVertex2f( 0.5f, -0.2f);
        glVertex2f( 0.5f, -1.2f);
        glVertex2f( 1.5f, -0.2f);
        glVertex2f( 1.5f, -1.2f);
        glVertex2f( 2.5f, -0.2f);
        glVertex2f( 2.5f, -1.2f);
        glVertex2f( 3.5f, -0.2f);
        glVertex2f( 3.5f, -1.2f);
    glEnd();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-4, 4, -4, 4);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("GL_LINE_STRIP hingga GL_QUAD_STRIP");
    background();
    glutDisplayFunc(Display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}