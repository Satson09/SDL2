#include "inc/main.h"
#include <stdio.h>

/**
 * @brief Parses the map from a file and loads it into memory.
 *
 * @param mapFilePath Path to the map file.
 * @param map         Pointer to the map array.
 * @param mapWidth    Width of the map.
 * @param mapHeight   Height of the map.
 * @return 0 on success, -1 on failure.
 */
int parseMapFromFile(const char* mapFilePath, int map[][MAP_WIDTH], int* mapWidth, int* mapHeight) {
    FILE* mapFile = fopen(mapFilePath, "r");
    if (!mapFile) {
        fprintf(stderr, "Error: Unable to open map file %s\n", mapFilePath);
        return -1;
    }

    // Read map dimensions from file
    if (fscanf(mapFile, "%d %d\n", mapWidth, mapHeight) != 2) {
        fprintf(stderr, "Error: Invalid map dimensions\n");
        fclose(mapFile);
        return -1;
    }

    // Validate map dimensions
    if (*mapWidth > MAP_WIDTH || *mapHeight > MAP_HEIGHT) {
        fprintf(stderr, "Error: Map dimensions exceed maximum allowed size\n");
        fclose(mapFile);
        return -1;
    }

    // Read map data from file
    for (int i = 0; i < *mapHeight; i++) {
        for (int j = 0; j < *mapWidth; j++) {
            if (fscanf(mapFile, "%d", &map[i][j]) != 1) {
                fprintf(stderr, "Error: Invalid map data\n");
                fclose(mapFile);
                return -1;
            }
        }
    }

    fclose(mapFile);
    return 0;
}

