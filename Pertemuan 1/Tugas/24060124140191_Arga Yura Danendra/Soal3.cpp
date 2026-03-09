#include <GL/glut.h>

void background() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void kotak(float x, float y, float w, float h) {
    glBegin(GL_QUADS);
        glVertex2f(x,     y);
        glVertex2f(x + w, y);
        glVertex2f(x + w, y + h);
        glVertex2f(x,     y + h);
    glEnd();
}

void Display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // kepala
    glColor3f(0.6f, 0.3f, 0.1f);
    kotak(-1.5f, -1.5f, 3.0f, 3.0f);

    // telinga
    glColor3f(0.6f, 0.3f, 0.1f);
    kotak(-2.2f, 0.2f, 0.8f, 0.8f);
    kotak( 1.4f, 0.2f, 0.8f, 0.8f);

    // moncong
    glColor3f(0.9f, 0.75f, 0.5f);
    kotak(-0.8f, -1.2f, 1.6f, 1.0f);

    // mata
    glColor3f(1.0f, 1.0f, 1.0f);
    kotak(-1.0f, 0.4f, 0.7f, 0.7f);
    kotak( 0.3f, 0.4f, 0.7f, 0.7f);

    // mata dalam
    glColor3f(0.0f, 0.0f, 0.0f);
    kotak(-0.75f, 0.55f, 0.35f, 0.35f);
    kotak( 0.4f, 0.55f, 0.35f, 0.35f);

    // idung
    glColor3f(0.0f, 0.0f, 0.0f);
    kotak(-0.25f, -0.5f, 0.5f, 0.3f);

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
    glutInitWindowSize(600, 600);
    glutCreateWindow("Muka Monyet - GL_QUADS");
    background();
    glutDisplayFunc(Display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}