#include <gl/glut.h>

void kubus(float x, float y, float z, float size, float r, float g, float b) {
    // Menggambar kubus dengan pusat di (x,y,z) dan ukuran size
    float half = size / 2.0f;
    glBegin(GL_QUADS);
        // Sisi depan
        glColor3f(r, g, b);
        glVertex3f(x - half, y - half, z + half);
        glVertex3f(x + half, y - half, z + half);
        glVertex3f(x + half, y + half, z + half);
        glVertex3f(x - half, y + half, z + half);

        // Sisi belakang
        glColor3f(r*0.7f, g*0.7f, b*0.7f);
        glVertex3f(x - half, y - half, z - half);
        glVertex3f(x - half, y + half, z - half);
        glVertex3f(x + half, y + half, z - half);
        glVertex3f(x + half, y - half, z - half);

        // Sisi atas
        glColor3f(r*0.8f, g*0.8f, b*0.8f);
        glVertex3f(x - half, y + half, z - half);
        glVertex3f(x - half, y + half, z + half);
        glVertex3f(x + half, y + half, z + half);
        glVertex3f(x + half, y + half, z - half);

        // Sisi bawah
        glColor3f(r*0.5f, g*0.5f, b*0.5f);
        glVertex3f(x - half, y - half, z - half);
        glVertex3f(x + half, y - half, z - half);
        glVertex3f(x + half, y - half, z + half);
        glVertex3f(x - half, y - half, z + half);

        // Sisi kiri
        glColor3f(r*0.6f, g*0.6f, b*0.6f);
        glVertex3f(x - half, y - half, z - half);
        glVertex3f(x - half, y - half, z + half);
        glVertex3f(x - half, y + half, z + half);
        glVertex3f(x - half, y + half, z - half);

        // Sisi kanan
        glColor3f(r*0.9f, g*0.9f, b*0.9f);
        glVertex3f(x + half, y - half, z - half);
        glVertex3f(x + half, y + half, z - half);
        glVertex3f(x + half, y + half, z + half);
        glVertex3f(x + half, y - half, z + half);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0.0, 2.0, 8.0,  // posisi kamera
              0.0, 1.0, 0.0,  // titik pandang
              0.0, 1.0, 0.0); // arah atas

    // Menggambar 5 kubus bertingkat
    kubus(0.0f, 0.5f, 0.0f, 0.8f, 1.0f, 0.0f, 0.0f); // merah
    kubus(0.0f, 1.5f, 0.0f, 0.7f, 0.0f, 1.0f, 0.0f); // hijau
    kubus(0.0f, 2.5f, 0.0f, 0.6f, 0.0f, 0.0f, 1.0f); // biru
    kubus(0.0f, 3.5f, 0.0f, 0.5f, 1.0f, 1.0f, 0.0f); // kuning
    kubus(0.0f, 4.5f, 0.0f, 0.4f, 1.0f, 0.0f, 1.0f); // magenta

    glutSwapBuffers();
}

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 640.0/480.0, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutCreateWindow("Tugas 3: Kubus Bertingkat");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}
