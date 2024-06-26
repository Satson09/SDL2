#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "main.h"

bool loadTexture(__attribute__((unused))const char* filename, SDL_Renderer* renderer) {
    // Load image from file
    SDL_Surface* surface = IMG_Load("image/texture.png");
    if (!surface) {
        printf("Failed to load image: %s\n", IMG_GetError());
        return false;  // Return false on failure;
    }

    // Convert surface to texture
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!texture) {
        printf("Failed to create texture from surface: %s\n", SDL_GetError());
        SDL_FreeSurface(surface);
        return false;  // Return false on failure;
    }

    // Render texture
    SDL_Rect dstRect = {0, 0, surface->w, surface->h}; // Destination rectangle
    SDL_RenderCopy(renderer, texture, NULL, &dstRect);

    // Cleanup
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);

    return true;  // Return true on success
}

