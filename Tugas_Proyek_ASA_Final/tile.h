#ifndef TILE_H
#define TILE_H

#include "global.h"

void drawTexturedCube(float x, float y, float z, float sx, float sy, float sz, GLuint tex, float r = 1.0f, float g = 1.0f, float b = 1.0f);
void drawCubeMoving(float x, float y, float z, float sx, float sy, float sz);
void drawCubeFinish(float x, float y, float z, float sx, float sy, float sz);
void drawPyramid(float x, float y, float z);
void drawLevel();
void drawSkyBackground();

#endif
