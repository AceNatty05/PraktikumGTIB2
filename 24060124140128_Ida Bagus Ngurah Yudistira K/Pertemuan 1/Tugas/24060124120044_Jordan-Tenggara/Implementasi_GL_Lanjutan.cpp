#include <GL/glut.h>
#include <math.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0,0.7,0.0);
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.9,0.0);
        glVertex2f(-0.4,0.7);
        glVertex2f(0.1,0.0);

        glVertex2f(-0.1,0.0);
        glVertex2f(0.4,0.6);
        glVertex2f(0.9,0.0);
    glEnd();

    glColor3f(1.0,0.6,0.0);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0.0,0.75);
        for(int i=0;i<=360;i++)
        {
            float angle=i*3.1416/180;
            glVertex2f(0.1*cos(angle),0.1*sin(angle)+0.75);
        }
    glEnd();

    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.9,-0.4);
        glVertex2f(-0.7,-0.4);
        glVertex2f(-0.7,-0.1);
        glVertex2f(-0.9,-0.1);
    glEnd();

    glBegin(GL_TRIANGLES);
        glVertex2f(-0.92,-0.1);
        glVertex2f(-0.68,-0.1);
        glVertex2f(-0.8,0.05);
    glEnd();

    glColor3f(0.5,0.5,0.5);
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.25,-0.4);
        glVertex2f(-0.05,0.0);
        glVertex2f(0.15,-0.4);
    glEnd();

    glColor3f(0.6,0.9,0.6);
    glBegin(GL_QUADS);
        glVertex2f(0.2,-0.4);
        glVertex2f(0.9,-0.4);
        glVertex2f(0.9,0.0);
        glVertex2f(0.2,0.0);
    glEnd();

    glColor3f(0,0.5,0);
    for(float x=0.2; x<=0.9; x+=0.14)
    {
        glBegin(GL_LINES);
        glVertex2f(x,-0.4);
        glVertex2f(x,0.0);
        glEnd();
    }

    for(float y=-0.4; y<=0.0; y+=0.1)
    {
        glBegin(GL_LINES);
        glVertex2f(0.2,y);
        glVertex2f(0.9,y);
        glEnd();
    }

    glFlush();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640,480);
    glutCreateWindow("Rumah dan Sawah");

    glClearColor(1,1,1,1);

    glutDisplayFunc(display);
    glutMainLoop();
}
