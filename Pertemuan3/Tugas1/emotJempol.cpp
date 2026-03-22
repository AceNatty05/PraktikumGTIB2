#include <GL/glut.h>
#include <stdlib.h>

// Variabel kontrol gerakan
int shoulder = 0, elbow = 0, wrist = 0, armRotate = 0;
int fIndex = 0, fMiddle = 0, fRing = 0, fPinky = 0, thumbUp = 0, thumbFold = 0;

// Fungsi menggambar jari (Telunjuk - Kelingking)
void drawFinger(float yOffset, int bendAngle, float len1, float len2) {
    glPushMatrix();
        glTranslatef(0.4, yOffset, 0.0); 
        glRotatef((GLfloat)bendAngle, 0.0, 1.0, 0.0); 
        
        glTranslatef(len1/2, 0.0, 0.0);
        glPushMatrix();
            glScalef(len1, 0.15, 0.15); 
            glutWireCube(1.0);
        glPopMatrix();

        glTranslatef(len1/2, 0.0, 0.0);
        glRotatef((GLfloat)bendAngle, 0.0, 1.0, 0.0);
        glTranslatef(len2/2, 0.0, 0.0);
        glPushMatrix();
            glScalef(len2, 0.15, 0.15);
            glutWireCube(1.0);
        glPopMatrix();
    glPopMatrix();
}

// Fungsi menggambar Jempol
void drawThumb() {
    glPushMatrix();
        // Jempol berada di samping telapak
        glTranslatef(0.1, 0.6, 0.0); 
        
        // Logika Salut (Like): Berputar pada sumbu Z
        glRotatef((GLfloat)thumbUp, 0.0, 0.0, 1.0); 
        
        // Logika Lipat
        glRotatef((GLfloat)-thumbFold, 0.0, 1.0, 0.0); 

        // Ruas 1
        glTranslatef(0.2, 0.0, 0.0);
        glPushMatrix();
            glScalef(0.4, 0.2, 0.2); 
            glutWireCube(1.0);
        glPopMatrix();

        // Ruas 2
        glTranslatef(0.2, 0.0, 0.0);
        glRotatef((GLfloat)-thumbFold, 0.0, 1.0, 0.0); 
        glTranslatef(0.15, 0.0, 0.0);
        glPushMatrix();
            glScalef(0.3, 0.2, 0.2);
            glutWireCube(1.0);
        glPopMatrix();
    glPopMatrix();
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity(); 
    glTranslatef(0.0f, 0.0f, -12.0f); 

    glPushMatrix();
        // --- LENGAN ATAS ---
        glTranslatef(-2.5f, 0.0f, 0.0f);           
        glRotatef((GLfloat)shoulder, 0.0f, 0.0f, 1.0f); 
        glRotatef((GLfloat)armRotate, 1.0f, 0.0f, 0.0f); // Rotasi Lengan (X)
        glTranslatef(1.25f, 0.0f, 0.0f);            
        glPushMatrix();
            glScalef(2.5f, 0.6f, 0.6f); 
            glutWireCube(1.0f);
        glPopMatrix();

        // --- LENGAN BAWAH ---
        glTranslatef(1.25f, 0.0f, 0.0f);            
        glRotatef((GLfloat)elbow, 0.0f, 0.0f, 1.0f);
        glTranslatef(1.25f, 0.0f, 0.0f);            
        glPushMatrix();
            glScalef(2.5f, 0.6f, 0.6f); 
            glutWireCube(1.0f);
        glPopMatrix();

        // --- PERGELANGAN & TELAPAK ---
        glTranslatef(1.65f, 0.0f, 0.0f); 
        glRotatef((GLfloat)wrist, 0.0f, 0.0f, 1.0f); 
        glRotatef((GLfloat)armRotate, 1.0f, 0.0f, 0.0f); // Rotasi Telapak (X)
        
        glPushMatrix();
            glScalef(0.8, 1.2, 0.5); 
            glutWireCube(1.0);
        glPopMatrix();

        // JARI-JARI & JEMPOL
        drawThumb();         
        drawFinger(0.45, fIndex, 0.5, 0.4);   
        drawFinger(0.15, fMiddle, 0.6, 0.5);  
        drawFinger(-0.15, fRing, 0.55, 0.45); 
        drawFinger(-0.45, fPinky, 0.4, 0.3);  

    glPopMatrix(); 
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        // Kontrol Lengan (60 derajat)
        case 'r': armRotate = (armRotate + 45) % 360; break;
        case 'R': armRotate = (armRotate - 45) % 360; break;
        case 's': shoulder = (shoulder + 5) % 360; break;
        case 'S': shoulder = (shoulder - 5) % 360; break;
        case 'e': elbow = (elbow + 5) % 360; break;
        case 'E': elbow = (elbow - 5) % 360; break;
        case 'w': wrist = (wrist + 60) % 360; break;
        case 'W': wrist = (wrist - 60) % 360; break;

        // Kontrol Jari
        case 'a': if(fIndex < 90) fIndex += 5; break;
        case 'A': if(fIndex > 0) fIndex -= 5; break;
        case 'b': if(fMiddle < 90) fMiddle += 5; break;
        case 'B': if(fMiddle > 0) fMiddle -= 5; break;
        case 'c': if(fRing < 90) fRing += 5; break;
        case 'C': if(fRing > 0) fRing -= 5; break;
        case 'd': if(fPinky < 90) fPinky += 5; break;
        case 'D': if(fPinky > 0) fPinky -= 5; break;

        // Kontrol Jempol (Salut)
        case 't': if(thumbUp < 90) thumbUp += 5; break;   // Like ke atas
        case 'T': if(thumbUp > -90) thumbUp -= 5; break;  // Dislike ke bawah
        case 'g': if(thumbFold < 90) thumbFold += 5; break; 
        case 'G': if(thumbFold > 0) thumbFold -= 5; break;
        
        case 27: exit(0); break; 
    }
    glutPostRedisplay();
}

void Reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (GLfloat)w / (GLfloat)h, 1.0, 40.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1000, 700);
    glutCreateWindow("Lengan Robot");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glutDisplayFunc(display);
    glutReshapeFunc(Reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}

