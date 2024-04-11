#include "main.h"
#include <SDL2/SDL.h>

/**
 * drawMap - Draw the map on the window.
 * @renderer: SDL renderer.
 * @map: 2D array representing the map.
 * @mapWidth: Width of the map.
 * @mapHeight: Height of the map.
 * @playerX: Player's X position.
 * @playerY: Player's Y position.
 * @playerAngle: Player's angle.
 * @showMap: Flag to enable/disable map drawing.
 */
void drawMap(SDL_Renderer *renderer, int map[][MAP_WIDTH], int mapWidth, int mapHeight,
             float playerX, float playerY, float playerAngle, int showMap) {
    if (!showMap) {
        return;
    }

    // Set color for walls
    SDL_SetRenderDrawColor(renderer, 128, 128, 128, 255);

    // Draw walls
    for (int y = 0; y < mapHeight; y++) {
        for (int x = 0; x < mapWidth; x++) {
            if (map[y][x] == 1) {
                SDL_Rect wallRect = {x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE};
                SDL_RenderFillRect(renderer, &wallRect);
            }
        }
    }

    // Draw player's line of sight
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red color for line of sight
    SDL_RenderDrawLine(renderer, (int)(playerX * TILE_SIZE), (int)(playerY * TILE_SIZE),
                       (int)((playerX + cos(playerAngle)) * TILE_SIZE),
                       (int)((playerY + sin(playerAngle)) * TILE_SIZE));
}

