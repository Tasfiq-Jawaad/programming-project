#ifndef DEFINE_H
#define DEFINE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// defines for max and min permitted dimensions
#define MAX_DIM 100
#define MIN_DIM 5

// defines for the required autograder exit codes
#define EXIT_SUCCESS 0
#define EXIT_ARG_ERROR 1
#define EXIT_FILE_ERROR 2
#define EXIT_MAZE_ERROR 3
#define EXIT_UNEXPECTED_ERROR 100

// structure to represent coordinates
typedef struct __Coord
{
    int x;
    int y;
} Coord;

// structure to represent maze
typedef struct __Maze
{
    char **map;
    int height;
    int width;
    Coord start;
    Coord end;
    Coord position;
} Maze;

#endif