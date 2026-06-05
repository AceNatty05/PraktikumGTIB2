#include "tile.h"

// Fungsi menggambar kubus yang efisien
void drawTexturedCube(float x, float y, float z, float sx, float sy, float sz, GLuint tex, float r, float g, float b) {
    glPushMatrix(); 
    glTranslatef(x, y, z); 
    glScalef(sx, sy, sz); 
    
    // Bind tekstur di luar glBegin agar tidak membebani loop
    glBindTexture(GL_TEXTURE_2D, tex); 
    glColor3f(r, g, b); 
    
    float h = TILE_SIZE * 0.5f;
    glBegin(GL_QUADS);
        // Sisi-sisi kubus (disederhanakan untuk performa)
        glNormal3f(0,1,0);  glTexCoord2f(0,0); glVertex3f(-h,h,-h); glTexCoord2f(sx,0); glVertex3f(h,h,-h); glTexCoord2f(sx,sz); glVertex3f(h,h,h); glTexCoord2f(0,sz); glVertex3f(-h,h,h);
        glNormal3f(0,-1,0); glTexCoord2f(0,0); glVertex3f(-h,-h,-h); glTexCoord2f(sx,0); glVertex3f(h,-h,-h); glTexCoord2f(sx,sz); glVertex3f(h,-h,h); glTexCoord2f(0,sz); glVertex3f(-h,-h,h);
        glNormal3f(0,0,1);  glTexCoord2f(0,0); glVertex3f(-h,-h,h); glTexCoord2f(sx,0); glVertex3f(h,-h,h); glTexCoord2f(sx,sy); glVertex3f(h,h,h); glTexCoord2f(0,sy); glVertex3f(-h,h,h);
        glNormal3f(0,0,-1); glTexCoord2f(1,0); glVertex3f(h,-h,-h); glTexCoord2f(1,1); glVertex3f(h,h,-h); glTexCoord2f(0,1); glVertex3f(-h,h,-h); glTexCoord2f(0,0); glVertex3f(-h,-h,-h);
        glNormal3f(-1,0,0); glTexCoord2f(0,0); glVertex3f(-h,-h,-h); glTexCoord2f(sz,0); glVertex3f(-h,-h,h); glTexCoord2f(sz,sy); glVertex3f(-h,h,h); glTexCoord2f(0,sy); glVertex3f(-h,h,-h);
        glNormal3f(1,0,0);  glTexCoord2f(0,0); glVertex3f(h,-h,-h); glTexCoord2f(sz,0); glVertex3f(h,-h,h); glTexCoord2f(sz,sy); glVertex3f(h,h,h); glTexCoord2f(0,sy); glVertex3f(h,h,-h);
    glEnd(); 
    glPopMatrix(); 
}

void drawLevel() {
    // Aktifkan tekstur sekali saja untuk seluruh perulangan level
    glEnable(GL_TEXTURE_2D); 
    
    for (size_t i = 0; i < tiles.size(); i++) { 
        Tile& t = tiles[i];
        if (!t.active) continue;
        
        glPushMatrix(); 
        glTranslatef(t.x + t.shakeOffset, t.y, t.z);
        
        if (t.type == TRAP) {
            glDisable(GL_TEXTURE_2D); 
            drawPyramid(0.0f, 0.5f, 0.0f);
            glEnable(GL_TEXTURE_2D);  // Aktifkan kembali setelah piramida digambar
        } else {
            if (t.type == SAFE) drawTexturedCube(0,0,0, t.scaleX, t.scaleY, t.scaleZ, texBricks, 1,1,1);
            else if (t.type == MOVING) drawCubeMoving(0,0,0, t.scaleX, t.scaleY, t.scaleZ); 
            else if (t.type == FINISH) drawCubeFinish(0,0,0, t.scaleX, t.scaleY, t.scaleZ); 
        }
        glPopMatrix();
    }
}

