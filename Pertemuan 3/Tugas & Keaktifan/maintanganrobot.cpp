// =================================================================
// Nama: Birela Miadeta Purita
// Lab:  B2
// NIM:  24060124120002
// Tujuan: Tugas 3 - Mengimplementasikan tangan robot (emoticon) 
// =================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>

/* ROTASI LENGAN */
static int shoulder = 0;
static int elbow = 0;
static int wrist = 0;

/* SETIAP JARI 3 RUAS */
int f1_1=0,f1_2=0,f1_3=0; // Telunjuk
int f2_1=0,f2_2=0,f2_3=0; // Tengah
int f3_1=0,f3_2=0,f3_3=0; // Manis
int f4_1=0,f4_2=0,f4_3=0; // Kelingking
int f5_1=0,f5_2=0,f5_3=0; // Ibu jari

/* ROTASI TAMBAHAN */
static int thumb_rotate = 0; // Ibu jari
static int forearm_rotate = 0;
static int hand_rotate = 0;

/* POSISI DAN SKALA */
static float hand_x=0.0, hand_y=0.0, hand_z=0.0;
static float scale_factor=1.0;

/* WIREFRAME / SOLID */
int wireframe = 1;

/* EMOTICON: 0=Normal, 1=????, 2=???, 3=???? */
int current_emoticon = 0;

void init(void)
{
    glClearColor(0.0,0.0,0.0,0.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
}

/* RUAS JARI */
void drawFingerSegment(float length)
{
    glPushMatrix();
    glScalef(length,0.15,0.15);
    if(wireframe) glutWireCube(1.0);
    else glutSolidCube(1.0);
    glPopMatrix();
}

/* SATU JARI 3 RUAS */
void drawFinger(int a1,int a2,int a3)
{
    glPushMatrix();

    glRotatef(a1,0,0,1);
    glTranslatef(0.3,0,0);
    drawFingerSegment(0.6);

    glTranslatef(0.3,0,0);
    glRotatef(a2,0,0,1);
    drawFingerSegment(0.5);

    glTranslatef(0.25,0,0);
    glRotatef(a3,0,0,1);
    drawFingerSegment(0.4);

    glPopMatrix();
}

/* DISPLAY */
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();

    /* LENGAN ATAS */
    glTranslatef(-1.0,0.0,0.0);
    glRotatef((GLfloat)shoulder,0.0,0.0,1.0);
    glTranslatef(1.0,0.0,0.0);

    glPushMatrix();
    glScalef(2.0,0.4,0.4);
    if(wireframe) glutWireCube(1.0);
    else glutSolidCube(1.0);
    glPopMatrix();

    /* SIKU */
    glTranslatef(1.0,0.0,0.0);
    glRotatef((GLfloat)elbow,0.0,0.0,1.0);
    glTranslatef(1.0,0.0,0.0);

    glPushMatrix();
    glScalef(2.0,0.4,0.4);
    if(wireframe) glutWireCube(1.0);
    else glutSolidCube(1.0);
    glPopMatrix();

    /* PERGELANGAN */
    glTranslatef(1.0,0.0,0.0);
    glRotatef((GLfloat)wrist,0.0,0.0,1.0);
    glTranslatef(0.5,0.0,0.0);
    glRotatef((GLfloat)hand_rotate,0.0,1.0,0.0);

    /* TELAPAK */
    glPushMatrix();
    glScalef(1.0,0.6,0.4);
    if(wireframe) glutWireCube(1.0);
    else glutSolidCube(1.0);
    glPopMatrix();

    /* JARI */
    glPushMatrix();
    glTranslatef(0.5,0.25,0); drawFinger(f1_1,f1_2,f1_3); // Telunjuk
    glTranslatef(0.0,-0.13,0); drawFinger(f2_1,f2_2,f2_3); // Tengah
    glTranslatef(0.0,-0.12,0); drawFinger(f3_1,f3_2,f3_3); // Manis
    glTranslatef(0.0,-0.12,0); drawFinger(f4_1,f4_2,f4_3); // Kelingking
    glPopMatrix();

    /* IBU JARI */
    glPushMatrix();
    glRotatef((GLfloat)thumb_rotate,0.0,1.0,0.0);
    glTranslatef(0.3,-0.30,0);
    drawFinger(f5_1,f5_2,f5_3);
    glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int w,int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0,(GLfloat)w/(GLfloat)h,1.0,20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0,0.0,-8.0);
}

