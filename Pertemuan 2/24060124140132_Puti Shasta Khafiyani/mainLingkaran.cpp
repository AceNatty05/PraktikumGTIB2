#include <GL/glut.h>
#include <cmath>

#define PI 3.14159265358979323846

void drawCircle(float cx, float cy, float r, int segments) {
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(cx, cy); // center
        for (int i = 0; i <= segments; i++) {
            float angle = 2.0f * PI * i / segments;
            glVertex2f(cx + r * cos(angle), cy + r * sin(angle));
        }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.2f, 0.4f, 0.9f);
    drawCircle(0.0f, 0.0f, 0.5f, 100);

    glFlush();
}

void init() {
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Tugas 1 - Lingkaran");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
