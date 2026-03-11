// =================================================================
// Nama: Birela Miadeta Purita
// Lab:  B2
// NIM:  24060124120002
// Tujuan: Tugas 2 - Mengimplementasikan berbagai transformasi (mobil) 
// =================================================================

#include <GL/glut.h>
#include <cmath>
#define PI 3.1415926535898

float sudutRoda = 0.0f;

// fungsi membuat lingkaran (roda)
void roda(float x, float y){
    glPushMatrix();
    glTranslatef(x, y, 0);
    glRotatef(sudutRoda, 0,0,1);

    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    for(int i=0;i<100;i++){
        float angle = 2*PI*i/100;
        glVertex2f(cos(angle)*0.15, sin(angle)*0.15);
    }
    glEnd();

    glColor3f(0.7,0.7,0.7);
    glBegin(GL_LINES);
        glVertex2f(-0.15,0);
        glVertex2f(0.15,0);

        glVertex2f(0,-0.15);
        glVertex2f(0,0.15);
    glEnd();
    glPopMatrix();
}

// body mobil sport
void mobil(){
    glPushMatrix();

    // body bawah
    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
        glVertex2f(-0.8,-0.1);
        glVertex2f(0.8,-0.1);
        glVertex2f(0.7,0.15);
        glVertex2f(-0.7,0.15);
    glEnd();

    // atap mobil
    glBegin(GL_POLYGON);
        glVertex2f(-0.4,0.15);
        glVertex2f(0.3,0.15);
        glVertex2f(0.15,0.35);
        glVertex2f(-0.25,0.35);
    glEnd();

    // kaca
    glColor3f(0.6,0.9,1);
    glBegin(GL_POLYGON);
        glVertex2f(-0.35,0.17);
        glVertex2f(0.25,0.17);
        glVertex2f(0.1,0.33);
        glVertex2f(-0.22,0.33);
    glEnd();

    // spoiler belakang (biar sport)
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
        glVertex2f(-0.75,0.15);
        glVertex2f(-0.65,0.15);
        glVertex2f(-0.65,0.30);
        glVertex2f(-0.75,0.30);
    glEnd();

    // roda
    roda(-0.5,-0.1);
    roda(0.5,-0.1);

    glPopMatrix();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    mobil();
    glFlush();
}

void idle(){
    sudutRoda += 0.5;
    if(sudutRoda > 360) sudutRoda = 0;
    glutPostRedisplay();
}

void init(){
    glClearColor(1,1,1,1);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-2,2,-1,1);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800,400);
    glutCreateWindow("Mobil Sport - Birela");
    init();
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutMainLoop();
}
