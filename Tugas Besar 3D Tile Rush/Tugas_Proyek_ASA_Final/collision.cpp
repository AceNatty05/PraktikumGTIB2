#include "collision.h"
#include "player.h"
#include "level_generator.h"

// Tambahkan deklarasi extern ini di bagian atas file collision.cpp
extern void spawnSpikeSpark(float x, float y, float z);
extern void onLoseTimer(int value);
extern void onWinTimer(int value);

void triggerDeath() {
    spawnSpikeSpark(player.x, player.y, player.z);
    lives--; 
    if (lives <= 0) { currentLevel = 1; lives = 3; }
    gameState = LOSE_SCREEN; 
    glutTimerFunc(1200, onLoseTimer, 0);
    glutPostRedisplay();
}

void updateCollision() {
    for (size_t i = 0; i < tiles.size(); i++) {
        Tile& t = tiles[i];
        if (t.type == MOVING) {
            float prevOffset = t.shakeOffset;
            t.shakeOffset = std::sin(timeT * 1.5f + t.pulseTime) * 1.35f;
            t.deltaOffset = t.shakeOffset - prevOffset;
        }
    }

    const float pHalfW = 0.45f;
    const float pHalfD = 0.28f;
    const float pHeight = 2.40f;

    if (player.onGround && player.lastPlatform && player.lastPlatform->type == MOVING) {
        player.x += player.lastPlatform->deltaOffset;
    }

    player.x += player.vx;
    for (size_t i = 0; i < tiles.size(); i++) {
        Tile& t = tiles[i];
        if (!t.active) continue;
        float tileX = t.x + t.shakeOffset;
        float halfW = t.scaleX; float halfD = t.scaleZ; float halfH = t.scaleY;
        
        bool overlapY = (player.y < t.y + halfH - 0.05f) && (player.y + pHeight > t.y - halfH + 0.05f);
        bool overlapZ = std::fabs(player.z - t.z) < (pHalfD + halfD);

        if (overlapY && overlapZ) {
            if (std::fabs(player.x - tileX) < (pHalfW + halfW)) {
                if (t.type == TRAP) { triggerDeath(); return; }
                
                if (player.x < tileX) {
                    player.x = tileX - halfW - pHalfW; // Dorong ke kiri
                } else {
                    player.x = tileX + halfW + pHalfW; // Dorong ke kanan
                }
                player.vx = 0.0f;
            }
        }
    }

    // Resolusi Z
    player.z += player.vz;
    for (size_t i = 0; i < tiles.size(); i++) {
        Tile& t = tiles[i];
        if (!t.active) continue;
        float tileX = t.x + t.shakeOffset;
        float halfW = t.scaleX; float halfD = t.scaleZ; float halfH = t.scaleY;
        
        bool overlapY = (player.y < t.y + halfH - 0.05f) && (player.y + pHeight > t.y - halfH + 0.05f);
        bool overlapX = std::fabs(player.x - tileX) < (pHalfW + halfW);

        if (overlapY && overlapX) {
            if (std::fabs(player.z - t.z) < (pHalfD + halfD)) {
                if (t.type == TRAP) { triggerDeath(); return; }
                
                // PERBAIKAN: Dorong berdasarkan posisi
                if (player.z < t.z) {
                    player.z = t.z - halfD - pHalfD; // Dorong ke belakang
                } else {
                    player.z = t.z + halfD + pHalfD; // Dorong ke depan
                }
                player.vz = 0.0f;
            }
        }
    }

    // Resolusi Y
    player.vy += GRAVITY;
    player.y += player.vy;
    player.onGround = false;
    Tile* groundCollisionTile = NULL;

    for (size_t i = 0; i < tiles.size(); i++) {
        Tile& t = tiles[i];
        if (!t.active) continue;
        float tileX = t.x + t.shakeOffset;
        float halfW = t.scaleX; float halfD = t.scaleZ; float halfH = t.scaleY;
        bool overlapX = std::fabs(player.x - tileX) < (halfW + 0.15f);
        bool overlapZ = std::fabs(player.z - t.z) < (halfD + 0.12f);

        if (overlapX && overlapZ) {
            if (player.y < t.y + halfH && player.y + pHeight > t.y - halfH) {
                if (t.type == TRAP) { triggerDeath(); return; }
                if (player.vy <= 0.0f) {
                    player.y = t.y + halfH; player.vy = 0.0f;
                    if (!player.onGround) {
                        player.scaleY = 0.78f; player.scaleX = player.scaleZ = 1.14f;
                        player.landingTimer = 10.0f;
                    }
                    player.onGround = true; player.jumpCount = 0; groundCollisionTile = &t;
                } else {
                    player.y = t.y - halfH - pHeight; player.vy = 0.0f;
                }
            }
        }
    }

    player.lastPlatform = groundCollisionTile;

    if (player.onGround && groundCollisionTile) {
        if (groundCollisionTile->type == FINISH) {
            player.vy = 0.0f; player.vx = 0.0f; player.vz = 0.0f;
            player.score += 150 * currentLevel;
            gameState = WIN_SCREEN;
            glutTimerFunc(2000, onWinTimer, 0);
        }
    }
}
