#ifndef MAIN_H
#define MAIN_H

#include <SDL2/SDL.h>
#include <stdbool.h> // Include the stdbool.h header for bool type

// Constants
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define TILE_SIZE 64
#define MAP_WIDTH 8
#define MAP_HEIGHT 8

// Structure to represent the camera/player
typedef struct {
    float x;
    float y;
    float angle;
} Camera;

// Function declarations
void updateCameraAngle(Camera* camera, SDL_Event event);
void castRays(SDL_Renderer* renderer, Camera* camera);
void drawMap(SDL_Renderer* renderer, int map[][MAP_WIDTH], int mapWidth, int mapHeight,
             float playerX, float playerY, float playerAngle, int showMap);
void renderScene(SDL_Renderer* renderer, Camera* camera);
void loadWeaponTextures(SDL_Renderer* renderer);
void renderWeapon(SDL_Renderer* renderer, Camera* camera);
void renderEnemies(SDL_Renderer* renderer);
void renderRain(SDL_Renderer* renderer); // Added declaration for renderRain function

// Declaration of bool movement variables
extern bool moveForward;
extern bool moveBackward;
extern bool moveLeft;
extern bool moveRight;

#endif /* MAIN_H */

