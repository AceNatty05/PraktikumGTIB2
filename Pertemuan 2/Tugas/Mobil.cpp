// Pertemuan 2 - Tugas - Mobil
// Nama : Hana Nafi'atul Haq
// NIM 	: 24060124130081
// Lab 	: B2

#include <GL/glut.h>
#include <cmath>

#define PI 3.1415926535

void Lingkaran(float cx,float cy,float r){
    int seg=100;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx,cy);

    for(int i=0;i<=seg;i++){
        float t=2*PI*i/seg;
        float x=cx+r*cos(t);
        float y=cy+r*sin(t);
        glVertex2f(x,y);
    }

    glEnd();
}

void GambarMobil(float r,float g,float b){
    glColor3f(r,g,b);

    glBegin(GL_POLYGON);
        glVertex2f(-0.25,-0.05);
        glVertex2f(0.25,-0.05);
        glVertex2f(0.25,0.10);
        glVertex2f(-0.25,0.10);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(-0.12,0.10);
        glVertex2f(0.12,0.10);
        glVertex2f(0.08,0.20);
        glVertex2f(-0.08,0.20);
    glEnd();

    glColor3f(0.9,0.9,0.9);

    glBegin(GL_POLYGON);
        glVertex2f(-0.07,0.12);
        glVertex2f(-0.01,0.12);
        glVertex2f(-0.01,0.18);
        glVertex2f(-0.07,0.18);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(0.02,0.12);
        glVertex2f(0.08,0.12);
        glVertex2f(0.08,0.18);
        glVertex2f(0.02,0.18);
    glEnd();

    glColor3f(0,0,0);

    Lingkaran(-0.15,-0.05,0.06);
    Lingkaran(0.15,-0.05,0.06);
}

void Langit(){
    glColor3f(0.92,0.92,0.85);

    glBegin(GL_POLYGON);
        glVertex2f(-1,1);
        glVertex2f(1,1);
        glVertex2f(1,-0.2);
        glVertex2f(-1,-0.2);
    glEnd();
}

void Matahari(){
    glColor3f(1.0,0.95,0.3);
    Lingkaran(-0.75,0.75,0.12);
    glLineWidth(3);
    glColor3f(1.0,0.85,0.2);

    int rays = 12;

    for(int i=0;i<rays;i++){
        float angle = 2*PI*i/rays;
        float x1 = -0.75 + 0.12*cos(angle);
        float y1 =  0.75 + 0.12*sin(angle);
        float x2 = -0.75 + 0.20*cos(angle);
        float y2 =  0.75 + 0.20*sin(angle);

        glBegin(GL_LINES);
            glVertex2f(x1,y1);
            glVertex2f(x2,y2);
        glEnd();
    }

    glLineWidth(1);
}

void Awan(float x, float y, float scale){

    glPushMatrix();
    glTranslatef(x,y,0);
    glScalef(scale,scale,1);

    glColor3f(1,1,1);

    Lingkaran(0.00,0.00,0.10);
    Lingkaran(-0.10,0.04,0.08);
    Lingkaran(0.10,0.05,0.09);
    Lingkaran(0.18,-0.01,0.07);
    Lingkaran(-0.18,-0.01,0.07);

    glPopMatrix();
}

void Pohon(float x,float scale){
    glPushMatrix();
    glTranslatef(x,-0.2,0);
    glScalef(scale,scale,1);

    glColor3f(0.45,0.30,0.15);
    glBegin(GL_POLYGON);
        glVertex2f(-0.03,0.0);
        glVertex2f(0.03,0.0);
        glVertex2f(0.03,0.16);
        glVertex2f(-0.03,0.16);
    glEnd();

    glColor3f(0.15,0.55,0.20);
    Lingkaran(0.0,0.25,0.10);
    Lingkaran(-0.08,0.20,0.08);
    Lingkaran(0.08,0.20,0.08);

    glPopMatrix();
}

