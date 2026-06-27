#include <GL/glut.h>
#include <math.h>

float posisiSedan = -1.2f;
float t = 0.0f;

void roda(float cx, float cy, float r) {
    glColor3f(0.1f, 0.1f, 0.1f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 24; i++) {
        float a = i * 2 * 3.14159f / 24;
        glVertex2f(cx + cos(a)*r, cy + sin(a)*r);
    }
    glEnd();
    glColor3f(0.6f, 0.6f, 0.6f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 24; i++) {
        float a = i * 2 * 3.14159f / 24;
        glVertex2f(cx + cos(a)*r*0.55f, cy + sin(a)*r*0.55f);
    }
    glEnd();
    glColor3f(0.85f, 0.85f, 0.85f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 12; i++) {
        float a = i * 2 * 3.14159f / 12;
        glVertex2f(cx + cos(a)*r*0.18f, cy + sin(a)*r*0.18f);
    }
    glEnd();
}

void mobil_sedan() {
    glPushMatrix();
    glTranslatef(posisiSedan, -0.28f, 0);

    // Body bawah
    glColor3f(0.08f, 0.39f, 0.75f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.42f, 0.00f);
        glVertex2f( 0.42f, 0.00f);
        glVertex2f( 0.37f, 0.14f);
        glVertex2f(-0.36f, 0.14f);
    glEnd();

    // Kabin
    glColor3f(0.12f, 0.53f, 0.90f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.22f, 0.14f);
        glVertex2f( 0.18f, 0.14f);
        glVertex2f( 0.10f, 0.30f);
        glVertex2f(-0.28f, 0.30f);
    glEnd();

    // Kaca depan
    glColor3f(0.70f, 0.88f, 1.0f);
    glBegin(GL_POLYGON);
        glVertex2f( 0.00f, 0.15f);
        glVertex2f( 0.14f, 0.15f);
        glVertex2f( 0.08f, 0.27f);
        glVertex2f(-0.01f, 0.27f);
    glEnd();

    // Kaca belakang
    glColor3f(0.60f, 0.82f, 0.95f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.26f, 0.15f);
        glVertex2f(-0.06f, 0.15f);
        glVertex2f(-0.12f, 0.27f);
        glVertex2f(-0.27f, 0.27f);
    glEnd();

    // Lampu depan
    glColor3f(1.0f, 0.88f, 0.3f);
    glBegin(GL_QUADS);
        glVertex2f( 0.39f, 0.03f);
        glVertex2f( 0.43f, 0.03f);
        glVertex2f( 0.43f, 0.08f);
        glVertex2f( 0.39f, 0.08f);
    glEnd();

    // Lampu belakang
    glColor3f(0.9f, 0.1f, 0.1f);
    glBegin(GL_QUADS);
        glVertex2f(-0.43f, 0.03f);
        glVertex2f(-0.39f, 0.03f);
        glVertex2f(-0.39f, 0.08f);
        glVertex2f(-0.43f, 0.08f);
    glEnd();

    // Knalpot
    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_QUADS);
        glVertex2f(-0.45f, 0.01f);
        glVertex2f(-0.42f, 0.01f);
        glVertex2f(-0.42f, 0.03f);
        glVertex2f(-0.45f, 0.03f);
    glEnd();

    // Roda kiri
    glPushMatrix();
    glTranslatef(-0.25f, -0.04f, 0);
    roda(0, 0, 0.065f);
    glPopMatrix();

    // Roda kanan
    glPushMatrix();
    glTranslatef(0.22f, -0.04f, 0);
    roda(0, 0, 0.065f);
    glPopMatrix();

    glPopMatrix();
}

void langit() {
    glBegin(GL_QUADS);
        glColor3f(0.05f, 0.05f, 0.10f); glVertex2f(-1,  1);
        glColor3f(0.05f, 0.05f, 0.10f); glVertex2f( 1,  1);
        glColor3f(0.12f, 0.22f, 0.38f); glVertex2f( 1, -0.10f);
        glColor3f(0.12f, 0.22f, 0.38f); glVertex2f(-1, -0.10f);
    glEnd();

    // Bulan sabit
    glColor3f(0.99f, 0.98f, 0.87f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 30; i++) {
        float a = i * 2 * 3.14159f / 30;
        glVertex2f(0.7f + cos(a)*0.07f, 0.75f + sin(a)*0.07f);
    }
    glEnd();
    glColor3f(0.06f, 0.07f, 0.12f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 30; i++) {
        float a = i * 2 * 3.14159f / 30;
        glVertex2f(0.73f + cos(a)*0.065f, 0.77f + sin(a)*0.065f);
    }
    glEnd();
}

