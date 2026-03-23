#include <GL/glut.h>
#include <string.h>

static int shoulder = 0, elbow = 0;
static int wrist = 0;
static int jempol1 = 0,     jempol2 = 0;
static int telunjuk1 = 0,   telunjuk2 = 0;
static int tengah1 = 0,     tengah2 = 0;
static int manis1 = 0,      manis2 = 0;
static int kelingking1 = 0, kelingking2 = 0;

static char poseLabel[64] = "Default";

void setPose(int pose) {
    switch (pose) {

    case 1: // Telunjuk lurus
        shoulder    = 0;   elbow       = 0;    wrist       = 0;
        jempol1     = -55;  jempol2     = -45;
        telunjuk1   = 0;   telunjuk2   = 0;
        tengah1     = 80;  tengah2     = 75;
        manis1      = 80;  manis2      = 75;
        kelingking1 = 75;  kelingking2 = 70;
        strcpy(poseLabel, "Pose 1 : Telunjuk  (tekan 1)");
        break;

    case 2: // Thumbs Up
        shoulder    = 0;   elbow       = 0;    wrist       = 0;
        jempol1     = 0;  jempol2     = 0;
        telunjuk1   = 80;  telunjuk2   = 75;
        tengah1     = 80;  tengah2     = 75;
        manis1      = 80;  manis2      = 75;
        kelingking1 = 80;  kelingking2 = 75;
        strcpy(poseLabel, "Pose 2 : Thumbs Up  (tekan 2)");
        break;

    case 3: // OK Sign
        shoulder    = 0;   elbow       = 0;    wrist       = 0;
        jempol1     = -55;  jempol2     = -50;
        telunjuk1   = 60;  telunjuk2   = 55;
        tengah1     = 0;   tengah2     = 0;
        manis1      = 5;   manis2      = 0;
        kelingking1 = 10;  kelingking2 = 0;
        strcpy(poseLabel, "Pose 3 : OK Sign  (tekan 3)");
        break;

    default: // Reset semua
        shoulder = elbow = wrist = 0;
        jempol1 = jempol2 = 0;
        telunjuk1 = telunjuk2 = 0;
        tengah1 = tengah2 = 0;
        manis1 = manis2 = 0;
        kelingking1 = kelingking2 = 0;
        strcpy(poseLabel, "Default  (tekan 0 untuk reset)");
        break;
    }
    glutPostRedisplay();
}

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

// HUD label di sudut bawah layar
void drawHUD(void) {
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
        glLoadIdentity();
        gluOrtho2D(0, 800, 0, 600);
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
            glLoadIdentity();

            glColor3f(0.15f, 0.15f, 0.15f);
            glBegin(GL_QUADS);
                glVertex2f(0, 0);    glVertex2f(800, 0);
                glVertex2f(800, 52); glVertex2f(0, 52);
            glEnd();

            glColor3f(1.0f, 0.9f, 0.2f);
            glRasterPos2f(12, 32);
            for (const char* c = poseLabel; *c; c++)
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);

            glColor3f(0.7f, 0.7f, 0.7f);
            const char* hint = "1=Telunjuk  2=ThumbsUp  3=OK";
            glRasterPos2f(12, 12);
            for (const char* c = hint; *c; c++)
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, *c);

        glPopMatrix();
        glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(-1.5, 0.0, -7.0);

    glColor3f(1.0f, 1.0f, 1.0f);

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

    drawHUD();
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
        case '1': setPose(1); break;
        case '2': setPose(2); break;
        case '3': setPose(3); break;
        case '0': setPose(0); break;

        case 's': shoulder = (shoulder + 5) % 360; glutPostRedisplay(); break;
        case 'S': shoulder = (shoulder - 5 + 360) % 360; glutPostRedisplay(); break;
        case 'e': elbow = (elbow + 5) % 360; glutPostRedisplay(); break;
        case 'E': elbow = (elbow - 5 + 360) % 360; glutPostRedisplay(); break;
        case 'w': wrist = (wrist + 5) % 360; glutPostRedisplay(); break;
        case 'W': wrist = (wrist - 5 + 360) % 360; glutPostRedisplay(); break;
        case 'j': jempol1 = (jempol1 + 5) % 180; glutPostRedisplay(); break;
        case 'J': jempol1 = (jempol1 - 5 + 180) % 180; glutPostRedisplay(); break;
        case 'l': jempol2 = (jempol2 + 5) % 100; glutPostRedisplay(); break;
        case 'L': jempol2 = (jempol2 - 5 + 100) % 100; glutPostRedisplay(); break;
        case 't': telunjuk1 = (telunjuk1 + 5) % 90; glutPostRedisplay(); break;
        case 'T': telunjuk1 = (telunjuk1 - 5 + 90) % 90; glutPostRedisplay(); break;
        case 'y': telunjuk2 = (telunjuk2 + 5) % 90; glutPostRedisplay(); break;
        case 'Y': telunjuk2 = (telunjuk2 - 5 + 90) % 90; glutPostRedisplay(); break;
        case 'g': tengah1 = (tengah1 + 5) % 90; glutPostRedisplay(); break;
        case 'G': tengah1 = (tengah1 - 5 + 90) % 90; glutPostRedisplay(); break;
        case 'h': tengah2 = (tengah2 + 5) % 90; glutPostRedisplay(); break;
        case 'H': tengah2 = (tengah2 - 5 + 90) % 90; glutPostRedisplay(); break;
        case 'b': manis1 = (manis1 + 5) % 90; glutPostRedisplay(); break;
        case 'B': manis1 = (manis1 - 5 + 90) % 90; glutPostRedisplay(); break;
        case 'n': manis2 = (manis2 + 5) % 90; glutPostRedisplay(); break;
        case 'N': manis2 = (manis2 - 5 + 90) % 90; glutPostRedisplay(); break;
        case 'k': kelingking1 = (kelingking1 + 5) % 90; glutPostRedisplay(); break;
        case 'K': kelingking1 = (kelingking1 - 5 + 90) % 90; glutPostRedisplay(); break;
        case 'm': kelingking2 = (kelingking2 + 5) % 90; glutPostRedisplay(); break;
        case 'M': kelingking2 = (kelingking2 - 5 + 90) % 90; glutPostRedisplay(); break;

        case 27: exit(0); break;
        default: break;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Emoticon");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
