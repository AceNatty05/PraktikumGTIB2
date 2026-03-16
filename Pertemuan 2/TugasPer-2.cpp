#include <windows.h>
#include <GL/glut.h>
#include <math.h>

// Variabel animasi
float carPosX = -80.0f;     // posisi mobil
float wheelAngle = 0.0f;    // sudut rotasi roda

void init() {
    glClearColor(0.6f, 0.9f, 1.0f, 1.0f); // langit
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -50, 50); // koordinat 2D
}

// Fungsi menggambar lingkaran
void drawCircle(float radius, int segments) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < segments; i++) {
        float theta = 2.0f * 3.1415926f * i / segments;
        float x = radius * cos(theta);
        float y = radius * sin(theta);
        glVertex2f(x, y);
    }
    glEnd();
}

// Fungsi menggambar roda
void drawWheel() {
    // Ban luar
    glColor3f(0.1f, 0.1f, 0.1f);
    drawCircle(8.0f, 50);

    // Velg
    glColor3f(0.8f, 0.8f, 0.8f);
    drawCircle(4.0f, 50);

    // Jari-jari roda
    glColor3f(0.2f, 0.2f, 0.2f);
    glLineWidth(2);
    glBegin(GL_LINES);
        glVertex2f(-8, 0); glVertex2f(8, 0);
        glVertex2f(0, -8); glVertex2f(0, 8);
        glVertex2f(-5.6f, -5.6f); glVertex2f(5.6f, 5.6f);
        glVertex2f(-5.6f, 5.6f);  glVertex2f(5.6f, -5.6f);
    glEnd();
}

// Fungsi menggambar badan mobil
void drawCarBody() {
    // Body bawah
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(-35, -5);
        glVertex2f(35, -5);
        glVertex2f(35, 15);
        glVertex2f(-35, 15);
    glEnd();

    // Atap mobil
    glColor3f(0.85f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-20, 15);
        glVertex2f(-5, 28);
        glVertex2f(18, 28);
        glVertex2f(30, 15);
    glEnd();

    // Kaca depan
    glColor3f(0.7f, 0.9f, 1.0f);
    glBegin(GL_QUADS);
        glVertex2f(2, 17);
        glVertex2f(16, 17);
        glVertex2f(14, 26);
        glVertex2f(6, 26);
    glEnd();

    // Kaca belakang
    glBegin(GL_QUADS);
        glVertex2f(-17, 17);
        glVertex2f(-2, 17);
        glVertex2f(2, 26);
        glVertex2f(-10, 26);
    glEnd();

    // Lampu depan
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(35, 2);
        glVertex2f(40, 2);
        glVertex2f(40, 10);
        glVertex2f(35, 10);
    glEnd();

    // Lampu belakang
    glColor3f(1.0f, 0.5f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(-40, 2);
        glVertex2f(-35, 2);
        glVertex2f(-35, 10);
        glVertex2f(-40, 10);
    glEnd();
}

// Fungsi menggambar jalan
void drawRoad() {
    // Aspal
    glColor3f(0.2f, 0.2f, 0.2f);
    glBegin(GL_QUADS);
        glVertex2f(-100, -30);
        glVertex2f(100, -30);
        glVertex2f(100, -50);
        glVertex2f(-100, -50);
    glEnd();

    // Garis jalan
    glColor3f(1.0f, 1.0f, 1.0f);
    for (int i = -90; i <= 90; i += 30) {
        glBegin(GL_QUADS);
            glVertex2f(i, -40);
            glVertex2f(i + 15, -40);
            glVertex2f(i + 15, -38);
            glVertex2f(i, -38);
        glEnd();
    }
}

// Fungsi utama menggambar mobil
void drawCar() {
    glPushMatrix(); // STACK 1: simpan matriks utama mobil
        glTranslatef(carPosX, -10.0f, 0.0f); // translasi mobil

        // Body mobil
        glPushMatrix(); // STACK 2
            drawCarBody();
        glPopMatrix();

        // Roda depan
        glPushMatrix(); // STACK 3
            glTranslatef(20.0f, -5.0f, 0.0f); // pindah ke posisi roda depan
            glRotatef(wheelAngle, 0.0f, 0.0f, 1.0f); // rotasi roda
            drawWheel();
        glPopMatrix();

        // Roda belakang
        glPushMatrix(); // STACK 4
            glTranslatef(-20.0f, -5.0f, 0.0f); // pindah ke posisi roda belakang
            glRotatef(wheelAngle, 0.0f, 0.0f, 1.0f); // rotasi roda
            drawWheel();
        glPopMatrix();

    glPopMatrix(); // kembalikan matriks utama
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawRoad();
    drawCar();

    glFlush();
    glutSwapBuffers();
}

// Animasi
void update(int value) {
    carPosX += 0.8f;      // mobil bergerak ke kanan
    wheelAngle -= 8.0f;   // roda berputar

    if (carPosX > 120.0f) {
        carPosX = -120.0f;
    }

    glutPostRedisplay();
    glutTimerFunc(16, update, 0); // ~60 FPS
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(900, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Mobil 2D - Primitive, Translasi, Rotasi, Stack");

    init();
    glutDisplayFunc(display);
    glutTimerFunc(16, update, 0);

    glutMainLoop();
    return 0;
}
