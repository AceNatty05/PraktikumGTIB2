#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3f(1.0f, 0.0f, 0.0f);
    glRectf(-0.5f, 0.0f, 0.5f, -0.5f);
    glEnd();
    glFlush();

    glColor3f(1.0f, 0.5f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.6f, 0.0f);
    glVertex2f(0.6f, 0.0f);
    glVertex2f(0.0f, 0.6f);
    glEnd();
    glFlush();

    glColor3f(0.0f, 0.0f, 1.0f);
    glRectf(-0.1f, -0.2f, 0.1f, -0.5f);
    glEnd();
    glFlush();

    glColor3f(1.0f, 0.0f, 0.0f);
    glPointSize(8.0f);
    glBegin(GL_POINTS);
    glVertex2f(0.07f, -0.35f);
    glEnd();
    glFlush();

    glColor3f(0.0f, 0.0f, 1.0f);
    glRectf(-0.45f, -0.1f, -0.25f, -0.3f);
    glEnd();
    glFlush();

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.35f, -0.1f);
    glVertex2f(-0.35f, -0.3f);
    glVertex2f(-0.45f, -0.2f);
    glVertex2f(-0.25f, -0.2f);
    glEnd();
    glFlush();

    glColor3f(0.0f, 0.0f, 1.0f);
    glRectf(0.25f, -0.1f, 0.45f, -0.3f);
    glEnd();
    glFlush();

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINES);
	glVertex2f(0.35f, -0.1f);
    glVertex2f(0.35f, -0.3f);
    glVertex2f(0.25f, -0.2f);
    glVertex2f(0.45f, -0.2f);
    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 480);
    glutCreateWindow("Rumah Galang");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
