#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Badan
    glColor3f(0.2f, 0.6f, 1.0f);
    glRectf(-0.3f, -0.2f, 0.3f, 0.4f);

    // Kepala
    glColor3f(1.0f, 1.0f, 0.0f);
    glRectf(-0.2f, 0.4f, 0.2f, 0.7f);

    // Mata
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(8.0f);
    glBegin(GL_POINTS);
        glVertex2f(-0.1f, 0.6f);
        glVertex2f(0.1f, 0.6f);
    glEnd();

    // Mulut
    glColor3f(1.0f, 0.0f, 0.0f);
    glLineWidth(2.0f);
    glBegin(GL_LINES);
        glVertex2f(-0.1f, 0.5f);
        glVertex2f(0.1f, 0.5f);
    glEnd();

    // Lengan
    glBegin(GL_LINES);
        glVertex2f(-0.3f, 0.2f);
        glVertex2f(-0.5f, 0.0f);
        glVertex2f(0.3f, 0.2f);
        glVertex2f(0.5f, 0.0f);
    glEnd();

    // Kaki
    glBegin(GL_LINES);
        glVertex2f(-0.2f, -0.2f);
        glVertex2f(-0.2f, -0.5f);
        glVertex2f(0.2f, -0.2f);
        glVertex2f(0.2f, -0.5f);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Robot Keaktifan");
    glutDisplayFunc(display);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutMainLoop();
    return 0;
}
