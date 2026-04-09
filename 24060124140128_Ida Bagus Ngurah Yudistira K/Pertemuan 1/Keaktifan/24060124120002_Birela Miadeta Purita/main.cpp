// =================================================================
// Nama: Birela Miadeta Purita
// Lab:  B2
// NIM:  24060124120002
// Tujuan: Membuat Kubus bertingkat dari objek primitif sekreatif mungkin 
//         menjadi bentuk hati.
// =================================================================

#include <GL/glut.h>

// Fungsi Kotak 
void pixel(int x, int y) {
    glBegin(GL_QUADS);
    glVertex2i(x, y);
    glVertex2i(x + 1, y);
    glVertex2i(x + 1, y + 1);
    glVertex2i(x, y + 1);
    glEnd();
}

// Fungsi Hati
void drawBigHeart(int xOff, int yOff) {
    // Bagian atas
    for(int i=1; i<=3; i++) pixel(xOff+i, yOff+7); //3 kotak
    for(int i=5; i<=7; i++) pixel(xOff+i, yOff+7); //3 kotak
    for(int i=0; i<=8; i++) if(i != 4) pixel(xOff+i, yOff+6); //8 kotak

    // Bagian tengah
    for(int y=3; y<=5; y++) {
        for(int x=0; x<=8; x++) pixel(xOff+x, yOff+y); //3x9=27 kotak
    }

    // Bagian bawah
    for(int i=1; i<=7; i++) pixel(xOff+i, yOff+2); //7 kotak
    for(int i=2; i<=6; i++) pixel(xOff+i, yOff+1); //5 kotak
    pixel(xOff+4, yOff+0); //1 kotak
}
//Total= 54 kotak

// Fungsi Display 
void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Menggambar hati warna pink tua
    glColor3f(1.0f, 0.2f, 0.5f);
    drawBigHeart(11, 12); 

    // Menggambar titik putih 
    glColor3f(1.0f, 1.0f, 1.0f);
    pixel(11+2, 12+5);

    glFlush();
}

// Fungsi agar gambar tidak gepeng saat jendela ditarik
void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    float aspect = (float)w / (float)h;
    if (w <= h)
        gluOrtho2D(0, 32, (32 - 32/aspect)/2, 32 - (32 - 32/aspect)/2);
    else
        gluOrtho2D((32 - 32*aspect)/2, 32 - (32 - 32*aspect)/2, 0, 32);

    glMatrixMode(GL_MODELVIEW);
}

// Fungsi Main
int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Tugas GTI - Hati Pixel");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 

    glutMainLoop();
    return 0;
}
