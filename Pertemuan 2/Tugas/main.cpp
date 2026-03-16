#include <GL/glut.h>
#include <math.h>

#define PI 3.1415926535898

// fungsi lingkaran isi
void circle(float r)
{
    glBegin(GL_POLYGON);
    for(int i=0;i<100;i++)
    {
        float angle = 2*PI*i/100;
        glVertex2f(r*cos(angle), r*sin(angle));
    }
    glEnd();
}

// roda mobil
void roda()
{
    glPushMatrix();
    glColor3f(0,0,0); 
    circle(0.07);
    glPopMatrix();
}

// mobil
void mobil(float x, float y)
{
    glPushMatrix();
    glTranslatef(x,y,0);

    glColor3f(1,0,0);
    glBegin(GL_QUADS);
        glVertex2f(-0.3,-0.1);
        glVertex2f(0.3,-0.1);
        glVertex2f(0.3,0.1);
        glVertex2f(-0.3,0.1);
    glEnd();
    glFlush();

    glBegin(GL_QUADS);
        glVertex2f(-0.15,0.1);
        glVertex2f(0.15,0.1);
        glVertex2f(0.1,0.22);
        glVertex2f(-0.1,0.22);
    glEnd();
    glFlush();

    glColor3f(0.6,0.8,1);
    glBegin(GL_QUADS);
        glVertex2f(-0.12,0.12);
        glVertex2f(0.12,0.12);
        glVertex2f(0.08,0.2);
        glVertex2f(-0.08,0.2);
    glEnd();
    glFlush();

    glPushMatrix();
        glTranslatef(-0.18,-0.1,0);
        roda();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.18,-0.1,0);
        roda();
    glPopMatrix();

    glPopMatrix();
}

void jalan()
{
    glColor3f(0.2,0.2,0.2);
    glBegin(GL_QUADS);
        glVertex2f(-1,-0.4);
        glVertex2f(1,-0.4);
        glVertex2f(1,-0.8);
        glVertex2f(-1,-0.8);
    glEnd();
    glFlush();

    glColor3f(1,1,1);
    for(float i=-1;i<1;i+=0.3)
    {
        glBegin(GL_QUADS);
            glVertex2f(i,-0.58);
            glVertex2f(i+0.15,-0.58);
            glVertex2f(i+0.15,-0.62);
            glVertex2f(i,-0.62);
        glEnd();
        glFlush();
    }
}

void matahari()
{
    glPushMatrix();
    glTranslatef(0.7,0.7,0);
    glColor3f(1,1,0);
    circle(0.1);
    glPopMatrix();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_QUADS);

	    glColor3f(0.5, 0.8, 1.0);
	    glVertex2f(-1, 1);
	    glVertex2f(1, 1);
	
	    glColor3f(1.0, 0.6, 0.3);
	    glVertex2f(1, -0.4);
	    glVertex2f(-1, -0.4);
	
	glEnd();

    matahari();
    jalan();
    mobil(0,-0.45);

    glFlush();
}

void init()
{
    glClearColor(1,1,1,1);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1,1,-1,1);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(600,480);
    glutCreateWindow("Mobil di Jalan Aspal");

    init();
    glutDisplayFunc(display);

    glutMainLoop();
}
