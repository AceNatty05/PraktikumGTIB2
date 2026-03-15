#include <GL/glut.h>
#include <cstdlib>
#include <cmath>

#define PI 3.1415926535898
const int NUM_STARS = 100;

void Mobil(float tur, float tug, float tub, float mer, float meg, float meb, float mur, float mug, float mub) {

    // Body atas
    glColor3f(mur, mug, mub);
    glPushMatrix();
    glBegin(GL_POLYGON);
        glVertex2f((float)(-14.0/50.0), (float)(-6.0/50.0));
        glVertex2f((float)(21.0/50.0), (float)(-5.0/50.0));
        glVertex2f((float)(0.0/50.0), (float)(-1.5/50.0));
    glEnd();
    glPopMatrix();

    // Body bawah
    glColor3f(tur, tug, tub);
    glPushMatrix();
    glBegin(GL_POLYGON);
        glVertex2f((float)(-14.0/50.0), (float)(-6.0/50.0));
        glVertex2f((float)(21.0/50.0), (float)(-5.0/50.0));
        glVertex2f((float)(19.5/50.0), (float)(-11.0/50.0));
        glVertex2f((float)(10.0/50.0), (float)(-11.0/50.0));
        glVertex2f((float)(-7.0/50.0), (float)(-11.0/50.0));
        glVertex2f((float)(-15.0/50.0), (float)(-9.5/50.0));
        glVertex2f((float)(-15.0/50.0), (float)(-8.5/50.0));
        glVertex2f((float)(-15.5/50.0), (float)(-6.0/50.0));
    glEnd();
    glPopMatrix();

    // Body tengah
    glColor3f(mer, meg, meb);
    glPushMatrix();
    glBegin(GL_POLYGON);
        glVertex2f((float)(-14.0/50.0), (float)(-6.0/50.0));
        glVertex2f((float)(21.0/50.0), (float)(-5.0/50.0));
        glVertex2f((float)(20.0/50.0), (float)(-9.0/50.0));
        glVertex2f((float)(17.5/50.0), (float)(-9.0/50.0));
        glVertex2f((float)(9.5/50.0), (float)(-9.5/50.0));
        glVertex2f((float)(-6.0/50.0), (float)(-9.5/50.0));
        glVertex2f((float)(-14.0/50.0), (float)(-8.5/50.0));
        glVertex2f((float)(-15.0/50.0), (float)(-8.5/50.0));
        glVertex2f((float)(-15.5/50.0), (float)(-6.0/50.0));
    glEnd();
    glPopMatrix();

    // Kaca
    glColor4f(0.2,0.2,0.2,0.5);
    glPushMatrix();
    glBegin(GL_POLYGON);
        glVertex2f((float)(0.0/50.0), (float)(-2.0/50.0));
        glVertex2f((float)(8.0/50.0), (float)(-3.4/50.0));
        glVertex2f((float)(8.0/50.0), (float)(-4.5/50.0));
        glVertex2f((float)(-10.0/50.0), (float)(-5.2/50.0));
    glEnd();
    glPopMatrix();

    // Roda
    glColor3f(0,0,0);
    int segmen = 100;
    float r = 2.5/50;

    glPushMatrix();
    float cx = -10.5/50.0, cy = -10.0/50.0;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx,cy);
    for(int i=0;i<=segmen;i++){
        float theta = 2.0f * PI * i / segmen;
        glVertex2f(cx + r*cos(theta), cy + r*sin(theta));
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    cx = 13.5/50.0; cy = -10.5/50.0;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx,cy);
    for(int i=0;i<=segmen;i++){
        float theta = 2.0f * PI * i / segmen;
        glVertex2f(cx + r*cos(theta), cy + r*sin(theta));
    }
    glEnd();
    glPopMatrix();

    glFlush();
}

void drawGradientSky(){
    glBegin(GL_QUADS);
    glColor3f(1.0,0.5,0.0);
    glVertex2f(-1,1);
    glVertex2f(1,1);
    glColor3f(0.0,0.0,0.5);
    glVertex2f(1,-0.1);
    glVertex2f(-1,-0.1);
    glEnd();
}

void drawStars(){
    glColor3f(1,1,1);
    glPointSize(2);
    glBegin(GL_POINTS);

    for(int i=0;i<NUM_STARS;i++){
        float x=((rand()%200)/100.0f)-1.0f;
        float y=((rand()%100)/100.0f)+0.5f;
        glVertex2f(x,y);
    }

    glEnd();
}

