#include <GL/glut.h>

void RenderKarakter(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    // 1. BADAN (biru)
    glColor3f(0.0f, 0.0f, 1.0f); // biru
    glRectf(-0.25f, -0.3f, 0.25f, 0.2f);

    // 2. KEPALA (krem)
    // Dibuat lebih lebar sedikit dari badan sesuai sketsa
    glColor3f(1.0f, 0.90f, 0.7f);
    glRectf(-0.35f, 0.2f, 0.35f, 0.6f);

    // 3. MATA KIRI 
    glColor3f(1.0f, 1.0f, 1.0f); 
    glRectf(-0.25f, 0.35f, -0.1f, 0.5f);
    glColor3f(0.0f, 0.0f, 0.0f); 
	glRectf(-0.15f, 0.38f, -0.1f, 0.47f);


    // 4. MATA KANAN 
    glColor3f(1.0f, 1.0f, 1.0f); 
    glRectf(0.1f, 0.35f, 0.25f, 0.5f);
    glColor3f(0.0f, 0.0f, 0.0f); 
    glRectf(0.20f, 0.38f, 0.25f, 0.47f);

    // 5. MULUT 
    glColor3f(0.5f, 0.0f, 0.0f);
    glRectf(-0.08f, 0.25f, 0.08f, 0.32f);

    // 6. KAKI KIRI 
    glColor3f(1.0f, 0.9f, 0.5f);
    glRectf(-0.25f, -0.7f, -0.02f, -0.3f);

    // 7. KAKI KANAN 
    glRectf(0.02f, -0.7f, 0.25f, -0.3f);
    
    // 8. TANGAN KIRI (Dari sudut pandang kita, menempel di sisi kiri badan)
    glRectf(-0.45f, -0.18f, -0.25f, 0.18f);

    // 9. TANGAN KANAN (Dari sudut pandang kita, menempel di sisi kanan badan)
    glRectf(0.25f, -0.18f, 0.45f, 0.18f);

    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Karakter roblox");
    
    // Warna background (Putih agar karakter terlihat jelas)
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); 
    
    glutDisplayFunc(RenderKarakter);
    glutMainLoop();
    return 0;
}
