//Nama : Revalina Salwa Aliya W.P
//Nim  : 24060124140155

#include <GL/glut.h>
#include <stdlib.h>

//pundaknya
int shoulder = 0, elbow = 0, wrist = 0;

int f1a=0,f1b=0,f1c=0;
int f2a=0,f2b=0,f2c=0;
int f3a=0,f3b=0,f3c=0;
int f4a=0,f4b=0,f4c=0;
int f5a=0,f5b=0,f5c=0;
int f5up=0;
int f4up=0;

int batas(int x){
    if(x < 0) return 0;
    if(x > 180) return 180;
    return x;
}

int batas_jempol(int x){
    if(x < 0) return 0;
    if(x > 270) return 270;
    return x;
}

//ruas ruas jarinya
void ruas(float p){
    glPushMatrix();
    glTranslatef(p/2,0,0);
    glScalef(p,0.15,0.15);
    glutWireCube(1);
    glPopMatrix();
}

//jarinya
void jari(float x,float y,int a,int b,int c){
    glPushMatrix();
    glTranslatef(x,y,0);
    glRotatef(a,0,0,1);
    ruas(0.4);
    glTranslatef(0.4,0,0);
    glRotatef(b,0,0,1);
    ruas(0.35);
    glTranslatef(0.35,0,0);
    glRotatef(c,0,0,1);
    ruas(0.3);
    glPopMatrix();
}

//jempol
void jempol(){
    glPushMatrix();
    glTranslatef(0.2,-0.25,0);
    glRotatef(-60,0,0,1);
    glRotatef(30,0,1,0);

    int down_atas   = f5a > 0   ? (f5a > 90  ? 90  : f5a) : 0;
    int down_tengah = f5a > 90  ? (f5a > 180 ? 90  : f5a - 90) : 0;
    int down_bawah  = f5a > 180 ? f5a - 180 : 0;

    int up_atas   = f5up > 0   ? (f5up > 60  ? 60  : f5up) : 0;
    int up_tengah = f5up > 60  ? (f5up > 120 ? 60  : f5up - 60) : 0;
    int up_bawah  = f5up > 120 ? f5up - 120 : 0;

    glRotatef(down_bawah - up_bawah,  0,0,1);
    ruas(0.4);
    glTranslatef(0.4,0,0);
    glRotatef(down_tengah - up_tengah, 0,0,1);
    ruas(0.35);
    glTranslatef(0.35,0,0);
    glRotatef(down_atas - up_atas,   0,0,1);
    ruas(0.3);
    glPopMatrix();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0,0,-6);
    glPushMatrix();

    glTranslatef(-2,0,0);
    glRotatef(shoulder,0,0,1);

    glPushMatrix();
    glScalef(2,0.4,0.4);
    glutWireCube(1);
    glPopMatrix();

    glTranslatef(1.4,0,0);
    glRotatef(elbow,0,0,1);

    glPushMatrix();
    glScalef(2,0.4,0.4);
    glutWireCube(1);
    glPopMatrix();

    glTranslatef(1.4,0,0);
    glRotatef(wrist,0,0,1);

    glPushMatrix();
    glScalef(0.9,0.5,0.5);
    glutWireCube(1);
    glPopMatrix();

    jari(0.45,0.25,f1a,f1b,f1c);
    jari(0.45,0.08,f2a,f2b,f2c);
    jari(0.45,-0.08,f3a,f3b,f3c);
    jari(0.45,-0.22,f4a-f4up,f4b-f4up,f4c-f4up);

    jempol();

    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int w,int h){
    if(w==0||h==0) return;
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60,(float)w/h,1,20);
    glMatrixMode(GL_MODELVIEW);
}

void reset(){
    f1a=f1b=f1c=0;
    f2a=f2b=f2c=0;
    f3a=f3b=f3c=0;
    f4a=f4b=f4c=0;
    f5a=f5b=f5c=0;
    f5up=0;
    f4up=0;
}

//keyboard buat gerakin
void keyboard(unsigned char key,int x,int y){
    switch(key){
        case 's': shoulder+=5; break;
        case 'S': shoulder-=5; break;
        case 'e': elbow+=5; break;
        case 'E': elbow-=5; break;
        case 'w': wrist+=5; break;
        case 'W': wrist-=5; break;

        case '1': f1a+=5; f1b+=4; f1c+=3; break;
        case '2': f2a+=5; f2b+=4; f2c+=3; break;
        case '3': f3a+=5; f3b+=4; f3c+=3; break;
        case '4': f4a+=5; f4b+=4; f4c+=3; break;
        case '5': f5a+=5; f5b+=4; f5c+=3; break;
        case '6': f5up+=5; break;
        case '7': f4up+=5; break;

        case 'r': reset(); break;

        case 27: exit(0);
    }

    f1a=batas(f1a); f1b=batas(f1b); f1c=batas(f1c);
    f2a=batas(f2a); f2b=batas(f2b); f2c=batas(f2c);
    f3a=batas(f3a); f3b=batas(f3b); f3c=batas(f3c);
    f4a=batas(f4a); f4b=batas(f4b); f4c=batas(f4c);
    f5a=batas_jempol(f5a); f5b=batas_jempol(f5b); f5c=batas_jempol(f5c);
    f5up=batas(f5up);
    f4up=batas(f4up);

    glutPostRedisplay();
}

//main
int main(int argc,char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(700,600);
    glutCreateWindow("tangann");
    glClearColor(0,0,0,0);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
