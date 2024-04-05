#include "inc/main.h"
#include <SDL2/SDL_image.h>

// Load weapon textures
SDL_Texture* weaponTexture = NULL;

void loadWeaponTextures(SDL_Renderer* renderer) {
    // Load weapon texture from file
    SDL_Surface* weaponSurface = IMG_Load("weapon_texture.png");
    if (!weaponSurface) {
	fprintf(stderr, "Failed to load weapon texture: %s\n", SDL_GetError());
        // Handle error
    }

    // Convert surface to texture
    weaponTexture = SDL_CreateTextureFromSurface(renderer, weaponSurface);
    SDL_FreeSurface(weaponSurface);
    // Check if texture loading was successful
     if (!weaponTexture) {
	 fprintf(stderr, "Failed to load weapon texture: %s\n", SDL_GetError());
        // Handle error
    }
}

// Render weapon texture
void renderWeapon(SDL_Renderer* renderer, Camera* camera) {
    // Set position and size of weapon texture
    SDL_Rect weaponRect = {10, SCREEN_HEIGHT - 100, 100, 100}; // Example position and size

    // Render weapon texture
    SDL_RenderCopy(renderer, weaponTexture, NULL, &weaponRect);
}

