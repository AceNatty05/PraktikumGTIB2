#include <GL/glut.h>
#include <stdlib.h>

/* ====== Sendi lengan ====== */
static int bahu = 0;
static int siku = 0;
static int pergelangan = 0;

/* ====== Sendi tiap jari (ruas bawah & ruas atas) ====== */
static int ibuJariBawah = 0,  ibuJariAtas  = 0;
static int telunjukBawah = 0, telunjukAtas = 0;
static int tengahBawah   = 0, tengahAtas   = 0;
static int manisBawah    = 0, manisAtas    = 0;
static int kelingBawah   = 0, kelingAtas   = 0;

/* ============================================================
   Util: gambar satu kotak (ruas) dengan ukuran sx, sy, sz
   ============================================================ */
void gambarRuas(float sx, float sy, float sz) {
    glPushMatrix();
        glScalef(sx, sy, sz);
        glutWireCube(1.0);
    glPopMatrix();
}

/* ============================================================
   Reset semua sendi ke posisi netral
   ============================================================ */
void resetSemua(void) {
    bahu = siku = pergelangan = 0;
    ibuJariBawah = ibuJariAtas = 0;
    telunjukBawah = telunjukAtas = 0;
    tengahBawah = tengahAtas = 0;
    manisBawah = manisAtas = 0;
    kelingBawah = kelingAtas = 0;
}

/* ============================================================
   Gambar satu jari (2 ruas) relatif terhadap titik pangkalnya
   ============================================================ */
void gambarJari(int sendiBawah, int sendiAtas,
                float panjang1, float panjang2, float lebar, float tebal) {
    glPushMatrix();
        glRotatef((GLfloat)sendiBawah, 0.0f, 0.0f, 1.0f);
        glTranslatef(panjang1 / 2.0f, 0.0f, 0.0f);
        gambarRuas(panjang1, lebar, tebal);

        glTranslatef(panjang1 / 2.0f, 0.0f, 0.0f);
        glRotatef((GLfloat)sendiAtas, 0.0f, 0.0f, 1.0f);
        glTranslatef(panjang2 / 2.0f, 0.0f, 0.0f);
        gambarRuas(panjang2, lebar * 0.9f, tebal * 0.9f);
    glPopMatrix();
}

/* ============================================================
   Fungsi tampilan utama
   ============================================================ */
void tampil(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -8.0f);

    glColor3f(1.0f, 1.0f, 1.0f);

    glPushMatrix();
        /* --- Lengan atas, dimulai dari bahu --- */
        glTranslatef(-3.2f, 0.0f, 0.0f);
        glRotatef((GLfloat)bahu, 0.0f, 0.0f, 1.0f);
        glPushMatrix();
            glTranslatef(1.4f, 0.0f, 0.0f);
            gambarRuas(2.8f, 0.38f, 0.18f);
        glPopMatrix();

        /* --- Lengan bawah, dimulai dari siku --- */
        glTranslatef(2.8f, 0.0f, 0.0f);
        glRotatef((GLfloat)siku, 0.0f, 0.0f, 1.0f);
        glPushMatrix();
            glTranslatef(1.2f, 0.0f, 0.0f);
            gambarRuas(2.4f, 0.32f, 0.16f);
        glPopMatrix();

        /* --- Pergelangan & telapak tangan --- */
        glTranslatef(2.4f, 0.0f, 0.0f);
        glRotatef((GLfloat)pergelangan, 0.0f, 0.0f, 1.0f);
        glPushMatrix();
            glTranslatef(0.45f, 0.0f, 0.0f);
            gambarRuas(0.9f, 0.72f, 0.14f);
        glPopMatrix();

        /* --- Ibu jari, posisi miring dari sisi telapak --- */
        glPushMatrix();
            glTranslatef(0.05f, 0.42f, 0.0f);
            glRotatef(75.0f, 0.0f, 0.0f, 1.0f);
            gambarJari(ibuJariBawah, ibuJariAtas, 0.34f, 0.24f, 0.10f, 0.10f);
        glPopMatrix();

        /* --- Empat jari lainnya, sejajar keluar dari telapak --- */
        glPushMatrix();
            glTranslatef(0.30f, 0.27f, 0.0f);
            gambarJari(telunjukBawah, telunjukAtas, 0.46f, 0.32f, 0.10f, 0.10f);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(0.30f, 0.09f, 0.0f);
            gambarJari(tengahBawah, tengahAtas, 0.52f, 0.36f, 0.10f, 0.10f);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(0.30f, -0.09f, 0.0f);
            gambarJari(manisBawah, manisAtas, 0.46f, 0.32f, 0.10f, 0.10f);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(0.30f, -0.27f, 0.0f);
            gambarJari(kelingBawah, kelingAtas, 0.36f, 0.24f, 0.09f, 0.09f);
        glPopMatrix();

    glPopMatrix();

    glutSwapBuffers();
}

/* ============================================================
   Reshape
   ============================================================ */
void ubahUkuran(int w, int h) {
    if (h == 0) h = 1;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (GLdouble)w / (GLdouble)h, 0.5, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

/* ============================================================
   Kontrol manual tiap sendi lewat keyboard
   ============================================================ */
void papanTombol(unsigned char key, int x, int y) {
    switch (key) {
        /* Lengan */
        case 's': bahu = (bahu + 5) % 360; break;
        case 'S': bahu = (bahu - 5 + 360) % 360; break;
        case 'e': siku = (siku + 5) % 360; break;
        case 'E': siku = (siku - 5 + 360) % 360; break;
        case 'w': pergelangan = (pergelangan + 5) % 360; break;
        case 'W': pergelangan = (pergelangan - 5 + 360) % 360; break;

        /* Ibu jari */
        case 'j': ibuJariBawah += 5; break;
        case 'J': ibuJariBawah -= 5; break;
        case 'u': ibuJariAtas  += 5; break;
        case 'U': ibuJariAtas  -= 5; break;

        /* Telunjuk */
        case 't': telunjukBawah += 5; break;
        case 'T': telunjukBawah -= 5; break;
        case 'y': telunjukAtas  += 5; break;
        case 'Y': telunjukAtas  -= 5; break;

        /* Tengah */
        case 'g': tengahBawah += 5; break;
        case 'G': tengahBawah -= 5; break;
        case 'h': tengahAtas  += 5; break;
        case 'H': tengahAtas  -= 5; break;

        /* Manis */
        case 'b': manisBawah += 5; break;
        case 'B': manisBawah -= 5; break;
        case 'n': manisAtas  += 5; break;
        case 'N': manisAtas  -= 5; break;

        /* Kelingking */
        case 'k': kelingBawah += 5; break;
        case 'K': kelingBawah -= 5; break;
        case 'm': kelingAtas  += 5; break;
        case 'M': kelingAtas  -= 5; break;

        /* Reset */
        case '0': resetSemua(); break;

        case 27: exit(0); break;
        default: break;
    }
    glutPostRedisplay();
}

void inisialisasi(void) {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glColor3f(1.0, 1.0, 1.0);
    glEnable(GL_DEPTH_TEST);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(900, 650);
    glutCreateWindow("Tugas - Tangan");

    inisialisasi();
    resetSemua();

    glutDisplayFunc(tampil);
    glutReshapeFunc(ubahUkuran);
    glutKeyboardFunc(papanTombol);

    glutMainLoop();
    return 0;
}

