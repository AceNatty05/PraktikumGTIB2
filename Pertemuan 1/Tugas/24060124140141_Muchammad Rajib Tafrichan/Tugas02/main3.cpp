#include <GL/glut.h>
#include <gl/gl.h>
#include <math.h>


/*
void SegiEmpat(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glTranslatef(0.0, 0.0, 0.0);
    glColor3f(1.0f, 0.0f, 1.0f);
    glRectf(-0.18, 0.18, 0.18, -0.18);
    glRectf(-0.8, 0.1, 0.1, -0.8);
    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Segi Empat");
    glutDisplayFunc(SegiEmpat);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutMainLoop();
    return 0;
}

*/

void RenderScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Bagian 1: Menggambar Garis
    glPushMatrix(); 
        glLineWidth(2.0f); 
        glBegin(GL_LINES); 
            glColor3f(1.0f, 1.0f, 1.0f); 
            glVertex3f(0.00, 0.20, 0.0); 
            glVertex3f(0.00, -0.20, 0.0); 
        glEnd(); 
    glPopMatrix(); 
    
    
    // Bagian 2: Menggambar Titik dengan translasi
    glPushMatrix();
	    glTranslatef(0.35,0.5,0.0);
	    glBegin(GL_POINTS);
	    	glColor3f(0.80f,0.00f,1.00f);
	    	glVertex3f(0.25, 0.25, 0.0); 
	    glEnd();
	glPopMatrix();
    

 glFlush();
}

void Segitiga(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glRotated(90.0, 0.0, 0.0, 1.0);
    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f); glVertex3f(0.0, 0.0, 0.0);
        glColor3f(0.0f, 1.0f, 0.0f); glVertex3f(0.15, 0.0, 0.00);
        glColor3f(0.0f, 0.0f, 1.0f); glVertex3f(0.0, 0.15, 0.00);
    glEnd();
    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Segi Tiga");
    glutDisplayFunc(Segitiga);
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
    glutMainLoop();
    return 0;
}
