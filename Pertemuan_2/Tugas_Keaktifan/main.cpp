#include <GL/glut.h>
#include <math.h>
#define PI 3.1415926

void spiderweb()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glLineWidth(3.0);

    int sisi = 12;
    int lingkar = 6;

    for(int i=0;i<sisi;i++)
    {
        glBegin(GL_LINES);
            glVertex2f(0.0,0.0);
            glVertex2f(0.8,0.0);
        glEnd();

        glRotatef(360.0/sisi,0,0,1);
    }

    glPopMatrix();
    
    for(int j=1;j<=lingkar;j++)
    {
        float r = 0.8 * j/lingkar;

        glBegin(GL_LINE_LOOP);

        for(int i=0;i<sisi;i++)
        {
            float sudut = 2*PI*i/sisi;
            float x = r*cos(sudut);
            float y = r*sin(sudut);

            glVertex2f(x,y);
        }

        glEnd();
    }

    glFlush();
}

void init()
{
    glClearColor(0.0, 0.0, 0.0, 0); 
    glColor3f(1,1,1);          
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800,600);
    glutCreateWindow("Spiderweb");

    init();

    glutDisplayFunc(spiderweb);

    glutMainLoop();
}
