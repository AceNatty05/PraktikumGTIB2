#include <GL/glut.h>
#include <math.h>

int radial = 12;     
int rings = 5;       

void drawRadial()
{
    glBegin(GL_LINES);
        glVertex2f(0,0);
        glVertex2f(0.85,0);
    glEnd();
}

void drawRing(float r)
{
    glBegin(GL_LINE_LOOP);

    for(int i=0;i<radial;i++)
    {
        float angle = (2*M_PI*i)/radial;

        float x = r*cos(angle);
        float y = r*sin(angle);

        glVertex2f(x,y);
    }

    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.1,0.1,0.1);

    float sudut = 360.0 / radial;

    
    for(int i=0;i<radial;i++)
    {
        glPushMatrix();
        glRotatef(i*sudut,0,0,1);
        drawRadial();
        glPopMatrix();
    }

    
    for(int i=1;i<=rings;i++)
    {
        drawRing(i*0.15);
    }

    glFlush();
}

void init()
{
    glClearColor(1,1,1,1);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1,1,-1,1);
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(700,700);
    glutCreateWindow("Jaring2");

    init();
    glutDisplayFunc(display);

    glutMainLoop();
}
