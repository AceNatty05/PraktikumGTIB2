#include "level_generator.h"
#include "global.h"

void generateLevel(int level) {
    tiles.clear();
    clouds.clear();
    particles.clear();

    
    int totalTiles = 10 + level;
    if (totalTiles > 20) totalTiles = 20;

    float currentZ = 0.0f; 

    for (int i = 0; i < totalTiles; ++i) {
        // 1. GENERATE BALOK UTAMA (SAFE / MOVING / FINISH)
        Tile t;
        t.shakeOffset = 0.0f; 
        t.deltaOffset = 0.0f;
        t.pulseTime = (float)(rand() % 100); 
        t.active = true;
        
        if (i == totalTiles - 1) {
            // Balok Terakhir selalu FINISH
            t.type = FINISH; 
            t.scaleX = 2.0f; t.scaleZ = 2.0f; t.scaleY = 1.0f;
        } else {
            // LOGIKA LEVEL 3 KE ATAS: Peluang muncul tile MOVING (berosilasi)
            if (level >= 3 && (rand() % 10 < 3)) { 
                // 30% peluang balok menjadi tile yang bergerak
                t.type = MOVING;
                t.scaleX = 1.2f; t.scaleZ = 1.2f; t.scaleY = 1.0f;
            } else {
                // Balok aman (statis)
                t.type = SAFE; 
                t.scaleX = 1.2f; t.scaleZ = 1.2f; t.scaleY = 1.0f;
            }
        }

        t.x = 0.0f;
        t.z = currentZ; // Posisi balok mengikuti pelacak dinamis
        t.y = 0.0f;
        
        tiles.push_back(t);

        // 2. GENERATE PIRAMIDA (TRAP) 
        int trapChance = 2 + (level / 2); 
        if (trapChance > 6) trapChance = 6; 

        if (i > 0 && i < totalTiles - 1 && (rand() % 10 < trapChance)) {
            Tile trap;
            trap.type = TRAP;
            trap.active = true;
            trap.scaleX = 0.6f; trap.scaleZ = 0.6f; trap.scaleY = 0.2f;
            
            trap.x = 0.0f;
            trap.z = currentZ - 2.0f;
            trap.y = 0.0f; 
            
            tiles.push_back(trap);

            currentZ -= 4.0f; 
        } else {
            // Jika tidak ada piramida, jarak ke balok berikutnya normal (3.2f)
            currentZ -= 3.2f;
        }
    }

    // 3. GENERATE DEKORASI AWAN
    for (int i = 0; i < 9; ++i) {
        Cloud c;
        c.x = -40.0f + ((float)rand() / RAND_MAX) * 80.0f;
        c.y = -8.0f - ((float)rand() / RAND_MAX) * 6.0f; 
        c.z = -50.0f + ((float)rand() / RAND_MAX) * 100.0f;
        c.sizeX = 6.0f + ((float)rand() / RAND_MAX) * 12.0f;
        c.sizeY = 2.0f + ((float)rand() / RAND_MAX) * 3.0f;
        c.sizeZ = 6.0f + ((float)rand() / RAND_MAX) * 12.0f;
        c.speed = 0.01f + ((float)rand() / RAND_MAX) * 0.02f;
        clouds.push_back(c);
    }


}
