#include <GL/glut.h>

// Bahu dan siku
static int shoulder = 0, elbow = 0;

// Rotasi pergelangan
static int wrist = 0;

// Sendi Jempol
static int jempol1 = 0, jempol2 = 0;

// Sendi Telunjuk
static int telunjuk1 = 0, telunjuk2 = 0;

// Sendi Tengah
static int tengah1 = 0, tengah2 = 0;

// Sendi Manis
static int manis1 = 0, manis2 = 0;

// Sendi Kelingking
static int kelingking1 = 0, kelingking2 = 0;

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void drawFinger(int joint1, int joint2, float len1, float len2, float w, float h) {
    glPushMatrix();
        glRotatef((GLfloat)joint1, 0.0, 0.0, 1.0);
        glTranslatef(len1/2, 0.0, 0.0);
        glPushMatrix();
            glScalef(len1, h, w);
            glutWireCube(1.0);
        glPopMatrix();
        glTranslatef(len1/2, 0.0, 0.0);
        glRotatef((GLfloat)joint2, 0.0, 0.0, 1.0);
        glTranslatef(len2/2, 0.0, 0.0);
        glPushMatrix();
            glScalef(len2, h*0.9f, w*0.9f);
            glutWireCube(1.0);
        glPopMatrix();
    glPopMatrix();
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(-1.5, 0.0, -7.0);

    // UPPER ARM
    glPushMatrix();
        glTranslatef(-1.0, 0.0, 0.0);
        glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
        glTranslatef(1.0, 0.0, 0.0);
        glPushMatrix();
            glScalef(2.0, 0.4, 1.0);
            glutWireCube(1.0);
        glPopMatrix();

        // LOWER ARM
        glTranslatef(1.0, 0.0, 0.0);
        glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
        glTranslatef(1.0, 0.0, 0.0);
        glPushMatrix();
            glScalef(2.0, 0.4, 1.0);
            glutWireCube(1.0);
        glPopMatrix();

        // PERGELANGAN
        glTranslatef(1.0, 0.0, 0.0);
        glRotatef((GLfloat)wrist, 0.0, 0.0, 1.0);
        glTranslatef(0.3, 0.0, 0.0);

        // TELAPAK
        glPushMatrix();
            glScalef(0.6, 0.8, 0.5);
            glutWireCube(1.0);
        glPopMatrix();

        // JEMPOL
        glPushMatrix();
		glTranslatef(0.1,  0.5, 0.0);
		glRotatef( 90.0, 0.0, 0.0, 1.0);
            drawFinger(jempol1, jempol2, 0.25f, 0.2f, 0.15f, 0.15f);
        glPopMatrix();
        // TELUNJUK
        glPushMatrix();
            glTranslatef(0.35, 0.25, 0.0);
            drawFinger(telunjuk1, telunjuk2, 0.3f, 0.25f, 0.12f, 0.12f);
        glPopMatrix();

        // TENGAH
        glPushMatrix();
            glTranslatef(0.35, 0.08, 0.0);
            drawFinger(tengah1, tengah2, 0.35f, 0.28f, 0.12f, 0.12f);
        glPopMatrix();

        // MANIS
        glPushMatrix();
            glTranslatef(0.35, -0.08, 0.0);
            drawFinger(manis1, manis2, 0.30f, 0.22f, 0.12f, 0.12f);
        glPopMatrix();

        // KELINGKING
        glPushMatrix();
            glTranslatef(0.35, -0.25, 0.0);
            drawFinger(kelingking1, kelingking2, 0.22f, 0.18f, 0.10f, 0.10f);
        glPopMatrix();

    glPopMatrix();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat)w/(GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        // Bahu
        case 's': shoulder = (shoulder + 5) % 360; glutPostRedisplay(); break;
        case 'S': shoulder = (shoulder - 5) % 360; glutPostRedisplay(); break;
        // Siku-siku
        case 'e': elbow = (elbow + 5) % 360; glutPostRedisplay(); break;
        case 'E': elbow = (elbow - 5) % 360; glutPostRedisplay(); break;
        // Pergelangan Tangan
        case 'w': wrist = (wrist + 5) % 20; glutPostRedisplay(); break;
        case 'W': wrist = (wrist - 5) % 20; glutPostRedisplay(); break;
        // Jempol
        case 'j': jempol1 = (jempol1 - 5) % 180; glutPostRedisplay(); break;
        case 'J': jempol1 = (jempol1 + 5) % 180; glutPostRedisplay(); break;
        case 'l': jempol2 = (jempol2 - 5) % 100; glutPostRedisplay(); break;
        case 'L': jempol2 = (jempol2 + 5) % 100; glutPostRedisplay(); break;
        // Telunjuk
        case 't': telunjuk1 = (telunjuk1 + 5) % 90; glutPostRedisplay(); break;
        case 'T': telunjuk1 = (telunjuk1 - 5) % 90; glutPostRedisplay(); break;
        case 'y': telunjuk2 = (telunjuk2 + 5) % 90; glutPostRedisplay(); break;
        case 'Y': telunjuk2 = (telunjuk2 - 5) % 90; glutPostRedisplay(); break;
        // Jari Tengah
        case 'g': tengah1 = (tengah1 + 5) % 90; glutPostRedisplay(); break;
        case 'G': tengah1 = (tengah1 - 5) % 90; glutPostRedisplay(); break;
        case 'h': tengah2 = (tengah2 + 5) % 90; glutPostRedisplay(); break;
        case 'H': tengah2 = (tengah2 - 5) % 90; glutPostRedisplay(); break;
        // Jari Manis kayak aku
        case 'b': manis1 = (manis1 + 5) % 90; glutPostRedisplay(); break;
        case 'B': manis1 = (manis1 - 5) % 90; glutPostRedisplay(); break;
        case 'n': manis2 = (manis2 + 5) % 90; glutPostRedisplay(); break;
        case 'N': manis2 = (manis2 - 5) % 90; glutPostRedisplay(); break;
        // Jari kelingking
        case 'k': kelingking1 = (kelingking1 + 5) % 90; glutPostRedisplay(); break;
        case 'K': kelingking1 = (kelingking1 - 5) % 90; glutPostRedisplay(); break;
        case 'm': kelingking2 = (kelingking2 + 5) % 90; glutPostRedisplay(); break;
        case 'M': kelingking2 = (kelingking2 - 5) % 90; glutPostRedisplay(); break;

        case 27: exit(0); break;
        default: break;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Tangan");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