// GUNUNG 
void drawMountain(){

    glColor3f(0.2,0.3,0.2);
    glBegin(GL_TRIANGLES);
        glVertex2f(-1,-0.1);
        glVertex2f(-0.6,0.4);
        glVertex2f(-0.2,-0.1);
    glEnd();

    glBegin(GL_TRIANGLES);
        glVertex2f(-0.3,-0.1);
        glVertex2f(0.1,0.45);
        glVertex2f(0.5,-0.1);
    glEnd();

    glBegin(GL_TRIANGLES);
        glVertex2f(0.2,-0.1);
        glVertex2f(0.7,0.35);
        glVertex2f(1,-0.1);
    glEnd();

//    // salju
//    glColor3f(1,1,1);
//
//// salju 1
//glBegin(GL_TRIANGLES);
//glVertex2f(-0.55,0.20);
//glVertex2f(-0.45,0.20);
//glVertex2f(-0.50,0.30);
//glEnd();
//
//// salju 2
//glBegin(GL_TRIANGLES);
//glVertex2f(-0.50,0.18);
//glVertex2f(-0.40,0.18);
//glVertex2f(-0.45,0.27);
//glEnd();
//
//// salju 3
//glBegin(GL_TRIANGLES);
//glVertex2f(-0.60,0.18);
//glVertex2f(-0.50,0.18);
//glVertex2f(-0.55,0.27);
//glEnd();
//    
//    
//    glColor3f(1,1,1);
//    glBegin(GL_TRIANGLES);
//        glVertex2f(-0.63,0.33);
//        glVertex2f(-0.6,0.4);
//        glVertex2f(-0.57,0.33);
//    glEnd();
//    
//     glColor3f(1,1,1);
//    glBegin(GL_TRIANGLES);
//        glVertex2f(-0.50,0.20);
//        glVertex2f(-0.5,0.3);
//        glVertex2f(-0.40,0.20);
//    glEnd();
//    

    glBegin(GL_TRIANGLES);
        glVertex2f(0.07,0.38);
        glVertex2f(0.1,0.45);
        glVertex2f(0.13,0.38);
    glEnd();

    glBegin(GL_TRIANGLES);
        glVertex2f(0.67,0.30);
        glVertex2f(0.7,0.35);
        glVertex2f(0.73,0.30);
    glEnd();
}

void drawRoad(){
    glColor3f(0.2,0.2,0.2);
    glBegin(GL_QUADS);
        glVertex2f(-1,-0.1);
        glVertex2f(1,-0.1);
        glVertex2f(1,-1);
        glVertex2f(-1,-1);
    glEnd();
}

void drawRoadLines(){

    glColor3f(1,1,1);
    glLineWidth(5);

    glBegin(GL_LINES);
    for(float x=-0.9;x<1.0;x+=0.4){
        glVertex2f(x,-0.6);
        glVertex2f(x+0.3,-0.6);
    }
    glEnd();
}

void display(){

    glClear(GL_COLOR_BUFFER_BIT);

    drawGradientSky();
    drawStars();
    drawMountain();
    drawRoad();
    drawRoadLines();

    glPushMatrix();
    glTranslatef(-0.5,0,0);
    glScalef(-0.8,0.8,1);
    Mobil(0.4,0.2,0.0,0.6,0.4,0.2,0.8,0.6,0.4);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5,0,0);
    glScalef(-0.8,0.8,1);
    Mobil(0.0,0.5,0.0,0.2,0.7,0.2,0.4,1.0,0.4);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5,-0.5,0);
    Mobil(0.4,0.0,0.4,0.6,0.2,0.6,0.8,0.4,0.8);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.2,-0.3,0);
    glScalef(0.9,0.9,1);
    Mobil(0.5,0.4,0.0,0.7,0.6,0.2,1.0,0.8,0.4);
    glPopMatrix();

    glFlush();
}

void init(){
    glClearColor(1,1,1,1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1,1,-1,1);
}

int main(int argc,char** argv){

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000,1000);

    glutCreateWindow("Cybertruck Mountain Scene");

    init();
    glutDisplayFunc(display);

    glutMainLoop();
}
