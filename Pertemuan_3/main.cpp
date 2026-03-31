#include <GL/glut.h>

int bahuZ = 0, bahuY = 0, siku = 0;
int telapakX = -90, telapakY = 0, telapakZ = 0;

int jari[5][3]; 

int mode = 0;

void cube(float x, float y, float z) {
    glPushMatrix();
    glScalef(x, y, z);
    glutWireCube(1.0);
    glPopMatrix();
}

void drawFinger(float panjang, int *sudut) {
    for (int i = 0; i < 3; i++) {
        glRotatef(sudut[i], 0, 0, 1);
        cube(panjang, 0.1, 0.1);
        glTranslatef(panjang, 0, 0);
    }
}

void drawHand() {
    glRotatef(telapakX, 1, 0, 0);
    glRotatef(telapakY, 0, 1, 0);
    glRotatef(telapakZ, 0, 0, 1);

    cube(0.5, 0.2, 0.6);

    glPushMatrix();
    glTranslatef(0.25, 0, 0.25);
    drawFinger(0.2, jari[0]);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.25, 0, 0.05);
    drawFinger(0.25, jari[1]);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.25, 0, -0.1);
    drawFinger(0.2, jari[2]);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.25, 0, -0.25);
    drawFinger(0.18, jari[3]);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 0.35);
    glRotatef(40, 0, 1, 0);
    drawFinger(0.15, jari[4]);
    glPopMatrix();
}

void drawArm() {
    glTranslatef(-1.5, 0, 0);
    glRotatef(bahuZ, 0, 0, 1);
    glRotatef(bahuY, 0, 1, 0);
    glTranslatef(1.5, 0, 0);

    cube(0.8, 0.3, 0.5);

    glTranslatef(-1.0, 0, 0);
    glRotatef(siku, 0, 0, 1);

    glTranslatef(1.2, 0, 0);
    cube(1.2, 0.3, 0.5);

    drawHand();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();

    drawArm();

    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, (float)w/h, 1, 20);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0,0,-6);
}

//input
void keyboard(unsigned char key, int x, int y) {

    if (key == '1') mode = 0;
    if (key == '2') mode = 1;

    if (mode == 0) {
        // lengan 
        if (key=='q') bahuZ +=5;
        if (key=='a') bahuZ -=5;

        if (key=='w') bahuY +=5;
        if (key=='s') bahuY -=5;

        if (key=='e') siku +=5;
        if (key=='d') siku -=5;

		// telapak
        if (key=='z') telapakX +=5;
        if (key=='x') telapakX -=5;

        if (key=='c') telapakY +=5;
        if (key=='v') telapakY -=5;

        if (key=='b') telapakZ +=5;
        if (key=='n') telapakZ -=5;
    }
    else {
        // jari
        if (key=='q') jari[0][0]+=5;
        if (key=='a') jari[0][1]+=5;
        if (key=='z') jari[0][2]+=5;

    }

    glutPostRedisplay();
}

void init() {
    glClearColor(0,0,0,0);
    glShadeModel(GL_FLAT);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(700,600);
    glutCreateWindow("Simulasi Lengan 3D");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}
