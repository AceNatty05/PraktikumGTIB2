#include <GL/glut.h>

static int rotasiBahuZ = 0, rotasiBahuY = 0, rotasiSiku = 0;
static int sudutTelapakX = -90, sudutTelapakZ = 0;

static int tlunjukPangkal = 0, tlunjukTengah = 0, tlunjukUjung = 0;
static int jariTengahPangkal = 0, jariTengahTengah = 0, jariTengahUjung = 0;
static int manisPangkal = 0, manisTengah = 0, manisUjung = 0;
static int klingkingPangkal = 0, klingkingTengah = 0, klingkingUjung = 0;

static int ibuJariSumbuX = 0, ibuJariSumbuY = 0, ibuJariUjung = 0;

int statusAktif = 0;

void pengaturanAwal(void) {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glShadeModel(GL_FLAT);
}

void renderLayar(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();

    glTranslatef(-1.8f, 0.0f, 0.0f);
    glRotatef((GLfloat)rotasiBahuZ, 0.0f, 0.0f, 1.0f);
    glRotatef((GLfloat)rotasiBahuY, 0.0f, 1.0f, 0.0f);
    glTranslatef(1.8f, 0.0f, 0.0f);
    
    glPushMatrix();
        glTranslatef(-1.4f, 0.0f, 0.0f);
        glScalef(0.85f, 0.35f, 0.70f); 
        glutWireCube(1.0f);
    glPopMatrix();

    glTranslatef(-1.0f, 0.0f, 0.0f);
    glRotatef((GLfloat)rotasiSiku, 0.0f, 0.0f, 1.0f);

    glTranslatef(1.4f, 0.0f, 0.0f); 
    
    glPushMatrix();
        glTranslatef(-0.7f, 0.0f, 0.0f);
        glScalef(1.25f, 0.32f, 0.65f); 
        glutWireCube(1.0f);
    glPopMatrix();

    // 3. BAGIAN TELAPAK TANGAN
    glRotatef((GLfloat)sudutTelapakX, 1.0f, 0.0f, 0.0f);
    glRotatef((GLfloat)sudutTelapakZ, 0.0f, 0.0f, 1.0f);
    
    glPushMatrix();
        glScalef(0.4f, 0.2f, 0.56f);
        glutWireCube(1.0f);
    glPopMatrix();

    // 4. BAGIAN IBU JARI
    glPushMatrix();
        glTranslatef(0.0f, 0.0f, 0.38f);
        glRotatef((GLfloat)-ibuJariSumbuX, 1.0f, 0.0f, 0.0f);
        glRotatef((GLfloat)ibuJariSumbuY, 0.0f, 1.0f, 0.0f);
        
        glPushMatrix();
            glScalef(0.1f, 0.1f, 0.2f);
            glutWireCube(1.0f);
        glPopMatrix();
        
        glTranslatef(0.0f, 0.0f, 0.2f);
        glRotatef((GLfloat)-ibuJariUjung, 1.0f, 0.0f, 0.0f);
        
        glPushMatrix();
            glScalef(0.1f, 0.1f, 0.25f);
            glutWireCube(1.0f);
        glPopMatrix();
    glPopMatrix();

    // 5. JARI TELUNJUK
    glPushMatrix();
        glTranslatef(0.3f, 0.0f, 0.22f);
        glRotatef((GLfloat)tlunjukPangkal, 0.0f, 0.0f, 1.0f);
        glPushMatrix();
            glScalef(0.2f, 0.1f, 0.13f);
            glutWireCube(1.0f);
        glPopMatrix();
        
        glTranslatef(0.2f, 0.0f, 0.0f);
        glRotatef((GLfloat)tlunjukTengah, 0.0f, 0.0f, 1.0f);
        glPushMatrix();
            glScalef(0.22f, 0.1f, 0.13f);
            glutWireCube(1.0f);
        glPopMatrix();
        
        glTranslatef(0.22f, 0.0f, 0.0f);
        glRotatef((GLfloat)tlunjukUjung, 0.0f, 0.0f, 1.0f);
        glPushMatrix();
            glScalef(0.21f, 0.1f, 0.13f);
            glutWireCube(1.0f);
        glPopMatrix();
    glPopMatrix();

    // 6. JARI TENGAH
    glPushMatrix();
        glTranslatef(0.3f, 0.0f, 0.05f);
        glRotatef((GLfloat)jariTengahPangkal, 0.0f, 0.0f, 1.0f);
        glPushMatrix();
            glScalef(0.25f, 0.1f, 0.14f);
            glutWireCube(1.0f);
        glPopMatrix();
        
        glTranslatef(0.25f, 0.0f, 0.0f);
        glRotatef((GLfloat)jariTengahTengah, 0.0f, 0.0f, 1.0f);
        glPushMatrix();
            glScalef(0.27f, 0.1f, 0.14f);
            glutWireCube(1.0f);
        glPopMatrix();
        
        glTranslatef(0.27f, 0.0f, 0.0f);
        glRotatef((GLfloat)jariTengahUjung, 0.0f, 0.0f, 1.0f);
        glPushMatrix();
            glScalef(0.21f, 0.1f, 0.14f);
            glutWireCube(1.0f);
        glPopMatrix();
    glPopMatrix();

    // 7. JARI MANIS
    glPushMatrix();
        glTranslatef(0.3f, 0.0f, -0.1f);
        glRotatef((GLfloat)manisPangkal, 0.0f, 0.0f, 1.0f);
        glPushMatrix();
            glScalef(0.2f, 0.1f, 0.11f);
            glutWireCube(1.0f);
        glPopMatrix();
        
        glTranslatef(0.2f, 0.0f, 0.0f);
        glRotatef((GLfloat)manisTengah, 0.0f, 0.0f, 1.0f);
        glPushMatrix();
            glScalef(0.21f, 0.1f, 0.11f);
            glutWireCube(1.0f);
        glPopMatrix();
        
        glTranslatef(0.21f, 0.0f, 0.0f);
        glRotatef((GLfloat)manisUjung, 0.0f, 0.0f, 1.0f);
        glPushMatrix();
            glScalef(0.2f, 0.1f, 0.11f);
            glutWireCube(1.0f);
        glPopMatrix();
    glPopMatrix();

    // 8. JARI KELINGKING
    glPushMatrix();
        glTranslatef(0.3f, 0.0f, -0.21f);
        glRotatef((GLfloat)klingkingPangkal, 0.0f, 0.0f, 1.0f);
        glPushMatrix();
            glScalef(0.18f, 0.1f, 0.1f);
            glutWireCube(1.0f);
        glPopMatrix();
        
        glTranslatef(0.18f, 0.0f, 0.0f);
        glRotatef((GLfloat)klingkingTengah, 0.0f, 0.0f, 1.0f);
        glPushMatrix();
            glScalef(0.17f, 0.1f, 0.1f);
            glutWireCube(1.0f);
        glPopMatrix();
        
        glTranslatef(0.17f, 0.0f, 0.0f);
        glRotatef((GLfloat)klingkingUjung, 0.0f, 0.0f, 1.0f);
        glPushMatrix();
            glScalef(0.19f, 0.1f, 0.1f);
            glutWireCube(1.0f);
        glPopMatrix();
    glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
}

