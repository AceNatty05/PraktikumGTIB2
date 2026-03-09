#include <gl/glut.h>
#include <gl/gl.h>
#include <math.h>

// =================================================================
// Nama: Birela Miadeta Purita
// Lab:  B2
// NIM:  24060124120002
// Tujuan: Keaktifan 2 - Mengimplementasikan berbagai transformasi (rotasi) 
// =================================================================

void RenderScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix(); 
 
    for(int i = 0; i < 10; i++) 
    {
        glPushMatrix();
        glRotated(i * 36, 0, 0, 1); //360 : 10 = 36

        // Menggambar 1 cabang utama 
        glBegin(GL_LINES);
            glColor3f(1.0, 1.0, 1.0);
            glVertex2f(0.0, 0.0);  
            glVertex2f(0.7, 0.0);  
        glEnd();

        // Menggambar ranting-ranting kecil 
        for(float j = 0.2; j <= 0.6; j += 0.2) 
        {
            glPushMatrix();
                glTranslatef(j, 0.0, 0.0); // Translasi
                glPushMatrix();
                    glRotated(45, 0, 0, 1); // Rotated 45 derajat 
                    glBegin(GL_LINES);
                        glVertex2f(0.0, 0.0);
                        glVertex2f(0.15, 0.0);
                    glEnd();
                glPopMatrix();

                // Ranting Bawah
                glPushMatrix();
                    glRotated(-45, 0, 0, 1); // Rotated -45 derajat
                    glBegin(GL_LINES);
                        glVertex2f(0.0, 0.0);
                        glVertex2f(0.15, 0.0);
                    glEnd();
                glPopMatrix();

            glPopMatrix(); // Kembali ke batang utama
        }

        glPopMatrix(); // Kembali ke titik pusat untuk rotasi
    }
    glPopMatrix();
    glFlush();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Snowflake - Birela Miadeta Purita");
    glutDisplayFunc(RenderScene);
    glClearColor(0.0f, 0.0f, 0.2f, 1.0f); 
    glutMainLoop();
    return 0;
}
