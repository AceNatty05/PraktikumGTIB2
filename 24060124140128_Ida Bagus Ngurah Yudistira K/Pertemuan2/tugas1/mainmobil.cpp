#include <GL/glut.h>
#include <math.h>

void circle(float r)
{
    glBegin(GL_POLYGON);
    for(int i=0;i<100;i++)
    {
        float angle = 2*3.1416*i/100;
        glVertex2f(r*cos(angle), r*sin(angle));
    }
    glEnd();
}

void roda()
{
    glPushMatrix();

    glColor3f(0,0,0);
    circle(0.03);

    glColor3f(0.7,0.7,0.7);
    circle(0.015);

    glPopMatrix();
}

void mobil()
{
    glPushMatrix();

    glColor3f(1,0,0);

    glBegin(GL_QUADS);
        glVertex2f(-0.15,0);
        glVertex2f(0.15,0);
        glVertex2f(0.15,0.07);
        glVertex2f(-0.15,0.07);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(-0.08,0.07);
        glVertex2f(0.08,0.07);
        glVertex2f(0.05,0.13);
        glVertex2f(-0.05,0.13);
    glEnd();

    glPushMatrix();
        glTranslatef(-0.1,-0.02,0);
        roda();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.1,-0.02,0);
        roda();
    glPopMatrix();

    glPopMatrix();
}

void jalan()
{
    glColor3f(0.3,0.3,0.3);

    glBegin(GL_QUADS);
        glVertex2f(-1,-0.7);
        glVertex2f(1,-0.7);
        glVertex2f(1,-0.15);
        glVertex2f(-1,-0.15);
    glEnd();

    glColor3f(1,1,1);

    for(float i=-0.9;i<1;i+=0.4)
    {
        glBegin(GL_QUADS);
            glVertex2f(i,-0.45);
            glVertex2f(i+0.2,-0.45);
            glVertex2f(i+0.2,-0.42);
            glVertex2f(i,-0.42);
        glEnd();
    }
}

void gedung()
{
    glPushMatrix();

    glColor3f(0.5,0.5,0.7);

    glBegin(GL_QUADS);
        glVertex2f(-0.1,-0.15);
        glVertex2f(0.1,-0.15);
        glVertex2f(0.1,0.4);
        glVertex2f(-0.1,0.4);
    glEnd();

    glColor3f(1,1,0);

    for(float y=-0.05;y<0.35;y+=0.12)
    {
        for(float x=-0.062;x<=0.06;x+=0.06)
        {
            glBegin(GL_QUADS);
                glVertex2f(x-0.02,y);
                glVertex2f(x+0.02,y);
                glVertex2f(x+0.02,y+0.06);
                glVertex2f(x-0.02,y+0.06);
            glEnd();
        }
    }

    glPopMatrix();
}

void pohon()
{
    glPushMatrix();

    glColor3f(0.55,0.27,0.07);

    glBegin(GL_QUADS);
        glVertex2f(-0.025,-0.1);
        glVertex2f(0.025,-0.1);
        glVertex2f(0.02,0.05);
        glVertex2f(-0.02,0.05);
    glEnd();

    glColor3f(0,0.6,0);

    glPushMatrix();
        glTranslatef(0,0.1,0);
        circle(0.08);
    glPopMatrix();

    glPopMatrix();
}

void awan()
{
    glPushMatrix();

    glColor3f(1,1,1);

    circle(0.05);

    glPushMatrix();
        glTranslatef(0.05,0,0);
        circle(0.05);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.05,0,0);
        circle(0.05);
    glPopMatrix();

    glPopMatrix();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    jalan();

    // mobil
    glPushMatrix();
        glTranslatef(-0.7,-0.35,0);
        mobil();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0,-0.35,0);
        mobil();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.7,-0.35,0);
        mobil();
    glPopMatrix();

    // gedung kiri
    glPushMatrix();
        glTranslatef(-0.85,0,0);
        gedung();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.55,0,0);
        gedung();
    glPopMatrix();

    // gedung kanan
    glPushMatrix();
        glTranslatef(0.55,0,0);
        gedung();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.85,0,0);
        gedung();
    glPopMatrix();

    // pohon
    glPushMatrix();
        glTranslatef(-0.35,-0.05,0);
        pohon();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.35,-0.05,0);
        pohon();
    glPopMatrix();

    // awan
    glPushMatrix();
        glTranslatef(-0.5,0.6,0);
        awan();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.5,0.65,0);
        awan();
    glPopMatrix();

    glFlush();
}

void init()
{
    glClearColor(0.53,0.81,0.92,1);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1,1,-1,1);
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(900,600);
    glutCreateWindow("Mobil di jalan hehe");

    init();
    glutDisplayFunc(display);

    glutMainLoop();
}
