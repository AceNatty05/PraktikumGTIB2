
#include <GL/glut.h>

void Roket(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    // background langit
	glColor3f(0.05f, 0.10f, 0.35f);
	glRectf(-1.0f, 1.0f, 1.0f, -1.0f);

    // badan roket 
    glColor3f(0.92f, 0.92f, 0.95f);
    glRectf(-0.18f, 0.68f, 0.18f, -0.38f);

    // ujung roket 
    glColor3f(0.90f, 0.15f, 0.15f);
    glRectf(-0.18f, 0.68f, 0.18f, 0.55f);
    glRectf(-0.14f, 0.78f, 0.14f, 0.68f);
    glRectf(-0.10f, 0.86f, 0.10f, 0.78f);
    glRectf(-0.06f, 0.92f, 0.06f, 0.86f);

    // garis tengah roket 
    glColor3f(0.75f, 0.75f, 0.80f);
    glRectf(-0.02f, 0.55f, 0.02f, -0.38f);

    // jendela roket 
    glColor3f(0.20f, 0.75f, 1.00f);
    glRectf(-0.08f, 0.30f, 0.08f, 0.14f);

    // highlight jendela 
    glColor3f(1.0f, 1.0f, 1.0f);
    glRectf(-0.06f, 0.28f, -0.03f, 0.25f);

    // sirip kiri 
    glColor3f(0.90f, 0.15f, 0.15f);
    glRectf(-0.30f, -0.10f, -0.18f, -0.32f);

    // sirip kanan 
    glRectf(0.18f, -0.10f, 0.30f, -0.32f);

    // mesin abu gelap
    glColor3f(0.35f, 0.35f, 0.40f);
    glRectf(-0.12f, -0.38f, 0.12f, -0.52f);

    // api roket 
    glColor3f(1.0f, 0.85f, 0.10f);   // kuning
    glRectf(-0.07f, -0.52f, 0.07f, -0.70f);

    glColor3f(1.0f, 0.50f, 0.10f);   // oranye
    glRectf(-0.10f, -0.52f, 0.10f, -0.62f);

    glColor3f(1.0f, 0.20f, 0.20f);   // merah
    glRectf(-0.05f, -0.70f, 0.05f, -0.80f);

    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Roket Syifa");

    glutDisplayFunc(Roket);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glutMainLoop();
    return 0;
}
