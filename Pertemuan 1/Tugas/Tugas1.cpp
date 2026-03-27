#include <GL/glut.h>

void displayPrimitif(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    
    glColor3f(.9f, 0.9f, 0.9f);
    glBegin(GL_LINE_STRIP);
        glVertex2f(-1.0, 0.5);
        glVertex2f(-0.5, 1.0);
        glVertex2f(-0.5, 0.5);
    glEnd();

    
    glColor3f(0.0f, 0.6f, 0.0f);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.9, 0.4);
        glVertex2f(-0.5, 0.4);
        glVertex2f(-0.7, 0.6);
    glEnd();

    
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.5, 0.5);
        glVertex2f(0.5, -0.5);
        glVertex2f(-0.5, -0.5);
        glVertex2f(-0.5, 0.5);
    glEnd();

   
    glColor3f(1.0f, 0.0f, 1.0f);
    glBegin(GL_TRIANGLE_STRIP);
        glVertex2f(1.3, 1.1);
        glVertex2f(1.3, -1.1);
        glVertex2f(1.5, 1.1);
        glVertex2f(1.5, -1.1);
    glEnd();

    
    glColor3f(0.2f, 0.2f, 0.2f);
    glBegin(GL_QUADS);
        glVertex2f(0.3, 0.1);
        glVertex2f(0.3, -0.1);
        glVertex2f(0.5, -0.1);
        glVertex2f(0.5, 0.1);
    glEnd();

    
    glColor3f(1.0f, 0.5f, 0.0f);
    glBegin(GL_QUAD_STRIP);
        glVertex2f(0.3, -0.1);
        glVertex2f(0.3, -0.4);
        glVertex2f(0.5, -0.1);
        glVertex2f(0.5, -0.4);
    glEnd();

    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Primitif");
    glutDisplayFunc(displayPrimitif);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutMainLoop();
    return 0;
}