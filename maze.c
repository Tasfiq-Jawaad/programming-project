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
void moveUp(Maze *maze);
void moveDown(Maze *maze);
void moveRight(Maze *maze);
void moveLeft(Maze *maze);
void printMap(Maze *maze);
int endGame();
void print_maze(Maze *maze);
void move(Maze *maze, coord *player, char direction);
int has_won(Maze *maze, coord *player);
int get_width(FILE *file);
int get_height(FILE *file);
int read_maze(Maze *this, FILE *file);
int create_maze(Maze *this, int height, int width);
void free_maze(Maze *this);
int validateDimention(int dimentions);

int main(int argc, char *argv[])
{
    // Check for correct number of command-line arguments
    if (argc != 2)
    {
        printf("Usage: maze <filename>\n");
        return EXIT_ARG_ERROR;
    }

    // Open the maze file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Error: Bad filename\n");
        return EXIT_FILE_ERROR;
    }

    // Read the maze file and store the map
    Maze maze; // Declare the maze variable
    read_maze(&maze, file);

    print_maze(&maze);

    char key;
    do
    {
        printf("Current position: %d, %d\n", maze.position.x, maze.position.y);
        scanf("\r%c", &key);
        if (key == 'w' || key == 'W')
        {
            moveUp(&maze);
        }
        // Add more conditions for other keys if needed
        printf("new position: %d, %d\n", maze.position.x, maze.position.y);
        print_maze(&maze);
        // ...
    } while (1);
    // moveUp(&maze);
}

/**
 * @brief Initialise a maze object - allocate memory and set attributes
 *
 * @param file pointer to the maze to be initialised
 * @param height height to allocate
 * @param width width to allocate
 * @return int 0 on success, 1 on fail
 */

void moveUp(Maze *this)
{
    // in this function, the game will check if the 'up' movement is valid or not

    // if movement is valid
    // the current row and column will be updated
    // if movement invalid
    // it will check if there is a wall up ahead
    if (this->position.y > 0 && this->map[this->position.y -1][this->position.x] != '#')
    {
        this->position.y--;
        printf("Dialogue: Moved up\n");
    }
    // else if (this->position.x == 0)
    // {
    //     printf("Dialogue: Can't move up. That's the edge\n");
    // }
    // else
    // {
    //     printf("Dialogue: Can't move up. There is a wall\n");
    // }
    // // if its the end of the this
    // if (this->position.x == this->end.x && this->position.y == this->end.y)
    // {
    //     endGame();
    // }
}

