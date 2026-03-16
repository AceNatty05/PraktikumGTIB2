#include <GL/glut.h>
#include <cmath>

const float PI = 3.14159;


void buatLingkaran(float xPusat, float yPusat, float radius, int jumlahTitik)
{
    glBegin(GL_POLYGON);

    for(int k = 0; k < jumlahTitik; k++)
    {
        float sudut = (2 * PI * k) / jumlahTitik;

        float x = xPusat + radius * cos(sudut);
        float y = yPusat + radius * sin(sudut);

        glVertex2f(x, y);
    }

    glEnd();
}

void tampil()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();

    glColor3f(0.7f, 0.3f, 0.5f);

    buatLingkaran(0.0f, 0.0f, 0.5f, 120);

    glFlush();
}

void pengaturan()
{
    glClearColor(0.05f, 0.05f, 0.05f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-1, 1, -1, 1);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(600, 600);
    glutInitWindowPosition(200, 150);

    glutCreateWindow("Gambar Lingkaran OpenGL");

    pengaturan();

    glutDisplayFunc(tampil);

    glutMainLoop();

    return 0;
}
