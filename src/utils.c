#include "inc/main.h"
#include <SDL2/SDL_image.h>

// Function definition
void renderTextures(SDL_Renderer* renderer) {
    // Load texture images for ground and ceiling
    SDL_Surface* groundSurface = IMG_Load("ground_texture.png");
    SDL_Surface* ceilingSurface = IMG_Load("ceiling_texture.png");

    // Convert surfaces to textures
    SDL_Texture* groundTexture = SDL_CreateTextureFromSurface(renderer, groundSurface);
    SDL_Texture* ceilingTexture = SDL_CreateTextureFromSurface(renderer, ceilingSurface);

    // Check if texture loading was successful
    if (!groundTexture || !ceilingTexture) {
        printf("Failed to load textures: %s\n", IMG_GetError());
        SDL_FreeSurface(groundSurface);
        SDL_FreeSurface(ceilingSurface);
        return;
    }

    // Render ground texture
    SDL_Rect groundRect = {0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2};
    SDL_RenderCopy(renderer, groundTexture, NULL, &groundRect);

    // Render ceiling texture
    SDL_Rect ceilingRect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT / 2};
    SDL_RenderCopy(renderer, ceilingTexture, NULL, &ceilingRect);

    // Cleanup
    SDL_FreeSurface(groundSurface);
    SDL_FreeSurface(ceilingSurface);
    SDL_DestroyTexture(groundTexture);
    SDL_DestroyTexture(ceilingTexture);
}

