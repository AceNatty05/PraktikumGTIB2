#include <GL/glut.h>

void TriangleStrip(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glShadeModel(GL_FLAT);

    glBegin(GL_TRIANGLE_STRIP);
    glColor3d(0.5, 0.5, 0.5); 
    glVertex3d(-0.9, -0.2, 0.0);
    glColor3d(0.7, 0.7, 0.7);
    glVertex3d(-0.9,  0.2, 0.0);
        
    glColor3d(0.5, 0.5, 0.5); 
    glVertex3d(-0.5, -0.2, 0.0); 
    glColor3d(0.7, 0.7, 0.7); 
    glVertex3d(-0.5,  0.2, 0.0); 

    glColor3d(0.5, 0.5, 0.5);
    glVertex3d(0.0, -0.2, 0.0);
    glColor3d(0.7, 0.7, 0.7);
    glVertex3d(0.0,  0.2, 0.0);
    
    glColor3d(0.5, 0.5, 0.5);
    glVertex3d(0.5, -0.2, 0.0);
    glColor3d(0.7, 0.7, 0.7);
    glVertex3d(0.5,  0.2, 0.0);

    glColor3d(0.5, 0.5, 0.5);
    glVertex3d(0.9, -0.2, 0.0);
    glColor3d(0.7, 0.7, 0.7);
    glVertex3d(0.9,  0.2, 0.0);
    glEnd();

    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 400); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Jembatan GL_TRIANGLE_STRIP");
    glClearColor(0.5, 0.8, 1.0, 1.0);
    glutDisplayFunc(TriangleStrip);
    glutMainLoop();
    return 0;
}
