#include <gl/glut.h>
#include <gl/gl.h>
#include <math.h>

// Tambahkan definisi PI di sini
#define PI 3.14159265358979323846

void RenderScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Menggambar Lingkaran di Tengah
    glPushMatrix();
        // Berikan warna agar lingkaran terlihat (misal: putih)
  		glColor3f(1.0f, 1.0f, 1.0f);  // putih
        glLineWidth(4.0f);

        glBegin(GL_LINE_LOOP);
            int circle_points = 200;
            float radius = 0.4f;
            for (int i = 0; i < circle_points; i++) {
                float angle = 2.0f * PI * (float)i / (float)circle_points;
                glVertex2f(radius * cosf(angle), radius * sinf(angle));
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
    glutCreateWindow("Simple"); 
    glutDisplayFunc(RenderScene); 
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f); 
    glutMainLoop(); 
    return 0; 
}
