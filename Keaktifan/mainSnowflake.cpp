#include <GL/glut.h>
#include <math.h>

void batang()
{
    glBegin(GL_LINES);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.0, 0.4);
    glEnd();
}

void snowflake()
{
    for(int i = 0; i < 6; i++)
    {
        glPushMatrix();
        glRotatef(i * 60, 0, 0, 1);
        batang();
        glPushMatrix();
            glTranslatef(0.0, 0.3, 0.0);
            glRotatef(30,0,0,1);
            batang();
        glPopMatrix();

        glPushMatrix();
            glTranslatef(0.0, 0.3, 0.0);
            glRotatef(-30,0,0,1);
            batang();
        glPopMatrix();

        glPopMatrix();
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glColor3f(1,1,1);
    snowflake();
    glFlush();
}

void init()
{
    glClearColor(0.0,0.0,0.1,1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1,1,-1,1);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600,480);
    glutCreateWindow("Snowflake - Translasi dan Rotasi");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
