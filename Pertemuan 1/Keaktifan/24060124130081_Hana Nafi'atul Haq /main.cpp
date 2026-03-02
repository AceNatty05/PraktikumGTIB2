#include <GL/glut.h>

// Hana Nafi'atul Haq - 24060124130081

void Kotak(float x1, float y1, float x2, float y2, float r, float g, float b) {
    glColor3f(r, g, b);
    glRectf(x1, y1, x2, y2);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    Kotak(-0.6f, -0.2f, 0.4f, 0.2f, 1.0f, 0.5f, 0.0f); //badan
    Kotak(0.4f, -0.15f, 0.7f, 0.15f, 1.0f, 0.3f, 0.0f); //ekor
    Kotak(-0.2f, 0.2f, 0.1f, 0.4f, 1.0f, 0.6f, 0.2f); //sirip atas
    Kotak(-0.2f, -0.4f, 0.1f, -0.2f, 1.0f, 0.6f, 0.2f); // sirip bawah
    Kotak(-0.45f, 0.05f, -0.35f, 0.15f, 1.0f, 1.0f, 1.0f); // mata putih
    Kotak(-0.42f, 0.08f, -0.38f, 0.12f, 0.0f, 0.0f, 0.0f); // mata hitam

    glFlush();
}

void init(void) {
    glClearColor(0.5f, 0.8f, 1.0f, 1.0f);
    glLoadIdentity();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Gambar Ikan Primitif :)");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
}
