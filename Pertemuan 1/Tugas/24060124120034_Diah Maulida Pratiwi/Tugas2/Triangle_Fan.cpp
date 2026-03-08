#include <GL/glut.h>

void TriangleFan(void) {
    glClear(GL_COLOR_BUFFER_BIT);
	// Ini memastikan setiap segitiga memiliki warna padat tunggal.
    glShadeModel(GL_FLAT);
    glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0f, 1.0f, 1.0f); // Putih (diabaikan)
    glVertex3f(0.0f, 0.0f, 0.0f); // Titik Tengah
    glColor3f(1.0f, 0.0f, 0.0f); // Merah
    glVertex3f(0.0f, 0.8f, 0.0f); // Atas
	glColor3f(1.0f, 0.5f, 0.0f); // Oranye
    glVertex3f(0.5f, 0.5f, 0.0f); // Kanan Atas
	glColor3f(1.0f, 1.0f, 0.0f); // Kuning
    glVertex3f(0.8f, 0.0f, 0.0f); // Kanan
    glColor3f(0.0f, 1.0f, 0.0f); // Hijau
    glVertex3f(0.5f, -0.5f, 0.0f); // Kanan Bawah
    glColor3f(0.0f, 0.0f, 1.0f); // Biru
	glVertex3f(0.0f, -0.8f, 0.0f); // Bawah
	glColor3f(0.5f, 0.0f, 1.0f); // Ungu
    glVertex3f(-0.5f, -0.5f, 0.0f); // Kiri Bawah
	glColor3f(0.0f, 1.0f, 1.0f); // Cyan
    glVertex3f(-0.8f, 0.0f, 0.0f); // Kiri
	glColor3f(1.0f, 0.0f, 1.0f); // Magenta
    glVertex3f(-0.5f, 0.5f, 0.0f); // Kiri Atas
	glColor3f(1.0f, 0.0f, 0.0f); // Merah
    glVertex3f(0.0f, 0.8f, 0.0f); // Atas lagi
    glEnd();
    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 640);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Implementasi GL_TRIANGLE_FAN");
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f); // Latar Biru
    glutDisplayFunc(TriangleFan);
    glutMainLoop();
    return 0;
}
