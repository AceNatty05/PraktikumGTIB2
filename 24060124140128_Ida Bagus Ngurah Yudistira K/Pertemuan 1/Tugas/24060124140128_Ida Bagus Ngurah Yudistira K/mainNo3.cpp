#include <GL/glut.h>

void pohon() {
    glBegin(GL_QUADS);

    // Batang pohon
    glColor3f(0.5f, 0.25f, 0.1f);
    glVertex2f(-0.1f, -0.7f);
    glVertex2f( 0.1f, -0.7f);
    glVertex2f( 0.1f, -0.2f);
    glVertex2f(-0.1f, -0.2f);

    // Daun bawah
    glColor3f(0.0f, 0.6f, 0.0f);
    glVertex2f(-0.4f, -0.2f);
    glVertex2f( 0.4f, -0.2f);
    glVertex2f( 0.4f,  0.2f);
    glVertex2f(-0.4f,  0.2f);

    // Daun tengah
    glVertex2f(-0.25f, 0.1f);
    glVertex2f( 0.25f, 0.1f);
    glVertex2f( 0.25f, 0.45f);
    glVertex2f(-0.25f, 0.45f);

    // Daun atas
    glVertex2f(-0.15f, 0.35f);
    glVertex2f( 0.15f, 0.35f);
    glVertex2f( 0.15f, 0.7f);
    glVertex2f(-0.15f, 0.7f);

    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Tanah (digambar sekali saja)
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.4f, 0.2f);
    glVertex2f(-1.0f, -0.55f);
    glVertex2f( 1.0f, -0.55f);
    glVertex2f( 1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glEnd();

    // Pohon kiri
    glPushMatrix();
    glTranslatef(-0.6f, 0.15f, 0.0f);
    pohon();
    glPopMatrix();

    // Pohon tengah
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    pohon();
    glPopMatrix();

    // Pohon kanan
    glPushMatrix();
    glTranslatef(0.6f, 0.15f, 0.0f);
    pohon();
    glPopMatrix();

    glFlush();
}

void init() {
    glClearColor(0.8f, 0.9f, 1.0f, 1.0f);
    gluOrtho2D(-1, 1, -1, 1);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Pohons");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
