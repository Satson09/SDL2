#include "main.h"
#include <SDL2/SDL_image.h>

// Function definition
bool renderEnemies(SDL_Renderer* renderer) {
    // Load texture images for enemies
    SDL_Surface* enemySurface = IMG_Load("image/enemy.jpeg");

    // Check if surface loading was successful
    if (!enemySurface) {
        printf("Failed to load enemy surface: %s\n", IMG_GetError());
        return false;  // Return false on failure
    }

    // Convert surface to texture
    SDL_Texture* enemyTexture = SDL_CreateTextureFromSurface(renderer, enemySurface);

    // Check if texture loading was successful
    if (!enemyTexture) {
        printf("Failed to load enemy texture: %s\n", IMG_GetError());
        SDL_FreeSurface(enemySurface);
        return false;    // Return false on failure
    }

    // Render enemies at different positions
    // Example positions:
    SDL_Rect enemyRect1 = {200, 200, 50, 50};
    SDL_Rect enemyRect2 = {300, 300, 50, 50};
    
    // Render enemies
    SDL_RenderCopy(renderer, enemyTexture, NULL, &enemyRect1);
    SDL_RenderCopy(renderer, enemyTexture, NULL, &enemyRect2);

    // Cleanup
    SDL_FreeSurface(enemySurface);
    SDL_DestroyTexture(enemyTexture);

    return true;  // Return true on success
}

