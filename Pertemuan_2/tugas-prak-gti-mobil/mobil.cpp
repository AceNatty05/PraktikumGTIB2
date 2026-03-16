#include <GL/glut.h>
#include <math.h>

float posisiMobil = -1.5;
float rotasiRoda = 0;

void roda()
{
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    for(int i=0;i<360;i++)
    {
        float rad = i * 3.1416 / 180;
        glVertex2f(cos(rad)*0.08, sin(rad)*0.08);
    }
    glEnd();

    glColor3f(0.8,0.8,0.8);
    glBegin(GL_POLYGON);
    for(int i=0;i<360;i++)
    {
        float rad = i * 3.1416 / 180;
        glVertex2f(cos(rad)*0.04, sin(rad)*0.04);
    }
    glEnd();

    glPushMatrix();
    glRotatef(rotasiRoda,0,0,1);

    glBegin(GL_LINES);
        glVertex2f(-0.08,0); glVertex2f(0.08,0);
        glVertex2f(0,-0.08); glVertex2f(0,0.08);
    glEnd();

    glPopMatrix();
}

void mobil()
{
    glPushMatrix();
    glTranslatef(posisiMobil,-0.3,0);

    glColor3f(1,0,0);
    glBegin(GL_QUADS);
        glVertex2f(-0.4,0);
        glVertex2f(0.4,0);
        glVertex2f(0.35,0.15);
        glVertex2f(-0.35,0.15);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(-0.2,0.15);
        glVertex2f(0.2,0.15);
        glVertex2f(0.1,0.3);
        glVertex2f(-0.1,0.3);
    glEnd();

	glColor3f(0.7,0.9,1);
	glBegin(GL_QUADS);

    glVertex2f(-0.14,0.19);
    glVertex2f(-0.04,0.19);
    glVertex2f(-0.04,0.26);
    glVertex2f(-0.14,0.26);

    glVertex2f(0.04,0.19);
    glVertex2f(0.14,0.19);
    glVertex2f(0.14,0.26);
    glVertex2f(0.04,0.26);
	
	glEnd();

    glPushMatrix();
    glTranslatef(-0.25,-0.02,0);
    roda();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.25,-0.02,0);
    roda();
    glPopMatrix();

    glPopMatrix();
}

void pohon(float x, float y)
{
    glPushMatrix();
    glTranslatef(x,y,0);

    glColor3f(0.55,0.27,0.07);
    glBegin(GL_QUADS);
        glVertex2f(-0.03,0);
        glVertex2f(0.03,0);
        glVertex2f(0.03,0.2);
        glVertex2f(-0.03,0.2);
    glEnd();

    glColor3f(0,0.6,0);
    glBegin(GL_POLYGON);
    for(int i=0;i<360;i++)
    {
        float rad = i * 3.1416 / 180;
        glVertex2f(cos(rad)*0.12, sin(rad)*0.12 + 0.25);
    }
    glEnd();

    glPopMatrix();
}

void jalan()
{
    glColor3f(0.2,0.2,0.2);
    glBegin(GL_QUADS);
        glVertex2f(-1,-0.4);
        glVertex2f(1,-0.4);
        glVertex2f(1,-0.2);
        glVertex2f(-1,-0.2);
    glEnd();

    glColor3f(1,1,1);
    glBegin(GL_LINES);
        glVertex2f(-1,-0.3);
        glVertex2f(1,-0.3);
    glEnd();
}

void rumput()
{
    glColor3f(0,0.7,0);
    glBegin(GL_QUADS);
        glVertex2f(-1,-1);
        glVertex2f(1,-1);
        glVertex2f(1,-0.4);
        glVertex2f(-1,-0.4);
    glEnd();
}

void langit()
{
    glColor3f(0.5,0.8,1);
    glBegin(GL_QUADS);
        glVertex2f(-1,0);
        glVertex2f(1,0);
        glVertex2f(1,1);
        glVertex2f(-1,1);
    glEnd();
}

void gunung()
{
    glColor3f(0.4,0.5,0.4);
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.7,0);
        glVertex2f(-0.2,0);
        glVertex2f(-0.45,0.45);

        glVertex2f(0.1,0);
        glVertex2f(0.6,0);
        glVertex2f(0.35,0.5);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    langit();
    gunung();
    rumput();
    jalan();

    pohon(-0.8,-0.2);
    pohon(-0.5,-0.2);
    pohon(0.7,-0.2);

    mobil();

    glutSwapBuffers();
}

void update(int value)
{
    posisiMobil += 0.01;
    rotasiRoda -= 10;

    if(posisiMobil > 1.5)
        posisiMobil = -1.5;

    glutPostRedisplay();
    glutTimerFunc(30,update,0);
}

void init()
{
    glClearColor(1,1,1,1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800,600);
    glutCreateWindow("Mobil 2D dengan Pohon");

    init();

    glutDisplayFunc(display);
    glutTimerFunc(30,update,0);

    glutMainLoop();
}
