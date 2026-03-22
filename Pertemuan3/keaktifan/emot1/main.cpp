#include <GL/glut.h> 

static int thumb1 = 0, thumb2 = 0, thumb11 = 0; 
static int telunjuk1 = 85, telunjuk2 = 0, telunjuk3 = 0; 
static int jTengah1 = 85, jTengah2 = 0, jTengah3 = 0; 
static int jManis1 = 85, jManis2 = 0, jManis3 = 0; 
static int kelingking1 = 85, kelingking2 = 0, kelingking3 = 0; 
static int telapak1 = -90, telapak2 = 0; 
static int lenganA1 = 0, lenganA2 = 0,lenganB = 0; 
int mode = 0;
 
void init(void){ 
 glClearColor(0,0,0,0); 
 glShadeModel(GL_FLAT); 
} 
 
void tampilan(void){ 
 glClear(GL_COLOR_BUFFER_BIT); 
 glPushMatrix(); 
  //lengan atas 
  glTranslatef(-1.8,0,0); 
  glRotatef((GLfloat) lenganA1,0,0,1); 
  glRotatef((GLfloat) lenganA2,0,1,0); 
  glTranslatef(1.8,0,0); 
  glPushMatrix(); 
   glTranslatef(-1.4,0,0); 
   glScalef(0.8,0.2,0.56); 
   glutWireCube(1); 
  glPopMatrix(); 
  //lengan bawah 
  glTranslatef(-1,0,0); 
  glRotatef((GLfloat) lenganB,0,0,1); 
  glTranslatef(1,0,0); 
  glPushMatrix(); 
   glTranslatef(-0.6,0,0); 
   glScalef(0.8,0.2,0.56); 
   glutWireCube(1); 
  glPopMatrix(); 
  //telapak 
  glRotatef((GLfloat) telapak1, 1,0,0); 
  glRotatef((GLfloat) telapak2, 0,0,1); 
  glPushMatrix(); 
   glScalef (0.4, 0.2, 0.56);  
   glutWireCube (1.0);  
  glPopMatrix(); 
  //ibu jari 
  glPushMatrix(); 
   glTranslatef(0,0,0.38); 
   glRotatef((GLfloat) -thumb11,1,0,0); 
   glRotatef((GLfloat) thumb1,0,1,0); 
   glPushMatrix(); 
    glScalef(0.1,0.1,0.2); 
    glutWireCube(1.0); 
   glPopMatrix(); 
   glTranslatef(0,0,0.2); 
   glRotatef((GLfloat) -thumb2,1,0,0); 
   glPushMatrix(); 
    glScalef(0.1,0.1,0.25); 
    glutWireCube(1.0); 
   glPopMatrix(); 
  glPopMatrix(); 

  //jari telunjuk 
  glPushMatrix(); 
   glTranslatef(0.3,0,0.22); 
   glRotatef((GLfloat) telunjuk1,0,0,1); 
   glPushMatrix(); 
    glScalef(0.2,0.1,0.13); 
    glutWireCube(1.0); 
   glPopMatrix(); 
   glTranslatef(0.2,0,0); 
   glRotatef((GLfloat) telunjuk2,0,0,1); 
   glPushMatrix(); 
    glScalef(0.22,0.1,0.13); 
    glutWireCube(1.0); 
   glPopMatrix(); 
   glTranslatef(0.22,0,0); 
   glRotatef((GLfloat) telunjuk3,0,0,1); 
   glPushMatrix(); 
    glScalef(0.21,0.1,0.13); 
    glutWireCube(1.0); 
   glPopMatrix(); 
  glPopMatrix(); 
   
  //jari tengah 
  glPushMatrix(); 
   glTranslatef(0.3,0,0.05); 
   glRotatef((GLfloat) jTengah1,0,0,1); 
   glPushMatrix(); 
    glScalef(0.25,0.1,0.14); 
    glutWireCube(1.0); 
   glPopMatrix(); 
   glTranslatef(0.25,0,0); 
   glRotatef((GLfloat) jTengah2,0,0,1); 
   glPushMatrix(); 
    glScalef(0.27,0.1,0.14); 
    glutWireCube(1.0); 
   glPopMatrix(); 
   glTranslatef(0.27,0,0); 
   glRotatef((GLfloat) jTengah3,0,0,1); 
   glPushMatrix(); 
    glScalef(0.21,0.1,0.14); 
    glutWireCube(1.0); 
   glPopMatrix(); 
  glPopMatrix(); 
   
  //jari manis 
  glPushMatrix(); 
   glTranslatef(0.3,0,-0.1); 
   glRotatef((GLfloat) jManis1,0,0,1); 
   glPushMatrix(); 
    glScalef(0.2,0.1,0.11); 
    glutWireCube(1.0); 
   glPopMatrix(); 
   glTranslatef(0.2,0,0); 
   glRotatef((GLfloat) jManis2,0,0,1); 
   glPushMatrix(); 
    glScalef(0.21,0.1,0.11); 
    glutWireCube(1.0); 
   glPopMatrix(); 
   glTranslatef(0.21,0,0); 
   glRotatef((GLfloat) jManis3,0,0,1); 
   glPushMatrix(); 
    glScalef(0.2,0.1,0.11); 
    glutWireCube(1.0); 
   glPopMatrix(); 
  glPopMatrix(); 
   
  //jari kelingking 
  glPushMatrix(); 
   glTranslatef(0.3,0,-0.21); 
   glRotatef((GLfloat) kelingking1,0,0,1); 
   glPushMatrix(); 
    glScalef(0.18,0.1,0.1); 
    glutWireCube(1.0); 
   glPopMatrix(); 
   glTranslatef(0.18,0,0); 
   glRotatef((GLfloat) kelingking2,0,0,1); 
   glPushMatrix(); 
    glScalef(0.17,0.1,0.1); 
    glutWireCube(1.0); 
   glPopMatrix(); 
   glTranslatef(0.17,0,0); 
   glRotatef((GLfloat) kelingking3,0,0,1); 
   glPushMatrix(); 
    glScalef(0.19,0.1,0.1); 
    glutWireCube(1.0); 
   glPopMatrix(); 
  glPopMatrix(); 
   
 glPopMatrix(); 
 glutSwapBuffers(); 
} 

