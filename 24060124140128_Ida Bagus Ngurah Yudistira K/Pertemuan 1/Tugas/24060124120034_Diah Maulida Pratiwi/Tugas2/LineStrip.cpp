#include <GL/glut.h>

void GarisStrip(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(4.0f);
    glBegin(GL_LINE_STRIP);
    glColor3f(1.f, 1.0f, 1.0f);
    glVertex3f(0.5, 0.5, 0.0);
    glVertex3f(-0.5, 0.5, 0.0);
    glVertex3f(-0.5, 0.0, 0.0);
    glVertex3f(0.5, 0.0, 0.0);
    glVertex3f(0.5, -0.5, 0.0);
    glVertex3f(-0.5, -0.5, 0.0);
    glEnd();
    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 640);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Implementasi GL_LINE_STRIP");
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
    glutDisplayFunc(GarisStrip);
    glutMainLoop();
    return 0;
}
