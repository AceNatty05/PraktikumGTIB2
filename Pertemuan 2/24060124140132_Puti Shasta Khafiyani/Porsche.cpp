
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

void circle(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy)
{
    glBegin(GL_POLYGON);
    glVertex2f(cx, cy);
    for (int i = 0; i <= 360; i++)
    {
        float angle = i * 3.1416 / 180;
        float x = rx * cos(angle);
        float y = ry * sin(angle);
        glVertex2f((x + cx), (y + cy));
    }
    glEnd();
}

void drawMirror()
{
    glPushMatrix();
        glTranslatef(150, 185, 0);
        glRotatef(-15, 0, 0, 1);

        glColor3ub(255, 182, 213);
        glBegin(GL_POLYGON);
            glVertex2f(0,  0);
            glVertex2f(22, 0);
            glVertex2f(22, 9);
            glVertex2f(0,  9);
        glEnd();

        glColor3ub(180, 225, 245);
        glBegin(GL_POLYGON);
            glVertex2f(2, 1);
            glVertex2f(20, 1);
            glVertex2f(20, 8);
            glVertex2f(2,  8);
        glEnd();
    glPopMatrix();
}

void drawLampu(float tx, float ty)
{
    glPushMatrix();
        glTranslatef(tx, ty, 0);
        glColor3ub(252, 255, 232);
        circle(15, 10, 0, 0);
        glColor3ub(238, 255, 107);
        circle(10, 5, 0, 0);
    glPopMatrix();
}

void drawWheel(float tx, float ty)
{
    glPushMatrix();
        glTranslatef(tx, ty, 0);

        glColor3ub(43, 43, 43);
        circle(25, 30, 0, 0);

        glColor3ub(192, 192, 192);
        circle(20, 25, 0, 0);

        glColor3ub(255, 255, 255);
        for (int i = 0; i < 3; i++)
        {
            glPushMatrix();
                glRotatef(i * 120.0f, 0, 0, 1);
                glTranslatef(12, 0, 0);
                circle(3, 3, 0, 0);
            glPopMatrix();
        }

        glColor3ub(100, 100, 100);
        circle(5, 5, 0, 0);
    glPopMatrix();
}

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 400, 0, 400);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Jalan
    glPushMatrix();
        glTranslatef(0, 0, 0);

        glColor3ub(90, 90, 98);
        glBegin(GL_QUADS);
            glVertex2d(0,   0);
            glVertex2d(400, 0);
            glVertex2d(400, 100);
            glVertex2d(0,   100);
        glEnd();

        // Marka Jalan
        glColor3ub(255, 255, 180);
        glLineWidth(2.0f);
        for (int x = 10; x < 400; x += 55)
        {
            glBegin(GL_LINES);
                glVertex2d(x,      50);
                glVertex2d(x + 35, 50);
            glEnd();
        }
        glLineWidth(1.0f);
    glPopMatrix();

    // Mobil
    glPushMatrix();
        glTranslatef(-70, 0, 0); 

        // Body
        glColor3ub(255, 214, 232);
        glBegin(GL_POLYGON);
            glVertex2d(70,120);
            glVertex2d(350,120);
            glVertex2d(350,180);
            glVertex2d(320,200);
            glVertex2d(200,220);
            glVertex2d(200,180);
            glVertex2d(100,180);
            glVertex2d(70,120);
        glEnd();

        // Kaca
        glColor3ub(232, 251, 255);
        glBegin(GL_POLYGON);
            glVertex2d(200,210);
            glVertex2d(290,180);
            glVertex2d(290,195);
            glVertex2d(160,180);
        glEnd();

        drawMirror();
        drawWheel(290, 120);
        drawWheel(150, 120);
        drawLampu(90, 160);

    glPopMatrix();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Porsche");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

