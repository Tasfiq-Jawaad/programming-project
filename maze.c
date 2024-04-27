#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLUMNS 100

// Structure to represent a maze
typedef struct {
    int rows;
    int columns;
    char cells[MAX_ROWS][MAX_COLUMNS];
    int currentCol;
    int currentRow;
    int startCol;
    int startRow;
    int endCol;
    int endRow;
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

int main(int argc, char *argv[]) {
    // Check for correct number of command-line arguments
    if (argc != 2) {
        printf("Usage: studentData <filename>");
        return EXIT_FAILURE;
    }

    // Open the maze file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Bad filename");
        return EXIT_FAILURE;
    }

    Maze maze = loadMazeFromFile(file);


    // Close the file
    fclose(file);

    displayMaze(maze);

    // Navigation
    char key;
    do {
        scanf("\r%c", &key);

        switch (key) {
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



Maze loadMazeFromFile(FILE *file) {
    Maze maze;
    int row = 0, column = 0;
    char ch;

    // in this function, the game will scan the maze file and store each of the wall
    // and identify the starting row and column
    // and the ending row and column
    while ((ch = fgetc(file)) != EOF) {
        
    }
    maze.columns = column;   
    return maze;
}

void moveUp(Maze maze){
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

void moveDown(Maze maze){
    // in this function, the game will check if the 'down' movement is valid or not

    // if movement is valid
        // the current row and column will be updated
    // if movement invalid
        // it will check if there is a wall up ahead
            printf("Dialogue : can't move down. There is a wall\n");
        // else
            printf("Dialogue : can't move down. That's the edge\n");
}

void moveRight(Maze maze){
    // in this function, the game will check if the 'right' movement is valid or not

    // if movement is valid
        // the current row and column will be updated
    // if movement invalid
        // it will check if there is a wall up ahead
            printf("Dialogue : can't move right. There is a wall\n");
        // else
            printf("Dialogue : can't move right. That's the edge\n");
}

void moveRight(Maze maze){
    // in this function, the game will check if the 'left' movement is valid or not

    // if movement is valid
        // the current row and column will be updated
    // if movement invalid
        // it will check if there is a wall up ahead
            printf("Dialogue : can't move left. There is a wall\n");
        // else
            printf("Dialogue : can't move left. That's the edge\n");
}

void printMap(Maze maze){
    // in this function, the program will printf the whole map
    // and replace the current position with X
}

void endGame(){
    printf("You won!\n");
    return EXIT_SUCCESS;
}



// /**
//  * @file maze.c
//  * @author (YOUR NAME)
//  * @brief Code for the maze game for COMP1921 Assignment 2
//  * NOTE - You can remove or edit this file however you like - this is just a provided skeleton code
//  * which may be useful to anyone who did not complete assignment 1.
//  */

// #include <stdio.h>
// #include <stdlib.h>

// // defines for max and min permitted dimensions
// #define MAX_DIM 100
// #define MIN_DIM 5

// // defines for the required autograder exit codes
// #define EXIT_SUCCESS 0
// #define EXIT_ARG_ERROR 1
// #define EXIT_FILE_ERROR 2
// #define EXIT_MAZE_ERROR 3

// typedef struct __Coord
// {
//     int x;
//     int y;
// } coord;

// typedef struct __Maze
// {
//     char **map;
//     int height;
//     int width;
//     coord start;
//     coord end;
// } maze;

// /**
//  * @brief Initialise a maze object - allocate memory and set attributes
//  *
//  * @param this pointer to the maze to be initialised
//  * @param height height to allocate
//  * @param width width to allocate
//  * @return int 0 on success, 1 on fail
//  */
// int create_maze(maze *this, int height, int width)
// {
// }

// /**
//  * @brief Free the memory allocated to the maze struct
//  *
//  * @param this the pointer to the struct to free
//  */
// void free_maze(maze *this)
// {
// }

// /**
//  * @brief Validate and return the width of the mazefile
//  *
//  * @param file the file pointer to check
//  * @return int 0 for error, or a valid width (5-100)
//  */
// int get_width(FILE *file)
// {
// }

// /**
//  * @brief Validate and return the height of the mazefile
//  *
//  * @param file the file pointer to check
//  * @return int 0 for error, or a valid height (5-100)
//  */
// int get_height(FILE *file)
// {
// }

// /**
//  * @brief read in a maze file into a struct
//  *
//  * @param this Maze struct to be used
//  * @param file Maze file pointer
//  * @return int 0 on success, 1 on fail
//  */
// int read_maze(maze *this, FILE *file)
// {
// }

// /**
//  * @brief Prints the maze out - code provided to ensure correct formatting
//  *
//  * @param this pointer to maze to print
//  * @param player the current player location
//  */
// void print_maze(maze *this, coord *player)
// {
//     // make sure we have a leading newline..
//     printf("\n");
//     for (int i = 0; i < this->height; i++)
//     {
//         for (int j = 0; j < this->width; j++)
//         {
//             // decide whether player is on this spot or not
//             if (player->x == j && player->y == i)
//             {
//                 printf("X");
//             }
//             else
//             {
//                 printf("%c", this->map[i][j]);
//             }
//         }
//         // end each row with a newline.
//         printf("\n");
//     }
// }

// /**
//  * @brief Validates and performs a movement in a given direction
//  *
//  * @param this Maze struct
//  * @param player The player's current position
//  * @param direction The desired direction to move in
//  */
// void move(maze *this, coord *player, char direction)
// {
// }

// /**
//  * @brief Check whether the player has won and return a pseudo-boolean
//  *
//  * @param this current maze
//  * @param player player position
//  * @return int 0 for false, 1 for true
//  */
// int has_won(maze *this, coord *player)
// {
// }

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