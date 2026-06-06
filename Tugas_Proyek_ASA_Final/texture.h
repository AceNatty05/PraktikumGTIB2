#ifndef TEXTURE_H
#define TEXTURE_H

#include "global.h"

Image* loadBMP(const char* filename);
GLuint loadBMPTexture(const char* filename);
void initTextures();

#endif
