#include "player.h"

void resetPlayer() {
    if (tiles.empty()) return;
    player.x = tiles[0].x; 
    player.y = tiles[0].y + (TILE_SIZE * tiles[0].scaleY) * 0.5f + 1.0f; 
    player.z = tiles[0].z;
    player.vx = 0.0f; player.vy = 0.0f; player.vz = 0.0f;
    player.onGround = true; player.wasOnGround = true; player.jumpCount = 0; player.walkCycle = 0.0f; player.isMoving = false;
    player.scaleX = 1.0f; player.scaleY = 1.0f; player.scaleZ = 1.0f;
    player.landingTimer = 0.0f; player.rotationHeading = 0.0f;
    player.lastPlatform = NULL;
    panX = 0.0f; panY = 0.0f; panZ = 0.0f; diedBySpike = false;
}

void drawCharacter() {
    glPushAttrib(GL_ENABLE_BIT | GL_LIGHTING_BIT); 
    glDisable(GL_TEXTURE_2D); 
    
    glPushMatrix();
    glTranslatef(player.x, player.y, player.z); 
    glRotatef(rotationY, 0.0f, 1.0f, 0.0f);
    glScalef(player.scaleX, player.scaleY, player.scaleZ);

    float wc = player.walkCycle;
    float swing = player.isMoving ? std::sin(wc) * 35.0f : 0.0f;
    float legSwing = player.isMoving ? std::sin(wc) * 28.0f : 0.0f;
    float breathingBob = std::sin(timeT * 4.0f) * 0.02f;

    // Kaki Kiri
    glPushMatrix(); 
    glTranslatef(-0.15f, 0.28f + breathingBob, 0.0f); 
    glRotatef(legSwing, 1.0f, 0.0f, 0.0f);
    glColor3f(0.12f, 0.12f, 0.14f); 
    glScalef(0.15f, 0.58f, 0.15f); 
    glutSolidCube(1.0f); 
    glPopMatrix();
    
    // Kaki Kanan
    glPushMatrix(); 
    glTranslatef(0.15f, 0.28f + breathingBob, 0.0f); 
    glRotatef(-legSwing, 1.0f, 0.0f, 0.0f);
    glColor3f(0.12f, 0.12f, 0.14f); 
    glScalef(0.15f, 0.58f, 0.15f); 
    glutSolidCube(1.0f); 
    glPopMatrix();
    
    // Torso / Badan
    glPushMatrix(); 
    glTranslatef(0.0f, 0.85f + breathingBob, 0.0f); 
    glColor3f(0.05f, 0.45f, 0.90f); 
    glScalef(0.48f, 0.55f, 0.28f); 
    glutSolidCube(1.0f); 
    glPopMatrix();
    
    // Tangan Kiri
    glPushMatrix(); 
    glTranslatef(-0.32f, 0.85f + breathingBob, 0.0f); 
    glRotatef(-swing, 1.0f, 0.0f, 0.0f);
    glColor3f(0.98f, 0.77f, 0.54f); 
    glScalef(0.14f, 0.48f, 0.14f); 
    glutSolidCube(1.0f); 
    glPopMatrix();
    
    // Tangan Kanan
    glPushMatrix(); 
    glTranslatef(0.32f, 0.85f + breathingBob, 0.0f); 
    glRotatef(swing, 1.0f, 0.0f, 0.0f);
    glColor3f(0.98f, 0.77f, 0.54f); 
    glScalef(0.14f, 0.48f, 0.14f); 
    glutSolidCube(1.0f); 
    glPopMatrix();
    
    // Kepala & Ekspresi Mata Kontras
    glPushMatrix(); 
    glTranslatef(0.0f, 1.35f + breathingBob * 1.5f, 0.0f); 
    glColor3f(0.98f, 0.77f, 0.54f); 
    glScalef(0.42f, 0.42f, 0.42f); 
    glutSolidCube(1.0f); 
    
    glDisable(GL_LIGHTING);
    glColor3f(0.05f, 0.05f, 0.05f);
    glPushMatrix(); glTranslatef(-0.2f, 0.1f, 0.51f); glScalef(0.1f, 0.15f, 0.05f); glutSolidCube(1.0f); glPopMatrix();
    glPushMatrix(); glTranslatef(0.2f, 0.1f, 0.51f); glScalef(0.1f, 0.15f, 0.05f); glutSolidCube(1.0f); glPopMatrix();
    glEnable(GL_LIGHTING);
    glPopMatrix(); 
    
    glPopMatrix(); 
    glPopAttrib(); 
}

void updateAnimation() {
    float speedSq = (player.vx * player.vx) + (player.vz * player.vz);
    player.isMoving = speedSq > 0.0005f;
    
    if (player.isMoving) {
        float speed = std::sqrt(speedSq);
        player.walkCycle += speed * 12.0f;
        
    } else {
        player.walkCycle = 0.0f;
    }
    
    if (player.landingTimer > 0) {
        player.landingTimer -= 1.0f;
        float t = player.landingTimer / 10.0f;
        player.scaleY = 0.81f + (1.0f - t) * 0.19f;
        player.scaleX = player.scaleZ = 1.12f - (1.0f - t) * 0.12f;
    } else {
        player.scaleX = player.scaleY = player.scaleZ = 1.0f;
    }
}
