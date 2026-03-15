//Nama: Revalina Salwa Aliya W.P
//NIM : 24060124140155

#include <gl/glut.h>
#include <gl/gl.h>
#include <math.h>

#define PI 3.14159265358979323846

void RenderScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
        glBegin(GL_TRIANGLE_FAN);
            glColor3f(0.7f, 0.9f, 1.0f); 
            glVertex2f(0.0f, 0.0f);
            int titik = 100;
            float r = 0.5f;
            for (int i = 0; i <= titik; i++){
                float angle = 2.0f * PI * i / titik;
                glColor3f(0.0f, 0.2f, 0.8f); 
                glVertex2f(r * cosf(angle), r * sinf(angle));
            }
        glEnd();
    glPopMatrix();

    glFlush();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("lingkaran");
    glutDisplayFunc(RenderScene);
    glClearColor(0.05f, 0.05f, 0.15f, 1.0f);
    glutMainLoop();
    return 0;
}
