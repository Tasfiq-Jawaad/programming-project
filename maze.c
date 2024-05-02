/**
 * @file maze.c
 * @author Mohammad Tasfiq Jawaad
 * @brief Code for the maze game for COMP1921 Assignment 2
 */

#include "define.h"
#include "utility.h"

void read_maze(Maze *this, Coord *player, FILE *file);
void create_maze(Maze *maze);

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

    // variable declation
    Maze maze; // declare the maze variable
    Coord player; // variable to store player's position

    // Get the width and height of the maze
    maze.width = get_width(file);
    validateDimention(maze.width);
    
    maze->height = get_height(file);
    validateDimention(maze->height);

    // Create the maze
    create_maze(maze);

    // read the maze file and set the map
    read_maze(&maze, &player, file);


    // Read the maze file and store the map

    print_maze(&maze);

    char input[3];
    do
    {
        printf("Enter a character: ");
        fgets(input, sizeof(input), stdin);
        // scanf("%s", input);
        input[strcspn(input, "\n")] = '\0'; // Remove the newline character
        if (strlen(input) > 1)
        {
            printf("Error: Only one character allowed\n");
            clearBuffer();
        }
        else
        {
            char character = input[0];
            // Rest of your code using the character input
            if (character == 'w' || character == 'W')
            {
                moveUp(&maze);
            }
            else if (character == 's' || character == 'S')
            {
                moveDown(&maze);
            }
            else if (character == 'd' || character == 'D')
            {
                moveRight(&maze);
            }
            else if (character == 'a' || character == 'A')
            {
                moveLeft(&maze);
            }
            else if (character == 'm' || character == 'M')
            {
                print_maze(&maze);
            }
            else
            {
                printf("Error: invalid key\n");
            }
            // clearBuffer();
            // Remove the else block for 'w' or 'W' characters
        }

        // Add more conditions for other keys if needed
        // print_maze(&maze);
        // ...
    } while (1);
    // moveUp(&maze);
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
        int chCount = 0;
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
        // printf("%s\n", maze->map[i]); // Print the scanned line
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