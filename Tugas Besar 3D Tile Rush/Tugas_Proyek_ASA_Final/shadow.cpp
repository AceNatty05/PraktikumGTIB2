#include "shadow.h"

Tile* getTileForShadow() {
    Tile* highestTile = NULL; 
    float highestY = -9999.0f;
    for (size_t i = 0; i < tiles.size(); i++) { 
        Tile& t = tiles[i];
        if (!t.active) continue;
        float tx = t.x + t.shakeOffset;
        float halfW = (TILE_SIZE * t.scaleX) * 0.5f;
        float halfD = (TILE_SIZE * t.scaleZ) * 0.5f;
        if (std::fabs(player.x - tx) <= halfW + 0.3f && std::fabs(player.z - t.z) <= halfD + 0.3f) {
            float topY = t.y + (TILE_SIZE * t.scaleY) * 0.5f;
            if (player.y >= topY - 1.5f && topY > highestY) { 
                highestY = topY; highestTile = &t; 
            }
        }
    }
    return highestTile;
}

void drawBlobShadow() {
    glPushAttrib(GL_ENABLE_BIT);
    glDisable(GL_LIGHTING);
    glDisable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDepthMask(GL_FALSE); // Mematikan sementara penulisan kedalaman z-buffer untuk mencegah z-fighting berkrepip
    
    Tile* pt = getTileForShadow();
    if (pt) {
        float shadowHeight = pt->y + (TILE_SIZE * pt->scaleY) * 0.5f + 0.035f;
        glPushMatrix();
        glTranslatef(player.x, shadowHeight, player.z);
        
        float radius = 0.58f;
        float opacity = 0.78f;
        float heightDiff = player.y - shadowHeight;
        if (heightDiff > 0.0f) {
            radius *= (1.0f / (1.0f + heightDiff * 0.35f));
            opacity *= (1.0f / (1.0f + heightDiff * 0.40f));
        }
        
        glColor4f(0.005f, 0.005f, 0.015f, opacity);
        glBegin(GL_TRIANGLE_FAN);
        glVertex3f(0.0f, 0.0f, 0.0f);
        int numSegments = 24;
        for (int i = 0; i <= numSegments; ++i) {
            float angle = i * 2.0f * PI / numSegments;
            glVertex3f(std::cos(angle) * radius, 0.0f, std::sin(angle) * radius);
        }
        glEnd();
        glPopMatrix();
    }
    glDepthMask(GL_TRUE); 
    glPopAttrib();
}
