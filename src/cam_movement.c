#include "inc/main.h"
/**
 * @brief Updates the camera position based on keyboard input.
 *
 * @param camera Pointer to the camera struct.
 * @param event  SDL event containing keyboard input.
 */

void updateCameraPosition(Camera* camera, SDL_Event event) {
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_w:
                // Move camera forward
                camera->x += cos(camera->angle * M_PI / 180);
                camera->y += sin(camera->angle * M_PI / 180);
                break;
            case SDLK_s:
                // Move camera backward
                camera->x -= cos(camera->angle * M_PI / 180);
                camera->y -= sin(camera->angle * M_PI / 180);
                break;
            case SDLK_a:
                // Move camera left
                camera->x -= cos((camera->angle + 90) * M_PI / 180);
                camera->y -= sin((camera->angle + 90) * M_PI / 180);
                break;
            case SDLK_d:
                // Move camera right
                camera->x += cos((camera->angle + 90) * M_PI / 180);
                camera->y += sin((camera->angle + 90) * M_PI / 180);
                break;
            default:
                break;
        }
    }
}