/* EMOTICON PRESET */
void setEmoticon(int type)
{
    current_emoticon = type;

    switch(type)
    {
        case 1: // ????
            f1_1=f1_2=f1_3=0; // Telunjuk terbuka
            f2_1=f2_2=f2_3=90; // Tengah menekuk
            f3_1=f3_2=f3_3=90; // Manis menekuk
            f4_1=f4_2=f4_3=0; // Kelingking terbuka
            f5_1=f5_2=f5_3=0; // Ibu jari terbuka
            thumb_rotate=0;
            break;
        case 2: // ???
            f1_1=f1_2=f1_3=0; // Telunjuk
            f2_1=f2_2=f2_3=0; // Tengah
            f3_1=f3_2=f3_3=90; // Manis menekuk
            f4_1=f4_2=f4_3=90; // Kelingking menekuk
            f5_1=f5_2=f5_3=90; // Ibu jari menekuk
            thumb_rotate=0;
            break;
        case 3: // ????
            f1_1=f1_2=f1_3=90; // Telunjuk menekuk
            f2_1=f2_2=f2_3=90; // Tengah menekuk
            f3_1=f3_2=f3_3=90; // Manis menekuk
            f4_1=f4_2=f4_3=0;  // Kelingking terbuka
            f5_1=f5_2=f5_3=0;  // Ibu jari terbuka
            thumb_rotate=0;
            break;
        default: // Normal
            f1_1=f1_2=f1_3=0; f2_1=f2_2=f2_3=0; f3_1=f3_2=f3_3=0;
            f4_1=f4_2=f4_3=0; f5_1=f5_2=f5_3=0;
            shoulder=elbow=wrist=0;
            forearm_rotate=hand_rotate=thumb_rotate=0;
            hand_x=hand_y=hand_z=0;
            scale_factor=1.0;
            break;
    }
    glutPostRedisplay();
}

/* KEYBOARD */
void keyboard(unsigned char key,int x,int y)
{
    switch(key)
    {
        /* ROTASI */
        case 's': shoulder=(shoulder+5)%360; break;
        case 'S': shoulder=(shoulder-5)%360; break;
        case 'e': elbow=(elbow+5)%360; break;
        case 'E': elbow=(elbow-5)%360; break;
        case 'w': wrist=(wrist+5)%360; break;
        case 'W': wrist=(wrist-5)%360; break;
        case 'r': forearm_rotate=(forearm_rotate+5)%360; break;
        case 'R': forearm_rotate=(forearm_rotate-5)%360; break;
        case 'h': hand_rotate=(hand_rotate+5)%360; break;
        case 'H': hand_rotate=(hand_rotate-5)%360; break;
        case 't': thumb_rotate=(thumb_rotate+5)%360; break;
        case 'T': thumb_rotate=(thumb_rotate-5)%360; break;

        /* JARI MANUAL */
        case '1': f1_1+=5; break; case 'q': f1_2+=5; break; case 'a': f1_3+=5; break;
        case '2': f2_1+=5; break; case 'z': f2_2+=5; break; case 'x': f2_3+=5; break;
        case '3': f3_1+=5; break; case 'c': f3_2+=5; break; case 'v': f3_3+=5; break;
        case '4': f4_1+=5; break; case 'b': f4_2+=5; break; case 'n': f4_3+=5; break;
        case '5': f5_1+=5; break; case 'm': f5_2+=5; break; case ',': f5_3+=5; break;

        /* EMOTICON */
        case 'y': setEmoticon(1); break; //ily
        case 'u': setEmoticon(2); break; //nembak
        case 'i': setEmoticon(3); break; //pose L
        case 'o': setEmoticon(0); break; // Normal

        /* Wire/Solid */
        case ' ': wireframe = !wireframe; break;

        /* Exit */
        case 27: exit(0); break;
    }
    glutPostRedisplay();
}

/* SPECIAL KEYS */
void specialKeys(int key,int x,int y)
{
    switch(key)
    {
        case GLUT_KEY_UP:    hand_y+=0.1; break;
        case GLUT_KEY_DOWN:  hand_y-=0.1; break;
        case GLUT_KEY_LEFT:  hand_x-=0.1; break;
        case GLUT_KEY_RIGHT: hand_x+=0.1; break;
        case GLUT_KEY_PAGE_UP: hand_z+=0.1; break;
        case GLUT_KEY_PAGE_DOWN: hand_z-=0.1; break;
        case GLUT_KEY_HOME:  scale_factor+=0.1; break;
        case GLUT_KEY_END:   scale_factor-=0.1; if(scale_factor<0.1) scale_factor=0.1; break;
    }
    glutPostRedisplay();
}

/* MAIN */
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Robot Hand 3D - Emoticon");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);
    glutMainLoop();
    return 0;
}
