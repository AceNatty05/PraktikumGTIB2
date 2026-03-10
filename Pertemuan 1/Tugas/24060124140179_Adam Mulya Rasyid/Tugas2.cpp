#include <gl/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // GL_LINE_STRIP (kiri atas)
    glBegin(GL_LINE_STRIP);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(-0.8f, 0.8f, 0.0f);
        glVertex3f(-0.5f, 0.6f, 0.0f);
        glVertex3f(-0.2f, 0.8f, 0.0f);
        glVertex3f(0.0f, 0.5f, 0.0f);
    glEnd();

    // GL_LINE_LOOP (kanan atas)
    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(0.2f, 0.8f, 0.0f);
        glVertex3f(0.5f, 0.8f, 0.0f);
        glVertex3f(0.7f, 0.5f, 0.0f);
        glVertex3f(0.4f, 0.5f, 0.0f);
    glEnd();

    // GL_TRIANGLE_FAN (tengah)
    glBegin(GL_TRIANGLE_FAN);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f(0.0f, 0.0f, 0.0f); // pusat
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(-0.2f, -0.1f, 0.0f);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(0.0f, -0.3f, 0.0f);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f(0.2f, -0.1f, 0.0f);
    glEnd();

    // GL_TRIANGLE_STRIP (kiri bawah)
    glBegin(GL_TRIANGLE_STRIP);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex3f(-0.8f, -0.4f, 0.0f);
        glVertex3f(-0.5f, -0.6f, 0.0f);
        glVertex3f(-0.6f, -0.2f, 0.0f);
        glVertex3f(-0.3f, -0.4f, 0.0f);
    glEnd();

    // GL_QUADS (kanan bawah)
    glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 1.0f);
        glVertex3f(0.5f, -0.2f, 0.0f);
        glVertex3f(0.8f, -0.2f, 0.0f);
        glVertex3f(0.8f, -0.5f, 0.0f);
        glVertex3f(0.5f, -0.5f, 0.0f);
    glEnd();

    // GL_QUAD_STRIP (bawah tengah)
    glBegin(GL_QUAD_STRIP);
        glColor3f(0.0f, 1.0f, 1.0f);
        glVertex3f(-0.3f, -0.7f, 0.0f);
        glVertex3f(-0.1f, -0.9f, 0.0f);
        glVertex3f(0.0f, -0.7f, 0.0f);
        glVertex3f(0.2f, -0.9f, 0.0f);
        glVertex3f(0.3f, -0.7f, 0.0f);
        glVertex3f(0.5f, -0.9f, 0.0f);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Tugas 2: Berbagai Primitif");
    glutDisplayFunc(display);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutMainLoop();
    return 0;
}
