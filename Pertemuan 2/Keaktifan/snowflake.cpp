// Pertemuan 2 - Keaktifan - Snowflake
// Nama : Hana Nafi'atul Haq
// NIM 	: 24060124130081
// Lab 	: B2

#include <GL/glut.h>

void Snowflake(){
    glBegin(GL_LINES);

    // batang utama
    glVertex2f(0.0,0.0);
    glVertex2f(0.35,0.0);

    // cabang tengah atas
    glVertex2f(0.20,0.0);
    glVertex2f(0.28,0.08);

    // cabang tengah bawah
    glVertex2f(0.20,0.0);
    glVertex2f(0.28,-0.08);

    // cabang ujung atas
    glVertex2f(0.35,0.0);
    glVertex2f(0.42,0.07);

    // cabang ujung bawah
    glVertex2f(0.35,0.0);
    glVertex2f(0.42,-0.07);

    glEnd();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,0.55);

    glPushMatrix(); 
	glRotatef(0,0,0,1); 
	Snowflake(); 
	glPopMatrix();
	
    glPushMatrix(); 
	glRotatef(45,0,0,1); 
	Snowflake(); 
	glPopMatrix();
	
    glPushMatrix(); 
	glRotatef(90,0,0,1); 
	Snowflake(); 
	glPopMatrix();
	
    glPushMatrix(); 
	glRotatef(135,0,0,1); 
	Snowflake(); 
	glPopMatrix();
	
    glPushMatrix(); 
	glRotatef(180,0,0,1); 
	Snowflake(); 
	glPopMatrix();
	
    glPushMatrix(); 
	glRotatef(225,0,0,1); 
	Snowflake(); 
	glPopMatrix();
	
    glPushMatrix(); 
	glRotatef(270,0,0,1); 
	Snowflake(); 
	glPopMatrix();
	
    glPushMatrix(); 
	glRotatef(315,0,0,1); 
	Snowflake(); 
	glPopMatrix();

    glFlush();
}

int main(int argc,char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600,600);
    glutCreateWindow("Snowflake - Hana");
    glutDisplayFunc(display);
    glClearColor(0.80, 0.93, 0.88, 1.0);
    glutMainLoop();
}
