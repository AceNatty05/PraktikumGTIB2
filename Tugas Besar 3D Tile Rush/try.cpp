#include <GL/glut.h>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <cstdio>

// Tile 
enum TileType { SAFE, TRAP, MOVING, FINISH };

struct Tile {
    float x, y, z;
    TileType type;
    bool active;
    float countdown;
    bool isFalling;
    float fallSpeed;
    float shakeOffset;
};

// Player
struct Player {
    float x, y, z;
    float prevX, prevZ;
    float vy;
    bool onGround;
    bool canJump;
    int score;
};

// Game State
enum GameState { PLAYING, WIN_SCREEN, LOSE_SCREEN };

// Globals
static std::vector<Tile> tiles;
static Player player;
static int   currentLevel = 1;
static int   lives        = 3;
static float timeT        = 0.0f;
static float rotationY = 0.0f;

// 0=Perspective, 1=Top, 2=Front, 3=Side
static int   viewMode     = 0;
static GameState gameState = PLAYING;

// camera
static float camX = 0, camY = 0, camZ = 0;

// input state
static bool keyW, keyA, keyS, keyD;

static const float TILE_SIZE  = 1.0f;
static const float TILE_STEP  = 1.3f;
static const float GRAVITY    = -0.015f;
static const float TRAP_LIMIT = 1.5f;

// Tekstur checkerboard untuk tile SAFE 
static GLuint texID = 0;
void initTexture() {
    const int SZ = 64;
    static unsigned char img[64][64][3];
    for (int i = 0; i < SZ; i++)
        for (int j = 0; j < SZ; j++) {
            unsigned char c = ((i/8 + j/8) % 2 == 0) ? 200 : 80;
            img[i][j][0] = c / 3;
            img[i][j][1] = (unsigned char)(c * 1.3f > 255 ? 255 : c * 1.3f);
            img[i][j][2] = c / 4;
        }
    glGenTextures(1, &texID);
    glBindTexture(GL_TEXTURE_2D, texID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, SZ, SZ, 0, GL_RGB, GL_UNSIGNED_BYTE, img);
}

// Level Generator 
void generateLevel(int level) {
    tiles.clear();
    float cx = 0.0f, cz = 0.0f;
    int dir = 0;
    float dx[4] = { TILE_STEP, 0.0f, -TILE_STEP, 0.0f };
    float dz[4] = { 0.0f, -TILE_STEP, 0.0f, TILE_STEP };
    int totalTiles = 15 + level;
    // level 1 = 5 tile
    int straightCount = (level == 1) ? 5 : 0;
    int segLen = 3 + (rand() % 3), segCount = 0;

    for (int i = 0; i < totalTiles; i++) {
        Tile t;
        t.x = cx; t.y = 0.0f; t.z = cz;
        t.active = true; t.countdown = 0.0f;
        t.isFalling = false; t.fallSpeed = 0.0f; t.shakeOffset = 0.0f;

        if (i == 0)                 t.type = SAFE;
        else if (i == totalTiles-1) t.type = FINISH;
        else if (i % 5 == 0)        t.type = TRAP;
        else if (i % 3 == 0)        t.type = MOVING;
        else                        t.type = SAFE;

        tiles.push_back(t);

        // belok hanya setelah tile lurus awal habis
        if (i >= straightCount) {
            segCount++;
            if (segCount >= segLen && i < totalTiles - 2) {
                int turn = rand() % 3;
                if (turn == 1)      dir = (dir + 1) % 4;
                else if (turn == 2) dir = (dir + 3) % 4;
                segLen   = 3 + (rand() % 3);
                segCount = 0;
            }
        }
        cx += dx[dir];
        cz += dz[dir];
    }
}

void resetPlayer() {
    player.x = tiles[0].x;
    player.y = tiles[0].y + TILE_SIZE * 0.5f; // kaki di permukaan tile
    player.z = tiles[0].z;
    player.prevX = player.x;
    player.prevZ = player.z;
    player.vy = 0.0f;
    player.onGround = true;
    player.canJump  = true;
}

// Collision
Tile* tileUnderPlayer() {
    float half = TILE_SIZE * 0.5f;
    for (size_t i = 0; i < tiles.size(); i++) {
        Tile& t = tiles[i];
        if (!t.active) continue;
        float tx = t.x + t.shakeOffset;
        bool now    = fabsf(player.x - tx)     <= half + 0.1f && fabsf(player.z - t.z) <= half + 0.1f;
        bool before = fabsf(player.prevX - tx) <= half + 0.1f && fabsf(player.prevZ - t.z) <= half + 0.1f;
        if ((now || before) && fabsf(player.y - (t.y + TILE_SIZE * 0.5f)) < 0.3f)
            return &t;
    }
    return NULL;
}

