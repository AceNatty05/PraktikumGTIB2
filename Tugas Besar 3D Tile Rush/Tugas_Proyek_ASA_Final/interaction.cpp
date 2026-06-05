#include "interaction.h"
#include "player.h"
#include "collision.h"
#include "level_generator.h"

void spawnDoubleJumpParticles(float x, float y, float z) {
    for (int i = 0; i < 20; ++i) {
        Particle p; p.x = x; p.y = y; p.z = z;
        float angle = ((float)rand() / RAND_MAX) * 2 * PI;
        float speed = 0.05f + ((float)rand() / RAND_MAX) * 0.05f;
        p.vx = std::cos(angle) * speed; p.vy = -0.01f - ((float)rand() / RAND_MAX) * 0.02f; p.vz = std::sin(angle) * speed;
        p.r = 0.8f; p.g = 0.95f; p.b = 1.0f; p.life = 1.0f;
        p.size = 0.15f + ((float)rand() / RAND_MAX) * 0.15f;
        particles.push_back(p);
    }
}

void spawnFinishParticles(float x, float y, float z) {
    if (rand() % 4 != 0) return;
    Particle p; p.x = x + (-1.5f + ((float)rand() / RAND_MAX) * 3.0f); p.y = y; p.z = z + (-1.5f + ((float)rand() / RAND_MAX) * 3.0f);
    p.vx = -0.01f + ((float)rand() / RAND_MAX) * 0.02f; p.vy = 0.04f + ((float)rand() / RAND_MAX) * 0.04f; p.vz = -0.01f + ((float)rand() / RAND_MAX) * 0.02f;
    p.r = 1.0f; p.g = 0.85f + ((float)rand() / RAND_MAX) * 0.15f; p.b = 0.2f; p.life = 1.0f;
    p.size = 0.1f + ((float)rand() / RAND_MAX) * 0.15f;
    particles.push_back(p);
}

void spawnSpikeSpark(float x, float y, float z) {
    for (int i = 0; i < 25; ++i) {
        Particle p; p.x = x; p.y = y + 0.5f; p.z = z;
        p.vx = -0.06f + ((float)rand() / RAND_MAX) * 0.12f; p.vy = 0.06f + ((float)rand() / RAND_MAX) * 0.12f; p.vz = -0.06f + ((float)rand() / RAND_MAX) * 0.12f;
        p.r = 1.0f; p.g = 0.1f; p.b = 0.1f; p.life = 1.0f;
        p.size = 0.18f + ((float)rand() / RAND_MAX) * 0.2f;
        particles.push_back(p);
    }
}

void handleInput() {
    float turnSpeed = 5.0f; 

    if (keyD) rotationY += turnSpeed;
    if (keyA) rotationY -= turnSpeed;
    
    if (keyS) {
        rotationY += 180.0f;
        keyS = false; // Reset agar tidak berputar terus menerus saat tombol ditahan
    }

    // Normalisasi agar rotasi tetap di rentang 0 - 360
    if (rotationY >= 360.0f) rotationY -= 360.0f;
    if (rotationY < 0.0f) rotationY += 360.0f;

    if (!keyW && !keyS) return;
    
    float rad = rotationY * PI / 180.0f;
    float fwdX = std::sin(rad); 
    float fwdZ = std::cos(rad);
    float accX = 0.0f; float accZ = 0.0f;

    if (keyW) { accX += fwdX; accZ += fwdZ; }
    if (keyS) { accX -= fwdX; accZ -= fwdZ; }

    float length = std::sqrt(accX * accX + accZ * accZ);
    if (length > 0.001f) {
        accX /= length; accZ /= length;
        player.vx += accX * PLAYER_ACCEL; 
        player.vz += accZ * PLAYER_ACCEL;
    }
}
void updatePhysics() {
	float currentFriction = player.onGround ? FRICTION : 1.5f;
    player.vx *= FRICTION; player.vz *= FRICTION;
    if (player.vx > MAX_SPEED) player.vx = MAX_SPEED; 
    if (player.vx < -MAX_SPEED) player.vx = -MAX_SPEED;
    if (player.vz > MAX_SPEED) player.vz = MAX_SPEED; 
    if (player.vz < -MAX_SPEED) player.vz = -MAX_SPEED;
}

