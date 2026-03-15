//Nama: Revalina Salwa Aliya W.P
//NIM : 24060124140155

#include <GL/glut.h>
#include <GL/gl.h>
#include <math.h>

#define PI 3.14159265358979323846f

void drawCircle(float cx, float cy, float r, int n, int filled){
    if (filled) {
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(cx, cy);
    } else {
        glBegin(GL_LINE_LOOP);
    }
    int i;
    for (i = 0; i <= n; i++){
        float a = 2.0f * PI * i / n;
        glVertex2f(cx + r * cosf(a), cy + r * sinf(a));
    }
    glEnd();
}

void drawLangit(){
    glColor3f(0.45f, 0.75f, 1.0f);
    glBegin(GL_QUADS);
        glVertex2f(-1.0f, -1.0f);
        glVertex2f( 1.0f, -1.0f);
        glVertex2f( 1.0f,  1.0f);
        glVertex2f(-1.0f,  1.0f);
    glEnd();
}

void drawAwan(float x, float y, float scale){
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glScalef(scale, scale, 1.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(0.00f,  0.00f, 0.10f, 32, 1);
    drawCircle(-0.08f, 0.04f, 0.08f, 32, 1);
    drawCircle( 0.09f, 0.05f, 0.09f, 32, 1);
    drawCircle( 0.13f,-0.02f, 0.07f, 32, 1);
    glPopMatrix();
}

void drawPohon(float x, float y){
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glColor3f(0.45f, 0.28f, 0.10f);
    glBegin(GL_QUADS);
        glVertex2f(-0.028f, 0.0f);
        glVertex2f( 0.028f, 0.0f);
        glVertex2f( 0.028f, 0.22f);
        glVertex2f(-0.028f, 0.22f);
    glEnd();
    glColor3f(0.10f, 0.50f, 0.15f);
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.15f, 0.17f);
        glVertex2f( 0.15f, 0.17f);
        glVertex2f( 0.00f, 0.38f);
    glEnd();
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.11f, 0.28f);
        glVertex2f( 0.11f, 0.28f);
        glVertex2f( 0.00f, 0.46f);
    glEnd();
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.075f, 0.38f);
        glVertex2f( 0.075f, 0.38f);
        glVertex2f( 0.00f,  0.54f);
    glEnd();
    glPopMatrix();
}

void drawJalan() {
    glColor3f(0.28f, 0.28f, 0.28f);
    glBegin(GL_QUADS);
        glVertex2f(-1.0f, -1.0f);
        glVertex2f( 1.0f, -1.0f);
        glVertex2f( 1.0f, -0.10f);
        glVertex2f(-1.0f, -0.30f);
    glEnd();

    glColor3f(1.0f, 1.0f, 0.3f);
    glLineWidth(2.5f);
    int g;
    for (g = 0; g < 6; g++){
        float x1 = -0.9f + g * 0.32f;
        float x2 = x1 + 0.18f;
        float y1 = -0.55f + x1 * 0.10f;
        float y2 = -0.55f + x2 * 0.10f;
        glBegin(GL_LINES);
            glVertex2f(x1, y1);
            glVertex2f(x2, y2);
        glEnd();
    }
    glLineWidth(1.0f);
}

