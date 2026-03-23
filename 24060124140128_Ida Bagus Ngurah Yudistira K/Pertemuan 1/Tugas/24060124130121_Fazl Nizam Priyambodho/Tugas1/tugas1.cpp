#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Titik menggunakan GL_POINTS
    glColor3f(1.0, 0.0, 0.0);
    glPointSize(8.0);
    glBegin(GL_POINTS);
        glVertex2f(-0.5, 0.5);
        glVertex2f(-0.3, 0.5);
        glVertex2f(-0.1, 0.5);
    glEnd();

    // Garis menggunakan GL_LINES
    glColor3f(0.0, 0.0, 1.0);
    glLineWidth(3.0);
    glBegin(GL_LINES);
        glVertex2f(-0.5, 0.2);
        glVertex2f(0.5, 0.2);

        glVertex2f(-0.5, 0.0);
        glVertex2f(0.5, 0.0);
    glEnd();

    glFlush();
}

void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Tugas 1 - Titik dan Garis");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
