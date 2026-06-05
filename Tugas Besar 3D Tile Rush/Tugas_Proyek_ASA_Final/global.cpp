#include "global.h"

std::vector<Tile> tiles;
std::vector<Cloud> clouds;
std::vector<Particle> particles;
std::vector<DecorativeBird> birds;
Player player;

int currentLevel = 1;
int lives = 3;
int cameraMode = 0;
float timeT = 0.0f;
float rotationY = 0.0f;
GameState gameState = PLAYING;
bool diedBySpike = false;

float camAngle = 45.0f;
float camDistance = 15.0f;
float panX = 0.0f, panY = 0.0f, panZ = 0.0f;

bool keyW = false, keyA = false, keyS = false, keyD = false;

GLuint texBricks = 0;
GLuint texSky = 0;

const float FRICTION = 0.800f;

float lightPos[]      = { 15.0f, 45.0f, 15.0f, 1.0f };
float lightAmbient[]  = { 0.30f, 0.30f, 0.33f, 1.0f }; 
float lightDiffuse[]  = { 0.65f, 0.60f, 0.50f, 1.0f }; 
float lightSpecular[] = { 0.20f, 0.20f, 0.20f, 1.0f }; 

Image::Image(char* ps, int w, int h) : pixels(ps), width(w), height(h) {}
Image::~Image() { delete[] pixels; }

// ======================================================
// IMPLEMENTASI FUNGSI HANDLING VISUAL ENVIRONMENT
// ======================================================

// Menggunakan loadBMP() yang sudah ada dari texture.cpp agar tidak duplikat
extern Image* loadBMP(const char* filename);

GLuint loadTexture(const char* filename) {
    Image* img = loadBMP(filename);
    if (!img) return 0;

    GLuint textureId;
    glGenTextures(1, &textureId);
    glBindTexture(GL_TEXTURE_2D, textureId);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    // ======================================================
    // JURUS ANTI-GAGAL: MENGGUNAKAN GLU BUILD 2D MIPMAPS
    // Mengizinkan resolusi gambar berukuran BEBAS (seperti 303x167)
    // ======================================================
    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, img->width, img->height, GL_RGB, GL_UNSIGNED_BYTE, img->pixels);

    delete img; 
    return textureId;
}

void initVisualEnvironment() {
    glClearColor(0.5f, 0.7f, 0.9f, 1.0f); // Tetap biru muda
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL); 

    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);
    
    // Aktifkan sistem pemetaan tekstur di memori
    glEnable(GL_TEXTURE_2D);
}
