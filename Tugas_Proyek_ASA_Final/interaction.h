#ifndef INTERACTION_H
#define INTERACTION_H

#include "global.h"

void handleInput();
void updatePhysics();
void update(int value);

void spawnDoubleJumpParticles(float x, float y, float z);
void spawnFinishParticles(float x, float y, float z);
void spawnSpikeSpark(float x, float y, float z);

void onWinTimer(int val);
void onLoseTimer(int val);

void keyDown(unsigned char key, int x, int y);
void keyUp(unsigned char key, int x, int y);
void specialKey(int key, int x, int y);

// Fungsi utility pembantu untuk rendering HUD teks UI di layar
void drawText2D(float x, float y, const char* str, float r = 0.0f, float g = 0.0f, float b = 0.0f);
void drawTextWithShadow(float x, float y, const char* str, float r, float g, float b);

#endif
