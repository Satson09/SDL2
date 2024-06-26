#ifndef MAIN_H
#define MAIN_H

#include <SDL2/SDL.h>
#include <stdbool.h> // Include the stdbool.h header for bool type

// Constants
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define FOV_ANGLE 60 * M_PI / 180
#define NUM_RAYS SCREEN_WIDTH
#define MAX_VIEW_DISTANCE 800
#define RAY_STEP 1
#define TILE_SIZE 64
#define CAMERA_SPEED 0.1

#define MAP_WIDTH 20
#define MAP_HEIGHT 13

// Structure to represent the camera/player
typedef struct {
    float x;
    float y;
    float angle;
} Camera;

// Function declarations
int detectCollision(float playerX, float playerY, int map[][MAP_WIDTH], __attribute__((unused))int mapWidth, __attribute__((unused))int mapHeight, int playerWidth, int playerHeight, float movementX, float movementY, float *newX, float *newY);
void updateCameraAngle(Camera* camera, SDL_Event event);
void castRays(SDL_Renderer* renderer, Camera* camera);
void drawMap(SDL_Renderer* renderer, int map[][MAP_WIDTH], int mapWidth, int mapHeight,
             float playerX, float playerY, float playerAngle, int showMap);
void renderScene(SDL_Renderer* renderer, Camera* camera);
bool loadTexture(__attribute__((unused))const char* filename, SDL_Renderer* renderer);
int parseMapFromFile(const char* mapFilePath, int map[][MAP_WIDTH], int* mapWidth, int* mapHeight);
bool loadWeaponTextures(SDL_Renderer* renderer);
void updateCameraPosition(Camera* camera, SDL_Event event);
void renderWeapon(SDL_Renderer* renderer, Camera* __attribute__((unused))camera );
bool renderEnemies(SDL_Renderer* renderer);
void rotateCamera(Camera* camera, float angle);
void renderTextures(SDL_Renderer* renderer);
void renderRain(SDL_Renderer* renderer); // Added declaration for renderRain function
void gameLoop(SDL_Renderer* renderer);

// Function to load and render textures
bool loadTexture(const char* filename, SDL_Renderer* renderer);

// Function to load and render weapon texture
bool loadWeaponTextures(SDL_Renderer* renderer);
void renderWeapon(SDL_Renderer* renderer, Camera* camera);

// Function to render enemies
bool renderEnemies(SDL_Renderer* renderer);

// Declaration of bool movement variables
extern bool moveForward;
extern bool moveBackward;
extern bool moveLeft;
extern bool moveRight;


#endif /* MAIN_H */


