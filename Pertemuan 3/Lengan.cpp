/*
 * Nama    : Adam Mulya Rasyid
 * NIM     : 24060124140179
 * Praktikum GKV 3 Modul 4
 * Deskripsi : Simulasi lengan + telapak + jari
 */

#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>

/* VARIABEL ROTASI */
static int shoulder = 0;
static int elbow = 0;
static int finger = 0;

/* INISIALISASI */
void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

/* DISPLAY */
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();

    /* ===== LENGAN ATAS ===== */
    glTranslatef(-1.0, 0.0, 0.0);
    glRotatef((GLfloat) shoulder, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);

    glPushMatrix();
    glScalef(2.0, 0.4, 1.0);
    glutWireCube(1.0);
    glPopMatrix();

    /* ===== SIKU ===== */
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat) elbow, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);

    glPushMatrix();
    glScalef(2.0, 0.4, 1.0);
    glutWireCube(1.0);
    glPopMatrix();

    /* ===== TELAPAK TANGAN ===== */
    glTranslatef(1.0, 0.0, 0.0);

    glPushMatrix();
    glScalef(0.8, 0.4, 0.4);
    glutWireCube(1.0);
    glPopMatrix();

    /* ===== JARI ===== */
    glTranslatef(0.5, 0.2, 0.0);
    glRotatef((GLfloat) finger, 0.0, 0.0, 1.0);

    glPushMatrix();
    glScalef(0.6, 0.1, 0.1);
    glutWireCube(1.0);
    glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
}

/* RESHAPE (PROYEKSI) */
void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(65.0, (GLfloat) w / (GLfloat) h, 1.0, 20.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -6.0);
}

/* KEYBOARD */
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
        /* SHOULDER */
        case 's': shoulder = (shoulder + 5) % 360; break;
        case 'S': shoulder = (shoulder - 5) % 360; break;

        /* ELBOW */
        case 'e': elbow = (elbow + 5) % 360; break;
        case 'E': elbow = (elbow - 5) % 360; break;

        /* FINGER */
        case 'f': finger = (finger + 5) % 360; break;
        case 'F': finger = (finger - 5) % 360; break;

        /* EXIT */
        case 27: exit(0); break;
    }
    glutPostRedisplay();
}

/* MAIN */
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(700, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Lengan + Tangan + Jari");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}