// Draw Helpers

// Tile SAFE: tekstur checkerboard (karakteristik: tekstur)
void drawCubeSafe(float x, float y, float z) {
    glPushMatrix();
    glTranslatef(x, y, z);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texID);
    float h = TILE_SIZE * 0.5f;
    glBegin(GL_QUADS);
        glNormal3f(0,1,0);
        glTexCoord2f(0,0); glVertex3f(-h, h,-h);
        glTexCoord2f(1,0); glVertex3f( h, h,-h);
        glTexCoord2f(1,1); glVertex3f( h, h, h);
        glTexCoord2f(0,1); glVertex3f(-h, h, h);
        glNormal3f(0,-1,0);
        glTexCoord2f(0,0); glVertex3f(-h,-h,-h);
        glTexCoord2f(1,0); glVertex3f( h,-h,-h);
        glTexCoord2f(1,1); glVertex3f( h,-h, h);
        glTexCoord2f(0,1); glVertex3f(-h,-h, h);
        glNormal3f(0,0,1);
        glTexCoord2f(0,0); glVertex3f(-h,-h, h);
        glTexCoord2f(1,0); glVertex3f( h,-h, h);
        glTexCoord2f(1,1); glVertex3f( h, h, h);
        glTexCoord2f(0,1); glVertex3f(-h, h, h);
        glNormal3f(0,0,-1);
        glTexCoord2f(0,0); glVertex3f(-h,-h,-h);
        glTexCoord2f(1,0); glVertex3f( h,-h,-h);
        glTexCoord2f(1,1); glVertex3f( h, h,-h);
        glTexCoord2f(0,1); glVertex3f(-h, h,-h);
        glNormal3f(-1,0,0);
        glTexCoord2f(0,0); glVertex3f(-h,-h,-h);
        glTexCoord2f(1,0); glVertex3f(-h,-h, h);
        glTexCoord2f(1,1); glVertex3f(-h, h, h);
        glTexCoord2f(0,1); glVertex3f(-h, h,-h);
        glNormal3f(1,0,0);
        glTexCoord2f(0,0); glVertex3f( h,-h,-h);
        glTexCoord2f(1,0); glVertex3f( h,-h, h);
        glTexCoord2f(1,1); glVertex3f( h, h, h);
        glTexCoord2f(0,1); glVertex3f( h, h,-h);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glColor3f(0,0,0); glutWireCube(TILE_SIZE + 0.01f);
    glPopMatrix();
}

// Tile FINISH: specular + shininess + emissive (karakteristik: refleksifitas & roughness)
void drawCubeFinish(float x, float y, float z) {
    glPushMatrix();
    glTranslatef(x, y, z);
    glDisable(GL_COLOR_MATERIAL);
    GLfloat matDiff[]  = {1.0f, 1.0f, 0.0f, 1.0f};
    GLfloat matSpec[]  = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat matShine[] = {120.0f};
    GLfloat matEmit[]  = {0.3f, 0.3f, 0.0f, 1.0f};
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,   matDiff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,  matSpec);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, matShine);
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION,  matEmit);
    GLfloat lightSpec[] = {1.0f, 1.0f, 1.0f, 1.0f};
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpec);
    float h = TILE_SIZE * 0.5f;
    glBegin(GL_QUADS);
        glNormal3f(0,1,0);
        glVertex3f(-h,h,-h); glVertex3f(h,h,-h); glVertex3f(h,h,h); glVertex3f(-h,h,h);
        glNormal3f(0,-1,0);
        glVertex3f(-h,-h,-h); glVertex3f(-h,-h,h); glVertex3f(h,-h,h); glVertex3f(h,-h,-h);
        glNormal3f(0,0,1);
        glVertex3f(-h,-h,h); glVertex3f(h,-h,h); glVertex3f(h,h,h); glVertex3f(-h,h,h);
        glNormal3f(0,0,-1);
        glVertex3f(-h,-h,-h); glVertex3f(-h,h,-h); glVertex3f(h,h,-h); glVertex3f(h,-h,-h);
        glNormal3f(-1,0,0);
        glVertex3f(-h,-h,-h); glVertex3f(-h,-h,h); glVertex3f(-h,h,h); glVertex3f(-h,h,-h);
        glNormal3f(1,0,0);
        glVertex3f(h,-h,-h); glVertex3f(h,h,-h); glVertex3f(h,h,h); glVertex3f(h,-h,h);
    glEnd();
    GLfloat noSpec[] = {0,0,0,1}; GLfloat noEmit[] = {0,0,0,1};
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, noSpec);
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, noEmit);
    glLightfv(GL_LIGHT0, GL_SPECULAR, noSpec);
    glEnable(GL_COLOR_MATERIAL);
    glColor3f(0,0,0); glutWireCube(TILE_SIZE + 0.01f);
    glPopMatrix();
}

