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

void drawBuilding(float x, float width, float height)
{
    glPushMatrix();
    glTranslatef(x, 0.0f, 0.0f);

    // gedung
    glColor3f(0.25f, 0.25f, 0.40f);
    glBegin(GL_QUADS);
        glVertex2f(0.0f,   -0.22f);
        glVertex2f(width,  -0.22f);
        glVertex2f(width,   height);
        glVertex2f(0.0f,    height);
    glEnd();

    // jendela
    glColor3f(1.0f, 1.0f, 0.6f);
    glBegin(GL_QUADS);
        glVertex2f(0.03f, 0.00f);
        glVertex2f(0.07f, 0.00f);
        glVertex2f(0.07f, 0.08f);
        glVertex2f(0.03f, 0.08f);
    glEnd();

    glBegin(GL_QUADS);
        glVertex2f(0.11f, 0.00f);
        glVertex2f(0.15f, 0.00f);
        glVertex2f(0.15f, 0.08f);
        glVertex2f(0.11f, 0.08f);
    glEnd();

    glBegin(GL_QUADS);
        glVertex2f(0.03f, 0.14f);
        glVertex2f(0.07f, 0.14f);
        glVertex2f(0.07f, 0.22f);
        glVertex2f(0.03f, 0.22f);
    glEnd();

    glBegin(GL_QUADS);
        glVertex2f(0.11f, 0.14f);
        glVertex2f(0.15f, 0.14f);
        glVertex2f(0.15f, 0.22f);
        glVertex2f(0.11f, 0.22f);
    glEnd();

    glPopMatrix();
}

void drawTree(float x)
{
    glPushMatrix();
    glTranslatef(x, -0.22f, 0.0f);

    // batang pohon
    glColor3f(0.55f, 0.30f, 0.10f);
    glBegin(GL_QUADS);
        glVertex2f(-0.02f, 0.0f);
        glVertex2f( 0.02f, 0.0f);
        glVertex2f( 0.02f, 0.18f);
        glVertex2f(-0.02f, 0.18f);
    glEnd();

    // daun bawah
    glColor3f(0.10f, 0.55f, 0.20f);
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.10f, 0.18f);
        glVertex2f( 0.10f, 0.18f);
        glVertex2f( 0.0f,  0.32f);
    glEnd();

    // daun atas
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.08f, 0.26f);
        glVertex2f( 0.08f, 0.26f);
        glVertex2f( 0.0f,  0.40f);
    glEnd();

    glPopMatrix();
} 

