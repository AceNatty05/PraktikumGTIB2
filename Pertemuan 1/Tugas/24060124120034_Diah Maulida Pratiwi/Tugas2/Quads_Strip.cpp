#include <GL/glut.h>

void QStrip(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glShadeModel(GL_FLAT);

    glBegin(GL_QUAD_STRIP);
    glColor3d(0.7, 0.7, 0.7);
	// Pasangan 1 (A & B)
    glVertex2d(-0.6, 0.6);
    glVertex2d(-0.2, 0.8);

    // Pasangan 2 (C & D)
    glColor3d(0.5, 0.5, 0.5);
    glVertex2d(-0.5, 0.3);
    glVertex2d(-0.1, 0.5);

    // Pasangan 3 (E & F)
    glColor3d(0.7, 0.7, 0.7);
    glVertex2d(-0.3, 0.1);
    glVertex2d( 0.1, 0.3);

    // Pasangan 4 (G & H)
    glColor3d(0.5, 0.5, 0.5);
    glVertex2d(-0.1, -0.1);
    glVertex2d( 0.3, 0.1);

    // Pasangan 5 (I & J)
    glColor3d(0.7, 0.7, 0.7);
    glVertex2d( 0.2, -0.3);
    glVertex2d( 0.5, -0.1);

    // Pasangan 6 (K & L)
    glColor3d(0.5, 0.5, 0.5);
    glVertex2d( 0.4, -0.6);
    glVertex2d( 0.7, -0.4);
    glEnd();

    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 400); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Implementasi GL_QUADS_STRIP");
    glClearColor(0.5, 0.8, 1.0, 1.0);
    glutDisplayFunc(QStrip);
    glutMainLoop();
    return 0;
}
