#include "main.h"
#include <stdio.h>
#include <SDL2/SDL_image.h>

/**
 * main - Entry point of the program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 * Return: 0 on success, non-zero on failure
 */
int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <map_txt>\n", argv[0]);
        return 1;
    }

    char* mapFilePath = argv[1];

    int map[MAP_HEIGHT][MAP_WIDTH];
    int mapWidth, mapHeight;

    if (parseMapFromFile(mapFilePath, map, &mapWidth, &mapHeight) != 0)
    {
        return 1;
    }

    // Initialize SDL
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        fprintf(stderr, "Error: SDL initialization failed: %s\n", SDL_GetError());
        return 1;
    }

    window = SDL_CreateWindow("3D Maze Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window)
    {
        fprintf(stderr, "Error: Window creation failed: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        fprintf(stderr, "Error: Renderer creation failed: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    Camera __attribute__((unused))camera = {2, 2, 0};

    // Load ground and ceiling textures
    if (!loadTexture("image/ground_texture.png", renderer) || !loadTexture("image/ceiling_texture.png", renderer))
    {
        fprintf(stderr, "Error: Failed to load ground or ceiling texture.\n");
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Load weapon texture
    if (!loadWeaponTextures(renderer))
    {
        fprintf(stderr, "Error: Failed to load weapon textures.\n");
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Render enemies
    if (!renderEnemies(renderer))
    {
        fprintf(stderr, "Error: Failed to render enemies.\n");
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Run the main game loop
    gameLoop(renderer);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
