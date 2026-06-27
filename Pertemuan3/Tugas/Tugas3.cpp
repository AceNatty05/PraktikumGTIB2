#include <GL/glut.h>

int pund = 0, siku = 0, gelang = 0, jari1 = 0, jari2 = 0, jari3 = 0, jari4 = 0, jari5 = 0;

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
    if (pund > 90) pund = 90;
    if (pund < -45) pund = -45;
    glRotatef((GLfloat)pund, 0.0, 0.0, 1.0);
    glTranslatef(2.0, 0.0, 0.0);
    
    glPushMatrix();
    glScalef(4.0, 0.8, 0.8);
    glutWireCube(1.0);
    glPopMatrix();
    
    glTranslatef(2.0, 0.0, 0.0);
    if (siku > 135) siku = 135;
    if (siku < 0) siku = 0;
    glRotatef((GLfloat)siku, 0.0, 0.0, 1.0);
    glTranslatef(2.0, 0.0, 0.0);
    
    glPushMatrix();
    glScalef(4.0, 0.8, 0.8);
    glutWireCube(1.0);
    glPopMatrix();
    
    // Pergelangan tangan
    glTranslatef(2.0, 0.0, 0.0);
    if (gelang > 45) gelang = 45;
    if (gelang < -45) gelang = -45;
    glRotatef((GLfloat)gelang, 0.0, 0.0, 1.0);
    
    glPushMatrix();
    glTranslatef(0.75, 0.0, 0.0);
    glScalef(1.5, 1.0, 0.6);
    glutWireCube(1.0);
    glPopMatrix();
    
    glTranslatef(1.5, 0.0, 0.0);
    
    DrawFinger(0.7, 0.18, 0.18, jari1, 0.0, 0.35, 0.15);   
    DrawFinger(0.8, 0.18, 0.18, jari2, 0.0, 0.1, 0.15);    
    DrawFinger(0.7, 0.18, 0.18, jari3, 0.0, -0.15, 0.15);  
    DrawFinger(0.6, 0.15, 0.15, jari4, 0.0, -0.4, 0.15);   
    DrawFinger(0.6, 0.18, 0.18, jari5, -0.4, 0.55, -0.15); 
    
    glPopMatrix(); 
    glPopMatrix(); 
    
    glutSwapBuffers();
}

void Keyboard(unsigned char key, int x, int y) {
    switch (key) {
        
        case 's': pund = (pund + 5);
                  if (pund > 90) pund = 90;
                  break;
        case 'S': pund = (pund - 5);
                  if (pund < -45) pund = -45;
                  break;
        
        
        case 'e': siku = (siku + 5);
                  if (siku > 135) siku = 135;
                  break;
        case 'E': siku = (siku - 5);
                  if (siku < 0) siku = 0;
                  break;
        
        case 'w': gelang = (gelang + 5); 
                  if (gelang > 45) gelang = 45;
                  break;
        case 'W': gelang = (gelang - 5);
                  if (gelang < -45) gelang = -45;
                  break;
        
        case '1': jari1 = (jari1 + 5) % 90; break;
        case '!': jari1 = (jari1 - 5) % 90; break;
        
        case '2': jari2 = (jari2 + 5) % 90; break;
        case '@': jari2 = (jari2 - 5) % 90; break;
        
        case '3': jari3 = (jari3 + 5) % 90; break;
        case '#': jari3 = (jari3 - 5) % 90; break;
        
        case '4': jari4 = (jari4 + 5) % 90; break;
        case '$': jari4 = (jari4 - 5) % 90; break;
        
        case '5': jari5 = (jari5 + 5) % 90; break;
        case '%': jari5 = (jari5 - 5) % 90; break;
        
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

