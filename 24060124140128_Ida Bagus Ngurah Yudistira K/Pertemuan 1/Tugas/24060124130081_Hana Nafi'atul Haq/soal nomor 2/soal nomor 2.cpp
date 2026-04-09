// Pertemuan 1 - Nomor 2 
// Nama : Hana Nafi'atul Haq
// NIM 	: 24060124130081
// Lab 	: B2

#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // LINE STRIP (atas kiri)
    glBegin(GL_LINE_STRIP);
        glColor3f(0.1f,0.4f,1.0f);
        glVertex2f(-0.7, 0.6);

        glColor3f(0.0f,0.6f,1.0f);
        glVertex2f(-0.6, 0.7);

        glColor3f(0.0f,0.8f,1.0f);
        glVertex2f(-0.5, 0.6);

        glColor3f(0.0f,0.6f,0.9f);
        glVertex2f(-0.4, 0.7);

        glColor3f(0.0f,0.4f,0.8f);
        glVertex2f(-0.3, 0.6);
    glEnd();


    // LINE LOOP (atas kanan)
    glBegin(GL_LINE_LOOP);
        glColor3f(0.2f,1.0f,0.4f);
        glVertex2f(0.3, 0.55);

        glColor3f(0.0f,0.9f,0.3f);
        glVertex2f(0.5, 0.7);

        glColor3f(0.0f,0.8f,0.2f);
        glVertex2f(0.7, 0.55);

        glColor3f(0.2f,0.7f,0.2f);
        glVertex2f(0.5, 0.4);
    glEnd();


    // TRIANGLE FAN (tengah kiri)
    glBegin(GL_TRIANGLE_FAN);

        glColor3f(1.0f,0.9f,0.3f);
        glVertex2f(-0.6,0.1);

        glColor3f(1.0f,0.7f,0.2f);
        glVertex2f(-0.9,-0.2);

        glColor3f(1.0f,0.5f,0.1f);
        glVertex2f(-0.3,-0.2);

        glColor3f(1.0f,0.6f,0.0f);
        glVertex2f(-0.3,0.4);

        glColor3f(1.0f,0.8f,0.2f);
        glVertex2f(-0.9,0.4);

        glVertex2f(-0.9,-0.2);

    glEnd();


    // TRIANGLE STRIP (tengah kanan)
    glBegin(GL_TRIANGLE_STRIP);

        glColor3f(1.0f,0.0f,0.0f);
        glVertex2f(0.1,-0.2);

        glColor3f(1.0f,0.3f,0.0f);
        glVertex2f(0.3,0.2);

        glColor3f(1.0f,0.6f,0.0f);
        glVertex2f(0.5,-0.2);

        glColor3f(1.0f,0.2f,0.2f);
        glVertex2f(0.7,0.2);

        glColor3f(0.9f,0.0f,0.3f);
        glVertex2f(0.9,-0.2);

    glEnd();


    // QUADS (bawah kiri)
    glBegin(GL_QUADS);

        glColor3f(0.6f,0.3f,0.9f);
        glVertex2f(-0.7,-0.5);

        glColor3f(0.7f,0.4f,1.0f);
        glVertex2f(-0.4,-0.5);

        glColor3f(0.5f,0.2f,0.8f);
        glVertex2f(-0.4,-0.8);

        glColor3f(0.4f,0.1f,0.7f);
        glVertex2f(-0.7,-0.8);

    glEnd();

    // QUAD STRIP (bawah kanan)
    glBegin(GL_QUAD_STRIP);
		glColor3f(0.3f,0.8f,1.0f);
		glVertex2f(0.25f, -0.35f);
		glVertex2f(0.25f, -0.75f);
		
		glColor3f(0.3f,0.8f,1.0f);
		glVertex2f(0.40f, -0.30f);
		glVertex2f(0.40f, -0.70f);
		
		glColor3f(0.1f, 0.75f, 0.7f);
		glVertex2f(0.55f, -0.38f);
		glVertex2f(0.55f, -0.78f);
		
		glColor3f(0.05f, 0.55f, 0.6f);
		glVertex2f(0.70f, -0.32f);
		glVertex2f(0.70f, -0.72f);
	
	glEnd();

    glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(900,650);
    glutCreateWindow("soal nomor 2");

    glClearColor(0.95f,0.95f,1.0f,1.0f);

    glutDisplayFunc(display);
    glutMainLoop();
}