void drawPyramid(float x, float y, float z) {
    glPushMatrix(); 
    glTranslatef(x, y + 0.3f, z); 
    float b = TILE_SIZE * 0.25f;
    float h = TILE_SIZE * 0.4f;
    glColor3f(0.8f, 0.1f, 0.1f); // Merah
    glBegin(GL_TRIANGLES);
        glVertex3f(0, h, 0); glVertex3f(-b, 0, b); glVertex3f(b, 0, b);
        glVertex3f(0, h, 0); glVertex3f(b, 0, b); glVertex3f(b, 0, -b);
        glVertex3f(0, h, 0); glVertex3f(b, 0, -b); glVertex3f(-b, 0, -b);
        glVertex3f(0, h, 0); glVertex3f(-b, 0, -b); glVertex3f(-b, 0, b);
    glEnd();
    glPopMatrix();
}

// Tambahkan fungsi pembantu agar tidak ada error link
void drawCubeMoving(float x, float y, float z, float sx, float sy, float sz) { drawTexturedCube(x, y, z, sx, sy, sz, texBricks, 0.3f, 0.65f, 1.0f); }
void drawCubeFinish(float x, float y, float z, float sx, float sy, float sz) { float p = 0.85f + 0.15f * std::sin(timeT * 5.0f); drawTexturedCube(x, y, z, sx, sy, sz, texBricks, 1.0f * p, 0.85f * p, 0.2f); }
void drawSkyBackground() {
    glPushAttrib(GL_ENABLE_BIT);
    glDisable(GL_LIGHTING); glDepthMask(GL_FALSE); 
    if (texSky != 0) {
        glEnable(GL_TEXTURE_2D); glBindTexture(GL_TEXTURE_2D, texSky); glColor3f(1.0f, 1.0f, 1.0f); 
    } else {
        glDisable(GL_TEXTURE_2D); glColor3f(0.45f, 0.68f, 0.88f); 
    }
    GLUquadric* q = gluNewQuadric(); gluQuadricTexture(q, GL_TRUE);
    glPushMatrix(); glRotatef(90.0f, 1.0f, 0.0f, 0.0f); glRotatef(timeT * 0.40f, 0.0f, 0.0f, 1.0f); gluSphere(q, 380.0f, 32, 24); glPopMatrix();
    gluDeleteQuadric(q); glPopAttrib(); glDepthMask(GL_TRUE); 
}

void drawBird(float x, float y, float z, float wingAngle) {
    glPushAttrib(GL_ENABLE_BIT); glDisable(GL_TEXTURE_2D); glEnable(GL_LIGHTING);
    glPushMatrix(); glTranslatef(x, y, z); glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    glColor3f(0.18f, 0.22f, 0.28f);
    glPushMatrix(); glScalef(0.24f, 0.16f, 0.45f); glutSolidCube(1.0f); glPopMatrix();
    glColor3f(1.0f, 0.60f, 0.0f);
    glPushMatrix(); glTranslatef(0.0f, 0.0f, 0.25f); glScalef(0.08f, 0.08f, 0.15f); glutSolidCube(1.0f); glPopMatrix();
    glPushMatrix();
        glTranslatef(-0.12f, 0.0f, 0.0f); glRotatef(wingAngle, 0.0f, 0.0f, 1.0f); glTranslatef(-0.25f, 0.0f, 0.0f);
        glColor3f(0.12f, 0.15f, 0.20f); glScalef(0.48f, 0.03f, 0.22f); glutSolidCube(1.0f);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0.12f, 0.0f, 0.0f); glRotatef(-wingAngle, 0.0f, 0.0f, 1.0f); glTranslatef(0.25f, 0.0f, 0.0f);
        glColor3f(0.12f, 0.15f, 0.20f); glScalef(0.48f, 0.03f, 0.22f); glutSolidCube(1.0f);
    glPopMatrix();
    glPopMatrix(); glPopAttrib();
}
