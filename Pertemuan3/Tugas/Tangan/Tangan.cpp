#include <GL/glut.h>
#include <string.h>

// --- state global ---
int bahuZ = 0, bahuY = 0, siku = 0;
int pergelangan = 0;
int jari[5][3];
int mode = 0;

void balok(float x, float y, float z) {
    glPushMatrix();
    glScalef(x, y, z);
    glutWireCube(1.0);
    glPopMatrix();
}

// Satu jari: 3 ruas dengan panjang berbeda
void drawRuas(float panjang, float tebal, int sudut) {
    glRotatef(sudut, 0, 0, 1);
    balok(panjang, tebal, tebal);
    glTranslatef(panjang, 0, 0);
}

void drawJari(float p1, float p2, float p3, float tebal, int *sudut) {
    drawRuas(p1, tebal, sudut[0]);
    drawRuas(p2, tebal * 0.9f, sudut[1]);
    drawRuas(p3, tebal * 0.8f, sudut[2]);
}

void drawTelapak() {
    glRotatef(pergelangan, 0, 0, 1);
    // Telapak tangan — lebih lebar di ujung
    balok(0.6, 0.15, 0.7);
}

void drawHand() {
    drawTelapak();

    // Ibu jari — posisi samping, rotasi beda
    glPushMatrix();
    glTranslatef(0.0, 0, 0.40);
    glRotatef(-30, 1, 0, 0);
    glRotatef(20, 0, 1, 0);
    drawJari(0.18, 0.14, 0.10, 0.09, jari[0]);
    glPopMatrix();

    // Telunjuk
    glPushMatrix();
    glTranslatef(0.30, 0, 0.22);
    drawJari(0.22, 0.18, 0.14, 0.09, jari[1]);
    glPopMatrix();

    // Jari tengah (paling panjang)
    glPushMatrix();
    glTranslatef(0.30, 0, 0.07);
    drawJari(0.25, 0.20, 0.16, 0.09, jari[2]);
    glPopMatrix();

    // Jari manis
    glPushMatrix();
    glTranslatef(0.30, 0, -0.08);
    drawJari(0.22, 0.18, 0.14, 0.09, jari[3]);
    glPopMatrix();

    // Kelingking
    glPushMatrix();
    glTranslatef(0.30, 0, -0.22);
    drawJari(0.17, 0.13, 0.10, 0.08, jari[4]);
    glPopMatrix();
}

void drawLenganBawah() {
    // Lengan bawah
    balok(1.4, 0.28, 0.45);
    glTranslatef(0.7, 0, 0);
    glRotatef(siku, 0, 0, 1);
    glTranslatef(0.7, 0, 0);

    // Lengan atas
    balok(1.2, 0.32, 0.50);
    glTranslatef(0.6, 0, 0);
    drawHand();
}

void drawArm() {
    glTranslatef(-1.8, 0, 0);
    glRotatef(bahuZ, 0, 0, 1);
    glRotatef(bahuY, 0, 1, 0);
    glTranslatef(1.8, 0, 0);
    drawLenganBawah();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    drawArm();
    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(55, (float)w / h, 1, 20);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 8, 0,   0, 0, 0,   1, 0, 0);
}

void keyboard(unsigned char key, int x, int y) {
    if (key == '1') mode = 0;
    if (key == '2') mode = 1;

    if (mode == 0) {
        // Bahu
        if (key == 'q') bahuZ += 5;
        if (key == 'a') bahuZ -= 5;
        if (key == 'w') bahuY += 5;
        if (key == 's') bahuY -= 5;
        // Siku
        if (key == 'e') siku += 5;
        if (key == 'd') siku -= 5;
        // Pergelangan
        if (key == 'r') pergelangan += 5;
        if (key == 'f') pergelangan -= 5;
    }
    else {
        // Ibu jari
        if (key == 'q') jari[0][0] += 5;
        if (key == 'a') jari[0][1] += 5;
        if (key == 'z') jari[0][2] += 5;
        // Telunjuk
        if (key == 'w') jari[1][0] += 5;
        if (key == 's') jari[1][1] += 5;
        if (key == 'x') jari[1][2] += 5;
        // Jari tengah
        if (key == 'e') jari[2][0] += 5;
        if (key == 'd') jari[2][1] += 5;
        if (key == 'c') jari[2][2] += 5;
        // Jari manis
        if (key == 'r') jari[3][0] += 5;
        if (key == 'f') jari[3][1] += 5;
        if (key == 'v') jari[3][2] += 5;
        // Kelingking
        if (key == 't') jari[4][0] += 5;
        if (key == 'g') jari[4][1] += 5;
        if (key == 'b') jari[4][2] += 5;
    }

    glutPostRedisplay();
}

void init() {
    glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
    glShadeModel(GL_FLAT);
    memset(jari, 0, sizeof(jari));
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(700, 600);
    glutCreateWindow("Simulasi Tangan 3D");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
