#include <GL/glut.h>

void Bentuk(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(3.0f);

    // 1. GL_LINE_STRIP 
    glBegin(GL_LINE_STRIP);
        glColor3f(0.1f, 0.9f, 1.0f);
        glVertex3f(-0.90f, -0.10f, 0.0f);  
    	glVertex3f(-0.82f,  0.25f, 0.0f);  
    	glVertex3f(-0.74f, -0.10f, 0.0f);  
    	glVertex3f(-0.66f,  0.15f, 0.0f);  
    	glVertex3f(-0.58f, -0.10f, 0.0f);  
    glEnd();

    // 2. GL_LINE_LOOP 
    glBegin(GL_LINE_LOOP);
        glColor3f(1.0f, 0.6f, 0.8f);
        glVertex3f(-0.40f,  0.35f, 0.0f);
        glVertex3f(-0.25f,  0.35f, 0.0f);
        glVertex3f(-0.25f,  0.20f, 0.0f);
        glVertex3f(-0.40f,  0.20f, 0.0f);
    glEnd();

    // 3. GL_TRIANGLE_FAN 
    glBegin(GL_TRIANGLE_FAN);
        glColor3f(0.9f, 1.0f, 1.0f);
        glVertex3f(0.00f, 0.28f, 0.0f);
        glVertex3f(-0.08f, 0.38f, 0.0f);
        glVertex3f( 0.00f, 0.44f, 0.0f);
        glVertex3f( 0.08f, 0.38f, 0.0f);
        glVertex3f( 0.10f, 0.28f, 0.0f);
        glVertex3f( 0.08f, 0.18f, 0.0f);
        glVertex3f( 0.00f, 0.12f, 0.0f);
        glVertex3f(-0.08f, 0.18f, 0.0f);
        glVertex3f(-0.10f, 0.28f, 0.0f);
        glVertex3f(-0.08f, 0.38f, 0.0f);
    glEnd();

    // 4. GL_TRIANGLE_STRIP 
    glBegin(GL_TRIANGLE_STRIP);
        glColor3f(0.8f, 0.7f, 1.0f);
        glVertex3f(0.28f, 0.18f, 0.0f);
        glVertex3f(0.36f, 0.38f, 0.0f);
        glVertex3f(0.44f, 0.18f, 0.0f);
        glVertex3f(0.52f, 0.38f, 0.0f);
        glVertex3f(0.60f, 0.18f, 0.0f);
    glEnd();

    // 5. GL_QUADS
    glBegin(GL_QUADS);
        glColor3f(1.0f, 0.7f, 0.6f);
        glVertex3f(-0.20f, -0.20f, 0.0f);
        glVertex3f(-0.05f, -0.20f, 0.0f);
        glVertex3f(-0.05f, -0.35f, 0.0f);
        glVertex3f(-0.20f, -0.35f, 0.0f);
    glEnd();

    // 6. GL_QUAD_STRIP 
    glBegin(GL_QUAD_STRIP);
        glColor3f(0.8f, 1.0f, 0.8f);

        glVertex3f(0.15f, -0.20f, 0.0f);
        glVertex3f(0.15f, -0.35f, 0.0f);

        glVertex3f(0.25f, -0.15f, 0.0f);
        glVertex3f(0.25f, -0.40f, 0.0f);

        glVertex3f(0.35f, -0.20f, 0.0f);
        glVertex3f(0.35f, -0.35f, 0.0f);

        glVertex3f(0.45f, -0.15f, 0.0f);
        glVertex3f(0.45f, -0.40f, 0.0f);
    glEnd();

    glFlush();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Nomor 2");

    glutDisplayFunc(Bentuk);

    glClearColor(1.0f, 0.85f, 0.90f, 1.0f);

    glutMainLoop();
    return 0;
}
