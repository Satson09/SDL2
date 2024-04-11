#include "main.h"
#include <math.h>

#define MAP_WIDTH 20
#define MAP_HEIGHT 13

int map[MAP_HEIGHT][MAP_WIDTH] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1},
};


/* Function to update the camera's angle based on user input */
void updateCameraAngle(Camera* camera, SDL_Event event) {
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_LEFT:
                camera->angle -= 0.1f;
                break;
            case SDLK_RIGHT:
                camera->angle += 0.1f;
                break;
            default:
                break;
        }
    }
}

/* Function to perform raycasting using DDA method */
void castRays(SDL_Renderer* renderer, Camera* camera) {
    float rayAngleIncrement = FOV_ANGLE / NUM_RAYS;
    float rayAngle = camera->angle - (FOV_ANGLE / 2);

    for (int i = 0; i < NUM_RAYS; i++) {
        float rayDirX = cos(rayAngle * M_PI / 180);
        float rayDirY = sin(rayAngle * M_PI / 180);

        float distanceToWallX = 0;
        float distanceToWallY = 0;
        int hitWall = 0;

        /* Perform DDA algorithm */
        while (!hitWall && (distanceToWallX < MAX_VIEW_DISTANCE || distanceToWallY < MAX_VIEW_DISTANCE)) {
            if (distanceToWallX < distanceToWallY) {
                distanceToWallX += RAY_STEP;
                int mapX = (int)(camera->x + rayDirX * distanceToWallX);
                int mapY = (int)(camera->y + rayDirY * distanceToWallX);

                if (mapX < 0 || mapX >= MAP_WIDTH || mapY < 0 || mapY >= MAP_HEIGHT || map[mapY][mapX]) {
                    hitWall = 1;
                }
            } else {
                distanceToWallY += RAY_STEP;
                int mapX = (int)(camera->x + rayDirX * distanceToWallY);
                int mapY = (int)(camera->y + rayDirY * distanceToWallY);

                if (mapX < 0 || mapX >= MAP_WIDTH || mapY < 0 || mapY >= MAP_HEIGHT || map[mapY][mapX]) {
                    hitWall = 1;
                }
            }
        }

        /* Calculate wall height based on distance */
        float distanceToWall = hitWall ? fmin(distanceToWallX, distanceToWallY) : MAX_VIEW_DISTANCE;
        int wallHeight = (int)(SCREEN_HEIGHT / distanceToWall);

        /* Set wall color based on the direction of the ray */
        if (fabs(tan(rayAngle * M_PI / 180)) > 1) {
            // Vertical ray (facing NORTH/SOUTH)
            SDL_SetRenderDrawColor(renderer, hitWall ? 0 : 255, 128, 128, 255);
        } else {
            // Horizontal ray (facing EAST/WEST)
            SDL_SetRenderDrawColor(renderer, hitWall ? 128 : 255, 128, 128, 255);
        }

        /* Draw wall segment */
        SDL_RenderDrawLine(renderer, i, SCREEN_HEIGHT / 2 - wallHeight / 2, i, SCREEN_HEIGHT / 2 + wallHeight / 2);

        rayAngle += rayAngleIncrement;
    }
}