void moveDown(Maze *maze)
{
    // in this function, the game will check if the 'down' movement is valid or not
    // if movement is valid
    // the current row and column will be updated
    // if movement invalid
    // it will check if there is a wall up ahead
    if (maze->position.x < maze->height - 1 && maze->map[maze->position.x + 1][maze->position.y] != '#')
    {
        maze->position.x++;
        printf("Dialogue: Moved down\n");
    }
    else if (maze->position.x == maze->height - 1)
    {
        printf("Dialogue: Can't move down. That's the edge\n");
    }
    else
    {
        printf("Dialogue: Can't move down. There is a wall\n");
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
    if (maze->position.y < maze->width - 1 && maze->map[maze->position.x][maze->position.y + 1] != '#')
    {
        maze->position.y++;
        printf("Dialogue: Moved right\n");
    }
    else if (maze->position.y == maze->width - 1)
    {
        printf("Dialogue: Can't move right. That's the edge\n");
    }
    else
    {
        printf("Dialogue: Can't move right. There is a wall\n");
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
    if (maze->position.y > 0 && maze->map[maze->position.x][maze->position.y - 1] != '#')
    {
        maze->position.y--;
        printf("Dialogue: Moved left\n");
    }
    else if (maze->position.y == 0)
    {
        printf("Dialogue: Can't move left. That's the edge\n");
    }
    else
    {
        printf("Dialogue: Can't move left. There is a wall\n");
    }
    // if its the end of the maze
    if (maze->position.x == maze->end.x && maze->position.y == maze->end.y)
    {
        endGame();
    }
}

// void printMap(Maze maze)
// {
//     // in this function, the program will printf the whole map
//     // and replace the current position with X
// }

int endGame()
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
        printf("Error: Memory allocation failed\n");
        exit(EXIT_UNEXPECTED_ERROR);
    }
    for (int i = 0; i < height; i++)
    {
        this->map[i] = (char *)malloc(width * sizeof(char));
        if (this->map[i] == NULL)
        {
            printf("Error: Memory allocation failed\n");
            exit(EXIT_UNEXPECTED_ERROR);
        }
    }

    // Initialize the start, end, and position coordinates
    this->start.x = -1;
    this->start.y = -1;
    this->end.x = -1;
    this->end.y = -1;
    this->position.x = -1;
    this->position.y = -1;

    // // Read the maze file and store the map
    // FILE *file = fopen("maze.txt", "r");
    // if (file == NULL)
    // {
    //     printf("Error: Bad filename");
    //     return 1;
    // }
    // if (read_maze(this, file) == 1)
    // {
    //     fclose(file);
    //     return 1;
    // }
    // fclose(file);

    // // Check if the maze is valid
    // if (this->start.x == -1 || this->start.y == -1 || this->end.x == -1 || this->end.y == -1 || this->position.x == -1 || this->position.y == -1)
    // {
    //     printf("Error: Invalid maze");
    //     return 1;
    // }

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
    int width = 0;
    char ch;
    // Read the first line of the file
    while ((ch = fgetc(file)) != '\n' && ch != EOF)
    {
        width++;
    }
    // Reset the file pointer to the beginning of the file
    fseek(file, 0, SEEK_SET);
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
    int height = 0;
    char ch;
    // Count the number of lines in the file
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
 * @brief read in a maze file into a struct
 *
 * @param this Maze struct to be used
 * @param file Maze file pointer
 * @return int 0 on success, 1 on fail
 */
int read_maze(Maze *this, FILE *file)
{
    // Get the width and height of the maze
    this->width = get_width(file);
    validateDimention(this->width);

    this->height = get_height(file);
    validateDimention(this->height);

    // Create the maze
    create_maze(this, this->height, this->width);

    // Read the maze file and store the map

    char ch;
    int startCount = 0;
    int endCount = 0;
    for (int i = 0; i < this->height; i++)
    {
        int chCount = 0;
        // Read each line until it reaches a new line or end of file
        while ((ch = fgetc(file)) != '\n' && ch != EOF)
        {
            this->map[i][chCount] = ch;
            if (ch == 'S')
            {
                this->start.x = chCount;
                this->start.y = i;
                this->position.x = chCount;
                this->position.y = i;
                startCount++;
            }
            if (ch == 'E')
            {
                this->end.x = chCount;
                this->end.y = i;
                endCount++;
            }
            if (ch != 'S' && ch != 'E' && ch != '#' && ch != ' ')
            {
                printf("Error: the maze contains invalid characters\n");
                exit(EXIT_MAZE_ERROR);
            }
            chCount++;
        }
        if ((i == this->height - 1 && chCount != 0 && chCount != this->width) || (i != this->height - 1 && chCount != this->width)) // Check if the row has the same size as the width
        // allowing for the last row to be empty
        {
            printf("Error: each row and column does not have the same size\n");
            exit(EXIT_MAZE_ERROR);
        }
        // printf("%s\n", this->map[i]); // Print the scanned line
    }

    if (startCount == 0)
    {
        printf("Error: starting point missing\n");
        exit(EXIT_MAZE_ERROR);
    }
    if (startCount > 1)
    {
        printf("Error: multiple starting point found\n");
        exit(EXIT_MAZE_ERROR);
    }
    if (endCount == 0)
    {
        printf("Error: no ending point found\n");
        exit(EXIT_MAZE_ERROR);
    }
    if (endCount > 1)
    {
        printf("Error: multiple ending point found\n");
        exit(EXIT_MAZE_ERROR);
    }
    printf("Success : maze loaded successfully\n");
    return 0;
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
        if(i == this->position.y)
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
void move(Maze *this, coord *player, char direction)
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
int has_won(Maze *this, coord *player)
{
}

/**
 * @brief Check whether the player has won and return a pseudo-boolean
 *
 * @param this current maze
 * @param player player position
 * @return int 0 for valid dimensions
 */
int validateDimention(int dimentions)
{
    if (dimentions < MIN_DIM)
    {
        printf("Error: the maze is too small\n");
        exit(EXIT_MAZE_ERROR);
    }
    if (dimentions > MAX_DIM)
    {
        printf("Error: the maze is too large\n");
        exit(EXIT_MAZE_ERROR);
    }
    return 0;
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

// Maze maze = loadMazeFromFile(file);

// // Close the file
// fclose(file);

// displayMaze(maze);

// // Navigation
// char key;
// do
// {
//     scanf("\r%c", &key);

//     switch (key)
//     {
//     case 'w':
//     case 'W':
//         moveUp(&maze);
//         break;
//     case 's':
//     case 'S':
//         moveDown(&maze);
//         break;
//     case 'd':
//     case 'D':
//         moveRight(&maze);
//         break;
//     case 'a':
//     case 'A':
//         moveLeft(&maze);
//         break;
//     case 'm':
//     case 'M':
//         printMap(&maze);
//         break;
//     default:
//         printf("Error: invalid key\n");
//     }

// } while (1);

// return EXIT_SUCCESS;