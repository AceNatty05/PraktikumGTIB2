// Pertemuan 1 - Nomor 1 - Point Lines
// Nama	: Hana Nafi'atul Haq
// NIM	: 24060124130081
// Lab 	: B2

#include <GL/glut.h>

void displayDasar(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(15.0f);
    glBegin(GL_POINTS);
        glColor3f(0.7f, 0.0f, 0.0f);
        glVertex2f(0.0f, 0.5f);
    glEnd();

    glLineWidth(3.0f);
    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f);

        glVertex2f(-0.5f, -0.5f);
        glVertex2f(0.5f, -0.5f);
        
        glVertex2f(-0.6f, 0.15f);
        glVertex2f(-0.5f, -0.5f);

        glVertex2f(-0.6f, 0.15f);
        glVertex2f(-0.2f, -0.05f);

        glVertex2f(-0.2f, -0.05f);
        glVertex2f(0.0f, 0.5f);

        glVertex2f(0.0f, 0.5f);
        glVertex2f(0.2f, -0.05f);

        glVertex2f(0.2f, -0.05f);
        glVertex2f(0.6f, 0.15f);

        glVertex2f(0.5f, -0.5f);
        glVertex2f(0.6f, 0.15f);

    glEnd();
    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Mahkota");

    glutDisplayFunc(displayDasar);
    glClearColor(0.70f, 0.85f, 0.70f, 1.0f);

    glutMainLoop();
    return 0;
}
