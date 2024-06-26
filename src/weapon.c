#include "main.h"
#include <SDL2/SDL_image.h>

// Load weapon textures
SDL_Texture* weaponTexture = NULL;

bool loadWeaponTextures(SDL_Renderer* renderer) {
    // Load weapon texture from file
    SDL_Surface* weaponSurface = IMG_Load("image/weapon.gif");
    if (!weaponSurface) {
	fprintf(stderr, "Failed to load weapon texture: %s\n", SDL_GetError());
	return false;  // Return false on failure
        // Handle error
    }

    // Convert surface to texture
    weaponTexture = SDL_CreateTextureFromSurface(renderer, weaponSurface);
    SDL_FreeSurface(weaponSurface);
    // Check if texture loading was successful
     if (!weaponTexture) {
	 fprintf(stderr, "Failed to load weapon texture: %s\n", SDL_GetError());
	 return false;  // Return false on failure
        // Handle error
     }
     return true;  // Return false on success
}

// Render weapon texture
void renderWeapon(SDL_Renderer* renderer, Camera* camera __attribute__((unused))) {
     // Ensure weapon texture is loaded before rendering
    if (weaponTexture) {
        // Set position and size of weapon texture
        SDL_Rect weaponRect = {10, SCREEN_HEIGHT - 100, 100, 100}; // Example position and size


        // Render weapon texture
        SDL_RenderCopy(renderer, weaponTexture, NULL, &weaponRect);
    } else {
        fprintf(stderr, "Weapon texture not loaded!\n");
        // Handle error or fallback behavior if needed
    }
}
