#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

void RenderScene(void){
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
        glBegin(GL_LINE_LOOP);
            GLint circlePoints = 100;
            for (int i = 0; i < circlePoints; i++){
                float angle = 2 * PI * i / circlePoints;
                glVertex2f(cos(angle), sin(angle));
            }
        glEnd();
    glPopMatrix();

glFlush();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("lingkaran");
    glutDisplayFunc(RenderScene);
    glClearColor(0.05f, 0.05f, 0.15f, 1.0f);
    glutMainLoop();
    return 0;
}