// Tile TRAP: transparansi saat countdown (karakteristik: transparansi)
void drawCubeTrap(float x, float y, float z, float r, float g, float b, float countdown) {
    glPushMatrix();
    glTranslatef(x, y, z);
    float alpha = 1.0f - (countdown / TRAP_LIMIT) * 0.7f;
    if (countdown > 0) {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glDepthMask(GL_FALSE);
    }
    glColor4f(r, g, b, alpha);
    glutSolidCube(TILE_SIZE);
    if (countdown > 0) {
        glDepthMask(GL_TRUE);
        glDisable(GL_BLEND);
    }
    glColor3f(0,0,0); glutWireCube(TILE_SIZE + 0.01f);
    glPopMatrix();
}

// Tile MOVING & default
void drawCube(float x, float y, float z, float r, float g, float b) {
    glPushMatrix();
    glTranslatef(x, y, z);
    glColor3f(r, g, b);
    glutSolidCube(TILE_SIZE);
    glColor3f(0,0,0);
    glutWireCube(TILE_SIZE + 0.01f);
    glPopMatrix();
}

void drawCharacter() {
    glPushMatrix();
    // player.y = tepat di permukaan tile, origin karakter = bawah kaki
    glTranslatef(player.x, player.y, player.z);
    glRotatef(rotationY, 0, 1, 0);

    // KAKI KIRI – mulai dari y=0 ke atas
    glPushMatrix();
    glTranslatef(-0.12f, 0.2f, 0.0f);
    glColor3f(0.1f, 0.1f, 0.1f);
    glScalef(0.13f, 0.4f, 0.13f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // KAKI KANAN
    glPushMatrix();
    glTranslatef(0.12f, 0.2f, 0.0f);
    glColor3f(0.1f, 0.1f, 0.1f);
    glScalef(0.13f, 0.4f, 0.13f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // BADAN – di atas kaki
    glPushMatrix();
    glTranslatef(0.0f, 0.65f, 0.0f);
    glColor3f(0.2f, 0.2f, 1.0f);
    glScalef(0.4f, 0.5f, 0.2f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // TANGAN KIRI
    glPushMatrix();
    glTranslatef(-0.3f, 0.65f, 0.0f);
    glRotatef(20, 0, 0, 1);
    glColor3f(1.0f, 0.8f, 0.6f);
    glScalef(0.12f, 0.4f, 0.12f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // TANGAN KANAN
    glPushMatrix();
    glTranslatef(0.3f, 0.65f, 0.0f);
    glRotatef(-20, 0, 0, 1);
    glColor3f(1.0f, 0.8f, 0.6f);
    glScalef(0.12f, 0.4f, 0.12f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // KEPALA – di atas badan
    glPushMatrix();
    glTranslatef(0.0f, 1.1f, 0.0f);
    glColor3f(1.0f, 0.8f, 0.6f);
    glutSolidSphere(0.2f, 16, 16);
    glPopMatrix();

    glPopMatrix();
}

void drawGrid() {
    glDisable(GL_LIGHTING);
    glColor3f(0.3f, 0.5f, 0.3f);
    glBegin(GL_LINES);
    for (int i = -50; i <= 50; i++) {
        glVertex3f((float)i, -0.51f, -50); glVertex3f((float)i, -0.51f,  50);
        glVertex3f(-50, -0.51f, (float)i); glVertex3f( 50, -0.51f, (float)i);
    }
    glEnd();
    glEnable(GL_LIGHTING);
}

void drawText2D(float x, float y, const char* str) {
    glMatrixMode(GL_PROJECTION);
    glPushMatrix(); glLoadIdentity();
    int vp[4]; glGetIntegerv(GL_VIEWPORT, vp);
    gluOrtho2D(0, vp[2], 0, vp[3]);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix(); glLoadIdentity();
    glDisable(GL_LIGHTING);
    glColor3f(1, 1, 1);
    glRasterPos2f(x, y);
    for (const char* c = str; *c; c++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    glEnable(GL_LIGHTING);
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
}

// Display 
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    int vp[4]; glGetIntegerv(GL_VIEWPORT, vp);
    float aspect = (float)vp[2] / vp[3];

    if (viewMode > 0) {
        glMatrixMode(GL_PROJECTION);
        glPushMatrix(); glLoadIdentity();
        glOrtho(-10*aspect, 10*aspect, -10, 10, -100, 100);
        glMatrixMode(GL_MODELVIEW); glLoadIdentity();
        if (viewMode == 1)
            gluLookAt(player.x, 30, player.z, player.x, 0, player.z, 0, 0, -1); // Top
        else if (viewMode == 2)
            gluLookAt(player.x, player.y, 30, player.x, player.y, 0, 0, 1, 0);  // Front
        else
            gluLookAt(30, player.y, player.z, 0, player.y, player.z, 0, 1, 0);  // Side
    } else {
        // Smooth camera
        camX += (player.x - 4 - camX) * 0.1f;
        camY += (player.y + 5 - camY) * 0.1f;
        camZ += (player.z + 4 - camZ) * 0.1f;
        gluLookAt(camX, camY, camZ, player.x, player.y, player.z, 0, 1, 0);
    }

    drawGrid();

    for (size_t i = 0; i < tiles.size(); i++) {
        Tile& t = tiles[i];
        if (!t.active) continue;
        float tx = t.x + t.shakeOffset;
        float r, g, b;
        switch (t.type) {
            case SAFE:   r=0.2f; g=0.8f; b=0.2f; break;
            case TRAP:
                if (t.countdown > 0) { float ratio = t.countdown/TRAP_LIMIT; r=1.0f; g=ratio*0.4f; b=0.0f; }
                else { r=1.0f; g=0.4f; b=0.0f; }
                break;
            case MOVING: r=0.2f; g=0.4f; b=1.0f; break;
            case FINISH: r=1.0f; g=1.0f; b=0.0f; break;
            default:     r=0.5f; g=0.5f; b=0.5f; break;
        }
        if      (t.type == SAFE)   drawCube(tx, t.y, t.z, 0.4f, 1.0f, 0.4f);
        else if (t.type == FINISH) drawCubeFinish(tx, t.y, t.z);
        else if (t.type == TRAP)   drawCubeTrap(tx, t.y, t.z, r, g, b, t.countdown);
        else                       drawCube(tx, t.y, t.z, r, g, b);
    }

    drawCharacter();

    if (viewMode > 0) {
        glMatrixMode(GL_PROJECTION); glPopMatrix();
        glMatrixMode(GL_MODELVIEW);
    }

    char buf[64];
    sprintf(buf, "Level: %d   Score: %d   Lives: %d", currentLevel, player.score, lives);
    drawText2D(10, 20, buf);
    const char* viewLabel[] = {"[V] Perspective","[V] Top View","[V] Front View","[V] Side View"};
    drawText2D(10, 45,  viewLabel[viewMode]);
    drawText2D(10, 70,  "W/S : Maju/Mundur");
    drawText2D(10, 95,  "A/D : Kiri/Kanan");
    drawText2D(10, 120, "SPACE : Lompat");
    drawText2D(10, 145, "V : Kamera   R : Restart   ESC : Keluar");

    if (gameState == WIN_SCREEN)
        drawText2D(200, 300, "YOU WIN! Next level loading...");
    if (gameState == LOSE_SCREEN)
        drawText2D(200, 300, "FELL! Respawning...");

    glutSwapBuffers();
}

void reshape(int w, int h) {
    if (h == 0) h = 1;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION); glLoadIdentity();
    gluPerspective(60.0, (double)w/h, 0.1, 200.0);
    glMatrixMode(GL_MODELVIEW);
}

// Win / Lose callbacks 
void onWinTimer(int) {
    currentLevel++;
    generateLevel(currentLevel);
    resetPlayer();
    gameState = PLAYING;
    glutPostRedisplay();
}

void onLoseTimer(int) {
    resetPlayer();
    for (size_t i = 0; i < tiles.size(); i++) {
        Tile& t = tiles[i];
        t.active=true; t.isFalling=false;
        t.fallSpeed=0; t.countdown=0; t.shakeOffset=0; t.y=0.0f;
    }
    gameState = PLAYING;
    glutPostRedisplay();
}

// Update
void update(int) {
    glutTimerFunc(16, update, 0);
    if (gameState != PLAYING) return;

    timeT += 0.016f;

    player.prevX = player.x;
    player.prevZ = player.z;

    float speed = 0.1f;
    if (keyW) player.x += speed;
    if (keyS) player.x -= speed;
    if (keyA) player.z -= speed;
    if (keyD) player.z += speed;

    for (size_t i = 0; i < tiles.size(); i++) {
        Tile& t = tiles[i];
        if (!t.active) continue;
        if (t.type == MOVING)
            t.x += sinf(timeT) * 0.02f;
        if (t.isFalling) {
            t.fallSpeed += 0.01f;
            t.y -= t.fallSpeed;
            if (t.y < -20.0f) t.active = false;
        }
    }

    Tile* ground = tileUnderPlayer();
    if (ground) {
        player.onGround = true;
        player.canJump  = true;
        player.vy = 0.0f;
        player.y = ground->y + TILE_SIZE * 0.5f; // kaki tepat di permukaan tile

        if (ground->type == TRAP && !ground->isFalling) {
            ground->countdown += 0.016f;
            ground->shakeOffset = (ground->countdown > TRAP_LIMIT * 0.6f)
                ? ((rand()%3 - 1) * 0.04f) : 0.0f;
            if (ground->countdown >= TRAP_LIMIT) {
                ground->isFalling   = true;
                ground->shakeOffset = 0.0f;
            }
        }

        if (ground->type == MOVING)
            player.x += sinf(timeT) * 0.02f;

        if (ground->type == FINISH) {
            player.score += 100 * currentLevel;
            gameState = WIN_SCREEN;
            glutTimerFunc(1500, onWinTimer, 0);
        }
    } else {
        player.onGround = false;
        player.vy += GRAVITY;
        player.y  += player.vy;
    }

    if (player.y < -5.0f) {
        lives--;
        if (lives <= 0) { currentLevel = 1; lives = 3; }
        gameState = LOSE_SCREEN;
        glutTimerFunc(1200, onLoseTimer, 0);
    }

    // rotasi karakter berdasarkan arah gerak player
    float dx = player.x - player.prevX;
    float dz = player.z - player.prevZ;
    if (fabsf(dx) > 0.001f || fabsf(dz) > 0.001f) {
        float targetAngle = atan2f(dx, dz) * 180.0f / 3.14159f;
        // normalisasi selisih sudut agar smooth
        float diff = targetAngle - rotationY;
        while (diff >  180.0f) diff -= 360.0f;
        while (diff < -180.0f) diff += 360.0f;
        rotationY += diff * 0.2f;
    }
	
    glutPostRedisplay();
}

// Input
void keyDown(unsigned char key, int, int) {
    switch (key) {
        case 'w': case 'W': keyW = true; break;
        case 's': case 'S': keyS = true; break;
        case 'a': case 'A': keyA = true; break;
        case 'd': case 'D': keyD = true; break;
        case ' ':
            if (player.canJump) { player.vy = 0.25f; player.canJump = false; }
            break;
        case 'v': case 'V': viewMode = (viewMode + 1) % 4; break;
        case 'r': case 'R':
            generateLevel(currentLevel); resetPlayer(); gameState = PLAYING; break;
        case 27: exit(0);
    }
    glutPostRedisplay();
}

void keyUp(unsigned char key, int, int) {
    switch (key) {
        case 'w': case 'W': keyW = false; break;
        case 's': case 'S': keyS = false; break;
        case 'a': case 'A': keyA = false; break;
        case 'd': case 'D': keyD = false; break;
    }
}

// Lighting
void initLighting() {
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glShadeModel(GL_SMOOTH); // Gouraud shading
    GLfloat pos[]  = {5, 10, 5, 1};         // point light
    GLfloat amb[]  = {0.3f, 0.3f, 0.3f, 1}; // ambient light
    GLfloat diff[] = {0.9f, 0.9f, 0.9f, 1}; // diffuse
    glLightfv(GL_LIGHT0, GL_POSITION, pos);
    glLightfv(GL_LIGHT0, GL_AMBIENT,  amb);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  diff);
}

// Main
int main(int argc, char** argv) {
    srand(42);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(900, 600);
    glutCreateWindow("3D Tile Rush");

    glEnable(GL_DEPTH_TEST);
    glClearColor(0.4f, 0.7f, 1.0f, 1.0f); // background biru langit
    initTexture();
    initLighting();

    generateLevel(currentLevel);
    resetPlayer();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyDown);
    glutKeyboardUpFunc(keyUp);
    glutTimerFunc(16, update, 0);

    glutMainLoop();
    return 0;
}