void reshape (int w, int h) {  
 glViewport (0, 0, (GLsizei) w, (GLsizei) h);  
 glMatrixMode (GL_PROJECTION);  
 glLoadIdentity ();  
 gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);  
 glMatrixMode(GL_MODELVIEW);  
 glLoadIdentity();  
 glTranslatef (0.0, 0.0, -5.0);  
} 

//void keyboard(unsigned char key, int x, int y) {  
//
// switch (key){
//
//  // ?? GANTI MODE
//  case '1': mode = 0; break; // lengan + telapak
//  case '2': mode = 1; return; // jari
//
//  case 27: exit(0);
//
//  case 9:
//    kelingking1 = kelingking2 = kelingking3 = 
//    lenganA1 = lenganA2 = lenganB = 
//    jManis1 = jManis2 = jManis3 = 
//    jTengah1 = jTengah2 = jTengah3 = 
//    telunjuk1 = telunjuk2 = telunjuk3 = 
//    thumb1 = thumb11 = thumb2 = 
//    telapak1 = telapak2 = 0;
//    glutPostRedisplay();
//    break;
// }
//
// // ?? BAGIAN MODE
// switch(mode){
//
//  // =========================
//  // MODE 0 ? LENGAN 
//  // =========================
//  case 0:
//    switch (key){
//
//      case 'q': lenganA1 = (lenganA1 + 5); if(lenganA1 > 110) lenganA1 = 110; break;
//      case 'Q': lenganA1 = (lenganA1 - 5); if(lenganA1 < -110) lenganA1 = -110; break;
//
//      case 'w': lenganA2 = (lenganA2 + 5); if (lenganA2 > 90) lenganA2 = 90; break;
//      case 'W': lenganA2 = (lenganA2 - 5); if (lenganA2 < -90) lenganA2 = -90; break;
//
//      case 'a': lenganB = (lenganB + 5); if(lenganB > 120) lenganB = 120; break;
//      case 'A': lenganB = (lenganB - 5); if(lenganB < 0) lenganB = 0; break;
//
//      case 'z': telapak1 = (telapak1 + 5); if(telapak1 > 90) telapak1 =90; break;
//      case 'Z': telapak1 = (telapak1 - 5); if(telapak1 < -90) telapak1 =-90; break;
//
//      case 'x': telapak2 = (telapak2 + 5); if (telapak2 > 90) telapak2 = 90; break;
//      case 'X': telapak2 = (telapak2 - 5); if (telapak2 < 0) telapak2 = 0; break;
//
//      case 'c': thumb11 = (thumb11 + 5); if (thumb11 > 90) thumb11 = 90; break;
//      case 'C': thumb11 = (thumb11 - 5); if (thumb11 < 0) thumb11 = 0; break;
//
//    }
//    break;
//
//
// // =========================
//// MODE 1 ? SEMUA JARI
//// =========================
//case 1:
//    switch(key){
//
//    // ===== TELUNJUK ===== (Q W E)
//    case 'q': telunjuk1 += 5; break;
//    case 'a': telunjuk1 -= 5; break;
//
//    case 'w': telunjuk2 += 5; break;
//    case 's': telunjuk2 -= 5; break;
//
//    case 'e': telunjuk3 += 5; break;
//    case 'd': telunjuk3 -= 5; break;
//
//
//    // ===== JARI TENGAH ===== (R T Y)
//    case 'r': jTengah1 += 5; break;
//    case 'f': jTengah1 -= 5; break;
//
//    case 't': jTengah2 += 5; break;
//    case 'g': jTengah2 -= 5; break;
//
//    case 'y': jTengah3 += 5; break;
//    case 'h': jTengah3 -= 5; break;
//
//
//    // ===== JARI MANIS ===== (U I O)
//    case 'u': jManis1 += 5; break;
//    case 'j': jManis1 -= 5; break;
//
//    case 'i': jManis2 += 5; break;
//    case 'k': jManis2 -= 5; break;
//
//    case 'o': jManis3 += 5; break;
//    case 'l': jManis3 -= 5; break;
//
//
//    // ===== KELINGKING ===== (Z X C)
//    case 'z': kelingking1 += 5; break;
//    case 'x': kelingking1 -= 5; break;
//
//    case 'c': kelingking2 += 5; break;
//    case 'v': kelingking2 -= 5; break;
//
//    case 'b': kelingking3 += 5; break;
//    case 'n': kelingking3 -= 5; break;
//
//
//    // ===== JEMPOL =====
//    case 'p': thumb1 += 5; break;
//    case ';': thumb1 -= 5; break;
//
//    case '[': thumb2 += 5; break;
//    case ']': thumb2 -= 5; break;
//
//    }
//   
//    break;
// }
//
// glutPostRedisplay();
//}

int main(int argc, char** argv) {  
 glutInit(&argc, argv);  
 glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);  
 glutInitWindowSize (700, 600);  
 glutInitWindowPosition (100, 100);  
 glutCreateWindow (argv[0]);  
 init();  
 glutDisplayFunc(tampilan);  
 glutReshapeFunc(reshape);  
// glutKeyboardFunc(keyboard);  
 glutMainLoop();  
 return 0; 
}