void drawRoad()
{
    // jalan
    glColor3f(0.35f, 0.35f, 0.35f);
    glBegin(GL_QUADS);
        glVertex2f(-1.0f, -1.0f);
        glVertex2f( 1.0f, -1.0f);
        glVertex2f( 1.0f, -0.22f);
        glVertex2f(-1.0f, -0.22f);
    glEnd();

    // garis jalan
    glColor3f(1.0f, 0.85f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(-0.80f, -0.62f);
        glVertex2f(-0.60f, -0.62f);
        glVertex2f(-0.60f, -0.57f);
        glVertex2f(-0.80f, -0.57f);
    glEnd();

    glBegin(GL_QUADS);
        glVertex2f(-0.30f, -0.62f);
        glVertex2f(-0.10f, -0.62f);
        glVertex2f(-0.10f, -0.57f);
        glVertex2f(-0.30f, -0.57f);
    glEnd();

    glBegin(GL_QUADS);
        glVertex2f(0.20f, -0.62f);
        glVertex2f(0.40f, -0.62f);
        glVertex2f(0.40f, -0.57f);
        glVertex2f(0.20f, -0.57f);
    glEnd();

    glBegin(GL_QUADS);
        glVertex2f(0.70f, -0.62f);
        glVertex2f(0.90f, -0.62f);
        glVertex2f(0.90f, -0.57f);
        glVertex2f(0.70f, -0.57f);
    glEnd();
}

void drawBackground()
{
    // langit
    glBegin(GL_QUADS);
        glColor3f(0.70f, 0.85f, 0.95f);
        glVertex2f(-1.0f,  1.0f);
        glVertex2f( 1.0f,  1.0f);
        glColor3f(0.60f, 0.80f, 0.95f);
        glVertex2f( 1.0f, -0.22f);
        glVertex2f(-1.0f, -0.22f);
    glEnd();

    drawSun();

    drawBuilding(-0.85f, 0.18f, 0.45f);
    drawBuilding( 0.55f, 0.18f, 0.55f);

	drawTree(-0.90f);
    drawTree(-0.60f);
    drawTree(0.75f);
    drawTree(0.90f);
    drawRoad();
}
void drawRefinedWheel()
{
    glPushMatrix();

    // ban
    glColor3f(0.02f, 0.02f, 0.02f);
    drawCircle(0.09f);

    // velg luar
    glColor3f(0.75f, 0.75f, 0.75f);
    drawCircle(0.055f);

    // velg tengah
    glColor3f(0.90f, 0.90f, 0.90f);
    drawCircle(0.022f);

    
    glEnd();

    glPopMatrix();
}

void drawRefinedSportCar()
{
    glPushMatrix();

    // bayangan
    glColor3f(0.20f, 0.20f, 0.20f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.45f, -0.21f);
        glVertex2f( 0.40f, -0.21f);
        glVertex2f( 0.35f, -0.23f);
        glVertex2f(-0.40f, -0.23f);
    glEnd();

    // body 
    glColor3f(0.60f, 0.60f, 0.65f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.55f, -0.10f);
        glVertex2f( 0.50f, -0.10f);
        glVertex2f( 0.55f,  0.00f);
        glVertex2f( 0.35f,  0.06f);
        glVertex2f( 0.10f,  0.18f);
        glVertex2f(-0.15f,  0.18f);
        glVertex2f(-0.40f,  0.02f);
        glVertex2f(-0.58f, -0.02f);
    glEnd();

    // garis samping
    glColor3f(0.35f, 0.35f, 0.38f);
    glLineWidth(2.5f);
    glBegin(GL_LINES);
        glVertex2f(-0.45f, 0.00f);
        glVertex2f( 0.45f, 0.00f);
    glEnd();

    // kaca depan
    glColor3f(0.82f, 0.92f, 0.98f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.35f, 0.03f);
        glVertex2f(-0.13f, 0.16f);
        glVertex2f(-0.02f, 0.16f);
        glVertex2f(-0.02f, 0.03f);
    glEnd();

    // kaca belakang
    glBegin(GL_POLYGON);
        glVertex2f(0.02f, 0.03f);
        glVertex2f(0.02f, 0.16f);
        glVertex2f(0.08f, 0.16f);
        glVertex2f(0.28f, 0.05f);
    glEnd();
    
    // lampu depan
    glColor3f(1.0f, 0.97f, 0.82f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.53f, -0.015f);
        glVertex2f(-0.51f,  0.010f);
        glVertex2f(-0.43f,  0.005f);
        glVertex2f(-0.45f, -0.020f);
    glEnd();

    // lampu belakang
    glColor3f(1.0f, 0.25f, 0.25f);
    glBegin(GL_POLYGON);
        glVertex2f(0.53f, -0.005f);
        glVertex2f(0.51f,  0.030f);
        glVertex2f(0.46f,  0.015f);
        glVertex2f(0.48f, -0.015f);
    glEnd();

    
    // roda kiri
    glPushMatrix();
        glTranslatef(-0.32f, -0.10f, 0.0f);
        drawRefinedWheel();
    glPopMatrix();

    // roda kanan
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
        drawRefinedSportCar();
    glPopMatrix();

    glFlush();
}

void init()
{
    glClearColor(0.70f, 0.84f, 0.94f, 1.0f);

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
    glutCreateWindow("Mobil");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}


