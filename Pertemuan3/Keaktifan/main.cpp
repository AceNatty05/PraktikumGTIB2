#include <GL/glut.h>
#include <stdlib.h>

int shoulder = 0;
int elbow = 0;
int palm = 0;

int indexBase = 0, indexTip = 0;
int middleBase = 0, middleTip = 0;
int ringBase = 0, ringTip = 0;
int littleBase = 0, littleTip = 0;
int thumbBase = 0, thumbTip = 0;

void DrawBox(float sx, float sy, float sz) {
    glPushMatrix();
    glScalef(sx, sy, sz);
    glutWireCube(1.0); 
    glPopMatrix();
}


void ResetPose() {
    shoulder = 0;
    elbow = 0;
    palm = 0;

    indexBase = indexTip = 0;
    middleBase = middleTip = 0;
    ringBase = ringTip = 0;
    littleBase = littleTip = 0;

    thumbBase = 0;
    thumbTip = 0;
}

void PoseMetal() {
    ResetPose();

    indexBase = 0; indexTip = 0;

    middleBase = 100; middleTip = 90;
    ringBase   = 105; ringTip   = 95;

    littleBase = 0; littleTip = 0;

    thumbBase = -10;
    thumbTip  = -5;
}

void PosePeace() {
    ResetPose();

    indexBase = 0; indexTip = 0;
    middleBase = 0; middleTip = 0;

    ringBase = 110; ringTip = 100;
    littleBase = 115; littleTip = 105;

    thumbBase = -8;
    thumbTip  = -5;
}

void PoseLove() {
    ResetPose();

    indexBase = 0; indexTip = 0;

    middleBase = 100; middleTip = 90;
    ringBase   = 105; ringTip   = 95;

    littleBase = 0; littleTip = 0;

    thumbBase = 12;   
    thumbTip  = 5;
}

void DrawFinger(float offsetY, float len1, float len2, int baseRot, int tipRot) {
    glPushMatrix();

    glTranslatef(0.60f, offsetY, 0.0f);
    glRotatef((GLfloat)(-baseRot), 0.0f, 0.0f, 1.0f);

    glPushMatrix();
        glTranslatef(len1 / 2.0f, 0.0f, 0.0f);
        DrawBox(len1, 0.08f, 0.08f);
    glPopMatrix();

    glTranslatef(len1, 0.0f, 0.0f);
    glRotatef((GLfloat)(-tipRot), 0.0f, 0.0f, 1.0f);

    glPushMatrix();
        glTranslatef(len2 / 2.0f, 0.0f, 0.0f);
        DrawBox(len2, 0.07f, 0.07f);
    glPopMatrix();

    glPopMatrix();
}

void DrawThumb() {
    glPushMatrix();


    glTranslatef(0.02f, 0.20f, 0.0f);

    glRotatef(25.0f, 0.0f, 0.0f, 1.0f);

    glRotatef((GLfloat)thumbBase, 0.0f, 0.0f, 1.0f);

    glPushMatrix();
        glTranslatef(0.20f, 0.0f, 0.0f);
        DrawBox(0.40f, 0.09f, 0.08f);
    glPopMatrix();

    glTranslatef(0.40f, 0.0f, 0.0f);
    glRotatef((GLfloat)thumbTip, 0.0f, 0.0f, 1.0f);

    glPushMatrix();
        glTranslatef(0.15f, 0.0f, 0.0f);
        DrawBox(0.30f, 0.08f, 0.07f);
    glPopMatrix();

    glPopMatrix();
}

void Display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();


    glTranslatef(0.0f, 0.0f, -8.0f);

    glPushMatrix();

        // bahu
        glTranslatef(-3.5f, 0.0f, 0.0f);
        glRotatef((GLfloat)shoulder, 0.0f, 0.0f, 1.0f);

        // lengan atas
        glPushMatrix();
            glTranslatef(1.5f, 0.0f, 0.0f);
            DrawBox(3.0f, 0.40f, 0.18f);
        glPopMatrix();

        // siku
        glTranslatef(3.0f, 0.0f, 0.0f);
        glRotatef((GLfloat)elbow, 0.0f, 0.0f, 1.0f);

        // lengan bawah
        glPushMatrix();
            glTranslatef(1.3f, 0.0f, 0.0f);
            DrawBox(2.6f, 0.35f, 0.16f);
        glPopMatrix();

        // telapak
        glTranslatef(2.6f, 0.0f, 0.0f);
        glRotatef((GLfloat)palm, 0.0f, 0.0f, 1.0f);

        glPushMatrix();
            glTranslatef(0.48f, 0.0f, 0.0f);
            DrawBox(0.96f, 0.78f, 0.14f);
        glPopMatrix();

        // ibu jari
        DrawThumb();

        // 4 jari
        DrawFinger( 0.32f, 0.50f, 0.34f, indexBase,  indexTip);
        DrawFinger( 0.12f, 0.60f, 0.40f, middleBase, middleTip);
        DrawFinger(-0.10f, 0.46f, 0.30f, ringBase,   ringTip);
        DrawFinger(-0.30f, 0.34f, 0.22f, littleBase, littleTip);

    glPopMatrix();

    glutSwapBuffers();
}

void Reshape(int w, int h) {
    if (h == 0) h = 1;

    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (GLdouble)w / (GLdouble)h, 0.5, 20.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case '1': PoseMetal(); break;
        case '2': PosePeace(); break;
        case '3': PoseLove();  break;
        case '0': ResetPose(); break;
        case 27: exit(0); break;
    }

    glutPostRedisplay();
}

void Init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glColor3f(1.0, 1.0, 1.0);
    glEnable(GL_DEPTH_TEST);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(900, 650);
    glutCreateWindow("Keaktifan - Tangan");

    Init();
    ResetPose();

    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);
    glutKeyboardFunc(Keyboard);

    glutMainLoop();
    return 0;
}
