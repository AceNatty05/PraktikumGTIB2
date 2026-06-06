#include "camera.h"

void setupCamera() {
    glLoadIdentity();
    float targetX = player.x + panX; 
    float targetY = player.y + 0.8f + panY; 
    float targetZ = player.z + panZ;
    
    float cx = 0, cy = 0, cz = 0;
    float upX = 0, upY = 1, upZ = 0;
    
    if (cameraMode == 0) { 
        float rad = camAngle * 3.14159f / 180.0f;
        cx = targetX + std::sin(rad) * camDistance; 
        cz = targetZ + std::cos(rad) * camDistance;
        cy = targetY + 4.8f;
    } else if (cameraMode == 1) { 
        cx = player.x; cy = player.y + 1.8f; cz = player.z;
        float headingRad = rotationY * 3.14159f / 180.0f; 
        float lookDirX = std::sin(headingRad);
        float lookDirZ = std::cos(headingRad);
        targetX = cx + lookDirX * 10.0f; targetY = cy; targetZ = cz + lookDirZ * 10.0f;
    } else if (cameraMode == 2) { 
        cx = targetX; cy = targetY + 22.0f; cz = targetZ + 0.05f;
    } else if (cameraMode == 3) { 
        cx = targetX + 18.0f; cy = targetY + 1.5f; cz = targetZ;
    } else { 
        float finishX = player.x, finishY = player.y, finishZ = player.z - 30.0f;
        for (size_t i = 0; i < tiles.size(); i++) {
            if (tiles[i].type == FINISH) { finishX = tiles[i].x; finishY = tiles[i].y; finishZ = tiles[i].z; break; }
        }
        cx = finishX; cy = finishY + 8.0f; cz = finishZ + 18.0f;
        targetX = finishX; targetY = finishY + 1.2f; targetZ = finishZ;
    }
    gluLookAt(cx, cy, cz, targetX, targetY, targetZ, upX, upY, upZ);
}

void reshape(int w, int h) {
    if (h == 0) h = 1; 
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION); glLoadIdentity();
    gluPerspective(52.0f, (float)w / h, 0.1f, 1200.0f);
    glMatrixMode(GL_MODELVIEW);
}
