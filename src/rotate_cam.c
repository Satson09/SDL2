#include "inc/main.h"
#include <math.h>

void rotateCamera(Camera* camera, float angle) {
    camera->angle += angle;
    // Normalize camera angle to keep it within the range [0, 360)
    if (camera->angle >= 360.0f) {
        camera->angle -= 360.0f;
    } else if (camera->angle < 0.0f) {
        camera->angle += 360.0f;
    }
}

