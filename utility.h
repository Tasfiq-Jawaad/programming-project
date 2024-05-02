#ifndef UTILITY_H
#define UTILITY_H

// Function prototypes

int get_width(FILE *file);
int validateDimention(int dimention);


void moveUp(Maze *maze);
void moveDown(Maze *maze);
void moveRight(Maze *maze);
void moveLeft(Maze *maze);
void printMap(Maze *maze);
int endGame();
void print_maze(Maze *maze);
void move(Maze *maze, Coord *player, char direction);
int has_won(Maze *maze, Coord *player);
int get_height(FILE *file);
void free_maze(Maze *this);
void clearBuffer();
FILE* open_file(const char* filename, const char* mode);

#endif