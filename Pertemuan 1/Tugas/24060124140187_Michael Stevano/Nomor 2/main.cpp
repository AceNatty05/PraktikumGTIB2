#include <GL/glut.h>

void lineStrip() {
	glLineWidth(4.0);
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_LINE_STRIP);
	glVertex2f(-0.8, 0.8);
	glVertex2f(-0.8, 0.6);
	glVertex2f(-0.6, 0.6);
	glVertex2f(-0.6, 0.8);
	glVertex2f(-0.8, 0.8);
	glEnd();
}

void lineLoop() {
	glLineWidth(4.0);
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-0.4, 0.8);
	glVertex2f(-0.4, 0.6);
	glVertex2f(-0.2, 0.6);
	glVertex2f(-0.2, 0.8);
	glEnd();
}

void triangleFan() {
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(0.1, 0.7);
	glVertex2f(0.0, 0.8);
	glVertex2f(0.2, 0.8);
	glVertex2f(0.2, 0.6);
	glVertex2f(0.0, 0.6);
	glVertex2f(0.0, 0.8);
	glEnd();
}

void triangleStrip() {
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f(0.4, 0.6);
	glVertex2f(0.5, 0.8);
	glVertex2f(0.6, 0.6);
	glVertex2f(0.7, 0.8);
	glVertex2f(0.8, 0.6);
	glEnd();
}

void quads() {
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2f(-0.8, 0.4);
	glVertex2f(-0.8, 0.2);
	glVertex2f(-0.6, 0.2);
	glVertex2f(-0.6, 0.4);
	glEnd();
}

void quadStrip() {
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_QUAD_STRIP);
	glVertex2f(-0.4, 0.4);
	glVertex2f(-0.4, 0.2);
	glVertex2f(-0.3, 0.4);
	glVertex2f(-0.3, 0.2);
	glVertex2f(-0.2, 0.4);
	glVertex2f(-0.2, 0.2);
	glEnd();
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	
	lineStrip();
	lineLoop();
	triangleFan();
	triangleStrip();
	quads();
	quadStrip();
	
	glFlush();
}

int main(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1280, 720);
	glutCreateWindow("Tugas 1");
	glClearColor(0.0, 0.0, 0.0, 1.0);
	
	glutDisplayFunc(display);
	glutMainLoop();
	
	return 0;
}
