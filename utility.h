#ifndef UTILITY_H
#define UTILITY_H

// Function declarations

FILE* open_file(const char* filename, const char* mode);
int get_width(FILE *file);
int get_height(FILE *file);
int validateDimension(int dimension);
void print_map(Maze *maze, Coord *player);
void isEndGame(Maze *maze, Coord *player);
void free_maze(Maze *this);
void moveUp(Maze *maze, Coord *player);
void moveDown(Maze *maze, Coord *player);
void moveRight(Maze *maze, Coord *player);
void moveLeft(Maze *maze, Coord *player);
void clearBuffer();

#endif