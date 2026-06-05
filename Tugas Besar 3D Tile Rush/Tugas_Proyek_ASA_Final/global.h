#ifndef GLOBAL_H
#define GLOBAL_H

// 1. Include Standard C++ Library Terlebih Dahulu
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <utility>

// 4. Include Library OpenGL / GLUT Sistem
#include <GL/glut.h>

#define PI 3.14159265359f

// ======================================================
// CONSTANTS (PHYSICS & TIMING)
// ======================================================
const float TILE_SIZE         = 2.0f;
const float GRAVITY           = -0.008f; 
const float MAX_SPEED = 0.3500f; 
const float PLAYER_ACCEL = 0.015f;
const float JUMP_FORCE        = 0.2500f;
const float DOUBLE_JUMP_FORCE = 0.2800f;
const float DELTA_TIME        = 0.016f;

// ======================================================
// ENUMERATIONS & STRUCTURES
// ======================================================
enum TileType { SAFE, TRAP, MOVING, FINISH };
enum GameState { PLAYING, WIN_SCREEN, LOSE_SCREEN };

struct Tile {
    float x, y, z;
    float scaleX, scaleY, scaleZ;
    TileType type;
    bool active;
    float shakeOffset;
    float deltaOffset; 
    float pulseTime; 
};

struct Player {
    float x, y, z;
    float vx, vy, vz;
    bool onGround;
    bool wasOnGround; 
    int jumpCount;
    int score;
    float walkCycle;
    bool isMoving;
    float scaleX, scaleY, scaleZ; 
    float landingTimer;          
    float rotationHeading;       
    Tile* lastPlatform;          
};

struct Cloud {
    float x, y, z;
    float sizeX, sizeY, sizeZ;
    float speed;
};

struct Particle {
    float x, y, z;
    float vx, vy, vz;
    float r, g, b, life;
    float size;
};

struct DecorativeBird {
    float x, y, z;
    float wingAngle;
    float speed;
    float baseZ;
};

// ======================================================
// GLOBAL VARIABLES (EXTERN LINKAGE)
// ======================================================
extern std::vector<Tile> tiles;
extern std::vector<Cloud> clouds;
extern std::vector<Particle> particles;
extern std::vector<DecorativeBird> birds;
extern Player player;

extern int currentLevel;
extern int lives;
extern int cameraMode;

extern float timeT;
extern float rotationY;

extern GameState gameState;
extern bool diedBySpike;

extern float camAngle;
extern float camDistance;
extern float panX, panY, panZ;

extern bool keyW, keyA, keyS, keyD;

extern GLuint texBricks;
extern GLuint texSky;

extern float lightPos[];
extern float lightAmbient[];
extern float lightDiffuse[];
extern float lightSpecular[];

extern const float FRICTION;

// ======================================================
// CLASS MANAGEMENT IMAGE & TEXTURE FUNCTIONS
// ======================================================
class Image {
public:
    char* pixels; 
    int width;
    int height;
    Image(char* ps, int w, int h);
    ~Image();
};

// Deklarasi fungsi helper tekstur global yang aman dari duplikasi
GLuint loadTexture(const char* filename);
void initVisualEnvironment();

#endif
