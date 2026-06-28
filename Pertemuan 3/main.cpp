#include <GL/glut.h>
#include <cmath>

// Posisi tangan pada sumbu X, Y, Z
float posX = 0.0f;
float posY = 0.0f;
float posZ = 0.0f;

// Rotasi telapak tangan
float palmRotation = 0.0f;

// Sudut tekukan jari
float fingerAngle = 0.0f;

// Fungsi menggambar balok
void drawBox(float x, float y, float z) {
    glPushMatrix();
    glScalef(x, y, z);
    glutSolidCube(1.0);
    glPopMatrix();
}

// Menggambar sumbu X, Y, Z
void drawAxes() {
    glLineWidth(3.0f);
    glBegin(GL_LINES);

    // Sumbu X
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-5.0f, 0.0f, 0.0f);
    glVertex3f(5.0f, 0.0f, 0.0f);

    // Sumbu Y
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, -5.0f, 0.0f);
    glVertex3f(0.0f, 5.0f, 0.0f);

    // Sumbu Z
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, 0.0f, -5.0f);
    glVertex3f(0.0f, 0.0f, 5.0f);

    glEnd();
}

// Menggambar satu jari
void drawFinger(float xOffset) {
    glPushMatrix();

    glTranslatef(xOffset, 1.0f, 0.0f);
    glRotatef(-fingerAngle, 1.0f, 0.0f, 0.0f);

    // Ruas jari pertama
    glPushMatrix();
    glTranslatef(0.0f, 0.25f, 0.0f);
    drawBox(0.18f, 0.5f, 0.18f);
    glPopMatrix();

    // Ruas jari kedua
    glTranslatef(0.0f, 0.5f, 0.0f);
    glRotatef(-fingerAngle, 1.0f, 0.0f, 0.0f);

    glPushMatrix();
    glTranslatef(0.0f, 0.25f, 0.0f);
    drawBox(0.16f, 0.5f, 0.16f);
    glPopMatrix();

    glPopMatrix();
}

// Menggambar lengan, telapak, dan jari
void drawArmHand() {
    glPushMatrix();

    // Translasi seluruh tangan
    glTranslatef(posX, posY, posZ);

    // Lengan
    glColor3f(0.8f, 0.6f, 0.4f);
    glPushMatrix();
    glTranslatef(0.0f, -1.5f, 0.0f);
    drawBox(0.7f, 2.5f, 0.7f);
    glPopMatrix();

    // Telapak tangan
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    glRotatef(palmRotation, 0.0f, 1.0f, 0.0f);

    glColor3f(0.9f, 0.7f, 0.5f);
    drawBox(1.2f, 1.0f, 0.35f);

    // Jari-jari
    glColor3f(0.9f, 0.7f, 0.5f);
    drawFinger(-0.45f);
    drawFinger(-0.15f);
    drawFinger(0.15f);
    drawFinger(0.45f);

    // Ibu jari
    glPushMatrix();
    glTranslatef(-0.75f, 0.2f, 0.0f);
    glRotatef(45.0f, 0.0f, 0.0f, 1.0f);
    glRotatef(-fingerAngle, 1.0f, 0.0f, 0.0f);
    drawBox(0.18f, 0.6f, 0.18f);
    glPopMatrix();

    glPopMatrix();
    glPopMatrix();
}

// Tampilan utama
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(
        4.0, 4.0, 8.0,
        0.0, 0.0, 0.0,
        0.0, 1.0, 0.0
    );

    drawAxes();
    drawArmHand();

    glutSwapBuffers();
}

// Mengatur ukuran layar
void reshape(int width, int height) {
    if (height == 0) height = 1;

    float aspect = (float)width / (float)height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45.0, aspect, 1.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
}

// Kontrol keyboard
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'a':
        case 'A':
            posX -= 0.2f;
            break;

        case 'd':
        case 'D':
            posX += 0.2f;
            break;

        case 'w':
        case 'W':
            posY += 0.2f;
            break;

        case 's':
        case 'S':
            posY -= 0.2f;
            break;

        case 'q':
        case 'Q':
            posZ -= 0.2f;
            break;

        case 'e':
        case 'E':
            posZ += 0.2f;
            break;

        case 'j':
        case 'J':
            palmRotation -= 5.0f;
            break;

        case 'l':
        case 'L':
            palmRotation += 5.0f;
            break;

        case 'i':
        case 'I':
            if (fingerAngle < 75.0f) {
                fingerAngle += 5.0f;
            }
            break;

        case 'k':
        case 'K':
            if (fingerAngle > 0.0f) {
                fingerAngle -= 5.0f;
            }
            break;

        case 'r':
        case 'R':
            posX = 0.0f;
            posY = 0.0f;
            posZ = 0.0f;
            palmRotation = 0.0f;
            fingerAngle = 0.0f;
            break;

        case 27:
            exit(0);
            break;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(900, 700);
    glutCreateWindow("Simulasi Lengan, Telapak Tangan, dan Jari");

    glEnable(GL_DEPTH_TEST);

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glutMainLoop();

    return 0;
}
