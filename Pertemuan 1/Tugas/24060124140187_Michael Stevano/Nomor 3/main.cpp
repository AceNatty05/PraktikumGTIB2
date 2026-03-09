#include <GL/glut.h>

void rectangles() {
	glColor3f(0.8, 0.8, 0.8);
	glRectf(-0.9, -1.0, -0.65, 0.6);
	glRectf(-0.55, -1.0, -0.30, 0.6);
	
	glColor3f(1.0, 1.0, 1.0);
	glRectf(0.0, 0.2, 0.6, 0.35);
	glRectf(0.25, 0.0, 0.35, 0.5);
	glRectf(0.5, 0.2 , 0.6, 0.45);
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	
	rectangles();
	
	glFlush();
}

int main(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1280, 720);
	glutCreateWindow("Tugas 1");
	glClearColor(0.5, 0.9, 1.0, 1.0);
	
	glutDisplayFunc(display);
	glutMainLoop();
	
	return 0;
}
