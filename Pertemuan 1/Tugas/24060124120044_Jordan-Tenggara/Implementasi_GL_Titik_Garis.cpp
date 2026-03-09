#include <GL/glut.h>

void Garis(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(8.0f);


    glBegin(GL_POINTS);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(-0.2f, 0.2f, 0.0f);
        glVertex3f(0.2f, 0.2f, 0.0f); 
    glEnd();

    glLineWidth(2.0f);
    glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(-0.2f, 0.2f, 0.0f); 
        glVertex3f(0.2f, 0.2f, 0.0f);  
    glEnd();

    glFlush();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Membuat Titik dan Garis");

    glutDisplayFunc(Garis);
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

    glutMainLoop();
    return 0;
}
