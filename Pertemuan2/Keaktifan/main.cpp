#include <GL/glut.h>

void snowflake()
{
    glBegin(GL_LINES);

        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(0.0, 0.55, 0.0);

        glVertex3f(0.0, 0.30, 0.0);
        glVertex3f(-0.10, 0.40, 0.0);

        glVertex3f(0.0, 0.30, 0.0);
        glVertex3f(0.10, 0.40, 0.0);

        glVertex3f(0.0, 0.45, 0.0);
        glVertex3f(-0.08, 0.52, 0.0);

        glVertex3f(0.0, 0.45, 0.0);
        glVertex3f(0.08, 0.52, 0.0);

    glEnd();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.7, 0.85);
    glLineWidth(3.0);

    for(int i=0;i<8;i++)
    {
        glPushMatrix();

        glRotatef(i*45,0.0,0.0,1.0);

        snowflake();

        glPopMatrix();
    }

    glPointSize(10.0);
    glColor3f(1.0,1.0,0.5);

    glBegin(GL_POINTS);
        glVertex3f(0.0,0.0,0.0);
    glEnd();

    glFlush();
}

int main(int argc,char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Snowflake");

    glutDisplayFunc(display);

    glClearColor(0.95,0.90,1.0,1.0);

    glutMainLoop();
}