void update(int) {
    glutTimerFunc(16, update, 0); 
    timeT += DELTA_TIME;
    
    if (gameState != PLAYING) { glutPostRedisplay(); return; }

    handleInput();
    updatePhysics();
    updateCollision();
    
    // Update posisi awan dekoratif
    for (size_t i = 0; i < clouds.size(); ++i) {
        clouds[i].x += clouds[i].speed;
        if (clouds[i].x > 50.0f) clouds[i].x = -50.0f;
    }

    // Update posisi burung dekoratif
    for (size_t i = 0; i < birds.size(); ++i) {
        birds[i].x += birds[i].speed;
        birds[i].wingAngle = std::sin(timeT * 15.0f) * 30.0f;
        if (birds[i].x > 40.0f) birds[i].x = -40.0f;
    }

    updateAnimation();
    
    // Update partikel life
    for (size_t i = 0; i < particles.size(); ) {
        particles[i].x += particles[i].vx; particles[i].y += particles[i].vy; particles[i].z += particles[i].vz;
        particles[i].life -= 0.025f;
        if (particles[i].life <= 0.0f) { particles[i] = particles.back(); particles.pop_back(); }
        else { ++i; }
    }

    if (player.y < -15.0f) {
        lives--; 
        if (lives <= 0) { currentLevel = 1; lives = 3; }
        gameState = LOSE_SCREEN; 
        glutTimerFunc(1200, onLoseTimer, 0);
    }
    glutPostRedisplay();
}

void keyDown(unsigned char key, int, int) {
    switch (key) {
        case 'w': case 'W': keyW = true; break; 
        case 's': case 'S': keyS = true; break;
        case 'a': case 'A': keyA = true; break; 
        case 'd': case 'D': keyD = true; break;
        case ' ': 
    		if (player.onGround) { 
        		player.vy = JUMP_FORCE; 
        		player.onGround = false; 
        		player.jumpCount = 1; 
        
    				// Dorongan maju HANYA saat melompat pertama kali dari tanah
        		if (keyW) {
            		float rad = rotationY * PI / 180.0f;
            		player.vx += std::sin(rad) * 0.05f; 
            		player.vz += std::cos(rad) * 0.05f;
        		}
        
        		player.scaleY = 1.25f; player.scaleX = player.scaleZ = 0.88f; 
        		player.landingTimer = 0.0f;
    		} else if (player.jumpCount == 1) { 
        		player.vy = DOUBLE_JUMP_FORCE; 
       			player.jumpCount = 2; 
        		player.scaleY = 1.35f; player.scaleX = player.scaleZ = 0.82f;
        
        		// Opsional: Sedikit dorongan lagi untuk double jump agar lebih terasa
        		if (keyW) {
            		float rad = rotationY * PI / 180.0f;
            		player.vx += std::sin(rad) * 0.03f; 
            		player.vz += std::cos(rad) * 0.03f;
        		}
        		spawnDoubleJumpParticles(player.x, player.y, player.z);
    		} 
    		break;
        case 'v': case 'V': cameraMode = (cameraMode + 1) % 5; break;
        case 'r': case 'R': generateLevel(currentLevel); resetPlayer(); gameState = PLAYING; break;
        case 27: exit(0); break; 
    }
}

void keyUp(unsigned char key, int, int) {
    switch (key) {
        case 'w': case 'W': keyW = false; break; 
        case 's': case 'S': keyS = false; break;
        case 'a': case 'A': keyA = false; break; 
        case 'd': case 'D': keyD = false; break;
    }
}

void specialKey(int key, int, int) {
    switch(key) { 
        case GLUT_KEY_LEFT:  camAngle -= 6.0f; break;
        case GLUT_KEY_RIGHT: camAngle += 6.0f; break;
        case GLUT_KEY_UP:    camDistance = std::max(6.0f, camDistance - 1.0f); break;
        case GLUT_KEY_DOWN:  camDistance = std::min(30.0f, camDistance + 1.0f); break;
    }
}

void onWinTimer(int) { currentLevel++; generateLevel(currentLevel); resetPlayer(); gameState = PLAYING; glutPostRedisplay(); }
void onLoseTimer(int) { resetPlayer(); gameState = PLAYING; glutPostRedisplay(); }

// Tambahan fungsi utility render teks di interaction.cpp
void drawText2D(float x, float y, const char* str, float r, float g, float b) {
    glMatrixMode(GL_PROJECTION); glPushMatrix(); glLoadIdentity();
    int vp[4]; glGetIntegerv(GL_VIEWPORT, vp); gluOrtho2D(0, vp[2], 0, vp[3]);
    glMatrixMode(GL_MODELVIEW); glPushMatrix(); glLoadIdentity();
    glPushAttrib(GL_ENABLE_BIT);
    glDisable(GL_LIGHTING); glDisable(GL_DEPTH_TEST); glDisable(GL_BLEND); glDisable(GL_TEXTURE_2D);
    glColor3f(r, g, b); glRasterPos2f(x, y);
    for (const char* c = str; *c; c++) { glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c); }
    glPopAttrib(); glPopMatrix(); glMatrixMode(GL_PROJECTION); glPopMatrix(); glMatrixMode(GL_MODELVIEW);
}

void drawTextWithShadow(float x, float y, const char* str, float r, float g, float b) {
    drawText2D(x + 1.5f, y - 1.5f, str, 0.02f, 0.02f, 0.02f);
    drawText2D(x, y, str, r, g, b);
}
