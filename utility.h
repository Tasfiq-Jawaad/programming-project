#ifndef UTILITY_H
#define UTILITY_H

// Function declarations

FILE* open_file(const char* filename, const char* mode);
int get_width(FILE *file);
int get_height(FILE *file);
int validateDimension(int dimension);
void print_map(Maze *maze);
void isEndGame(Maze *maze);
void free_maze(Maze *this);
void moveUp(Maze *maze);
void moveDown(Maze *maze);
void moveRight(Maze *maze);
void moveLeft(Maze *maze);
void clearBuffer();

#endif