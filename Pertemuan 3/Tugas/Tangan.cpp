// Pertemuan 3 - Tugas - Tangan
// Nama : Hana Nafi'atul Haq
// NIM 	: 24060124130081
// Lab 	: B2

#include <GL/glut.h>
#include <stdlib.h>

int shoulder = 0, elbow = 0, wrist = 0;

int f1_1=0,f1_2=0,f1_3=0;
int f2_1=0,f2_2=0,f2_3=0;
int f3_1=0,f3_2=0,f3_3=0;
int f4_1=0,f4_2=0,f4_3=0;
int f5_1=0,f5_2=0,f5_3=0;

void Reshape(int w, int h) {
    if (h == 0) h = 1;

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
}

void drawFinger(int a1,int a2,int a3){
    glPushMatrix();

    glRotatef(a1,0,0,1);
    glTranslatef(0.3,0,0);
    glPushMatrix();
        glScalef(0.6,0.12,0.12);
        glutWireCube(1);
    glPopMatrix();

    glTranslatef(0.3,0,0);
    glRotatef(a2,0,0,1);
    glPushMatrix();
        glScalef(0.5,0.1,0.1);
        glutWireCube(1);
    glPopMatrix();

    glTranslatef(0.25,0,0);
    glRotatef(a3,0,0,1);
    glPushMatrix();
        glScalef(0.4,0.08,0.08);
        glutWireCube(1);
    glPopMatrix();

    glPopMatrix();
}

void Display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -6.0);

    glPushMatrix();

    // bahu (shoulder)
    glTranslatef(-1,0,0);
    glRotatef(shoulder,0,0,1);
    glTranslatef(1,0,0);

    glPushMatrix();
    glScalef(2,0.4,0.4);
    glutWireCube(1);
    glPopMatrix();

    // siku (elbow)
    glTranslatef(1,0,0);
    glRotatef(elbow,0,0,1);
    glTranslatef(1,0,0);

    glPushMatrix();
    glScalef(2,0.4,0.4);
    glutWireCube(1);
    glPopMatrix();

    // pergelangan (wrist)
    glTranslatef(1,0,0);
    glRotatef(wrist,0,0,1);
    glTranslatef(0.6,0,0);

    // telapak
    glPushMatrix();
    glScalef(1.2,0.6,0.5);
    glutWireCube(1);
    glPopMatrix();

    // 4 jari depan
    glPushMatrix();
    glTranslatef(0.6,0.3,0); drawFinger(f1_1,f1_2,f1_3);
    glTranslatef(0,-0.2,0); drawFinger(f2_1,f2_2,f2_3);
    glTranslatef(0,-0.2,0); drawFinger(f3_1,f3_2,f3_3);
    glTranslatef(0,-0.2,0); drawFinger(f4_1,f4_2,f4_3);
    glPopMatrix();

    // ibu jari
    glPushMatrix();
    glTranslatef(0.3,-0.4,0);
    glRotatef(-40,0,0,1);
    glRotatef(30,0,1,0);
    drawFinger(f5_1,f5_2,f5_3);
    glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
}

void resetFinger(){
    f1_1=f1_2=f1_3=0;
    f2_1=f2_2=f2_3=0;
    f3_1=f3_2=f3_3=0;
    f4_1=f4_2=f4_3=0;
    f5_1=f5_2=f5_3=0;
}

void Keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 's': shoulder+=5; break;
    case 'S': shoulder-=5; break;
    case 'e': elbow+=5; break;
    case 'E': elbow-=5; break;
    case 'w': wrist+=5; break;
    case 'W': wrist-=5; break;
    
    case '1': f1_1+=5; f1_2+=4; f1_3+=3; break;
    case '2': f2_1+=5; f2_2+=4; f2_3+=3; break;
	case '3': f3_1+=5; f3_2+=4; f3_3+=3; break;
	case '4': f4_1+=5; f4_2+=4; f4_3+=3; break;
	case '5': f5_1+=5; f5_2+=4; f5_3+=3; break;
	case '!': f1_1-=5; f1_2-=4; f1_3-=3; break;
    case '@': f2_1-=5; f2_2-=4; f2_3-=3; break;
	case '#': f3_1-=5; f3_2-=4; f3_3-=3; break;
	case '$': f4_1-=5; f4_2-=4; f4_3-=3; break;
	case '%': f5_1-=5; f5_2-=4; f5_3-=3; break;
    
    // tekuk semua jari
    case 'f':
        f1_1+=5; f1_2+=4; f1_3+=3;
        f2_1+=5; f2_2+=4; f2_3+=3;
        f3_1+=5; f3_2+=4; f3_3+=3;
        f4_1+=5; f4_2+=4; f4_3+=3;
        f5_1+=5; f5_2+=4; f5_3+=3;
        break;
        
	// reset jari
    case 'F': 
        f1_1=f1_2=f1_3=0;
        f2_1=f2_2=f2_3=0;
        f3_1=f3_2=f3_3=0;
        f4_1=f4_2=f4_3=0;
        f5_1=f5_2=f5_3=0;
        break;
        
    // reset semua
    case 'Z':
    	f1_1=f1_2=f1_3=0;
        f2_1=f2_2=f2_3=0;
        f3_1=f3_2=f3_3=0;
        f4_1=f4_2=f4_3=0;
        f5_1=f5_2=f5_3=0;
        shoulder = 0;
        elbow = 0;
        wrist  = 0;
        break;

    case 27: exit(0);
    }

    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Emoticon Tangan - Hana");

    glClearColor(0,0,0,0);

    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);
    glutKeyboardFunc(Keyboard);

    glutMainLoop();
    return 0;
}
