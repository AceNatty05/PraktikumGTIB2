#include <GL/glut.h>

// =================================================================
// Nama: Birela Miadeta Purita
// Lab:  B2
// NIM:  24060124120002
// Tujuan: Tugas 1 - Mengimplementasikan berbagai Grafik Primitif Dasar
// =================================================================

void displayPrimitif(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // 1. GL_POINTS (Titik)
    glPointSize(10.0f); 
    glBegin(GL_POINTS);  
        glColor3f(1.0f, 0.0f, 0.0f); // Warna Merah 
        glVertex2f(-0.7, 0.7); 
    glEnd();

    // 2. GL_LINES (Garis)
    glLineWidth(3.0f); 
    glBegin(GL_LINES); 
        glColor3f(1.0f, 1.0f, 1.0f); // Warna Putih 
        glVertex2f(-0.8, 0.4);
        glVertex2f(-0.4, 0.4);
    glEnd();

    // 3. GL_LINE_STRIP (Garis bersambung terbuka)
    glColor3f(0.0f, 1.0f, 0.0f); // Warna Hijau 
    glBegin(GL_LINE_STRIP); 
        glVertex2f(0.1, 0.7);
        glVertex2f(0.3, 0.9);
        glVertex2f(0.5, 0.7);
    glEnd();

    // 4. GL_LINE_LOOP (Garis bersambung tertutup)
    glColor3f(0.0f, 1.0f, 1.0f); // Warna Cyan
    glBegin(GL_LINE_LOOP); 
        glVertex2f(0.6, 0.7);
        glVertex2f(0.8, 0.9);
        glVertex2f(0.9, 0.7);
    glEnd();

    // 5. GL_TRIANGLE_FAN (Segitiga menyebar dari satu pusat)
    glColor3f(1.0f, 1.0f, 0.0f); // Warna Kuning
    glBegin(GL_TRIANGLE_FAN);  
        glVertex2f(-0.6, -0.2); 
        glVertex2f(-0.8, -0.4);
        glVertex2f(-0.6, -0.6);
        glVertex2f(-0.4, -0.4);
    glEnd();

    // 6. GL_TRIANGLE_STRIP (Segitiga bersambung)
    glColor3f(1.0f, 0.0f, 1.0f); // Warna Ungu
    glBegin(GL_TRIANGLE_STRIP); 
        glVertex2f(0.1, -0.4);
        glVertex2f(0.2, -0.2);
        glVertex2f(0.3, -0.4);
        glVertex2f(0.4, -0.2);
    glEnd();

    // 7. GL_QUADS (Segiempat)
    glColor3f(1.0f, 0.5f, 0.0f); // Warna Oranye
    glBegin(GL_QUADS); 
        glVertex2f(0.6, -0.2);
        glVertex2f(0.9, -0.2);
        glVertex2f(0.9, -0.5);
        glVertex2f(0.6, -0.5);
    glEnd();

    // 8. GL_QUAD_STRIP (Segiempat bersambung)
    glColor3f(0.5f, 0.5f, 1.0f); // Warna Biru 
    glBegin(GL_QUAD_STRIP); // 
        glVertex2f(-0.2, -0.7);
        glVertex2f(-0.2, -0.9);
        glVertex2f(0.2, -0.7);
        glVertex2f(0.2, -0.9);
        glVertex2f(0.6, -0.7);
        glVertex2f(0.6, -0.9);
    glEnd();
    glFlush(); 
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); 
    glutCreateWindow("Tugas 1 - Soal no 1 & 2");
    glutDisplayFunc(displayPrimitif); 
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
    glutMainLoop();
    return 0;
}