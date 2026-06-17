#include <GL/glut.h>

// Fungsi kotak 
void Kotak(float x1, float y1, float x2, float y2,
           float r, float g, float b) {

    glColor3f(r, g, b);
    glRectf(x1, y1, x2, y2);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    // ===== MATA =====
    Kotak(-0.6f, 0.6f, -0.2f, 0.2f, 0,0,0);
    Kotak( 0.2f, 0.6f,  0.6f, 0.2f, 0,0,0);

    // ===== HIDUNG =====
    Kotak(-0.2f, 0.2f, 0.2f, -0.1f, 0,0,0);

    // ===== MULUT =====
    Kotak(-0.6f, -0.1f, -0.2f, -0.6f, 0,0,0);
    Kotak( 0.2f, -0.1f,  0.6f, -0.6f, 0,0,0);
    Kotak(-0.2f, -0.3f,  0.2f, -0.6f, 0,0,0);

    // ===== SHADING HIJAU GELAP =====
    Kotak(-0.6f, 0.6f, -0.2f, 0.5f, 0.0f, 0.4f, 0.0f);
    Kotak( 0.2f, 0.6f,  0.6f, 0.5f, 0.0f, 0.4f, 0.0f);
    Kotak(-0.2f, 0.0f,  0.2f, -0.1f, 0.0f, 0.4f, 0.0f);

    glFlush();
}

void init(void) {
    glClearColor(0.0f, 0.7f, 0.0f, 1.0f); // background hijau
//    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Creeper - glRectf");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}