void drawJeepPink(float tx){
    float jalanY = -0.20f + tx * 0.10f;

    glPushMatrix();
    glTranslatef(tx, jalanY, 0.0f);
    glRotatef(6.0f, 0.0f, 0.0f, 1.0f);

    //body mobil
glColor3f(1.0f, 0.55f, 0.75f);
glBegin(GL_QUADS);
    glVertex2f(-0.58f,  0.00f);
    glVertex2f( 0.58f,  0.00f);
    glVertex2f( 0.55f,  0.32f); 
    glVertex2f(-0.55f,  0.32f);
glEnd();

glBegin(GL_QUADS);
    glVertex2f(-0.48f,  0.32f);
    glVertex2f( 0.42f,  0.32f);
    glVertex2f( 0.40f,  0.52f);
    glVertex2f(-0.46f,  0.52f);
glEnd();

// atap
glColor3f(0.90f, 0.40f, 0.62f);
glBegin(GL_QUADS);
    glVertex2f(-0.44f, 0.51f);
    glVertex2f( 0.38f, 0.51f);
    glVertex2f( 0.38f, 0.57f);
    glVertex2f(-0.44f, 0.57f);
glEnd();

//jendela
glColor3f(0.55f, 0.80f, 0.95f);
glBegin(GL_QUADS);
    glVertex2f( 0.13f, 0.34f);
    glVertex2f( 0.38f, 0.34f);
    glVertex2f( 0.36f, 0.50f);
    glVertex2f( 0.15f, 0.50f);
glEnd();

glColor3f(0.50f, 0.75f, 0.92f);
glBegin(GL_QUADS);
    glVertex2f(-0.11f, 0.34f);
    glVertex2f( 0.11f, 0.34f);
    glVertex2f( 0.11f, 0.50f);
    glVertex2f(-0.11f, 0.50f);
glEnd();

glBegin(GL_QUADS);
    glVertex2f(-0.39f, 0.34f);
    glVertex2f(-0.14f, 0.34f);
    glVertex2f(-0.14f, 0.50f);
    glVertex2f(-0.39f, 0.50f);
glEnd();

//garis pintu
glColor3f(0.85f, 0.35f, 0.58f);
glLineWidth(2.0f);
glBegin(GL_LINES);
    glVertex2f( 0.13f, 0.00f);
    glVertex2f( 0.13f, 0.32f);
glEnd();
glBegin(GL_LINES);
    glVertex2f(-0.11f, 0.00f);
    glVertex2f(-0.11f, 0.32f);
glEnd();
glBegin(GL_LINES);
    glVertex2f(-0.35f, 0.00f);
    glVertex2f(-0.35f, 0.32f);
glEnd();
glLineWidth(1.0f);

    // bumper
    glColor3f(0.75f, 0.25f, 0.48f);
    glBegin(GL_QUADS);
        glVertex2f( 0.55f, -0.04f);
        glVertex2f( 0.64f, -0.04f);
        glVertex2f( 0.64f,  0.12f);
        glVertex2f( 0.55f,  0.12f);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2f(-0.64f, -0.04f);
        glVertex2f(-0.55f, -0.04f);
        glVertex2f(-0.55f,  0.12f);
        glVertex2f(-0.64f,  0.12f);
    glEnd();

    //lampu
    glPushMatrix();
        glTranslatef(0.58f, 0.09f, 0.0f);
        glRotatef(15.0f, 0.0f, 0.0f, 1.0f);
        glColor3f(1.0f, 1.0f, 0.7f);
        drawCircle(0.0f, 0.0f, 0.052f, 32, 1);
        glColor3f(0.75f, 0.25f, 0.48f);
        glLineWidth(2.0f);
        drawCircle(0.0f, 0.0f, 0.052f, 32, 0);
        glLineWidth(1.0f);
    glPopMatrix();

    glColor3f(0.9f, 0.15f, 0.15f);
    glBegin(GL_QUADS);
        glVertex2f(-0.60f, 0.06f);
        glVertex2f(-0.56f, 0.06f);
        glVertex2f(-0.56f, 0.15f);
        glVertex2f(-0.60f, 0.15f);
    glEnd();

    //ban mobil
    glPushMatrix();
        glTranslatef(0.34f, 0.0f, 0.0f);
        glColor3f(0.10f, 0.10f, 0.10f);
        drawCircle(0.0f, 0.0f, 0.14f, 32, 1);
        glColor3f(0.65f, 0.65f, 0.68f);
        drawCircle(0.0f, 0.0f, 0.082f, 32, 1);
        glColor3f(0.4f, 0.4f, 0.45f);
        glLineWidth(2.0f);
        int x;
        for (x = 0; x < 5; x++) {
            float s = x * 72.0f * PI / 180.0f;
            glBegin(GL_LINES);
                glVertex2f(0.0f, 0.0f);
                glVertex2f(cosf(s)*0.082f, sinf(s)*0.082f);
            glEnd();
        }
        glColor3f(0.25f, 0.25f, 0.25f);
        drawCircle(0.0f, 0.0f, 0.026f, 16, 1);
        glLineWidth(1.0f);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.35f, 0.0f, 0.0f);
        glColor3f(0.10f, 0.10f, 0.10f);
        drawCircle(0.0f, 0.0f, 0.14f, 32, 1);
        glColor3f(0.65f, 0.65f, 0.68f);
        drawCircle(0.0f, 0.0f, 0.082f, 32, 1);
        glColor3f(0.4f, 0.4f, 0.45f);
        glLineWidth(2.0f);
        int n;
        for (n = 0; n < 5; n++) {
            float s = n * 72.0f * PI / 180.0f;
            glBegin(GL_LINES);
                glVertex2f(0.0f, 0.0f);
                glVertex2f(cosf(s)*0.082f, sinf(s)*0.082f);
            glEnd();
        }
        glColor3f(0.25f, 0.25f, 0.25f);
        drawCircle(0.0f, 0.0f, 0.026f, 16, 1);
        glLineWidth(1.0f);
    glPopMatrix();

    glPopMatrix();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    drawLangit();
    drawAwan(-0.55f, 0.70f, 1.1f);
    drawAwan( 0.30f, 0.60f, 0.9f);
    drawJalan();
    float pohonX = 0.78f;
	float pohonY = -0.30f + ((pohonX + 1.0f) / 2.0f) * 0.20f;
	drawPohon(pohonX, pohonY);
    drawJeepPink(0.0f);

    glutSwapBuffers();
}

void init(){
    glClearColor(0.45f, 0.75f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(800, 500);
    glutCreateWindow("jeep wrangler pink");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
