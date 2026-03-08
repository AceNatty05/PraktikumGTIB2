#include <GL/glut.h>
#include <math.h>

#define PI 3.14159265358979323846

void display() {
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    // -- GL_POINTS --
    glPointSize(8.0f);
    glBegin(GL_POINTS);
        glColor3f(1.0f, 0.5f, 0.7f);  
		glVertex2f(-0.85f,  0.80f);
        glColor3f(0.5f, 0.8f, 1.0f);  
		glVertex2f(-0.70f,  0.90f);
        glColor3f(0.6f, 1.0f, 0.7f);  
		glVertex2f(-0.55f,  0.75f);
        glColor3f(1.0f, 0.9f, 0.5f);  
		glVertex2f(-0.75f,  0.70f);
        glColor3f(0.8f, 0.6f, 1.0f);  
		glVertex2f(-0.60f,  0.85f);
    glEnd();

    // -- GL_LINES --
    glLineWidth(2.0f);
    glBegin(GL_LINES);
        glColor3f(0.5f, 0.8f, 1.0f);
        glVertex2f(-0.40f, 0.90f);  
		glVertex2f(-0.10f, 0.70f);

        glColor3f(1.0f, 0.6f, 0.8f);
        glVertex2f(-0.30f, 0.70f);  
		glVertex2f(-0.05f, 0.90f);

        glColor3f(0.6f, 1.0f, 0.7f);
        glVertex2f(-0.35f, 0.80f);  
		glVertex2f(-0.10f, 0.80f);
    glEnd();

    // -- GL_LINE_STRIP --
    glLineWidth(2.0f);
    glColor3f(0.5f, 0.7f, 1.0f);
    glBegin(GL_LINE_STRIP);
        glVertex2f( 0.10f,  0.70f);
        glVertex2f( 0.25f,  0.90f);
        glVertex2f( 0.40f,  0.72f);
        glVertex2f( 0.55f,  0.90f);
        glVertex2f( 0.70f,  0.72f);
        glVertex2f( 0.85f,  0.88f);
    glEnd();

    // -- GL_LINE_LOOP --
    glLineWidth(1.5f);
    glColor3f(0.6f, 0.6f, 0.6f);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.85f,  0.55f);
        glVertex2f(-0.65f,  0.65f);
        glVertex2f(-0.45f,  0.55f);
        glVertex2f(-0.65f,  0.40f);
    glEnd();

    // -- GL_TRIANGLE_FAN --
    float fanColors[8][3] = {
        {1.0f,0.7f,0.9f},{0.7f,0.9f,1.0f},{0.7f,1.0f,0.8f},{1.0f,0.95f,0.6f},
        {0.85f,0.7f,1.0f},{1.0f,0.7f,0.8f},{0.7f,1.0f,0.9f},{1.0f,0.85f,0.7f}
    };
    glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(0.20f, 0.53f);
        for (int i = 0; i <= 8; i++) {
            float a = (float)i / 8 * 2 * PI - PI / 2;
            glColor3f(fanColors[i%8][0], fanColors[i%8][1], fanColors[i%8][2]);
            glVertex2f(0.20f + 0.18f * cos(a), 0.53f + 0.18f * sin(a));
        }
    glEnd();

    // -- GL_TRIANGLE_STRIP --
    glBegin(GL_TRIANGLE_STRIP);
        glColor3f(1.0f, 0.7f, 0.9f);  
		glVertex2f( 0.50f,  0.65f);
        glColor3f(0.8f, 0.7f, 1.0f);  
		glVertex2f( 0.50f,  0.42f);
        glColor3f(0.7f, 0.9f, 1.0f);  
		glVertex2f( 0.63f,  0.65f);
        glColor3f(0.7f, 1.0f, 0.8f);  
		glVertex2f( 0.63f,  0.42f);
        glColor3f(1.0f, 0.95f,0.6f);  
		glVertex2f( 0.76f,  0.65f);
        glColor3f(0.9f, 0.7f, 1.0f);  
		glVertex2f( 0.76f,  0.42f);
        glColor3f(0.7f, 1.0f, 0.9f);  
		glVertex2f( 0.88f,  0.65f);
        glColor3f(1.0f, 0.8f, 0.7f);  
		glVertex2f( 0.88f,  0.42f);
    glEnd();

    // -- GL_QUADS --
    glBegin(GL_QUADS);
        glColor3f(0.7f, 0.9f, 1.0f);  
		glVertex2f(-0.85f,  0.35f);
        glColor3f(1.0f, 0.95f,0.6f);  
		glVertex2f(-0.45f,  0.35f);
        glColor3f(1.0f, 0.7f, 0.9f);  
		glVertex2f(-0.45f,  0.15f);
        glColor3f(0.7f, 1.0f, 0.8f);  
		glVertex2f(-0.85f,  0.15f);
    glEnd();

    // -- GL_QUAD_STRIP --
    glBegin(GL_QUAD_STRIP);
        glColor3f(0.7f, 0.9f, 1.0f);   
		glVertex2f( 0.10f,  0.35f);
        glColor3f(0.7f, 0.9f, 1.0f);   
		glVertex2f( 0.10f,  0.15f);
        glColor3f(0.85f,0.7f, 1.0f);   
		glVertex2f( 0.32f,  0.35f);
        glColor3f(0.85f,0.7f, 1.0f);   
		glVertex2f( 0.32f,  0.15f);
        glColor3f(0.7f, 1.0f, 0.85f);  
		glVertex2f( 0.54f,  0.35f);
        glColor3f(0.7f, 1.0f, 0.85f);  
		glVertex2f( 0.54f,  0.15f);
        glColor3f(1.0f, 0.95f,0.6f);   
		glVertex2f( 0.76f,  0.35f);
        glColor3f(1.0f, 0.95f,0.6f);   
		glVertex2f( 0.76f,  0.15f);
        glColor3f(1.0f, 0.7f, 0.85f);  
		glVertex2f( 0.88f,  0.35f);
        glColor3f(1.0f, 0.7f, 0.85f);  
		glVertex2f( 0.88f,  0.15f);
    glEnd();

    // -- KUBUS BERTINGKAT --
    float s   = 0.18f;
    float gap = 0.02f;

    // baris bawah: 3 kubus
    float bx[3] = { -0.60f, -0.60f + s+gap, -0.60f + 2*(s+gap) };
    float by = -0.55f;

    for (int i = 0; i < 3; i++) {
        glBegin(GL_QUADS);
            glColor3f(0.7f, 0.85f, 1.0f);   
			glVertex2f(bx[i],   by);
            glColor3f(0.7f, 0.85f, 1.0f);   
			glVertex2f(bx[i]+s, by);
            glColor3f(0.85f,0.95f, 1.0f);   
			glVertex2f(bx[i]+s, by+s);
            glColor3f(0.85f,0.95f, 1.0f);   
			glVertex2f(bx[i],   by+s);
        glEnd();
        glColor3f(0.55f, 0.70f, 0.85f);
        glLineWidth(1.0f);
        glBegin(GL_LINE_LOOP);
            glVertex2f(bx[i],   by);
            glVertex2f(bx[i]+s, by);
            glVertex2f(bx[i]+s, by+s);
            glVertex2f(bx[i],   by+s);
        glEnd();
    }

    // baris atas: 2 kubus
    float tx[2] = { bx[0]+(s+gap)*0.5f, bx[1]+(s+gap)*0.5f };
    float ty = by + s + gap;

    for (int i = 0; i < 2; i++) {
        glBegin(GL_QUADS);
            glColor3f(0.7f, 0.85f, 1.0f);   
			glVertex2f(tx[i],   ty);
            glColor3f(0.7f, 0.85f, 1.0f);   
			glVertex2f(tx[i]+s, ty);
            glColor3f(0.85f,0.95f, 1.0f);   
			glVertex2f(tx[i]+s, ty+s);
            glColor3f(0.85f,0.95f, 1.0f);   
			glVertex2f(tx[i],   ty+s);
        glEnd();
        glColor3f(0.55f, 0.70f, 0.85f);
        glLineWidth(1.0f);
        glBegin(GL_LINE_LOOP);
            glVertex2f(tx[i],   ty);
            glVertex2f(tx[i]+s, ty);
            glVertex2f(tx[i]+s, ty+s);
            glVertex2f(tx[i],   ty+s);
        glEnd();
    }

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 700);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Primitive OpenGL");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}