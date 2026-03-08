#include <GL/glut.h>

void TitikGaris(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(8.0f);
    glBegin(GL_POINTS);
    glColor3f(1.0f, 0.0f, 0.0f); 
    glVertex3f(-0.20f, 0.20f, 0.0f); // titik kiri
    glVertex3f(0.20f, 0.20f, 0.0f);  // titik kanan
    glEnd();

    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glColor3f(0.0f, 1.0f, 0.0f);

    // garis kiri
    glVertex3f(-0.20f, 0.20f, 0.0f);
    glVertex3f(0.00f, -0.20f, 0.0f);

    // garis kanan
    glVertex3f(0.20f, 0.20f, 0.0f);
    glVertex3f(0.00f, -0.20f, 0.0f);

    glEnd();

    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Titik dan Garis");

    glutDisplayFunc(TitikGaris);

    glClearColor(1.0f, 1.0f, 0.2f, 0.2f); 

    glutMainLoop();
    return 0;
}
