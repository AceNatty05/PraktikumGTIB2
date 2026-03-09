#include <GL/glut.h>

void background() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void Display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // titik
    glPointSize(10.0f);
    glBegin(GL_POINTS);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(-1.0f, 0.0f);
    glEnd();

    // garis diagonal (/)
    glLineWidth(3.0f);
    glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(-1.0f, -1.0f);
        glVertex2f( 1.0f,  1.0f);
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
    glutCreateWindow("1 Titik dan 1 Garis");
    background();
    glutDisplayFunc(Display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}