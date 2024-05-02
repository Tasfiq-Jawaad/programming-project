/**
 * @file maze.c
 * @author Mohammad Tasfiq Jawaad
 * @brief Code for the maze game for COMP1921 Assignment 2
 */

#include "define.h"
#include "utility.h"

void read_maze(Maze *this, Coord *player, FILE *file);
void create_maze(Maze *maze);
void display_menu();

int main(int argc, char *argv[])
{
    // check for correct number of command-line arguments
    if (argc != 2)
    {
        printf("Usage: maze <filename>\n");
        return EXIT_ARG_ERROR;
    }

    // open the maze file
    FILE *file = open_file(argv[1], "r");

    // variable declaration
    Maze maze; // declare the maze variable
    Coord player; // variable to store player's position

    // Get the width and height of the maze
    maze.width = get_width(file);
    validateDimension(maze.width);
    
    maze.height = get_height(file);
    validateDimension(maze.height);

    // Create the maze
    create_maze(&maze);

    // read the maze file and set the map
    read_maze(&maze, &player, file);


    // initially show the map for the player
    print_map(&maze);

    // display the menu
    display_menu();

    // navigation input
    char input[3]; // input buffer with one extra space to check for extra characters
    do
    {
        printf("What will be your move?: ");
        fgets(input, sizeof(input), stdin);

        input[strcspn(input, "\n")] = '\0'; // Remove the newline character to compare the input
        if (strlen(input) > 1)
        {
            printf("Error: Only one character allowed\n");
            clearBuffer(); // clear the buffer
        }
        else
        {
            char character = input[0];
            switch (character)
            {
            case 'w':
            case 'W':
                moveUp(&maze);
                break;
            case 's':
            case 'S':
                moveDown(&maze);
                break;
            case 'd':
            case 'D':
                moveRight(&maze);
                break;
            case 'a':
            case 'A':
                moveLeft(&maze);
                break;
            case 'm':
            case 'M':
                print_map(&maze);
                break;
            default:
                printf("Error: invalid key\n");
                break;
            }
        }
    } while (1);
}


/**
 * @brief read in a maze file into a struct
 *
 * @param maze Maze struct containing the map
 * @param player Player struct to store the player's position
 * @param file Maze file pointer
 * @return void as the maze is updated in place
 */
void read_maze(Maze *maze, Coord *player, FILE *file)
{
    // Read the maze file and store the map
    char ch;
    int startCount = 0;
    int endCount = 0;
    for (int i = 0; i < maze->height; i++)
    {
        int chCount = 0; // counter for the number of characters in the row
        // Read each line until it reaches a new line or end of file
        while ((ch = fgetc(file)) != '\n' && ch != EOF)
        {
            maze->map[i][chCount] = ch;
            if (ch == 'S')
            {
                maze->start.x = chCount;
                maze->start.y = i;
                maze->position.x = chCount;
                maze->position.y = i;
                startCount++;
            }
            if (ch == 'E')
            {
                maze->end.x = chCount;
                maze->end.y = i;
                endCount++;
            }
            if (ch != 'S' && ch != 'E' && ch != '#' && ch != ' ')
            {
                printf("Error: the maze contains invalid characters\n");
                exit(EXIT_MAZE_ERROR);
            }
            chCount++;
        }
        if ((i == maze->height - 1 && chCount != 0 && chCount != maze->width) || (i != maze->height - 1 && chCount != maze->width)) // Check if the row has the same size as the width
        // allowing for the last row to be empty
        {
            printf("Error: each row and column does not have the same size\n");
            exit(EXIT_MAZE_ERROR);
        }
    }

    if (startCount == 0)
    {
        printf("Error: starting point missing\n");
        exit(EXIT_MAZE_ERROR);
    }
    else if (startCount > 1)
    {
        printf("Error: multiple starting point found\n");
        exit(EXIT_MAZE_ERROR);
    }

    if (endCount == 0)
    {
        printf("Error: no ending point found\n");
        exit(EXIT_MAZE_ERROR);
    }
    else if (endCount > 1)
    {
        printf("Error: multiple ending point found\n");
        exit(EXIT_MAZE_ERROR);
    }
    printf("Success : maze loaded successfully\n");
}

/**
 * @brief Initialise a maze object - allocate memory and set attributes
 *
 * @param maze pointer to the maze to be initialised
 * @return void as the maze is updated in place
 */
void create_maze(Maze *maze)
{
    // Allocate memory for the map
    maze->map = (char **)malloc(maze->height * sizeof(char *));
    if (maze->map == NULL)
    {
        printf("Error: Memory allocation failed\n");
        exit(EXIT_UNEXPECTED_ERROR);
    }
    for (int i = 0; i < maze->height; i++)
    {
        maze->map[i] = (char *)malloc(maze->width * sizeof(char));
        if (maze->map[i] == NULL)
        {
            printf("Error: Memory allocation failed\n");
            exit(EXIT_UNEXPECTED_ERROR);
        }
    }

    // Initialize the start, end, and position coordinates with default values of -1
    maze->start.x = -1;
    maze->start.y = -1;
    maze->end.x = -1;
    maze->end.y = -1;
    maze->position.x = -1;
    maze->position.y = -1;
}

/**
 * @brief display the menu for the maze game
 *
 * @return void
 */
void display_menu()
{
    printf("Welcome to this maze game!\n");
    printf("Use the following keys to navigate the maze:\n");
    printf("W or w to move up\n");
    printf("S or s to move down\n");
    printf("A or a to move left\n");
    printf("D or d to move right\n");
    printf("M or m to display the map. Your current position will be displayed as X. Good luck!!\n");
}