#include <GL/glut.h>
#include <stdlib.h>

static void
resize(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

static void
display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    // TUGAS 1 
    // GL_POINTS dan GL_LINES
    
    // titik merah ///////////////////////////////////////
    glPointSize(8.0);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POINTS);
        glVertex2f(-0.95, 0.92);
        glVertex2f(-0.82, 0.92);
        glVertex2f(-0.69, 0.92);
        glVertex2f(-0.56, 0.92);
    glEnd();

    // garis biru ///////////////////////////////////////
    glColor3f(0.0, 0.0, 1.0);
    glLineWidth(1.5);
    glBegin(GL_LINES);
        glVertex2f(-0.95, 0.80);
        glVertex2f(-0.50, 0.80);

        glVertex2f(-0.95, 0.65);
        glVertex2f(-0.50, 0.65);

        glVertex2f(-0.72, 0.85);
        glVertex2f(-0.72, 0.58);
    glEnd();


    // TUGAS 2 
    // gl_line_strip/////////////////////////////////////
    glColor3f(1.0, 0.0, 0.0);
    glLineWidth(1.5);
    glBegin(GL_LINE_STRIP);
        glVertex2f(0.10, 0.95);
        glVertex2f(0.25, 0.82);
        glVertex2f(0.15, 0.70);
        glVertex2f(0.30, 0.60);
    glEnd();

    // gl_line_loop//////////////////////////////////////
    glColor3f(0.0, 0.5, 1.0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(0.50, 0.95);
        glVertex2f(0.68, 0.95);
        glVertex2f(0.76, 0.80);
        glVertex2f(0.68, 0.62);
        glVertex2f(0.50, 0.62);
        glVertex2f(0.42, 0.80);
    glEnd();

    // gl_triangle_fan///////////////////////////////////
    glColor3f(0.0, 0.8, 0.0);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0.20, 0.45);
        glVertex2f(0.05, 0.35);
        glVertex2f(0.08, 0.20);
        glVertex2f(0.22, 0.13);
        glVertex2f(0.36, 0.22);
        glVertex2f(0.35, 0.38);
    glEnd();

    // gl_triangle_strip/////////////////////////////////
    glColor3f(1.0, 0.5, 0.0);
    glBegin(GL_TRIANGLE_STRIP);
        glVertex2f(0.48, 0.48);
        glVertex2f(0.48, 0.18);
        glVertex2f(0.62, 0.48);
        glVertex2f(0.62, 0.18);
        glVertex2f(0.76, 0.48);
        glVertex2f(0.76, 0.18);
    glEnd();

    // gl_quads//////////////////////////////////////////
    glColor3f(0.5, 0.0, 0.8);
    glBegin(GL_QUADS);
        glVertex2f(0.05, 0.10);
        glVertex2f(0.30, 0.10);
        glVertex2f(0.30, -0.10);
        glVertex2f(0.05, -0.10);
    glEnd();

    // gl_quad_strip//////////////////////////////////////
    glColor3f(0.0, 0.8, 0.8);
    glBegin(GL_QUAD_STRIP);
        glVertex2f(0.42, 0.10);
        glVertex2f(0.42, -0.10);
        glVertex2f(0.55, 0.10);
        glVertex2f(0.55, -0.10);
        glVertex2f(0.68, 0.10);
        glVertex2f(0.68, -0.10);
        glVertex2f(0.80, 0.10);
        glVertex2f(0.80, -0.10);
    glEnd();

    // TUGAS 3 
    // kubus bertingkat///////////////////////////////////

    glColor3f(1.0, 0.5, 0.7);

    //3 kubus////////////////////////////////////////////
    glBegin(GL_QUADS);
        glVertex2f(-0.90, -0.95);
        glVertex2f(-0.60, -0.95);
        glVertex2f(-0.60, -0.65);
        glVertex2f(-0.90, -0.65);
    glEnd();

    glBegin(GL_QUADS);
        glVertex2f(-0.52, -0.95);
        glVertex2f(-0.22, -0.95);
        glVertex2f(-0.22, -0.65);
        glVertex2f(-0.52, -0.65);
    glEnd();

    glBegin(GL_QUADS);
        glVertex2f(-0.14, -0.95);
        glVertex2f(0.16, -0.95);
        glVertex2f(0.16, -0.65);
        glVertex2f(-0.14, -0.65);
    glEnd();

    //2 kubus////////////////////////////////////////
    glBegin(GL_QUADS);
        glVertex2f(-0.71, -0.57);
        glVertex2f(-0.41, -0.57);
        glVertex2f(-0.41, -0.27);
        glVertex2f(-0.71, -0.27);
    glEnd();

    glBegin(GL_QUADS);
        glVertex2f(-0.33, -0.57);
        glVertex2f(-0.03, -0.57);
        glVertex2f(-0.03, -0.27);
        glVertex2f(-0.33, -0.27);
    glEnd();

    //1 kubus////////////////////////////////////////
    glBegin(GL_QUADS);
        glVertex2f(-0.52, -0.19);
        glVertex2f(-0.22, -0.19);
        glVertex2f(-0.22, 0.11);
        glVertex2f(-0.52, 0.11);
    glEnd();

    // outline//////////////////////////////////////
    glColor3f(0.8, 0.2, 0.4);
    glLineWidth(2.0);

    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.90, -0.95);
        glVertex2f(-0.60, -0.95);
        glVertex2f(-0.60, -0.65);
        glVertex2f(-0.90, -0.65);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.52, -0.95);
        glVertex2f(-0.22, -0.95);
        glVertex2f(-0.22, -0.65);
        glVertex2f(-0.52, -0.65);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.14, -0.95);
        glVertex2f(0.16, -0.95);
        glVertex2f(0.16, -0.65);
        glVertex2f(-0.14, -0.65);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.71, -0.57);
        glVertex2f(-0.41, -0.57);
        glVertex2f(-0.41, -0.27);
        glVertex2f(-0.71, -0.27);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.33, -0.57);
        glVertex2f(-0.03, -0.57);
        glVertex2f(-0.03, -0.27);
        glVertex2f(-0.33, -0.27);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.52, -0.19);
        glVertex2f(-0.22, -0.19);
        glVertex2f(-0.22, 0.11);
        glVertex2f(-0.52, 0.11);
    glEnd();

    glutSwapBuffers();
}

static void
key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27:
        case 'q':
            exit(0);
            break;
    }
    glutPostRedisplay();
}

int
main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(10, 10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutCreateWindow("Tugas Pertemuan1");
    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glClearColor(1, 1, 1, 1);
    glutMainLoop();
    return EXIT_SUCCESS;
}