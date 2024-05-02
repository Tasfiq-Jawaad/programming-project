#include "define.h"
#include "utility.h"

/**
 * @brief Open a file and check if it is valid
 *
 * @param filename the name of the file to open
 * @param mode the mode to open the file in
 * @return FILE* the file pointer
 */
FILE *open_file(const char *filename, const char *mode)
{
    FILE *file = fopen(filename, mode);
    if (file == NULL)
    {
        printf("Error: Bad filename\n");
        exit(EXIT_FILE_ERROR);
    }
    return file;
}

/**
 * @brief return the width of the mazefile
 *
 * @param file the file pointer to check
 * @return int width of the first line
 */
int get_width(FILE *file)
{
    int width = 0;
    char ch;
    // read the first line of the file until it reaches a new line or end of file
    while ((ch = fgetc(file)) != '\n' && ch != EOF)
    {
        width++;
    }
    // Reset the file pointer to the beginning of the file
    fseek(file, 0, SEEK_SET);
    return width;
}

/**
 * @brief return the height of the mazefile
 *
 * @param file the file pointer to check
 * @return int number of line (height of the maze)
 */
int get_height(FILE *file)
{
    int height = 0;
    char ch;
    // Count the number of lines in the file until it reaches the end of the file
    while ((ch = fgetc(file)) != EOF)
    {
        if (ch == '\n')
        {
            height++;
        }
    }
    height++;
    // Reset the file pointer to the beginning of the file
    fseek(file, 0, SEEK_SET);
    return height;
}

/**
 * @brief check if the maze dimension is valid
 *
 * @param dimension
 * @return int 0 for valid dimensions
 */
int validateDimension(int dimension)
{
    if (dimension < MIN_DIM)
    {
        printf("Error: the maze is too small\n");
        exit(EXIT_MAZE_ERROR);
    }
    if (dimension > MAX_DIM)
    {
        printf("Error: the maze is too large\n");
        exit(EXIT_MAZE_ERROR);
    }
    return 0;
}

/**
 * @brief Prints the map
 *
 * @param maze pointer to maze to print
 * @param player the current player location
 */
void print_map(Maze *maze)
{
    // make sure we have a leading newline..
    printf("\n");
    for (int i = 0; i < maze->height; i++)
    {
        if (i == maze->position.y)
        {
            for (int j = 0; j < maze->width; j++)
            {
                if (maze->position.x == j)
                {
                    printf("X");
                }
                else
                {
                    printf("%c", maze->map[i][j]);
                }
            }
            printf("\n");
        }
        else
        {
            printf("%s\n", maze->map[i]);
        }
    }
}

/**
 * @brief check if the player has reached the end of the maze
 *
 * @return void
 */
void isEndGame(Maze *maze)
{
    if (maze->position.x == maze->end.x && maze->position.y == maze->end.y)
    {
        printf("You won!\n");
        free_maze(maze);
        exit(EXIT_SUCCESS);
    }
}

/**
 * @brief Free the memory allocated to the maze struct
 *
 * @param maze the pointer to the struct to free
 */
void free_maze(Maze *maze)
{
    for (int i = 0; i < maze->height; i++)
    {
        free(maze->map[i]);
    }
    free(maze->map);
}

/**
 * @brief Move the player up in the maze
 *
 * @param maze the maze structure containing the map
 * @return void as the maze is updated in place
 */
void moveUp(Maze *maze)
{
    if (maze->position.y > 0 && maze->map[maze->position.y - 1][maze->position.x] != '#')
    {
        maze->position.y--;
        printf("Dialogue: you moved up\n");
    }
    else if (maze->position.y == 0) // if the player is at the top edge/row
    {
        printf("Dialogue: can't move up. That's the edge\n");
    }
    else
    {
        printf("Dialogue: can't move up. There is a wall\n");
    }
    // check for end of game
    isEndGame(maze);
}

/**
 * @brief Move the player down in the maze
 *
 * @param maze the maze structure containing the map
 * @return void as the maze is updated in place
 */
void moveDown(Maze *maze)
{
    if (maze->position.y < maze->height - 1 && maze->map[maze->position.y + 1][maze->position.x] != '#')
    {
        maze->position.y++;
        printf("Dialogue: you moved down\n");
    }
    else if (maze->position.y == maze->height - 1) // if the player is at the bottom edge/row
    {
        printf("Dialogue: can't move down. That's the edge\n");
    }
    else
    {
        printf("Dialogue: can't move down. There is a wall\n");
    }
    // check for end of game
    isEndGame(maze);
}

/**
 * @brief Move the player right in the maze
 *
 * @param maze the maze structure containing the map
 * @return void as the maze is updated in place
 */
void moveRight(Maze *maze)
{
    if (maze->position.x < maze->width - 1 && maze->map[maze->position.y][maze->position.x + 1] != '#')
    {
        maze->position.x++;
        printf("Dialogue: you moved right\n");
    }
    else if (maze->position.x == maze->width - 1) // if the player is at the right edge/column
    {
        printf("Dialogue: can't move right. That's the edge\n");
    }
    else
    {
        printf("Dialogue: can't move right. There is a wall\n");
    }
    // check for end of game
    isEndGame(maze);
}

/**
 * @brief Move the player left in the maze
 *
 * @param maze the maze structure containing the map
 * @return void as the maze is updated in place
 */
void moveLeft(Maze *maze)
{
    if (maze->position.x > 0 && maze->map[maze->position.y][maze->position.x - 1] != '#')
    {
        maze->position.x--;
        printf("Dialogue: you moved left\n");
    }
    else if (maze->position.x == 0) // if the player is at the left edge/column
    {
        printf("Dialogue: can't move left. That's the edge\n");
    }
    else
    {
        printf("Dialogue: can't move left. There is a wall\n");
    }
    // check for end of game
    isEndGame(maze);
}

/**
 * @brief Clear the buffer
 *
 * @return void
 */
void clearBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}
