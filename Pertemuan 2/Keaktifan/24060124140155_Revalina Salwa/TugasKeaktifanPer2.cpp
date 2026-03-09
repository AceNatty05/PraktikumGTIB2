//Nama: Revalina Salwa Aliya W.P
//NIM : 24060124140155

#include <GL/glut.h>
#include <GL/gl.h>
#define SISI 8

//gambar garis utama, bawah, atas
void GambarGaris(){
    //utama
    glBegin(GL_LINES);
        glColor3f(1.0f, 0.8f, 0.9f); glVertex3f(0.0, 0.0, 0.0);
        glColor3f(1.0f, 0.2f, 0.6f); glVertex3f(0.0, 0.5, 0.0);
    glEnd();

    //bawah
    glBegin(GL_LINES);
        glColor3f(1.0f, 0.4f, 0.7f); glVertex3f(0.0, 0.2, 0.0);
        glColor3f(0.9f, 0.6f, 0.8f); glVertex3f(-0.1, 0.3, 0.0);
    glEnd();
    glBegin(GL_LINES);
        glColor3f(1.0f, 0.4f, 0.7f); glVertex3f(0.0, 0.2, 0.0);
        glColor3f(0.9f, 0.6f, 0.8f); glVertex3f(0.1, 0.3, 0.0);
    glEnd();

    //atas
    glBegin(GL_LINES);
        glColor3f(1.0f, 0.4f, 0.7f); glVertex3f(0.0, 0.35, 0.0);
        glColor3f(0.9f, 0.6f, 0.8f); glVertex3f(-0.1, 0.45, 0.0);
    glEnd();
    glBegin(GL_LINES);
        glColor3f(1.0f, 0.4f, 0.7f); glVertex3f(0.0, 0.35, 0.0);
        glColor3f(0.9f, 0.6f, 0.8f); glVertex3f(0.1, 0.45, 0.0);
    glEnd();
}

//render gambar
void RenderScene(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(2.0f);
    for (int i = 0; i < SISI; i++){
        glPushMatrix();
            glRotated(i * (360.0 / SISI), 0.0, 0.0, 1.0);
            GambarGaris();
        glPopMatrix();
    }
    glFlush();
}

//main
int main(int argc, char* argv[]){
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA);
    glutCreateWindow("snowflake warna pink");
    glutDisplayFunc(RenderScene);
    glClearColor(0.1f, 0.0f, 0.1f, 1.0f);
    glutMainLoop();
    return 0;
}
