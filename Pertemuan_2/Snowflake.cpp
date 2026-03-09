#include <GL/glut.h>

void snowflakeArm() {
    // 1 objek dasar (1 lengan snowflake)
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

    // objek pertama (tanpa rotasi)
    snowflakeArm();

    // rotasi 1
    glPushMatrix();
        glRotatef(60, 0.0, 0.0, 1.0);
        snowflakeArm();
    glPopMatrix();

    // rotasi 2
    glPushMatrix();
        glRotatef(120, 0.0, 0.0, 1.0);
        snowflakeArm();
    glPopMatrix();

    // rotasi 3
    glPushMatrix();
        glRotatef(180, 0.0, 0.0, 1.0);
        snowflakeArm();
    glPopMatrix();

    // rotasi 4
    glPushMatrix();
        glRotatef(240, 0.0, 0.0, 1.0);
        snowflakeArm();
    glPopMatrix();

    // rotasi 5
    glPushMatrix();
        glRotatef(300, 0.0, 0.0, 1.0);
        snowflakeArm();
    glPopMatrix();

    glFlush();
}

void init() {
    glClearColor(1,1,1,1); // background putih
    glColor3f(0,0,0);      // warna hitam

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
