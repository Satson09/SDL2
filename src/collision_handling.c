#include "inc/main.h"

/**
 * @brief Checks for collision between the player and walls in the map.
 *
 * @param playerX       X-coordinate of the player.
 * @param playerY       Y-coordinate of the player.
 * @param map           Pointer to the map array.
 * @param mapWidth      Width of the map.
 * @param mapHeight     Height of the map.
 * @param playerWidth   Width of the player.
 * @param playerHeight  Height of the player.
 * @param movementX     X-axis movement of the player.
 * @param movementY     Y-axis movement of the player.
 * @param newX          Output parameter for updated X-coordinate of the player after collision.
 * @param newY          Output parameter for updated Y-coordinate of the player after collision.
 * @return 1 if collision detected, 0 otherwise.
 */
int detectCollision(float playerX, float playerY, int map[][MAP_WIDTH], int mapWidth, int mapHeight, int playerWidth, int playerHeight, float movementX, float movementY, float *newX, float *newY) {
    // Calculate player's next position
    float nextPlayerX = playerX + movementX;
    float nextPlayerY = playerY + movementY;

    // Calculate player's position in map grid
    int gridX = (int)(nextPlayerX / TILE_SIZE);
    int gridY = (int)(nextPlayerY / TILE_SIZE);

    // Initialize updated player coordinates
    *newX = playerX;
    *newY = playerY;

    // Check collision with walls
    for (int i = 0; i < playerHeight; i++) {
        for (int j = 0; j < playerWidth; j++) {
            if (map[gridY + i][gridX + j] != 0) {
                // Collision detected
                // Adjust player's position to slide along the wall
                if (movementX > 0) {
                    *newX = (gridX + j) * TILE_SIZE - playerWidth;
                } else if (movementX < 0) {
                    *newX = (gridX + j + 1) * TILE_SIZE;
                }
                if (movementY > 0) {
                    *newY = (gridY + i) * TILE_SIZE - playerHeight;
                } else if (movementY < 0) {
                    *newY = (gridY + i + 1) * TILE_SIZE;
                }
                return 1;
            }
        }
    }

    // No collision detected
    *newX = nextPlayerX;
    *newY = nextPlayerY;
    return 0;
}