void highway() {
    // Bahu jalan
    glColor3f(0.17f, 0.17f, 0.17f);
    glBegin(GL_QUADS);
        glVertex2f(-1, -1);     glVertex2f(1, -1);
        glVertex2f( 1, -0.10f); glVertex2f(-1, -0.10f);
    glEnd();

    // Aspal
    glColor3f(0.22f, 0.22f, 0.22f);
    glBegin(GL_QUADS);
        glVertex2f(-1, -0.10f); glVertex2f(1, -0.10f);
        glVertex2f( 1, -0.40f); glVertex2f(-1, -0.40f);
    glEnd();

    // Garis kuning pinggir atas
    glColor3f(0.94f, 0.88f, 0.20f);
    glBegin(GL_QUADS);
        glVertex2f(-1, -0.10f); glVertex2f(1, -0.10f);
        glVertex2f( 1, -0.12f); glVertex2f(-1, -0.12f);
    glEnd();

    // Garis kuning pinggir bawah
    glBegin(GL_QUADS);
        glVertex2f(-1, -0.38f); glVertex2f(1, -0.38f);
        glVertex2f( 1, -0.40f); glVertex2f(-1, -0.40f);
    glEnd();

    // Garis putih tengah (animasi)
    float dashLen = 0.10f, gap = 0.08f, total = dashLen + gap;
    float offset = fmod(t * 0.5f, total);
    glColor3f(0.95f, 0.95f, 0.85f);
    for (float x = -1.0f - dashLen + offset; x < 1.2f; x += total) {
        glBegin(GL_QUADS);
            glVertex2f(x,         -0.235f);
            glVertex2f(x+dashLen, -0.235f);
            glVertex2f(x+dashLen, -0.255f);
            glVertex2f(x,         -0.255f);
        glEnd();
    }

    // Guardrail
    glColor3f(0.55f, 0.55f, 0.55f);
    for (float x = -1.0f; x < 1.0f; x += 0.18f) {
        glBegin(GL_QUADS);
            glVertex2f(x,       -0.09f);
            glVertex2f(x+0.12f, -0.09f);
            glVertex2f(x+0.12f, -0.10f);
            glVertex2f(x,       -0.10f);
        glEnd();
    }

    // Pohon siluet
    float trees[] = {-0.85f, -0.40f, 0.05f, 0.50f, 0.85f};
    for (int i = 0; i < 5; i++) {
        float tx = trees[i];
        glColor3f(0.27f, 0.18f, 0.12f);
        glBegin(GL_QUADS);
            glVertex2f(tx-0.015f, -0.60f); glVertex2f(tx+0.015f, -0.60f);
            glVertex2f(tx+0.015f, -0.42f); glVertex2f(tx-0.015f, -0.42f);
        glEnd();
        glColor3f(0.07f, 0.27f, 0.07f);
        glBegin(GL_TRIANGLES);
            glVertex2f(tx-0.08f, -0.42f);
            glVertex2f(tx+0.08f, -0.42f);
            glVertex2f(tx,       -0.26f);
        glEnd();
        glColor3f(0.10f, 0.35f, 0.10f);
        glBegin(GL_TRIANGLES);
            glVertex2f(tx-0.055f, -0.32f);
            glVertex2f(tx+0.055f, -0.32f);
            glVertex2f(tx,        -0.18f);
        glEnd();
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    langit();
    highway();
    mobil_sedan();

    glutSwapBuffers();
}

void idle() {
    t += 0.016f;
    posisiSedan += 0.008f;
    if (posisiSedan > 1.6f) posisiSedan = -1.6f;
    glutPostRedisplay();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 500);
    glutCreateWindow("Highway Scene");
    glClearColor(0.05f, 0.05f, 0.10f, 1.0f);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);
    glutMainLoop();
    return 0;
}
