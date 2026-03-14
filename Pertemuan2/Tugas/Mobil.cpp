#include <GL/glut.h>
#include <math.h>

#define PI 3.14159265358979323846f

// Warna langit (satu warna saja)
float skyColor[3] = {0.68f, 0.90f, 1.00f};

// Warna bukit
float grassGreen[3] = {0.13f, 0.55f, 0.13f};
float darkGreen[3]  = {0.05f, 0.35f, 0.05f};

void drawCircle(float cx, float cy, float r, int n = 36, int filled = 1) {
    if (filled) {
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(cx, cy);
    } else {
        glBegin(GL_LINE_LOOP);
    }
    int i;
    for (i = 0; i <= n; i++) {
        float a = 2.0f * PI * i / n;
        glVertex2f(cx + r * cosf(a), cy + r * sinf(a));
    }
    glEnd();
}

void drawSun() {
    // Matahari utama (lingkaran kuning cerah)
    glColor3f(1.0f, 0.95f, 0.3f);  // kuning terang
    drawCircle(-0.75f, 0.75f, 0.12f, 48, 1);

    // Efek sinar matahari (garis radial)
    glLineWidth(3.0f);
    glColor3f(1.0f, 0.85f, 0.2f);  // kuning agak pudar untuk sinar
    int rays = 12;
    int i;
    for (i = 0; i < rays; i++) {
        float angle = 2.0f * PI * i / rays;
        float x1 = -0.75f + 0.12f * cosf(angle);
        float y1 =  0.75f + 0.12f * sinf(angle);
        float x2 = -0.75f + 0.20f * cosf(angle);
        float y2 =  0.75f + 0.20f * sinf(angle);
        glBegin(GL_LINES);
            glVertex2f(x1, y1);
            glVertex2f(x2, y2);
        glEnd();
    }
    glLineWidth(1.0f);  // reset tebal garis
}

