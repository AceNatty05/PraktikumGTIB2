#include "texture.h"
#include <cstdio>
#include <cstdlib>

Image* loadBMP(const char* filename) {
    return NULL; 
}

// Mesin pembaca file BMP (Mendukung 24-bit dan 32-bit dari MS Paint/Drive)
GLuint loadBMPTexture(const char* filename) {
    unsigned char header[54];
    unsigned int  dataPos, width, height, imageSize;
    unsigned char* data = NULL;

    FILE* file = fopen(filename, "rb");
    if (!file) return 0;

    if (fread(header, 1, 54, file) != 54 || header[0] != 'B' || header[1] != 'M') {
        fclose(file); return 0;
    }

    dataPos   = *(unsigned int*)&header[0x0A];
    width     = *(unsigned int*)&header[0x12];
    height    = *(unsigned int*)&header[0x16];
    short bitDepth = *(short*)&header[0x1C];

    if (dataPos == 0) dataPos = 54;

    int bytesPerPixel = bitDepth / 8;
    imageSize = width * height * bytesPerPixel;
    if(imageSize <= 0) return 0;

    data = new unsigned char[imageSize];
    fseek(file, dataPos, SEEK_SET);
    size_t bytesRead = fread(data, 1, imageSize, file);
    fclose(file);

    if (bytesRead == 0) {
        delete[] data; return 0;
    }

    unsigned char* rgbData = new unsigned char[width * height * 3];
    for (unsigned int i = 0; i < width * height; ++i) {
        int srcIdx = i * bytesPerPixel;
        int dstIdx = i * 3;
        rgbData[dstIdx + 0] = data[srcIdx + 2]; // R
        rgbData[dstIdx + 1] = data[srcIdx + 1]; // G
        rgbData[dstIdx + 2] = data[srcIdx + 0]; // B
    }

    GLuint texID;
    glGenTextures(1, &texID);
    glBindTexture(GL_TEXTURE_2D, texID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    
    // Mipmaps untuk mengatur resolusi gambar bebas
    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_RGB, GL_UNSIGNED_BYTE, rgbData);

    delete[] data;
    delete[] rgbData;
    return texID;
}

// ======================================================
// FUNGSI CADANGAN: MEMBUAT BATA MERAH JIKA FILE BMP RUSAK
// ======================================================
GLuint generateRedBricks() {
    const int SZ = 64;
    unsigned char img[SZ * SZ * 3];

    for (int i = 0; i < SZ; i++) {
        for (int j = 0; j < SZ; j++) {
            int idx = (i * SZ + j) * 3;
            // Rumus membuat pola garis semen batu bata
            bool lineH = (i % 16 == 0 || i % 16 == 1);
            bool lineV = (j % 32 == 0 || j % 32 == 1);
            bool lineV2 = ((i >= 16) && ((j + 16) % 32 == 0 || (j + 16) % 32 == 1));
            
            // Warna bata merah terang dan semen abu-abu
            unsigned char r = (lineH || lineV || lineV2) ? 100 : 210; 
            unsigned char g = (lineH || lineV || lineV2) ? 100 : 50;
            unsigned char b = (lineH || lineV || lineV2) ? 100 : 40;
            
            img[idx]   = r;
            img[idx+1] = g;
            img[idx+2] = b;
        }
    }

    GLuint texID;
    glGenTextures(1, &texID);
    glBindTexture(GL_TEXTURE_2D, texID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, SZ, SZ, GL_RGB, GL_UNSIGNED_BYTE, img);
    return texID;
}

void initTextures() {
    // Memuat tekstur awan
    GLuint loadedSky = loadBMPTexture("awan.bmp");
    if (loadedSky == 0) loadedSky = loadBMPTexture("C:\\Users\\Asus\\GT\\GTI\\New_folder\\awan.bmp");

    // Memuat tekstur bricks
    GLuint loadedBricks = loadBMPTexture("bricks.bmp");
    if (loadedBricks == 0) loadedBricks = loadBMPTexture("C:\\Users\\Asus\\GT\\GTI\\New_folder\\bricks.bmp");
    
    // JARING PENGAMAN: Jika file gagal dibaca, langsung buat bata merah agar awan tidak bocor
    if (loadedBricks == 0) {
        loadedBricks = generateRedBricks();
    }

    ::texBricks = loadedBricks;
    ::texSky = loadedSky;
}
