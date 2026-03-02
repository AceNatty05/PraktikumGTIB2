#include <GL/glut.h>

void drawSquare(float size) {
    glBegin(GL_POLYGON);
        glVertex2f(-size,  size);
        glVertex2f( size,  size);
        glVertex2f( size, -size);
        glVertex2f(-size, -size);
    glEnd();

    
    glColor3f(0, 0, 0); 
    glBegin(GL_LINE_LOOP);
        glVertex2f(-size,  size);
        glVertex2f( size,  size);
        glVertex2f( size, -size);
        glVertex2f(-size, -size);
    glEnd();
}

void SegiEmpat() {
    glClear(GL_COLOR_BUFFER_BIT);

    float size = 0.6f;

    for (int i = 0; i < 5; i++) {
        glPushMatrix();


        if (i % 2 == 1) {
            glRotatef(45, 0, 0, 1);
        }

        
        glColor3f(1, 0, 0);
        drawSquare(size);

        glPopMatrix();

        size *= 0.7f; 
    }

    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Squares with Borders");

    glutDisplayFunc(SegiEmpat);
    glClearColor(0, 0, 1, 1);

    glutMainLoop();
    return 0;
}
