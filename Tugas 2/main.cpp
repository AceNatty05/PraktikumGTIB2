#include <GL/glut.h>
#include <math.h>

#define PI 3.1415926

void drawCircle(float r){
    int i;
    int triangleAmount = 40;

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0,0);
        for(i=0;i<=triangleAmount;i++)
        {
            float angle = 2 * PI * i / triangleAmount;
            glVertex2f(r*cos(angle), r*sin(angle));
        }
    glEnd();
}

void drawWheel(){

    glColor3f(0,0,0);
    drawCircle(0.06);

    glColor3f(0.6,0.6,0.6);
    drawCircle(0.035);
}

void drawRoad(){
    glPushMatrix();

    glColor3f(0.2,0.2,0.2);

    glBegin(GL_QUADS);
        glVertex2f(-1,-0.6);
        glVertex2f(1,-0.6);
        glVertex2f(1,-1);
        glVertex2f(-1,-1);
    glEnd();

    glPopMatrix();
}

void drawTree(float x,float y){
    glPushMatrix();

    glTranslatef(x,y,0);

    glColor3f(0.55,0.27,0.07);

    glBegin(GL_QUADS);
        glVertex2f(-0.02,-0.2);
        glVertex2f(0.02,-0.2);
        glVertex2f(0.02,0.1);
        glVertex2f(-0.02,0.1);
    glEnd();

    glColor3f(0,0.7,0);

    glPushMatrix();
        glTranslatef(0,0.18,0);
        drawCircle(0.1);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.07,0.12,0);
        drawCircle(0.08);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.07,0.12,0);
        drawCircle(0.08);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0,0.08,0);
        drawCircle(0.08);
    glPopMatrix();

    glPopMatrix();
}

void drawCloud(float x,float y){
    glPushMatrix();

    glTranslatef(x,y,0);

    glColor3f(1,1,1);

    glPushMatrix();
        drawCircle(0.05);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.06,0,0);
        drawCircle(0.05);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.06,0,0);
        drawCircle(0.05);
    glPopMatrix();

    glPopMatrix();
}

void drawGTR(){
    glPushMatrix();

    glTranslatef(0,-0.55,0);

    glColor3f(0.9,0.9,0.9);

    glBegin(GL_QUADS);
        glVertex2f(-0.35,0.0);
        glVertex2f(0.35,0.0);
        glVertex2f(0.35,0.12);
        glVertex2f(-0.35,0.12);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(-0.20,0.12);
        glVertex2f(0.18,0.12);
        glVertex2f(0.10,0.22);
        glVertex2f(-0.05,0.22);
        glVertex2f(-0.25,0.15);
    glEnd();

    glColor3f(0.3,0.6,0.7);

    glBegin(GL_QUADS);
        glVertex2f(-0.12,0.13);
        glVertex2f(0.12,0.13);
        glVertex2f(0.07,0.20);
        glVertex2f(-0.05,0.20);
    glEnd();
    
    glColor3f(0.1,0.1,0.1);

    glBegin(GL_QUADS);
        glVertex2f(0.30,0.12);
        glVertex2f(0.32,0.12);
        glVertex2f(0.32,0.17);
        glVertex2f(0.30,0.17);
    glEnd();

    glBegin(GL_QUADS);
        glVertex2f(0.26,0.17);
        glVertex2f(0.40,0.17);
        glVertex2f(0.40,0.19);
        glVertex2f(0.26,0.19);
    glEnd();

    glPushMatrix();
        glTranslatef(-0.22,-0.02,0);
        drawWheel();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.22,-0.02,0);
        drawWheel();
    glPopMatrix();

    glPopMatrix();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    drawRoad();

    drawTree(-0.7,-0.4);
    drawTree(-0.5,-0.4);
    drawTree(0.7,-0.4);

    drawCloud(-0.5,0.6);
    drawCloud(0.3,0.7);

    drawGTR();

    glFlush();
}

void init(){
    glClearColor(0.5,0.8,1.0,1.0);
    gluOrtho2D(-1,1,-1,1);
}

int main(int argc,char** argv){
    glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800,600);
	glutCreateWindow("Tugas 2");

    init();
	glutDisplayFunc(display);
	glutMainLoop();

    return 0;
}
