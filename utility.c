#include "define.h"
#include "utility.h"


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
 * @brief check if the maze dimention is valid
 *
 * @param dimention
 * @return int 0 for valid dimensions
 */
int validateDimention(int dimention)
{
    if (dimention < MIN_DIM)
    {
        printf("Error: the maze is too small\n");
        exit(EXIT_MAZE_ERROR);
    }
    if (dimention > MAX_DIM)
    {
        printf("Error: the maze is too large\n");
        exit(EXIT_MAZE_ERROR);
    }
    return 0;
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
    else if (maze->position.y == 0)
    {
        printf("Dialogue: can't move up. That's the edge\n");
    }
    else
    {
        printf("Dialogue: can't move up. There is a wall\n");
    }
    // if its the end of the maze
    if (maze->position.x == maze->end.x && maze->position.y == maze->end.y)
    {
        endGame();
    }
}

void moveDown(Maze *maze)
{
    // in this function, the game will check if the 'down' movement is valid or not
    // if movement is valid
    // the current row and column will be updated
    // if movement invalid
    // it will check if there is a wall up ahead
    if (maze->position.y < maze->height - 1 && maze->map[maze->position.y + 1][maze->position.x] != '#')
    {
        maze->position.y++;
        printf("Dialogue: you moved down\n");
    }
    else if (maze->position.y == maze->height - 1)
    {
        printf("Dialogue: can't move down. That's the edge\n");
    }
    else
    {
        printf("Dialogue: can't move down. There is a wall\n");
    }
    // if its the end of the maze
    if (maze->position.x == maze->end.x && maze->position.y == maze->end.y)
    {
        endGame();
    }
}

void moveRight(Maze *maze)
{
    // in this function, the game will check if the 'right' movement is valid or not

    // if movement is valid
    // the current row and column will be updated
    // if movement invalid
    // it will check if there is a wall up ahead
    if (maze->position.x < maze->width - 1 && maze->map[maze->position.y][maze->position.x + 1] != '#')
    {
        maze->position.x++;
        printf("Dialogue: you moved right\n");
    }
    else if (maze->position.x == maze->width - 1)
    {
        printf("Dialogue: can't move right. That's the edge\n");
    }
    else
    {
        printf("Dialogue: can't move right. There is a wall\n");
    }
    // if its the end of the maze
    if (maze->position.x == maze->end.x && maze->position.y == maze->end.y)
    {
        endGame();
    }
}

void moveLeft(Maze *maze)
{
    // in this function, the game will check if the 'left' movement is valid or not

    // if movement is valid
    // the current row and column will be updated
    // if movement invalid
    // it will check if there is a wall up ahead
    if (maze->position.x > 0 && maze->map[maze->position.y][maze->position.x - 1] != '#')
    {
        maze->position.x--;
        printf("Dialogue: you moved left\n");
    }
    else if (maze->position.x == 0)
    {
        printf("Dialogue: can't move left. That's the edge\n");
    }
    else
    {
        printf("Dialogue: can't move left. There is a wall\n");
    }
    // if its the end of the maze
    if (maze->position.x == maze->end.x && maze->position.y == maze->end.y)
    {
        endGame();
    }
}

// void printMap(Maze maze)
// {
//     // in this function, the program will printf the wgit adhole map
//     // and replace the current position with X
// }

int endGame()
{
    printf("You won!\n");
    exit(EXIT_SUCCESS);
}

// ----------------------------------------------


/**
 * @brief Free the memory allocated to the maze struct
 *
 * @param this the pointer to the struct to free
 */
void free_maze(Maze *this)
{
    for (int i = 0; i < this->height; i++)
    {
        free(this->map[i]);
    }
    free(this->map);
}




/**
 * @brief Prints the maze out - code provided to ensure correct formatting
 *
 * @param this pointer to maze to print
 * @param player the current player location
 */
void print_maze(Maze *this)
{
    // make sure we have a leading newline..
    printf("\n");
    for (int i = 0; i < this->height; i++)
    {
        if (i == this->position.y)
        {
            for (int j = 0; j < this->width; j++)
            {
                if (this->position.x == j)
                {
                    printf("X");
                }
                else
                {
                    printf("%c", this->map[i][j]);
                }
            }
            printf("\n");
        }
        else
        {
            printf("%s\n", this->map[i]);
        }
        // printf("%s\n", this->map[i]);
        // for (int j = 0; j < this->width; j++)
        // {
        //     // decide whether player is on this spot or not
        //     if (this->position.x == j && this->position.y == i)
        //     {
        //         printf("X");
        //     }
        //     else
        //     {
        //         printf("%c", this->map[i][j]);
        //     }
        // }
        // end each row with a newline.
    }
}

/**
 * @brief Validates and performs a movement in a given direction
 *
 * @param this Maze struct
 * @param player The player's current position
 * @param direction The desired direction to move in
 */
void move(Maze *this, Coord *player, char direction)
{
    // Check the desired direction and perform the movement
    switch (direction)
    {
    case 'w':
    case 'W':
        moveUp(this);
        break;
    case 's':
    case 'S':
        moveDown(this);
        break;
    case 'd':
    case 'D':
        moveRight(this);
        break;
    case 'a':
    case 'A':
        moveLeft(this);
        break;
    default:
        printf("Invalid direction\n");
        break;
    }
}

/**
 * @brief Check whether the player has won and return a pseudo-boolean
 *
 * @param this current maze
 * @param player player position
 * @return int 0 for false, 1 for true
 */
int has_won(Maze *this, Coord *player)
{
}



void clearBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

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
