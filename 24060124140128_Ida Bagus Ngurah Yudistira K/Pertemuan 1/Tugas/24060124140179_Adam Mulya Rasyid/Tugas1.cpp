#include <gl/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Gambar titik (GL_POINTS)
    glPointSize(10.0f);
    glBegin(GL_POINTS);
        glColor3f(1.0f, 0.0f, 0.0f); // merah
        glVertex3f(-0.5f, 0.5f, 0.0f);
        glColor3f(0.0f, 1.0f, 0.0f); // hijau
        glVertex3f(0.5f, 0.5f, 0.0f);
        glColor3f(0.0f, 0.0f, 1.0f); // biru
        glVertex3f(0.0f, 0.0f, 0.0f);
    glEnd();

    // Gambar garis (GL_LINES)
    glLineWidth(3.0f);
    glBegin(GL_LINES);
        glColor3f(1.0f, 1.0f, 0.0f); // kuning
        glVertex3f(-0.8f, -0.2f, 0.0f);
        glVertex3f(-0.2f, -0.8f, 0.0f);

        glColor3f(1.0f, 0.0f, 1.0f); // magenta
        glVertex3f(0.2f, -0.2f, 0.0f);
        glVertex3f(0.8f, -0.8f, 0.0f);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Tugas 1: Titik dan Garis");
    glutDisplayFunc(display);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // latar hitam
    glutMainLoop();
    return 0;
}