void GedungLayerBelakang(){
    glColor3f(0.70,0.82,0.85);

    float x=-1.0;

    for(int i=0;i<8;i++){

        float lebar=0.18;
        float tinggi=0.45 + (i%3)*0.08;

        glBegin(GL_POLYGON);
            glVertex2f(x,-0.2);
            glVertex2f(x+lebar,-0.2);
            glVertex2f(x+lebar,tinggi);
            glVertex2f(x,tinggi);
        glEnd();

        glColor3f(0.90,0.90,0.90);

        for(float wy=0.0; wy<tinggi-0.05; wy+=0.12){
            for(float wx=x+0.03; wx<x+lebar-0.05; wx+=0.07){

                glBegin(GL_POLYGON);
                    glVertex2f(wx,wy);
                    glVertex2f(wx+0.04,wy);
                    glVertex2f(wx+0.04,wy+0.05);
                    glVertex2f(wx,wy+0.05);
                glEnd();

            }
        }

        glColor3f(0.70,0.82,0.85);
        x+=0.22;
    }
}

void GedungLayerDepan(){
    glPushMatrix();
    glTranslatef(0.5,0,0);
    glColor3f(0.55,0.70,0.75);

    float x=-1.4;

    for(int i=0;i<10;i++){

        float lebar=0.16;
        float tinggi=0.35 + (i%3)*0.07;

        glBegin(GL_POLYGON);
            glVertex2f(x,-0.2);
            glVertex2f(x+lebar,-0.2);
            glVertex2f(x+lebar,tinggi);
            glVertex2f(x,tinggi);
        glEnd();

        glColor3f(0.92,0.92,0.92);

        for(float wy=0.0; wy<tinggi-0.05; wy+=0.12){
            for(float wx=x+0.03; wx<x+lebar-0.05; wx+=0.07){

                glBegin(GL_POLYGON);
                    glVertex2f(wx,wy);
                    glVertex2f(wx+0.04,wy);
                    glVertex2f(wx+0.04,wy+0.05);
                    glVertex2f(wx,wy+0.05);
                glEnd();

            }
        }

        glColor3f(0.55,0.70,0.75);
        x+=0.20;
    }

    glPopMatrix();
}

void Aspal(){
    glColor3f(0.35,0.35,0.35);

    glBegin(GL_POLYGON);
        glVertex2f(-1,-0.2);
        glVertex2f(1,-0.2);
        glVertex2f(1,-1);
        glVertex2f(-1,-1);
    glEnd();
}

void MarkaJalan(){
    glColor3f(1,1,1);
    glLineWidth(5);

    glBegin(GL_LINES);

    for(float x=-0.9;x<1;x+=0.4)
    {
        glVertex2f(x,-0.45);
        glVertex2f(x+0.25,-0.45);
    }

    glEnd();
}

void Render(){
    glClear(GL_COLOR_BUFFER_BIT);

    Langit();
    Matahari();
    GedungLayerBelakang();
    GedungLayerDepan();
    Aspal();
    MarkaJalan();

	Awan(-0.2,0.85,0.9);
	Awan(0.5,0.8,1.0);
	
	Pohon(-0.85,1.1);
	Pohon(-0.60,1.0);
	Pohon(0.45,1.0);
	Pohon(0.75,1.1);
    
	glPushMatrix();
    glTranslatef(-0.5,-0.3,0);
    glScalef(1.2,1.2,1);
    GambarMobil(1.0,0.2,0.2);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.55,-0.45,0);
    glScalef(1.2,1.2,1);
    GambarMobil(1.0,0.65,0.2);
    glPopMatrix();

    glFlush();
}

void Setup(){
    glClearColor(1,1,1,1);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-1,1,-1,1);
}

int main(int argc,char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(800,800);
    glutCreateWindow("Mobil Primitif - Hana");

    Setup();
    glutDisplayFunc(Render);
    glutMainLoop();

    return 0;
}
