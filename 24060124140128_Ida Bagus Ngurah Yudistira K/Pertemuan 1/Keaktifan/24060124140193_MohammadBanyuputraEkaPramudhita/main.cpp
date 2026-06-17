#include <GL/glut.h>

void SegiEmpat(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.8f, 0.6f);
    glRectf(-0.6f, -0.6f, 0.6f, -0.3f);
	
    glColor3f(1.0f, 0.7f, 0.5f);
    glRectf(-0.5f, -0.3f, 0.5f, -0.05f);

    glColor3f(1.0f, 1.0f, 1.0f);
    glRectf(-0.45f, -0.05f, 0.45f, 0.05f);

    glColor3f(0.0f, 0.0f, 1.0f);
    glRectf(-0.25f, 0.05f, -0.2f, 0.35f);

    glColor3f(1.0f, 1.0f, 0.0f);
    glRectf(-0.235f, 0.35f, -0.215f, 0.42f);

    glColor3f(0.0f, 1.0f, 0.0f);
    glRectf(-0.025f, 0.05f, 0.025f, 0.35f);

    glColor3f(1.0f, 1.0f, 0.0f);
    glRectf(-0.01f, 0.35f, 0.01f, 0.42f);

    glColor3f(1.0f, 0.0f, 1.0f);
    glRectf(0.2f, 0.05f, 0.25f, 0.35f);

    glColor3f(1.0f, 1.0f, 0.0f);
    glRectf(0.215f, 0.35f, 0.235f, 0.42f);

    glFlush();
}


int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Happy Birth Day for you!");
    glutDisplayFunc(SegiEmpat);
    glClearColor(1.0f, 0.6f, 0.8f, 1.0f);
    glutMainLoop();
    return 0;
}