void aturKamera(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -5.5f);
}

void controlKeyboard(unsigned char key, int x, int y) {
    if (key == '1') { statusAktif = 0; return; }
    if (key == '2') { statusAktif = 1; return; }
    
    // Reset posisi ke awal (Tombol TAB)
    if (key == 9) {
        klingkingPangkal = klingkingTengah = klingkingUjung = 0;
        rotasiBahuZ = rotasiBahuY = rotasiSiku = 0;
        manisPangkal = manisTengah = manisUjung = 0;
        jariTengahPangkal = jariTengahTengah = jariTengahUjung = 0;
        tlunjukPangkal = tlunjukTengah = tlunjukUjung = 0;
        ibuJariSumbuY = ibuJariSumbuX = ibuJariUjung = 0;
        sudutTelapakX = -90; 
        sudutTelapakZ = 0;
        glutPostRedisplay();
        return;
    }

    if (statusAktif == 0) {
        // PERGERAKAN LENGAN & TELAPAK
        switch (key) {
            case 'q': rotasiBahuZ += 5; if (rotasiBahuZ > 110) rotasiBahuZ = 110; break;
            case 'Q': rotasiBahuZ -= 5; if (rotasiBahuZ < -110) rotasiBahuZ = -110; break;

            case 'w': rotasiBahuY += 5; if (rotasiBahuY > 90) rotasiBahuY = 90; break;
            case 'W': rotasiBahuY -= 5; if (rotasiBahuY < -90) rotasiBahuY = -90; break;

            case 'a': rotasiSiku += 5; if (rotasiSiku > 120) rotasiSiku = 120; break;
            case 'A': rotasiSiku -= 5; if (rotasiSiku < 0) rotasiSiku = 0; break;

            case 'z': sudutTelapakX += 5; if (sudutTelapakX > 90) sudutTelapakX = 90; break;
            case 'Z': sudutTelapakX -= 5; if (sudutTelapakX < -90) sudutTelapakX = -90; break;

            case 'x': sudutTelapakZ += 5; if (sudutTelapakZ > 90) sudutTelapakZ = 90; break;
            case 'X': sudutTelapakZ -= 5; if (sudutTelapakZ < 0) sudutTelapakZ = 0; break;

            case 'c': ibuJariSumbuX += 5; if (ibuJariSumbuX > 90) ibuJariSumbuX = 90; break;
            case 'C': ibuJariSumbuX -= 5; if (ibuJariSumbuX < 0) ibuJariSumbuX = 0; break;
        }
    } 
    else if (statusAktif == 1) {
        // PERGERAKAN JARI-JARI TANGAN
        switch (key) {
            // Kontrol Telunjuk
            case 'q': tlunjukPangkal += 5; break;
            case 'a': tlunjukPangkal -= 5; break;
            case 'w': tlunjukTengah += 5; break;
            case 's': tlunjukTengah -= 5; break;
            case 'e': tlunjukUjung += 5; break;
            case 'd': tlunjukUjung -= 5; break;

            // Kontrol Jari Tengah
            case 'r': jariTengahPangkal += 5; break;
            case 'f': jariTengahPangkal -= 5; break;
            case 't': jariTengahTengah += 5; break;
            case 'g': jariTengahTengah -= 5; break;
            case 'y': jariTengahUjung += 5; break;
            case 'h': jariTengahUjung -= 5; break;

            // Kontrol Jari Manis
            case 'u': manisPangkal += 5; break;
            case 'j': manisPangkal -= 5; break;
            case 'i': manisTengah += 5; break;
            case 'k': manisTengah -= 5; break;
            case 'o': manisUjung += 5; break;
            case 'l': manisUjung -= 5; break;

            // Kontrol Kelingking
            case 'z': klingkingPangkal += 5; break;
            case 'x': klingkingPangkal -= 5; break;
            case 'c': klingkingTengah += 5; break;
            case 'v': klingkingTengah -= 5; break;
            case 'b': klingkingUjung += 5; break;
            case 'n': klingkingUjung -= 5; break;

            // Kontrol Ibu Jari
            case 'p': ibuJariSumbuY += 5; break;
            case ';': ibuJariSumbuY -= 5; break;
            case '[': ibuJariUjung += 5; break;
            case ']': ibuJariUjung -= 5; break;
        }
    }

    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(700, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Tugas 3");
    
    pengaturanAwal();
    glutDisplayFunc(renderLayar);
    glutReshapeFunc(aturKamera);
    glutKeyboardFunc(controlKeyboard);
    
    glutMainLoop();
    return 0;
}
