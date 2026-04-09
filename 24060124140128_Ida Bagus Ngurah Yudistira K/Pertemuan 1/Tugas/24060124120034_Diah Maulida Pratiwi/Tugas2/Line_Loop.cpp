#include <GL/glut.h>

void garisLoop() {
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(4.0f);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(0.0, 0.25, 0.0);
    glVertex3f(0.25, 0.5, 0.0);
    glVertex3f(0.5, 0.5, 0.0);
    glVertex3f(0.5, 0.0, 0.0);
    glVertex3f(0.0, -0.5, 0.0);
    glVertex3f(-0.5, 0.0, 0.0);
    glVertex3f(-0.5, 0.5, 0.0);
    glVertex3f(-0.25, 0.5, 0.0);
    glEnd();
    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 640);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Membuat GL_LINE_LOOP");
    glutDisplayFunc(garisLoop);
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
    glutMainLoop();
    return 0;
}
