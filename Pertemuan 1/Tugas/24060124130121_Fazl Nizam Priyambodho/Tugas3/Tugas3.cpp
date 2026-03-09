#include <GL/glut.h>

void gambarKubus(float x, float y, float ukuran)
{
    glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x + ukuran, y);
        glVertex2f(x + ukuran, y + ukuran);
        glVertex2f(x, y + ukuran);
    glEnd();

    // garis tepi kubus
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(x, y);
        glVertex2f(x + ukuran, y);
        glVertex2f(x + ukuran, y + ukuran);
        glVertex2f(x, y + ukuran);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // warna kubus
    glColor3f(0.3, 0.6, 0.9);

    // Baris bawah (3 kubus)
    gambarKubus(-0.6, -0.6, 0.3);
    glColor3f(0.3, 0.6, 0.9);
    gambarKubus(-0.3, -0.6, 0.3);
    glColor3f(0.3, 0.6, 0.9);
    gambarKubus(0.0, -0.6, 0.3);

    // Baris tengah (2 kubus)
    glColor3f(0.4, 0.7, 1.0);
    gambarKubus(-0.45, -0.3, 0.3);
    glColor3f(0.4, 0.7, 1.0);
    gambarKubus(-0.15, -0.3, 0.3);

    // Baris atas (1 kubus)
    glColor3f(0.5, 0.8, 1.0);
    gambarKubus(-0.3, 0.0, 0.3);

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
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Tugas 3 - Kubus Bertingkat");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

