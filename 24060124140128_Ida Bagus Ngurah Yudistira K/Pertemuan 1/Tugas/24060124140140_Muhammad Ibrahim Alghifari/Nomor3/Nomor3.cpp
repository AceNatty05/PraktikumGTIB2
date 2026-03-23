//Nama: Muhammad Ibrahim Alghifari
//NIM: 24060124140140
//Lab: B2
#include <GL/glut.h>

void SegiEmpat(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.0f, 0.0f);
    glRectf(-0.25, 0.25, 0.25, -0.25);

    glColor3f(0.0f, 1.0f, 0.0f);
    glRectf(-0.08, 0.35, 0.08, 0.25);

    glColor3f(0.0f, 0.0f, 1.0f);
    glRectf(-0.20, 0.55, 0.20, 0.35);

    glColor3f(1.0f, 0.8f, 0.0f);
    glRectf(0.25, 0.10, 0.75, -0.05);

    glColor3f(1.0f, 0.0f, 1.0f);
    glRectf(-0.75, 0.10, -0.25, -0.05);

    glColor3f(0.0f, 1.0f, 1.0f);
    glRectf(-0.75, 0.60, -0.65, 0.10);

    glColor3f(0.4f, 0.2f, 0.0f);
    glRectf(-0.18, -0.25, -0.08, -0.70);

    glColor3f(0.4f, 0.2f, 0.0f);
    glRectf(0.08, -0.25, 0.18, -0.70);

    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Robot");
    glutDisplayFunc(SegiEmpat);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutMainLoop();
    return 0;
}
