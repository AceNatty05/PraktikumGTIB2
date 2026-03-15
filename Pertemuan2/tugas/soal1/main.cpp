#include <GL/glut.h>
#include <math.h>

#define PI 3.1415926

void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    glBegin(GL_LINE_LOOP);

    int circle_points = 100;

    for(int i=0;i<circle_points;i++){
        float angle = 2 * PI * i / circle_points;
        glVertex2f(cos(angle)*0.5, sin(angle)*0.5);
    }

    glEnd();
    glPopMatrix();

    glFlush();
}

int main(int argc,char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600,600);
    glutCreateWindow("Lingkaran");

    glutDisplayFunc(display);

    glutMainLoop();
}