void drawCloud(float x, float y, float scale) {
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glScalef(scale, scale, 1.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(0.00f, 0.00f, 0.10f, 32, 1);
    drawCircle(-0.08f, 0.05f, 0.08f, 32, 1);
    drawCircle( 0.08f, 0.06f, 0.09f, 32, 1);
    drawCircle( 0.12f, -0.02f, 0.07f, 32, 1);
    glPopMatrix();
}

void drawSky() {
    glColor3fv(skyColor);
    glBegin(GL_QUADS);
        glVertex2f(-1.0f,  1.0f);
        glVertex2f( 1.0f,  1.0f);
        glVertex2f( 1.0f, -1.0f);
        glVertex2f(-1.0f, -1.0f);
    glEnd();
}

void drawWavyHill() {
    float x;
    glBegin(GL_TRIANGLE_STRIP);
    glColor3fv(darkGreen);
    for (x = -1.2f; x <= 1.2f; x += 0.035f) {
        float y = -0.48f + 0.17f * sinf(3.4f * x) + 0.10f * sinf(6.8f * x + 1.5f);
        glVertex2f(x, -1.0f);
        glVertex2f(x, y);
    }
    glEnd();

    glBegin(GL_TRIANGLE_STRIP);
    glColor3fv(grassGreen);
    for (x = -1.2f; x <= 1.2f; x += 0.035f) {
        float y = -0.48f + 0.17f * sinf(3.4f * x) + 0.10f * sinf(6.8f * x + 1.5f);
        glVertex2f(x, -1.0f);
        glVertex2f(x, y + 0.035f);
    }
    glEnd();
}

float getHillHeight(float x) {
    return -0.48f + 0.17f * sinf(3.4f * x) + 0.10f * sinf(6.8f * x + 1.5f) + 0.035f;
}

float getHillSlope(float x) {
    float dx = 0.05f;
    float h1 = getHillHeight(x - dx);
    float h2 = getHillHeight(x + dx);
    float slope = (h2 - h1) / (2.0f * dx);
    float angle_rad = atanf(slope);
    return angle_rad * 180.0f / PI;
}

void drawCar(float tx, float baseY, float r, float g, float b, float wheelAngle) {
    glPushMatrix();
    
    // Translasi ke posisi mobil
    glTranslatef(tx, baseY, 0.0f);
    
    // Rotasi mobil mengikuti kemiringan bukit
    float carTilt = getHillSlope(tx);
    glRotatef(carTilt, 0.0f, 0.0f, 1.0f);

    // Badan mobil diangkat agar roda tepat menyentuh garis hijau
    float bodyOffset = 0.075f;  // radius roda terbesar
    glTranslatef(0.0f, bodyOffset, 0.0f);

    // badan mobil
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
        glVertex2f(-0.25f, 0.00f);
        glVertex2f( 0.25f, 0.00f);
        glVertex2f( 0.22f, 0.12f);
        glVertex2f(-0.18f, 0.15f);
        glVertex2f(-0.22f, 0.12f);
    glEnd();

    // kabin
    glColor3f(0.70f, 0.85f, 1.00f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.15f, 0.12f);
        glVertex2f( 0.15f, 0.12f);
        glVertex2f( 0.10f, 0.22f);
        glVertex2f(-0.10f, 0.22f);
    glEnd();

    // roda kiri
    glPushMatrix();
    glTranslatef(-0.15f, 0.0f, 0.0f);
    glRotatef(wheelAngle, 0.0f, 0.0f, 1.0f);
    glColor3f(0.10f, 0.10f, 0.10f);
    drawCircle(0.0f, 0.0f, 0.075f, 32, 1);
    glColor3f(0.95f, 0.95f, 0.95f);
    drawCircle(0.0f, 0.0f, 0.048f, 32, 1);
    glColor3f(1.00f, 1.00f, 1.00f);
    drawCircle(0.0f, 0.0f, 0.024f, 32, 1);
    glPopMatrix();

    // roda kanan
    glPushMatrix();
    glTranslatef(0.15f, 0.0f, 0.0f);
    glRotatef(wheelAngle + 50.0f, 0.0f, 0.0f, 1.0f);
    glColor3f(0.10f, 0.10f, 0.10f);
    drawCircle(0.0f, 0.0f, 0.075f, 32, 1);
    glColor3f(0.95f, 0.95f, 0.95f);
    drawCircle(0.0f, 0.0f, 0.048f, 32, 1);
    glColor3f(1.00f, 1.00f, 1.00f);
    drawCircle(0.0f, 0.0f, 0.024f, 32, 1);
    glPopMatrix();

    // driver
    glColor3f(0.96f, 0.78f, 0.55f);
    drawCircle(0.0f, 0.18f, 0.055f, 36, 1);

    glColor3f(0.0f, 0.0f, 0.0f);
    drawCircle(-0.02f, 0.20f, 0.008f, 16, 1);
    drawCircle( 0.02f, 0.20f, 0.008f, 16, 1);

    glColor3f(0.85f, 0.3f, 0.3f);
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.025f, 0.18f);
        glVertex2f( 0.025f, 0.18f);
        glVertex2f( 0.00f,  0.15f);
    glEnd();

    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    drawSky();
    drawSun();
    drawWavyHill();

    drawCloud(-0.65f, 0.72f, 1.15f);
    drawCloud(0.55f, 0.80f, 0.95f);

    float hillY1 = getHillHeight(-0.50f);
    drawCar(-0.50f, hillY1, 0.97f, 0.97f, 0.97f, 35.0f);

    float hillY2 = getHillHeight(0.42f);
    drawCar(0.42f, hillY2, 1.00f, 0.22f, 0.22f, -25.0f);

    glutSwapBuffers();
}

void init() {
    glClearColor(skyColor[0], skyColor[1], skyColor[2], 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(960, 640);
    glutCreateWindow("Dua Mobil Potato di Bukit - Diah");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
