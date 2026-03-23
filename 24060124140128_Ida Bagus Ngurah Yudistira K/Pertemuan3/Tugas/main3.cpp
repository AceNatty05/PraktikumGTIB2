//Nama : Ida Bagus Ngurah Yudistira K
//NIM : 24060124140128

#include <GL/glut.h>

static int rotasiBahuZ = 0, rotasiBahuY = 0, rotasiSiku = 0;
static int sudutTelapakX = -90, sudutTelapakZ = 0;

static int tlunjukPangkal = 0, tlunjukTengah = 0, tlunjukUjung = 0;
static int jariTengahPangkal = 0, jariTengahTengah = 0, jariTengahUjung = 0;
static int manisPangkal = 0, manisTengah = 0, manisUjung = 0;
static int klingkingPangkal = 0, klingkingTengah = 0, klingkingUjung = 0;
static int ibuJariSumbuX = 0, ibuJariSumbuY = 0, ibuJariUjung = 0;


int clamp(int val, int minVal, int maxVal) {
    if (val < minVal) return minVal;
    if (val > maxVal) return maxVal;
    return val;
}

void pengaturanAwal(void) {
    glClearColor(0.1f, 0.1f, 0.1f, 0.0f);
    glShadeModel(GL_FLAT);
}

void renderLayar(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();

    // BAHU
    glTranslatef(-1.8f, 0.0f, 0.0f);
    glRotatef((GLfloat)rotasiBahuZ, 0.0f, 0.0f, 1.0f);
    glRotatef((GLfloat)rotasiBahuY, 0.0f, 1.0f, 0.0f);
    glTranslatef(1.8f, 0.0f, 0.0f);

    glPushMatrix();
        glTranslatef(-1.4f, 0.0f, 0.0f);
        glScalef(0.85f, 0.35f, 0.70f);
        glutWireCube(1.0f);
    glPopMatrix();

    // SIKU
    glTranslatef(-1.0f, 0.0f, 0.0f);
    glRotatef((GLfloat)rotasiSiku, 0.0f, 0.0f, 1.0f);
    glTranslatef(1.4f, 0.0f, 0.0f);

    glPushMatrix();
        glTranslatef(-0.7f, 0.0f, 0.0f);
        glScalef(1.25f, 0.32f, 0.65f);
        glutWireCube(1.0f);
    glPopMatrix();

    // TELAPAK
    glRotatef((GLfloat)sudutTelapakX, 1.0f, 0.0f, 0.0f);
    glRotatef((GLfloat)sudutTelapakZ, 0.0f, 0.0f, 1.0f);

    glPushMatrix();
        glScalef(0.4f, 0.2f, 0.56f);
        glutWireCube(1.0f);
    glPopMatrix();

    // IBU JARI
    glPushMatrix();
        glTranslatef(0.0f, 0.0f, 0.38f);
        glRotatef((GLfloat)-ibuJariSumbuX, 1.0f, 0.0f, 0.0f);
        glRotatef((GLfloat)ibuJariSumbuY,  0.0f, 1.0f, 0.0f);
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

    // TELUNJUK
    glPushMatrix();
        glTranslatef(0.3f, 0.0f, 0.22f);
        glRotatef((GLfloat)tlunjukPangkal, 0.0f, 0.0f, 1.0f);
        glPushMatrix(); glScalef(0.20f, 0.1f, 0.13f); glutWireCube(1.0f); glPopMatrix();
        glTranslatef(0.20f, 0.0f, 0.0f);
        glRotatef((GLfloat)tlunjukTengah, 0.0f, 0.0f, 1.0f);
        glPushMatrix(); glScalef(0.22f, 0.1f, 0.13f); glutWireCube(1.0f); glPopMatrix();
        glTranslatef(0.22f, 0.0f, 0.0f);
        glRotatef((GLfloat)tlunjukUjung, 0.0f, 0.0f, 1.0f);
        glPushMatrix(); glScalef(0.21f, 0.1f, 0.13f); glutWireCube(1.0f); glPopMatrix();
    glPopMatrix();

    // JARI TENGAH
    glPushMatrix();
        glTranslatef(0.3f, 0.0f, 0.05f);
        glRotatef((GLfloat)jariTengahPangkal, 0.0f, 0.0f, 1.0f);
        glPushMatrix(); glScalef(0.25f, 0.1f, 0.14f); glutWireCube(1.0f); glPopMatrix();
        glTranslatef(0.25f, 0.0f, 0.0f);
        glRotatef((GLfloat)jariTengahTengah, 0.0f, 0.0f, 1.0f);
        glPushMatrix(); glScalef(0.27f, 0.1f, 0.14f); glutWireCube(1.0f); glPopMatrix();
        glTranslatef(0.27f, 0.0f, 0.0f);
        glRotatef((GLfloat)jariTengahUjung, 0.0f, 0.0f, 1.0f);
        glPushMatrix(); glScalef(0.21f, 0.1f, 0.14f); glutWireCube(1.0f); glPopMatrix();
    glPopMatrix();

    // JARI MANIS
    glPushMatrix();
        glTranslatef(0.3f, 0.0f, -0.10f);
        glRotatef((GLfloat)manisPangkal, 0.0f, 0.0f, 1.0f);
        glPushMatrix(); glScalef(0.20f, 0.1f, 0.11f); glutWireCube(1.0f); glPopMatrix();
        glTranslatef(0.20f, 0.0f, 0.0f);
        glRotatef((GLfloat)manisTengah, 0.0f, 0.0f, 1.0f);
        glPushMatrix(); glScalef(0.21f, 0.1f, 0.11f); glutWireCube(1.0f); glPopMatrix();
        glTranslatef(0.21f, 0.0f, 0.0f);
        glRotatef((GLfloat)manisUjung, 0.0f, 0.0f, 1.0f);
        glPushMatrix(); glScalef(0.20f, 0.1f, 0.11f); glutWireCube(1.0f); glPopMatrix();
    glPopMatrix();

    // KELINGKING
    glPushMatrix();
        glTranslatef(0.3f, 0.0f, -0.23f);
        glRotatef((GLfloat)klingkingPangkal, 0.0f, 0.0f, 1.0f);
        glPushMatrix(); glScalef(0.18f, 0.1f, 0.10f); glutWireCube(1.0f); glPopMatrix();
        glTranslatef(0.18f, 0.0f, 0.0f);
        glRotatef((GLfloat)klingkingTengah, 0.0f, 0.0f, 1.0f);
        glPushMatrix(); glScalef(0.17f, 0.1f, 0.10f); glutWireCube(1.0f); glPopMatrix();
        glTranslatef(0.17f, 0.0f, 0.0f);
        glRotatef((GLfloat)klingkingUjung, 0.0f, 0.0f, 1.0f);
        glPushMatrix(); glScalef(0.19f, 0.1f, 0.10f); glutWireCube(1.0f); glPopMatrix();
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

    if (key == 9) {
        rotasiBahuZ = rotasiBahuY = rotasiSiku = 0;
        sudutTelapakX = -90; sudutTelapakZ = 0;
        tlunjukPangkal = tlunjukTengah = tlunjukUjung = 0;
        jariTengahPangkal = jariTengahTengah = jariTengahUjung = 0;
        manisPangkal = manisTengah = manisUjung = 0;
        klingkingPangkal = klingkingTengah = klingkingUjung = 0;
        ibuJariSumbuX = ibuJariSumbuY = ibuJariUjung = 0;
        glutPostRedisplay();
        return;
    }

    if (key == 27) exit(0); 

    switch (key) {

        // LENGAN & TELAPAK 
        case 'q': rotasiBahuZ = clamp(rotasiBahuZ + 5, -110, 110); break;
        case 'Q': rotasiBahuZ = clamp(rotasiBahuZ - 5, -110, 110); break;

        case 'w': rotasiBahuY = clamp(rotasiBahuY + 5, -90, 90);   break;
        case 'W': rotasiBahuY = clamp(rotasiBahuY - 5, -90, 90);   break;

        case 'a': rotasiSiku  = clamp(rotasiSiku  + 5,   0, 120);  break;
        case 'A': rotasiSiku  = clamp(rotasiSiku  - 5,   0, 120);  break;

        case 'z': sudutTelapakX = clamp(sudutTelapakX + 5, -90, 90); break;
        case 'Z': sudutTelapakX = clamp(sudutTelapakX - 5, -90, 90); break;

        case 'x': sudutTelapakZ = clamp(sudutTelapakZ + 5, -45, 45); break;
        case 'X': sudutTelapakZ = clamp(sudutTelapakZ - 5, -45, 45); break;

        // IBU JARI
        case 'c': ibuJariSumbuX = clamp(ibuJariSumbuX + 5,   0, 90); break;
        case 'C': ibuJariSumbuX = clamp(ibuJariSumbuX - 5,   0, 90); break;

        case 'v': ibuJariSumbuY = clamp(ibuJariSumbuY + 5, -45, 45); break;
        case 'V': ibuJariSumbuY = clamp(ibuJariSumbuY - 5, -45, 45); break;

        case 'b': ibuJariUjung  = clamp(ibuJariUjung  + 5,   0, 80); break;
        case 'B': ibuJariUjung  = clamp(ibuJariUjung  - 5,   0, 80); break;

        // TELUNJUK
        case 'r': tlunjukPangkal = clamp(tlunjukPangkal - 5, -90, 0); break;
        case 'R': tlunjukPangkal = clamp(tlunjukPangkal + 5, -90, 0); break;

        case 'e': tlunjukTengah  = clamp(tlunjukTengah  - 5, -90, 0); break;
        case 'E': tlunjukTengah  = clamp(tlunjukTengah  + 5, -90, 0); break;

        case 'd': tlunjukUjung   = clamp(tlunjukUjung   - 5, -90, 0); break;
        case 'D': tlunjukUjung   = clamp(tlunjukUjung   + 5, -90, 0); break;

        // JARI TENGAH
        case 't': jariTengahPangkal = clamp(jariTengahPangkal - 5, -90, 0); break;
        case 'T': jariTengahPangkal = clamp(jariTengahPangkal + 5, -90, 0); break;

        case 'y': jariTengahTengah  = clamp(jariTengahTengah  - 5, -90, 0); break;
        case 'Y': jariTengahTengah  = clamp(jariTengahTengah  + 5, -90, 0); break;

        case 'h': jariTengahUjung   = clamp(jariTengahUjung   - 5, -90, 0); break;
        case 'H': jariTengahUjung   = clamp(jariTengahUjung   + 5, -90, 0); break;

        // JARI MANIS
        case 'u': manisPangkal = clamp(manisPangkal - 5, -90, 0); break;
        case 'U': manisPangkal = clamp(manisPangkal + 5, -90, 0); break;

        case 'o': manisTengah  = clamp(manisTengah  - 5, -90, 0); break;
        case 'O': manisTengah  = clamp(manisTengah  + 5, -90, 0); break;

        case 'l': manisUjung   = clamp(manisUjung   - 5, -90, 0); break;
        case 'L': manisUjung   = clamp(manisUjung   + 5, -90, 0); break;

        // KELINGKING
        case 'i': klingkingPangkal = clamp(klingkingPangkal - 5, -90, 0); break;
        case 'I': klingkingPangkal = clamp(klingkingPangkal + 5, -90, 0); break;

        case 'p': klingkingTengah  = clamp(klingkingTengah  - 5, -90, 0); break;
        case 'P': klingkingTengah  = clamp(klingkingTengah  + 5, -90, 0); break;

        case ';': klingkingUjung   = clamp(klingkingUjung   - 5, -90, 0); break;
        case '\'':klingkingUjung   = clamp(klingkingUjung   + 5, -90, 0); break;

        // KEPALAN & BUKA SEMUA JARI
        case 'f':
            tlunjukPangkal    = clamp(tlunjukPangkal    - 5, -90, 0);
            tlunjukTengah     = clamp(tlunjukTengah     - 5, -90, 0);
            tlunjukUjung      = clamp(tlunjukUjung      - 5, -90, 0);
            jariTengahPangkal = clamp(jariTengahPangkal - 5, -90, 0);
            jariTengahTengah  = clamp(jariTengahTengah  - 5, -90, 0);
            jariTengahUjung   = clamp(jariTengahUjung   - 5, -90, 0);
            manisPangkal      = clamp(manisPangkal      - 5, -90, 0);
            manisTengah       = clamp(manisTengah       - 5, -90, 0);
            manisUjung        = clamp(manisUjung        - 5, -90, 0);
            klingkingPangkal  = clamp(klingkingPangkal  - 5, -90, 0);
            klingkingTengah   = clamp(klingkingTengah   - 5, -90, 0);
            klingkingUjung    = clamp(klingkingUjung    - 5, -90, 0);
            ibuJariSumbuX     = clamp(ibuJariSumbuX     + 5,   0, 90);
            break;

        case 'g':
            tlunjukPangkal    = clamp(tlunjukPangkal    + 5, -90, 0);
            tlunjukTengah     = clamp(tlunjukTengah     + 5, -90, 0);
            tlunjukUjung      = clamp(tlunjukUjung      + 5, -90, 0);
            jariTengahPangkal = clamp(jariTengahPangkal + 5, -90, 0);
            jariTengahTengah  = clamp(jariTengahTengah  + 5, -90, 0);
            jariTengahUjung   = clamp(jariTengahUjung   + 5, -90, 0);
            manisPangkal      = clamp(manisPangkal      + 5, -90, 0);
            manisTengah       = clamp(manisTengah       + 5, -90, 0);
            manisUjung        = clamp(manisUjung        + 5, -90, 0);
            klingkingPangkal  = clamp(klingkingPangkal  + 5, -90, 0);
            klingkingTengah   = clamp(klingkingTengah   + 5, -90, 0);
            klingkingUjung    = clamp(klingkingUjung    + 5, -90, 0);
            ibuJariSumbuX     = clamp(ibuJariSumbuX     - 5,   0, 90);
            break;

        default: break;
    }

    glutPostRedisplay();
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(700, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Animasi Lengan - GTI Pertemuan 3");

    pengaturanAwal();

    glutDisplayFunc(renderLayar);
    glutReshapeFunc(aturKamera);
    glutKeyboardFunc(controlKeyboard);

    glutMainLoop();
    return 0;
}
