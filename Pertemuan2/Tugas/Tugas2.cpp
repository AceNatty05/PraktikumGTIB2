#include <GL/glut.h>
#include <cmath>

const float PI = 3.14159265358979323846f;

void drawCircle(float radius, int segments = 100)
{
    glBegin(GL_POLYGON);
    for (int i = 0; i < segments; i++)
    {
        float angle = 2.0f * PI * i / segments;
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}

void drawSun()
{
    glPushMatrix();
    glTranslatef(0.75f, 0.75f, 0.0f);
    glColor3f(1.0f, 0.9f, 0.0f); 
    drawCircle(0.08f);
    glPopMatrix();
}

void drawBarn(float x, float width, float height)
{
    glPushMatrix();
    glTranslatef(x, -0.22f, 0.0f);

    // Dinding lumbung (merah tua)
    glColor3f(0.6f, 0.2f, 0.2f);
    glBegin(GL_QUADS);
        glVertex2f(0.0f,   0.0f);
        glVertex2f(width,  0.0f);
        glVertex2f(width,   height);
        glVertex2f(0.0f,    height);
    glEnd();

    // Atap lumbung (abu-abu tua)
    glColor3f(0.3f, 0.3f, 0.3f);
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.02f, height);
        glVertex2f(width + 0.02f, height);
        glVertex2f(width / 2.0f, height + 0.15f);
    glEnd();

    // Pintu lumbung (cokelat)
    glColor3f(0.4f, 0.2f, 0.1f);
    glBegin(GL_QUADS);
        glVertex2f(width/3.0f, 0.0f);
        glVertex2f(2.0f*width/3.0f, 0.0f);
        glVertex2f(2.0f*width/3.0f, height/2.0f);
        glVertex2f(width/3.0f, height/2.0f);
    glEnd();

    glPopMatrix();
}

void drawTree(float x, float yOffset)
{
    glPushMatrix();
    glTranslatef(x, -0.22f + yOffset, 0.0f);

    // Daun pohon (hijau tua)
    glColor3f(0.1f, 0.4f, 0.1f);
    drawCircle(0.12f); // Lingkungan utama daun

    // Daun tambahan (opsional)
    glPushMatrix();
    glTranslatef(0.05f, 0.05f, 0.0f);
    drawCircle(0.08f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.05f, -0.03f, 0.0f);
    drawCircle(0.09f);
    glPopMatrix();

    glPopMatrix();
} 

void drawCountryRoad()
{
    glColor3f(0.2f, 0.5f, 0.2f);
    glBegin(GL_QUADS);
        glVertex2f(-1.0f, -0.22f);
        glVertex2f( 1.0f, -0.22f);
        glVertex2f( 1.0f, -1.0f);
        glVertex2f(-1.0f, -1.0f);
    glEnd();

    glColor3f(0.6f, 0.4f, 0.2f);
    glBegin(GL_QUADS);
        glVertex2f(-1.0f, -0.8f);
        glVertex2f( 1.0f, -0.8f);
        glVertex2f( 1.0f, -0.4f);
        glVertex2f(-1.0f, -0.4f);
    glEnd();
}

void drawBackground()
{
    glBegin(GL_QUADS);
        glColor3f(0.6f, 0.8f, 0.9f);
        glVertex2f(-1.0f,  1.0f);
        glVertex2f( 1.0f,  1.0f);
        glColor3f(0.7f, 0.9f, 1.0f);
        glVertex2f( 1.0f, -0.22f);
        glVertex2f(-1.0f, -0.22f);
    glEnd();

    drawSun();

    // Lumbung di kejauhan
    drawBarn(-0.8f, 0.25f, 0.3f);
    
    // Pohon-pohon di ladang
    drawTree(-0.6f, 0.0f);
    drawTree(0.6f, -0.05f);
    drawTree(0.85f, 0.03f);

    drawCountryRoad();
}

void drawRefinedWheel()
{
    glPushMatrix();

    // Ban (hitam)
    glColor3f(0.02f, 0.02f, 0.02f);
    drawCircle(0.09f);

    // Velg luar (abu-abu)
    glColor3f(0.7f, 0.7f, 0.7f);
    drawCircle(0.055f);

    // Velg tengah (abu-abu terang)
    glColor3f(0.9f, 0.9f, 0.9f);
    drawCircle(0.022f);

    glPopMatrix();
}

void drawRefinedPickUpTruck()
{
    glPushMatrix();

    // Bayangan di bawah mobil
    glColor3f(0.15f, 0.15f, 0.15f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.5f, -0.21f);
        glVertex2f( 0.45f, -0.21f);
        glVertex2f( 0.4f, -0.23f);
        glVertex2f(-0.45f, -0.23f);
    glEnd();

    // Bodi Pick-Up (Cokelat Tua)
    glColor3f(0.4f, 0.25f, 0.1f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.55f, -0.10f); // Depan bawah
        glVertex2f( 0.50f, -0.10f); // Belakang bawah
        glVertex2f( 0.55f,  0.00f); // Sudut belakang bak
        glVertex2f( 0.10f,  0.00f); // Bagian atas bak terbuka
        glVertex2f( 0.10f,  0.18f); // Atas kabin depan
        glVertex2f(-0.15f,  0.18f); // Atas kabin depan
        glVertex2f(-0.40f,  0.02f); // Kap mesin depan
        glVertex2f(-0.58f, -0.02f); // Depan
    glEnd();

    // Kaca Depan
    glColor3f(0.8f, 0.9f, 1.0f);
    glBegin(GL_QUADS);
        glVertex2f(-0.35f, 0.03f);
        glVertex2f(-0.02f, 0.03f);
        glVertex2f(-0.02f, 0.16f);
        glVertex2f(-0.13f, 0.16f);
    glEnd();

    // Lampu Depan
    glColor3f(1.0f, 0.9f, 0.7f);
    glBegin(GL_QUADS);
        glVertex2f(-0.53f, -0.015f);
        glVertex2f(-0.51f,  0.010f);
        glVertex2f(-0.43f,  0.005f);
        glVertex2f(-0.45f, -0.020f);
    glEnd();

    

    // Roda kiri
    glPushMatrix();
        glTranslatef(-0.32f, -0.10f, 0.0f);
        drawRefinedWheel();
    glPopMatrix();

    // Roda kanan
    glPushMatrix();
        glTranslatef(0.32f, -0.10f, 0.0f);
        drawRefinedWheel();
    glPopMatrix();

    glPopMatrix();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    drawBackground();

    glPushMatrix();
        glTranslatef(0.0f, -0.10f, 0.0f);
        drawRefinedPickUpTruck();
    glPopMatrix();

    glFlush();
}

void init()
{
    // Warna latar belakang (langit biru pastel)
    glClearColor(0.7f, 0.9f, 1.0f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 700);
    glutInitWindowPosition(100, 80);
    glutCreateWindow("Pemandangan Pedesaan"); // Judul jendela baru

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}