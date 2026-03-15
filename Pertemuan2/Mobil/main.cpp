//Nama: Muhammad Ibrahim Alghifari
//NIM: 24060124140140
//Lab: B2

#include <GL/glut.h>
#include <math.h>
#define PI 3.14159265358979323846

void RenderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glLineWidth(2.0f);
    glColor3f(0.0f, 0.0f, 0.0f);

    glPushMatrix();
        glBegin(GL_LINE_LOOP);
            glVertex2f(-0.7f, -0.2f);
            glVertex2f(-0.3f, -0.2f);
            glVertex2f(-0.3f,  0.2f);
            glVertex2f(-0.7f,  0.2f);
        glEnd();
    glPopMatrix();

    glPushMatrix();
        glBegin(GL_LINE_LOOP);
            glVertex2f(-0.3f, -0.2f);
            glVertex2f( 0.3f, -0.2f);
            glVertex2f( 0.3f,  0.5f);
            glVertex2f(-0.3f,  0.5f);
        glEnd();
    glPopMatrix();

    glPushMatrix();
        glBegin(GL_LINE_LOOP);
            glVertex2f( 0.3f, -0.2f);
            glVertex2f( 0.7f, -0.2f);
            glVertex2f( 0.7f,  0.2f);
            glVertex2f( 0.3f,  0.2f);
        glEnd();
    glPopMatrix();

    glPushMatrix();
        glBegin(GL_LINE_LOOP);
            glVertex2f(-0.2f, 0.25f);
            glVertex2f( 0.2f, 0.25f);
            glVertex2f( 0.2f, 0.45f);
            glVertex2f(-0.2f, 0.45f);
        glEnd();
    glPopMatrix();

    GLint circle_points = 100;

    glPushMatrix();
        glTranslatef(-0.3f, -0.2f, 0.0f);
        glScalef(0.15f, 0.2f, 1.0f);
        glBegin(GL_LINE_LOOP);
            for (int i = 0; i < circle_points; i++) {
                float angle = 2 * PI * i / circle_points;
                glVertex2f(cos(angle), sin(angle));
            }
        glEnd();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.3f, -0.2f, 0.0f);
        glScalef(0.15f, 0.2f, 1.0f);
        glBegin(GL_LINE_LOOP);
            for (int i = 0; i < circle_points; i++) {
                float angle = 2 * PI * i / circle_points;
                glVertex2f(cos(angle), sin(angle));
            }
        glEnd();
    glPopMatrix();

    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Desain Mobil 2D");
    glutDisplayFunc(RenderScene);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutMainLoop();
    return 0;
}
