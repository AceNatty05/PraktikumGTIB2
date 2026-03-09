#include <GL/glut.h>

void snowflakeArm() {
    glBegin(GL_LINES);
        glVertex2f(0.0, 0.0);
        glVertex2f(0.0, 0.5);

        glVertex2f(0.0, 0.3);
        glVertex2f(0.1, 0.4);

        glVertex2f(0.0, 0.3);
        glVertex2f(-0.1, 0.4);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    snowflakeArm();

    glPushMatrix();
        glRotatef(60, 0.0, 0.0, 1.0);
        snowflakeArm();
    glPopMatrix();

    glPushMatrix();
        glRotatef(120, 0.0, 0.0, 1.0);
        snowflakeArm();
    glPopMatrix();

    glPushMatrix();
        glRotatef(180, 0.0, 0.0, 1.0);
        snowflakeArm();
    glPopMatrix();

    glPushMatrix();
        glRotatef(240, 0.0, 0.0, 1.0);
        snowflakeArm();
    glPopMatrix();

    glPushMatrix();
        glRotatef(300, 0.0, 0.0, 1.0);
        snowflakeArm();
    glPopMatrix();

    glFlush();
}

void init() {
    glClearColor(1,1,1,1); 
    glColor3f(0,0,0);      

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1,1,-1,1);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600,600);
    glutCreateWindow("Snowflake Manual Rotation");

    init();
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
