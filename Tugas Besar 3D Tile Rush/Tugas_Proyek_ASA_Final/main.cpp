#include "global.h"
#include "texture.h"
#include "player.h"
#include "tile.h"
#include "level_generator.h"
#include "camera.h"
#include "lighting.h"
#include "shadow.h"
#include "interaction.h"

// Deklarasi lokal untuk fungsi helper text yang berada di interaction
void drawTextWithShadow(float x, float y, const char* str, float r, float g, float b);

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    if (gameState == LOSE_SCREEN) { //
        glClearColor(0.18f, 0.02f, 0.02f, 1.0f); 
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        drawTextWithShadow(440, 360, "GAME OVER", 1.0f, 0.2f, 0.2f); //
        drawTextWithShadow(360, 300, "kamu gagal!", 1.0f, 1.0f, 1.0f); //
        drawTextWithShadow(390, 240, "Menunggu respawn otomatis...", 0.8f, 0.8f, 0.8f); //
        glutSwapBuffers(); return;
    }
    
    if (gameState == WIN_SCREEN) { //
        glClearColor(0.01f, 0.18f, 0.08f, 1.0f); 
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        drawTextWithShadow(410, 360, "VICTORY! LEVEL CLEAR", 0.2f, 1.0f, 0.2f); //
        drawTextWithShadow(390, 300, "Selamat Kamu Berhasil Lolos!", 1.0f, 1.0f, 1.0f); //
        glutSwapBuffers(); return;
    }

    setupCamera(); //
    drawSkyBackground(); 

    // Render Kabut Atmosferik Rendah
    glEnable(GL_FOG);
    float fogColor[] = { 0.53f, 0.8f, 0.98f, 1.0f };
    glFogfv(GL_FOG_COLOR, fogColor); glFogi(GL_FOG_MODE, GL_EXP2); glFogf(GL_FOG_DENSITY, 0.0035f);
    
    // Draw Awan Dekoratif
    glDisable(GL_LIGHTING); glDisable(GL_TEXTURE_2D); glEnable(GL_BLEND); glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    for (size_t i = 0; i < clouds.size(); ++i) { //
        glPushMatrix(); glTranslatef(clouds[i].x, clouds[i].y, clouds[i].z);
        glColor4f(1.0f, 1.0f, 1.0f, 0.58f); glScalef(clouds[i].sizeX, clouds[i].sizeY, clouds[i].sizeZ);
        glutSolidSphere(0.5f, 12, 10); glPopMatrix();
    }
    glDisable(GL_BLEND); glDisable(GL_FOG);

    // Efek Sinter/Spark Finish area
    for (size_t i = 0; i < tiles.size(); ++i) { //
        if (tiles[i].type == FINISH) { spawnFinishParticles(tiles[i].x, tiles[i].y + 1.2f, tiles[i].z); } //
    }

    // Render Partikel Efek Visual
    glPushAttrib(GL_ENABLE_BIT); glDisable(GL_LIGHTING); glDisable(GL_TEXTURE_2D); glEnable(GL_BLEND); glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    for (size_t i = 0; i < particles.size(); ++i) { //
        glPushMatrix(); glTranslatef(particles[i].x, particles[i].y, particles[i].z);
        glColor4f(particles[i].r, particles[i].g, particles[i].b, particles[i].life);
        glutSolidSphere(particles[i].size, 8, 8); glPopMatrix();
    }
    glPopAttrib();

    // Perbarui posisi lampu sun agar selaras dengan posisi player
    lightPos[0] = player.x + 3.0f; lightPos[1] = player.y + 35.0f; lightPos[2] = player.z + 1.0f; //

    glEnable(GL_LIGHTING); glEnable(GL_TEXTURE_2D);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos); //
    glColor3f(1.0f, 1.0f, 1.0f); 

    // Render seluruh level rintangan menggunakan fungsi kotak bertekstur bricks
    for (size_t i = 0; i < tiles.size(); i++) {
        drawLevel();
    }


    // Render Sistem Bayangan yang Diperbaiki (Akurat di atas platform)
    drawBlobShadow();

    glEnable(GL_LIGHTING); glEnable(GL_TEXTURE_2D);
    drawCharacter();

    // HUD Teks Informasi UI
    char buf[128]; 
    std::sprintf(buf, "LEVEL: %d   |   SCORE: %d   |   LIVES: %d", currentLevel, player.score, lives);
    drawTextWithShadow(25, 160, buf, 1.0f, 1.0f, 0.0f); //
    drawTextWithShadow(25, 125, "[W] Maju   |   [S] Putar Balik [A] putar Kanan   |   [D] putar Kiri", 1.0f, 1.0f, 1.0f); //
    drawTextWithShadow(25, 95, "[SPACE] Lompat / Double Jump", 1.0f, 1.0f, 1.0f); //

    const char* modeNames[] = {
        "Kamera: Default Follow (Belakang)", "Kamera: First-Person (Mata Karakter)",
        "Kamera: Top-Down (Atas)", "Kamera: Side-View (Samping)", "Kamera: Finish Line Overview"
    };
    char camBuf[128];
    std::sprintf(camBuf, "[V] Ganti Perspektif  |  %s", modeNames[cameraMode]); //
    drawTextWithShadow(25, 65, camBuf, 0.1f, 1.0f, 0.5f); //
    drawTextWithShadow(25, 35, "[Panah Kiri/Kanan] Putar Kamera", 1.0f, 1.0f, 1.0f); //

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    std::srand(128);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH | GLUT_ALPHA);
    glutInitWindowSize(1024, 640); glutInitWindowPosition(100, 100);
    glutCreateWindow("3D Tile Rush");

    glEnable(GL_DEPTH_TEST);
    
    // Inisialisasi visual environment global (mengubah bg putih polos & mengaktifkan tekstur bricks)
    initVisualEnvironment(); 
    
    initTextures();
    initLighting();
    generateLevel(currentLevel); //
    resetPlayer();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape); //
    glutKeyboardFunc(keyDown); //
    glutKeyboardUpFunc(keyUp); //
    glutSpecialFunc(specialKey); //
    
    glutTimerFunc(16, update, 0); //

    glutMainLoop();
    return 0;
}
