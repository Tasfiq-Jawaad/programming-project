/**
 * @file maze.c
 * @author Mohammad Tasfiq Jawaad
 * @brief Code for the maze game for COMP1921 Assignment 2
 */

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

// Structure to represent coordinates
typedef struct __Coord
{
    int x;
    int y;
} coord;

// Structure to represent maze
typedef struct __Maze
{
    char **map;
    int height;
    int width;
    coord start;
    coord end;
    coord position;
} Maze;

// Function prototypes
Maze loadMazeFromFile(FILE *file);
void displayMaze(Maze maze);
void moveUp(Maze maze);
void moveDown(Maze maze);
void moveRight(Maze maze);
void moveLeft(Maze maze);
void printMap(Maze maze);
void endGame();

int main(int argc, char *argv[])
{
    // Check for correct number of command-line arguments
    if (argc != 2)
    {
        printf("Usage: studentData <filename>");
        return EXIT_FAILURE;
    }

    // Open the maze file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Error: Bad filename");
        return EXIT_FAILURE;
    }

    Maze maze = loadMazeFromFile(file);

    // Close the file
    fclose(file);

    displayMaze(maze);

    // Navigation
    char key;
    do
    {
        scanf("\r%c", &key);

        switch (key)
        {
        case 'w':
        case 'W':
            moveUp(maze);
            break;
        case 's':
        case 'S':
            moveDown(maze);
            break;
        case 'd':
        case 'D':
            moveRight(maze);
            break;
        case 'a':
        case 'A':
            moveLeft(maze);
            break;
        case 'm':
        case 'M':
            printMap(maze);
            break;
        default:
            printf("Error: invalid key\n");
        }

    } while (1);

    return EXIT_SUCCESS;
}

/**
 * @brief Initialise a maze object - allocate memory and set attributes
 *
 * @param file pointer to the maze to be initialised
 * @param height height to allocate
 * @param width width to allocate
 * @return int 0 on success, 1 on fail
 */
Maze loadMazeFromFile(FILE *file)
{
    Maze maze;
    int row = 0, column = 0;
    char ch;

    // in this function, the game will scan the maze file and store each of the wall
    // and identify the starting row and column
    // and the ending row and column
    while ((ch = fgetc(file)) != EOF)
    {
    }
    // maze.columns = column;
    return maze;
}

void moveUp(Maze maze)
{
    // in this function, the game will check if the 'up' movement is valid or not

    // if movement is valid
    // the current row and column will be updated
    // if movement invalid
    // it will check if there is a wall up ahead
    printf("Dialogue : can't move up. There is a wall\n");
    // else
    printf("Dialogue : can't move up. That's the edge\n");
    // if its the end of the maze
}

void moveDown(Maze maze)
{
    // in this function, the game will check if the 'down' movement is valid or not

    // if movement is valid
    // the current row and column will be updated
    // if movement invalid
    // it will check if there is a wall up ahead
    printf("Dialogue : can't move down. There is a wall\n");
    // else
    printf("Dialogue : can't move down. That's the edge\n");
}

void moveRight(Maze maze)
{
    // in this function, the game will check if the 'right' movement is valid or not

    // if movement is valid
    // the current row and column will be updated
    // if movement invalid
    // it will check if there is a wall up ahead
    printf("Dialogue : can't move right. There is a wall\n");
    // else
    printf("Dialogue : can't move right. That's the edge\n");
}

void moveRight(Maze maze)
{
    // in this function, the game will check if the 'left' movement is valid or not

    // if movement is valid
    // the current row and column will be updated
    // if movement invalid
    // it will check if there is a wall up ahead
    printf("Dialogue : can't move left. There is a wall\n");
    // else
    printf("Dialogue : can't move left. That's the edge\n");
}

void printMap(Maze maze)
{
    // in this function, the program will printf the whole map
    // and replace the current position with X
}

void endGame()
{
    printf("You won!\n");
    return EXIT_SUCCESS;
}

// ----------------------------------------------

/**
 * @brief Initialise a maze object - allocate memory and set attributes
 *
 * @param this pointer to the maze to be initialised
 * @param height height to allocate
 * @param width width to allocate
 * @return int 0 on success, 1 on fail
 */
