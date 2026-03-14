#include <gl/glut.h>
#include <gl/gl.h>
#include <math.h>

#define PI 3.14159265

void sisiSF() {
    glLineWidth(7.0f); 
    glColor3f(0.4f, 0.7f, 1.0f); // Biru muda
    
    glBegin(GL_LINES);
        // Batang Utama
        glVertex2f(0.10f, 0.0f); 
        glVertex2f(0.6f, 0.0f);

        // Cabang-cabang
        glVertex2f(0.25f, 0.0f); glVertex2f(0.4f, 0.15f);
        glVertex2f(0.25f, 0.0f); glVertex2f(0.4f, -0.15f);

        glVertex2f(0.45f, 0.0f); glVertex2f(0.6f, 0.15f);
        glVertex2f(0.45f, 0.0f); glVertex2f(0.6f, -0.15f);
    glEnd();

    // Ujung Belah Ketupat
    glPushMatrix();
        glTranslatef(0.75f, 0.0f, 0.0f);
        glRotatef(45.0f, 0.0f, 0.0f, 1.0f);
        glBegin(GL_LINE_LOOP);
            glVertex2f(-0.1f, -0.1f); glVertex2f(0.1f, -0.1f);
            glVertex2f(0.1f, 0.1f); glVertex2f(-0.1f, 0.1f);
        glEnd();
    glPopMatrix();
}

void gambarLingkaranPusat(float radius) {
    glLineWidth(7.0f);
    glBegin(GL_LINE_LOOP);
        for (int i = 0; i < 100; i++) {
            float angle = 2.0f * PI * i / 100;
            glVertex2f(cos(angle) * radius, sin(angle) * radius);
        }
    glEnd();
}

void RenderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // 1. Gambar Lingkaran di Tengah
    glColor3f(0.4f, 0.7f, 1.0f);
    gambarLingkaranPusat(0.1f); // Radius kecil agar pas di tengah

    // 2. Gambar 6 Sisi Snowflake dengan Rotasi Manual
    // Sisi 1 s/d 6
    for (int i = 0; i < 6; i++) {
        glPushMatrix();
            glRotatef(i * 60.0f, 0.0f, 0.0f, 1.0f);
            sisiSF();
        glPopMatrix();
    }

    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Snowflake");

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); 
    glutDisplayFunc(RenderScene);
    glutMainLoop();
    return 0;
}
