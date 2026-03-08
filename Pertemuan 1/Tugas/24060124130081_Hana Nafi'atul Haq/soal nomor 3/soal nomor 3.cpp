// Pertemuan 1 - nomor 3 - kubus
// Nama	: Hana Nafi'atul Haq
// NIM	: 24060124130081
// Lab	: B2

#include <GL/glut.h>

void Segi4(float x1, float y1, float x2, float y2, float r, float g, float b) {
    glColor3f(r, g, b);
    glRectf(x1, y1, x2, y2);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    Segi4(-0.6f, -0.2f, 0.4f, 0.2f, 1.0f, 0.5f, 0.0f); // badan
    Segi4(0.4f, -0.15f, 0.7f, 0.15f, 1.0f, 0.3f, 0.0f); // ekor
    Segi4(-0.2f, 0.2f, 0.1f, 0.4f, 1.0f, 0.6f, 0.2f); // sirip atas
    Segi4(-0.2f, -0.4f, 0.1f, -0.2f, 1.0f, 0.6f, 0.2f); // sirip bawah
    Segi4(-0.45f, 0.05f, -0.35f, 0.15f, 1.0f, 1.0f, 1.0f); // mata putih
    Segi4(-0.42f, 0.08f, -0.38f, 0.12f, 0.0f, 0.0f, 0.0f); // mata hitam
    Segi4(-0.55f, -0.05f, -0.40f, 0.0f, 0.8f, 0.2f, 0.0f); // mulut

    glutSwapBuffers();
}

void init(void) {
    glClearColor(0.5f, 0.8f, 1.0f, 1.0f); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Gambar Ikan Primitif - Hana");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
