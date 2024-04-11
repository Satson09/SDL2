#include "main.h"
#include <stdlib.h> // For rand()

// Constants
#define NUM_RAINDROPS 100
#define RAIN_WIDTH 2
#define RAIN_HEIGHT 10
#define RAIN_SPEED 3

// Structure to represent a raindrop
typedef struct {
    int x, y; // Position
    int speed; // Falling speed
} Raindrop;

// Function definition
void renderRain(SDL_Renderer* renderer) {
    // Array to store raindrops
    Raindrop raindrops[NUM_RAINDROPS];

    // Initialize raindrop positions and speeds
    for (int i = 0; i < NUM_RAINDROPS; ++i) {
        raindrops[i].x = rand() % 800; // Random x-coordinate
        raindrops[i].y = -(rand() % 600); // Random initial y-coordinate above the screen
        raindrops[i].speed = rand() % RAIN_SPEED + 1; // Random falling speed
    }

    // Render raindrops
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // Set color to blue
    for (int i = 0; i < NUM_RAINDROPS; ++i) {
        SDL_Rect raindropRect = {raindrops[i].x, raindrops[i].y, RAIN_WIDTH, RAIN_HEIGHT};
        SDL_RenderFillRect(renderer, &raindropRect);
    }

    // Update raindrop positions
    for (int i = 0; i < NUM_RAINDROPS; ++i) {
        raindrops[i].y += raindrops[i].speed;
        // If raindrop falls off the screen, reset its position to the top
        if (raindrops[i].y > 600) {
            raindrops[i].x = rand() % 800; // Random x-coordinate
            raindrops[i].y = -(rand() % 600); // Random initial y-coordinate above the screen
            raindrops[i].speed = rand() % RAIN_SPEED + 1; // Random falling speed
        }
    }
}

