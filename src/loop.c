#include "main.h"
#include <SDL2/SDL.h>


// Define flags for player movement
bool moveForward = false;
bool moveBackward = false;
bool moveLeft = false;
bool moveRight = false;

/* gameLoop - Runs the main game loop
 *
 * This function handles game events and updates game state.
 * It contains the main game loop logic.
 */
void gameLoop(SDL_Renderer* renderer) {
     bool running = true;

    // Main game loop
    while (running) {
        // Handle events
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
		     running = false;
                    // Handle quit event
                    break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                        case SDLK_w:
                            // Set flag for moving forward
                            moveForward = true;
                            break;
                        case SDLK_s:
                            // Set flag for moving backward
                            moveBackward = true;
                            break;
                        case SDLK_a:
                            // Set flag for moving left
                            moveLeft = true;
                            break;
                        case SDLK_d:
                            // Set flag for moving right
                            moveRight = true;
                            break;
                        // Add cases for other key events as needed
                    }
                    break;
                case SDL_KEYUP:
                    switch (event.key.keysym.sym) {
                        case SDLK_w:
                            // Clear flag for moving forward
                            moveForward = false;
                            break;
                        case SDLK_s:
                            // Clear flag for moving backward
                            moveBackward = false;
                            break;
                        case SDLK_a:
                            // Clear flag for moving left
                            moveLeft = false;
                            break;
                        case SDLK_d:
                            // Clear flag for moving right
                            moveRight = false;
                            break;
                        // Add cases for other key events as needed
                    }
                    break;
                // Add cases for other event types as needed
            }
        }
	 // Update player movement based on key flags
        if (moveForward && !moveBackward) {
            // Move player forward
        } else if (moveBackward && !moveForward) {
            // Move player backward
        }
        if (moveLeft && !moveRight) {
            // Move player left
        } else if (moveRight && !moveLeft) {
            // Move player right
        }
	 // Clear screen
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Render game objects (example: draw a white rectangle)
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Set draw color to red
        SDL_Rect testRect = {50, 50, 100, 100}; // Define a test rectangle
        SDL_RenderFillRect(renderer, &testRect);

        // Present the rendered frame
        SDL_RenderPresent(renderer);
    }
}

