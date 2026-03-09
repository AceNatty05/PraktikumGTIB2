#include <GL/glut.h>

void point() {	
	glPointSize(6.0);
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POINTS);
	glVertex2f(-1.0, 1.0);
	glEnd();
}

void line() {
	glLineWidth(4.0);
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_LINES);
	glVertex2f(-1.0, -1.0);
	glVertex2f(1.0, 1.0);
	glEnd();
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	
	point();
	line();
	
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
