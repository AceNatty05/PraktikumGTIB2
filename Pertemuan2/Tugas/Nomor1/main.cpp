#include <GL/glut.h>
#include <math.h>

#define PI 3.1415926535898

void Lingkaran(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();

    int segmen = 100;
    float radius = 0.4f;

    glColor3f(0.2f, 0.9f, 1.0f); // warna lingkaran

    glBegin(GL_TRIANGLE_FAN);

        glVertex2f(0.0f, 0.0f);

        for (int i = 0; i <= segmen; i++)
        {
            float angle = 2.0f * PI * i / segmen;

            float x = radius * cos(angle);
            float y = radius * sin(angle);

            glVertex2f(x, y);
        }

    glEnd();

    glPopMatrix();

    glFlush();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Lingkaran");

    glutDisplayFunc(Lingkaran);

    // background 
    glClearColor(0.9f, 0.9f, 1.0f, 1.0f);

    glutMainLoop();
    return 0;
}



