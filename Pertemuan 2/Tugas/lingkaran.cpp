// Pertemuan 2 - Tugas - Lingkaran
// Nama : Hana Nafi'atul Haq
// NIM 	: 24060124130081
// Lab 	: B2

#include <GL/glut.h>
#include <math.h>

void Lingkaran(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    float x, y;
    float r = 0.3;

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.7f, 0.8f); 
    for(int i = 0; i < 360; i++) {
        x = r * cos(i * 3.1416 / 180);
        y = r * sin(i * 3.1416 / 180);
        glVertex2f(x - 0.4, y); 
    }
    glEnd();

    glLineWidth(3.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.6f, 0.4f, 1.0f); 
    for(int i = 0; i < 360; i++) {
        x = r * cos(i * 3.1416 / 180);
        y = r * sin(i * 3.1416 / 180);
        glVertex2f(x + 0.4, y);
    }
    glEnd();

    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Lingkaran - Hana");
    glutDisplayFunc(Lingkaran);
    glClearColor(0.85f, 0.9f, 1.0f, 1.0f);
    glutMainLoop();

    return 0;
}
