//Nama: Muhammad ibrahim Alghifari
//NIM: 24060124140140
//Lab: B2
#include <GL/glut.h>


int shoulder = 0, elbow = 0, wrist = 0;
int finger1 = 0, finger2 = 0, finger3 = 0, finger4 = 0, finger5 = 0;

void Reshape(int w, int h) {
    if (h == 0) h = 1;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70.0, (GLfloat)w / (GLfloat)h, 1.0, 30.0);
    glMatrixMode(GL_MODELVIEW);
}

void DrawFinger(float length, float width, float height, int angle, float posX, float posY, float posZ) {
    glPushMatrix();
    glTranslatef(posX, posY, posZ);
    glRotatef((GLfloat)angle, 0.0, 0.0, 1.0);
    glTranslatef(length/2, 0.0, 0.0);
    glPushMatrix();
    glScalef(length, width, height);
    glutWireCube(1.0);
    glPopMatrix();
    glPopMatrix();
}

void Display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -12.0); 
    
    glPushMatrix();
    glTranslatef(-2.0, 0.0, 0.0);
    if (shoulder > 90) shoulder = 90;
    if (shoulder < -45) shoulder = -45;
    glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
    glTranslatef(2.0, 0.0, 0.0);
    
    glPushMatrix();
    glScalef(4.0, 0.8, 0.8);
    glutWireCube(1.0);
    glPopMatrix();
    
    glTranslatef(2.0, 0.0, 0.0);
    if (elbow > 135) elbow = 135;
    if (elbow < 0) elbow = 0;
    glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
    glTranslatef(2.0, 0.0, 0.0);
    
    glPushMatrix();
    glScalef(4.0, 0.8, 0.8);
    glutWireCube(1.0);
    glPopMatrix();
    
    // Pergelangan tangan
    glTranslatef(2.0, 0.0, 0.0);
    if (wrist > 45) wrist = 45;
    if (wrist < -45) wrist = -45;
    glRotatef((GLfloat)wrist, 0.0, 0.0, 1.0);
    
    // Telapak tangan
    glPushMatrix();
    glTranslatef(0.75, 0.0, 0.0);
    glScalef(1.5, 1.0, 0.6);
    glutWireCube(1.0);
    glPopMatrix();
    
    glTranslatef(1.5, 0.0, 0.0);
    
    DrawFinger(0.7, 0.18, 0.18, finger1, 0.0, 0.35, 0.15);   // telunjuk
    DrawFinger(0.8, 0.18, 0.18, finger2, 0.0, 0.1, 0.15);    // tengah
    DrawFinger(0.7, 0.18, 0.18, finger3, 0.0, -0.15, 0.15);  // manis
    DrawFinger(0.6, 0.15, 0.15, finger4, 0.0, -0.4, 0.15);   // kelingking
    DrawFinger(0.6, 0.18, 0.18, finger5, -0.4, 0.55, -0.15); // jempol
    
    glPopMatrix(); 
    glPopMatrix(); 
    
    glutSwapBuffers();
}

void Keyboard(unsigned char key, int x, int y) {
    switch (key) {
        
        case 's': shoulder = (shoulder + 5);
                  if (shoulder > 90) shoulder = 90;
                  break;
        case 'S': shoulder = (shoulder - 5);
                  if (shoulder < -45) shoulder = -45;
                  break;
        
        
        case 'e': elbow = (elbow + 5);
                  if (elbow > 135) elbow = 135;
                  break;
        case 'E': elbow = (elbow - 5);
                  if (elbow < 0) elbow = 0;
                  break;
        
        // Kontrol pergelangan
        case 'w': wrist = (wrist + 5); 
                  if (wrist > 45) wrist = 45;
                  break;
        case 'W': wrist = (wrist - 5);
                  if (wrist < -45) wrist = -45;
                  break;
        
        // Kontrol jari telunjuk
        case '1': finger1 = (finger1 + 5) % 90; break;
        case '!': finger1 = (finger1 - 5) % 90; break;
        
        // Kontrol jari tengah
        case '2': finger2 = (finger2 + 5) % 90; break;
        case '@': finger2 = (finger2 - 5) % 90; break;
        
        // Kontrol jari manis
        case '3': finger3 = (finger3 + 5) % 90; break;
        case '#': finger3 = (finger3 - 5) % 90; break;
        
        // Kontrol jari kelingking
        case '4': finger4 = (finger4 + 5) % 90; break;
        case '$': finger4 = (finger4 - 5) % 90; break;
        
        // Kontrol jempol
        case '5': finger5 = (finger5 + 5) % 90; break;
        case '%': finger5 = (finger5 - 5) % 90; break;
        
        case 27: exit(0); break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600); 
    glutCreateWindow("Tangan");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClearDepth(1.0);
    glEnable(GL_DEPTH_TEST);
    
    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);
    glutKeyboardFunc(Keyboard);
    
    glutMainLoop();
    return 0;
}
