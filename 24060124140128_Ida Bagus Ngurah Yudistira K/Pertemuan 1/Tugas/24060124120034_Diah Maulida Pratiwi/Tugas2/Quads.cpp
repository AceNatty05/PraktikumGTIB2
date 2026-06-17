#include <GL/glut.h>

void Quads(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glShadeModel(GL_FLAT);

    glBegin(GL_QUADS);
    glColor3d(0.5, 0.5, 0.5); 
    glVertex3d(-0.1, -0.5, 0.0);
    glVertex3d(-0.5, 0.2, 0.0);
    glVertex3d(0.0, 0.5, 0.0);
    glVertex3d(0.5, 0.0, 0.0);
    glEnd();

    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 400); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Jembatan GL_QUADS");
    glClearColor(0.5, 0.8, 1.0, 1.0);
    glutDisplayFunc(Quads);
    glutMainLoop();
    return 0;
}