int create_maze(Maze *this, int height, int width)
{
    // Allocate memory for the map
    this->map = (char **)malloc(height * sizeof(char *));
    if (this->map == NULL)
    {
        printf("Error: Memory allocation failed");
        return 1;
    }
    for (int i = 0; i < height; i++)
    {
        this->map[i] = (char *)malloc(width * sizeof(char));
        if (this->map[i] == NULL)
        {
            printf("Error: Memory allocation failed");
            return 1;
        }
    }

    // Set the height and width
    this->height = height;
    this->width = width;

    // Initialize the start, end, and position coordinates
    this->start.x = -1;
    this->start.y = -1;
    this->end.x = -1;
    this->end.y = -1;
    this->position.x = -1;
    this->position.y = -1;

    // Read the maze file and store the map
    FILE *file = fopen("maze.txt", "r");
    if (file == NULL)
    {
        printf("Error: Bad filename");
        return 1;
    }
    if (read_maze(this, file) == 1)
    {
        fclose(file);
        return 1;
    }
    fclose(file);

    // Check if the maze is valid
    if (this->start.x == -1 || this->start.y == -1 || this->end.x == -1 || this->end.y == -1 || this->position.x == -1 || this->position.y == -1)
    {
        printf("Error: Invalid maze");
        return 1;
    }

    return 0;
}

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
 * @brief Validate and return the width of the mazefile
 *
 * @param file the file pointer to check
 * @return int 0 for error, or a valid width (5-100)
 */
int get_width(FILE *file)
{
    int width;
    if (fscanf(file, "%d", &width) != 1)
    {
        printf("Error: Invalid width");
        return 0;
    }
    if (width < MIN_DIM || width > MAX_DIM)
    {
        printf("Error: Invalid width");
        return 0;
    }
    return width;
}

/**
 * @brief Validate and return the height of the mazefile
 *
 * @param file the file pointer to check
 * @return int 0 for error, or a valid height (5-100)
 */
int get_height(FILE *file)
{
    int height;
    if (fscanf(file, "%d", &height) != 1)
    {
        printf("Error: Invalid height");
        return 0;
    }
    if (height < MIN_DIM || height > MAX_DIM)
    {
        printf("Error: Invalid height");
        return 0;
    }
    return height;
}

/**
 * @brief read in a maze file into a struct
 *
 * @param this Maze struct to be used
 * @param file Maze file pointer
 * @return int 0 on success, 1 on fail
 */
int read_maze(Maze *this, FILE *file)
{
    // Get the width and height of the maze
    int width = get_width(file);
    if (width == 0)
    {
        return 1;
    }
    int height = get_height(file);
    if (height == 0)
    {
        return 1;
    }

    // Create the maze
    if (create_maze(this, height, width) == 1)
    {
        return 1;
    }

    // Read the maze file
    if (fgetc(file) != '\n')
    {
        printf("Error: Invalid maze");
        return 1;
    }

    // Read the maze file and store the map
    int row = 0, column = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF)
    {
        if (ch == '\n')
        {
            row++;
            column = 0;
        }
        else
        {
            this->map[row][column] = ch;
            column++;
        }
    }

    // Check if the maze is valid
    if (this->start.x == -1 || this->start.y == -1 || this->end.x == -1 || this->end.y == -1 || this->position.x == -1 || this->position.y == -1)
    {
        printf("Error: Invalid maze");
        return 1;
    }

    return 0;
}

/**
 * @brief Prints the maze out - code provided to ensure correct formatting
 *
 * @param this pointer to maze to print
 * @param player the current player location
 */
void print_maze(Maze *this, coord *player)
{
    // make sure we have a leading newline..
    printf("\n");
    for (int i = 0; i < this->height; i++)
    {
        for (int j = 0; j < this->width; j++)
        {
            // decide whether player is on this spot or not
            if (player->x == j && player->y == i)
            {
                printf("X");
            }
            else
            {
                printf("%c", this->map[i][j]);
            }
        }
        // end each row with a newline.
        printf("\n");
    }
}

/**
 * @brief Validates and performs a movement in a given direction
 *
 * @param this Maze struct
 * @param player The player's current position
 * @param direction The desired direction to move in
 */
void move(Maze *this, coord *player, char direction)
{

}

/**
 * @brief Check whether the player has won and return a pseudo-boolean
 *
 * @param this current maze
 * @param player player position
 * @return int 0 for false, 1 for true
 */
int has_won(Maze *this, coord *player)
{
}

// int main()
// {
//     // check args

//     // set up some useful variables (you can rename or remove these if you want)
//     coord *player;
//     maze *this_maze = malloc(sizeof(maze));
//     FILE *f;

//     // open and validate mazefile

//     // read in mazefile to struct

//     // maze game loop

//     // win

//     // return, free, exit
// }