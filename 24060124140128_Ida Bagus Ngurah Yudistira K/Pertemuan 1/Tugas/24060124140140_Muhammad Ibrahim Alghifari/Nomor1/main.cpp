//Nama: Muhammad Ibrahim Alghifari
//NIM: 24060124140140
//Lab: B2
#include <GL/glut.h>

void displayDasar(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    
    glPointSize(10.0f);
    glBegin(GL_POINTS);
        glColor3f(1.0f, 0.0f, 0.0f); 
        glVertex2f(-0.5, 0.5);
        glVertex2f(0.5, 0.5);
    glEnd();

   
    glLineWidth(3.0f);
    glBegin(GL_LINES);
        glColor3f(0.0f, 0.0f, 0.0f); 
        glVertex2f(-0.5, -0.5);
        glVertex2f(0.5, -0.5);
    glEnd();

    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Titik dan Garis");
    glutDisplayFunc(displayDasar);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutMainLoop();
    return 0;
}
