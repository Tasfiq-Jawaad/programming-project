#!/bin/bash

gcc ./maze.c -o maze

all_counter=0
pass_counter=0

echo -e "~~ Argument Tests ~~"


    echo -n "Testing no arguments - "
        ./maze > out
        ((all_counter++))
        if grep -q "Usage: maze <filename>" out;
        then
            echo -e "\e[32mPASS\e[0m"
            ((pass_counter++))
        else
            echo -e "\e[31mFAIL\e[0m"
        fi


 # In this case, we are not expecting any success message
 # a message would mean the test failed
    echo -n "Testing 2 arguments - "
        ./maze x > out
        ((all_counter++))
        if grep -q "Usage: maze <filename>" out;
        then
            echo -e "\e[31mFAIL\e[0m"
        else
            echo -e "\e[32mPASS\e[0m"
            ((pass_counter++))
        fi

echo -e "\n~~ File Handling~~"

    echo -n "Testing bad filename - "
        ./maze fake_maze.txt > out
        ((all_counter++))
        if grep -q "Error: Bad filename" out;
        then
            echo -e "\e[32mPASS\e[0m"
            ((pass_counter++))
        else
            echo -e "\e[31mFAIL\e[0m"
        fi


    echo -n "Testing bad permissions - "
        # removing read permissions from this file
        chmod -r data/bad_perms.txt
        # adding a timeout to limit execution time in case it freezes.
        timeout 0.2s ./maze data/bad_perms.txt > out
        ((all_counter++))
        ((all_counter++))
        if grep -q "Error: Bad filename" out;
        then
            echo -e "\e[32mPASS\e[0m"
            ((pass_counter++))
        else
            echo -e "\e[31mFAIL\e[0m"
        fi
        # adding read perms back on to this for git.
        chmod +r data/bad_perms.txt

echo -e "\n~~ Maze Dimension Tests~~"

    echo -n "Testing invalid maze (empty) - "
        timeout 0.2s ./maze data/invalid_maze/empty_maze.txt > out
        ((all_counter++))
        if grep -q "Error: the maze is too small" out;
        then
            echo -e "\e[32mPASS\e[0m"
            ((pass_counter++))
        else
            echo -e "\e[31mFAIL\e[0m"
        fi

    echo -n "Testing invalid maze (small column size) - "
        timeout 0.2s ./maze data/invalid_maze/invalid_maze_too_small_cols.txt > out
        ((all_counter++))
        if grep -q "Error: the maze is too small" out;
        then
            echo -e "\e[32mPASS\e[0m"
            ((pass_counter++))
        else
            echo -e "\e[31mFAIL\e[0m"
        fi

    echo -n "Testing invalid maze (small row size) - "
        timeout 0.2s ./maze data/invalid_maze/invalid_maze_too_small_rows.txt > out
        ((all_counter++))
        if grep -q "Error: the maze is too small" out;
        then
            echo -e "\e[32mPASS\e[0m"
            ((pass_counter++))
        else
            echo -e "\e[31mFAIL\e[0m"
        fi

    echo -n "Testing invalid maze (large column size) - "
        timeout 0.2s ./maze data/invalid_maze/invalid_maze_too_large_cols.txt > out
        ((all_counter++))
        if grep -q "Error: the maze is too large" out;
        then
            echo -e "\e[32mPASS\e[0m"
            ((pass_counter++))
        else
            echo -e "\e[31mFAIL\e[0m"
        fi

    echo -n "Testing invalid maze (large row size) - "
        timeout 0.2s ./maze data/invalid_maze/invalid_maze_too_large_rows.txt > out
        ((all_counter++))
        if grep -q "Error: the maze is too large" out;
        then
            echo -e "\e[32mPASS\e[0m"
            ((pass_counter++))
        else
            echo -e "\e[31mFAIL\e[0m"
        fi


echo -e "\n~~ Column And Row Inconsistency Tests~~"

 # Testing with multiple file to make sure it can test multiple maze
    echo -n "Testing inconsistent row size (1) - "
    timeout 0.2s ./maze data/invalid_maze/invalid_maze_inconsistent_rows_1.txt > out
    ((all_counter++))
    if grep -q "Error: each row and column does not have the same size" out;
    then
        echo -e "\e[32mPASS\e[0m"
        ((pass_counter++))
    else
        echo -e "\e[31mFAIL\e[0m"
    fi

    echo -n "Testing inconsistent row size (2) - "
    timeout 0.2s ./maze data/invalid_maze/invalid_maze_inconsistent_rows_2.txt > out
    ((all_counter++))
    if grep -q "Error: each row and column does not have the same size" out;
    then
        echo -e "\e[32mPASS\e[0m"
        ((pass_counter++))
    else
        echo -e "\e[31mFAIL\e[0m"
    fi

    echo -n "Testing inconsistent row size (3) - "
    timeout 0.2s ./maze data/invalid_maze/invalid_maze_inconsistent_rows_3.txt > out
    ((all_counter++))
    if grep -q "Error: each row and column does not have the same size" out;
    then
        echo -e "\e[32mPASS\e[0m"
        ((pass_counter++))
    else
        echo -e "\e[31mFAIL\e[0m"
    fi

    echo -n "Testing inconsistent row size (4) - "
    timeout 0.2s ./maze data/invalid_maze/invalid_maze_inconsistent_rows_4.txt > out
    ((all_counter++))
    if grep -q "Error: each row and column does not have the same size" out;
    then
        echo -e "\e[32mPASS\e[0m"
        ((pass_counter++))
    else
        echo -e "\e[31mFAIL\e[0m"
    fi

    echo -n "Testing inconsistent row size (5) - "
    timeout 0.2s ./maze data/invalid_maze/invalid_maze_inconsistent_rows_5.txt > out
    ((all_counter++))
    if grep -q "Error: each row and column does not have the same size" out;
    then
        echo -e "\e[32mPASS\e[0m"
        ((pass_counter++))
    else
        echo -e "\e[31mFAIL\e[0m"
    fi


    echo -n "Testing inconsistent column size (1) - "
    timeout 0.2s ./maze data/invalid_maze/invalid_maze_inconsistent_columns_1.txt > out
    ((all_counter++))
    if grep -q "Error: each row and column does not have the same size" out;
    then
        echo -e "\e[32mPASS\e[0m"
        ((pass_counter++))
    else
        echo -e "\e[31mFAIL\e[0m"
    fi

    echo -n "Testing inconsistent column size (2) - "
    timeout 0.2s ./maze data/invalid_maze/invalid_maze_inconsistent_columns_2.txt > out
    ((all_counter++))
    if grep -q "Error: each row and column does not have the same size" out;
    then
        echo -e "\e[32mPASS\e[0m"
        ((pass_counter++))
    else
        echo -e "\e[31mFAIL\e[0m"
    fi

    echo -n "Testing inconsistent column size (3) - "
    timeout 0.2s ./maze data/invalid_maze/invalid_maze_inconsistent_columns_3.txt > out
    ((all_counter++))
    if grep -q "Error: each row and column does not have the same size" out;
    then
        echo -e "\e[32mPASS\e[0m"
        ((pass_counter++))
    else
        echo -e "\e[31mFAIL\e[0m"
    fi

    echo -n "Testing inconsistent column size (4) - "
    timeout 0.2s ./maze data/invalid_maze/invalid_maze_inconsistent_columns_4.txt > out
    ((all_counter++))
    if grep -q "Error: each row and column does not have the same size" out;
    then
        echo -e "\e[32mPASS\e[0m"
        ((pass_counter++))
    else
        echo -e "\e[31mFAIL\e[0m"
    fi

    echo -n "Testing inconsistent column size (5) - "
    timeout 0.2s ./maze data/invalid_maze/invalid_maze_inconsistent_columns_5.txt > out
    ((all_counter++))
    if grep -q "Error: each row and column does not have the same size" out;
    then
        echo -e "\e[32mPASS\e[0m"
        ((pass_counter++))
    else
        echo -e "\e[31mFAIL\e[0m"
    fi

echo -e "\n~~ Invalid Characters In The Maze Tests~~"

    echo -n "Testing invalid characters in maze - "
    ./maze data/invalid_maze/invalid_characters_maze.txt > out
    ((all_counter++))
    if grep -q "Error: the maze contains invalid characters" out;
    then
        echo -e "\e[32mPASS\e[0m"
        ((pass_counter++))
    else
        echo -e "\e[31mFAIL\e[0m"
    fi

echo -e "\n~~ Starting Point Tests~~"

    echo -n "Testing no starting point - "
    ./maze data/invalid_maze/invalid_no_starting_point_maze.txt > out
    ((all_counter++))
    if grep -q "Error: starting point missing" out;
    then
        echo -e "\e[32mPASS\e[0m"
        ((pass_counter++))
    else
        echo -e "\e[31mFAIL\e[0m"
    fi

    echo -n "Testing multiple starting point - "
    ./maze data/invalid_maze/invalid_multiple_starting_point.txt > out
    ((all_counter++))
    if grep -q "Error: multiple starting point found" out;
    then
        echo -e "\e[32mPASS\e[0m"
        ((pass_counter++))
    else
        echo -e "\e[31mFAIL\e[0m"
    fi

 # if only one starting point fount, then the program will
 # show no error message
    echo -n "Testing single starting point - "
    ./maze data/valid_maze/valid_single_starting_point.txt > out
    ((all_counter++))
    if grep -q "Error: starting point missing" out;
    then
        echo -e "\e[31mFAIL\e[0m"
    else
        if grep -q "Error: multiple starting point found" out;
        then
            echo -e "\e[31mFAIL\e[0m"
        else
            echo -e "\e[32mPASS\e[0m"
            ((pass_counter++))
        fi
    fi

echo -e "\n~~ Ending Point Tests~~"

    echo -n "Testing no ending point - "
    ./maze data/invalid_maze/invalid_no_ending_point_maze.txt > out
    ((all_counter++))
    if grep -q "Error: no ending point found" out;
    then
        echo -e "\e[32mPASS\e[0m"
        ((pass_counter++))
    else
        echo -e "\e[31mFAIL\e[0m"
    fi

    echo -n "Testing multiple ending point - "
    ./maze data/invalid_maze/invalid_multiple_ending_point_maze.txt > out
    ((all_counter++))
    if grep -q "Error: multiple ending point found" out;
    then
        echo -e "\e[32mPASS\e[0m"
        ((pass_counter++))
    else
        echo -e "\e[31mFAIL\e[0m"
    fi

 # if only one starting point fount, then the program will
 # show no error message
    echo -n "Testing single ending point - "
    ./maze data/valid_maze/valid_single_ending_point_maze.txt > out
    ((all_counter++))
    if grep -q "Error: no ending point found" out;
    then
        echo -e "\e[31mFAIL\e[0m"
    else
        if grep -q "Error: multiple ending point found" out;
        then
            echo -e "\e[31mFAIL\e[0m"
        else
            echo -e "\e[32mPASS\e[0m"
            ((pass_counter++))
        fi
    fi

echo -e "\n~~ Valid Maze Tests~~"

    echo -n "Testing valid maze (1) - "
    ./maze data/valid_maze/valid_maze_1.txt > out
    ((all_counter++))
    if grep -q "Success : maze loaded successfully" out;
    then
        echo -e "\e[32mPASS\e[0m"
        ((pass_counter++))
    else
        echo -e "\e[31mFAIL\e[0m"
    fi

    echo -n "Testing valid maze (2) - "
    ./maze data/valid_maze/valid_maze_2.txt > out
    ((all_counter++))
    if grep -q "Success : maze loaded successfully" out;
    then
        echo -e "\e[32mPASS\e[0m"
        ((pass_counter++))
    else
        echo -e "\e[31mFAIL\e[0m"
    fi

    echo -n "Testing valid maze (3) - "
    ./maze data/valid_maze/valid_maze_3.txt > out
    ((all_counter++))
    if grep -q "Success : maze loaded successfully" out;
    then
        echo -e "\e[32mPASS\e[0m"
        ((pass_counter++))
    else
        echo -e "\e[31mFAIL\e[0m"
    fi

echo -e "\n~~ Up Movement Tests~~"

    echo -n "Testing successful moving up (lower case) - "
    ./maze data/valid_maze/valid_maze_3.txt < data/moving_up_lower_case.txt > out
    ((all_counter++))
    if grep -q "Dialogue : you moved up" out;
    then
        echo -e "\e[32mPASS\e[0m"
        ((pass_counter++))
    else
        echo -e "\e[31mFAIL\e[0m"
    fi

    echo -n "Testing successful moving up (upper case) - "
    ./maze data/valid_maze/valid_maze_3.txt < data/moving_up_upper_case.txt > out
    ((all_counter++))
    if grep -q "Dialogue : you moved up" out;
    then
        echo -e "\e[32mPASS\e[0m"
        ((pass_counter++))
    else
        echo -e "\e[31mFAIL\e[0m"
    fi

 # if user can't move up, it means there is either a wall
 # or its the edge
    echo -n "Testing moving into wall upwards - "
    ./maze data/valid_maze/valid_maze_blocked_y.txt < data/moving_up_lower_case.txt > out
    ((all_counter++))
    if grep -q "Dialogue : can't move up. There is a wall" out;
    then
        echo -e "\e[32mPASS\e[0m"
        ((pass_counter++))
    else
        echo -e "\e[31mFAIL\e[0m"
    fi


 # There can be two edge cases
 # in this test there are no walls upwards
    echo -n "Testing moving of the edge (up - 1) - "
    ./maze data/valid_maze/valid_maze_start_at_top.txt < data/moving_up_lower_case.txt > out
    ((all_counter++))
    if grep -q "Dialogue : can't move up. That's the edge" out;
    then
        echo -e "\e[32mPASS\e[0m"
        ((pass_counter++))
    else
        echo -e "\e[31mFAIL\e[0m"
    fi

 # in this test, there are white spaces in top row
    echo -n "Testing moving of the edge (up - 2) - "
    ./maze data/valid_maze_white_space_up.txt < data/moving_up_lower_case.txt > out
    ((all_counter++))
    if grep -q "Dialogue : can't move up. That's the edge" out;
    then
        echo -e "\e[32mPASS\e[0m"
        ((pass_counter++))
    else
        echo -e "\e[31mFAIL\e[0m"
    fi

echo -e "\n~~ Down Movement Tests~~"

    echo -n "Testing successful moving down (lower case) - "
    ./maze data/valid_maze_3.txt < data/moving_down_lower_case.txt > out
    ((all_counter++))
    if grep -q "Dialogue : you moved down" out;
    then
        echo -e "\e[32mPASS\e[0m"
        ((pass_counter++))
    else
        echo -e "\e[31mFAIL\e[0m"
    fi

    echo -n "Testing successful moving down (upper case) - "
    ./maze data/valid_maze_3.txt < data/moving_down_upper_case.txt > out
    ((all_counter++))
    if grep -q "Dialogue : you moved down" out;
    then
        echo -e "\e[32mPASS\e[0m"
        ((pass_counter++))
    else
        echo -e "\e[31mFAIL\e[0m"
    fi

 # if user can't move down, it means there is either a wall
 # or its the edge
    echo -n "Testing moving into wall downwards - "
    ./maze data/valid_maze_blocked_y.txt < data/moving_down_lower_case.txt > out
    ((all_counter++))
    if grep -q "Dialogue : can't move down. There is a wall" out;
    then
        echo -e "\e[32mPASS\e[0m"
        ((pass_counter++))
    else
        echo -e "\e[31mFAIL\e[0m"
    fi


 # There can be two edge cases
 # in this test there are no walls downwards
    echo -n "Testing moving of the edge (down - 1) - "
    ./maze data/valid_maze_start_at_bottom.txt < data/moving_down_lower_case.txt > out
    ((all_counter++))
    if grep -q "Dialogue : can't move down. That's the edge" out;
    then
        echo -e "\e[32mPASS\e[0m"
        ((pass_counter++))
    else
        echo -e "\e[31mFAIL\e[0m"
    fi

 # in this test, there are white spaces in bottom row
    echo -n "Testing moving of the edge (down - 2) - "
    ./maze data/valid_maze_white_space_down.txt < data/moving_down_lower_case.txt > out
    ((all_counter++))
    if grep -q "Dialogue : can't move down. That's the edge" out;
    then
        echo -e "\e[32mPASS\e[0m"
        ((pass_counter++))
    else
        echo -e "\e[31mFAIL\e[0m"
    fi


echo -e "\n~~ Right Movement Tests~~"

    echo -n "Testing successful moving right (lower case) - "
    ./maze data/valid_maze_3.txt < data/moving_right_lower_case.txt > out
    ((all_counter++))
    if grep -q "Dialogue : you moved right" out;
    then
        echo -e "\e[32mPASS\e[0m"
        ((pass_counter++))
    else
        echo -e "\e[31mFAIL\e[0m"
    fi

    echo -n "Testing successful moving right (upper case) - "
    ./maze data/valid_maze_3.txt < data/moving_right_upper_case.txt > out
    ((all_counter++))
    if grep -q "Dialogue : you moved right" out;
    then
        echo -e "\e[32mPASS\e[0m"
        ((pass_counter++))
    else
        echo -e "\e[31mFAIL\e[0m"
    fi

 # if user can't move right, it means there is either a wall
 # or its the edge
    echo -n "Testing moving into wall right - "
    ./maze data/]valid_maze_blocked_x.txt < data/moving_right_lower_case.txt > out
    ((all_counter++))
    if grep -q "Dialogue : can't move right. There is a wall" out;
    then
        echo -e "\e[32mPASS\e[0m"
        ((pass_counter++))
    else
        echo -e "\e[31mFAIL\e[0m"
    fi


 # There can be two edge cases
 # in this test there are no walls right
    echo -n "Testing moving of the edge (right - 1) - "
    ./maze data/valid_maze_start_at_right.txt < data//moving_right_lower_case.txt > out
    ((all_counter++))
    if grep -q "Dialogue : can't move right. That's the edge" out;
    then
        echo -e "\e[32mPASS\e[0m"
        ((pass_counter++))
    else
        echo -e "\e[31mFAIL\e[0m"
    fi

 # in this test, there are white spaces in right column
    echo -n "Testing moving of the edge (right - 2) - "
    ./maze data/valid_maze_white_space_right.txt < data/moving_right_lower_case.txt > out
    ((all_counter++))
    if grep -q "Dialogue : can't move right. That's the edge" out;
    then
        echo -e "\e[32mPASS\e[0m"
        ((pass_counter++))
    else
        echo -e "\e[31mFAIL\e[0m"
    fi


echo -e "\n~~ Left Movement Tests~~"

    echo -n "Testing successful moving left (lower case) - "
    ./maze data/valid_maze_3.txt < data/moving_left_lower_case.txt > out
    ((all_counter++))
    if grep -q "Dialogue : you moved left" out;
    then
        echo -e "\e[32mPASS\e[0m"
        ((pass_counter++))
    else
        echo -e "\e[31mFAIL\e[0m"
    fi

    echo -n "Testing successful moving left (upper case) - "
    ./maze data/valid_maze_3.txt < data/moving_left_upper_case.txt > out
    ((all_counter++))
    if grep -q "Dialogue : you moved left" out;
    then
        echo -e "\e[32mPASS\e[0m"
        ((pass_counter++))
    else
        echo -e "\e[31mFAIL\e[0m"
    fi

 # if user can't move left, it means there is either a wall
 # or its the edge
    echo -n "Testing moving into wall left - "
    ./maze data/valid_maze_blocked_x.txt < data/moving_left_lower_case.txt > out
    ((all_counter++))
    if grep -q "Dialogue : can't move left. There is a wall" out;
    then
        echo -e "\e[32mPASS\e[0m"
        ((pass_counter++))
    else
        echo -e "\e[31mFAIL\e[0m"
    fi


 # There can be two edge cases
 # in this test there are no walls left
    echo -n "Testing moving of the edge (left - 1) - "
    ./maze data/valid_maze_start_at_left.txt < data/moving_left_lower_case.txt > out
    ((all_counter++))
    if grep -q "Dialogue : can't move left. That's the edge" out;
    then
        echo -e "\e[32mPASS\e[0m"
        ((pass_counter++))
    else
        echo -e "\e[31mFAIL\e[0m"
    fi

 # in this test, there are white spaces in left column
    echo -n "Testing moving of the edge (left - 2) - "
    ./maze data/valid_maze_white_space_left.txt < data/moving_right_lower_case.txt > out
    ((all_counter++))
    if grep -q "Dialogue : can't move left. That's the edge" out;
    then
        echo -e "\e[32mPASS\e[0m"
        ((pass_counter++))
    else
        echo -e "\e[31mFAIL\e[0m"
    fi


echo -e "\n~~ Bad user inputs ~~"

    echo -n "Testing bad movement (wrong key) - "
    echo "b" | timeout 0.2s ./maze data/valid_maze_3.txt > out
    ((all_counter++))
    if grep -q "Error: invalid key" out;
    then
        echo -e "\e[32mPASS\e[0m"
        ((pass_counter++))
    else
        echo -e "\e[31mFAIL\e[0m"
    fi

    echo -n "Testing bad movement (empty) - "
    echo | timeout 0.2s ./maze data/valid_maze_3.txt > out
    ((all_counter++))
    if grep -q "Error: invalid key" out;
    then
        echo -e "\e[32mPASS\e[0m"
        ((pass_counter++))
    else
        echo -e "\e[31mFAIL\e[0m"
    fi


echo -e "\n~~ Testing successful movement ~~"
    echo -n "Testing successful movement (1) - "
    ./maze data/valid_maze_3.txt < data/moving_around_1.txt > out
    ((all_counter++))
    if grep -q "Dialogue : you moved up" out;
    then
        if grep -q "Dialogue : you moved left" out;
            then
                if grep -q "Dialogue : you moved right" out;
                    then
                        if grep -q "Dialogue : you moved down" out;
                            then
                                echo -e "\e[32mPASS\e[0m"
                                ((pass_counter++))
                            else
                                echo -e "\e[31mFAIL\e[0m"
                            fi
                    else
                        echo -e "\e[31mFAIL\e[0m"
                    fi
            else
                echo -e "\e[31mFAIL\e[0m"
            fi
    else
        echo -e "\e[31mFAIL\e[0m"
    fi

    echo -n "Testing successful movement (2) - "
    ./maze data/valid_maze_2.txt < data/moving_around_2.txt > out
    ((all_counter++))
    if grep -q "Dialogue : you moved up" out;
    then
        if grep -q "Dialogue : you moved up" out;
            then
                if grep -q "Dialogue : you moved right" out;
                    then
                        echo -e "\e[32mPASS\e[0m"
                        ((pass_counter++))
                    else
                        echo -e "\e[31mFAIL\e[0m"
                    fi
            else
                echo -e "\e[31mFAIL\e[0m"
            fi
    else
        echo -e "\e[31mFAIL\e[0m"
    fi

# echo -e "\n~~ Opening Map ~~"

echo -e "\n~~ Testing Map Opening ~~"
    echo -n "Testing successful map open (1) - "
    ./maze data/valid_maze_1.txt < data/opening_map_lower_case.txt > out
    # -p enables Perl-compatible regular expressions, allowing multi line grep
    # the -z treats the input as a set of lines, each terminated by a null character.
    ((all_counter++))
    if grep -qPz '#E######\n#   ####\n#    ###\n### X###\n#### ###\n####S###' out
        then
            echo -e "\e[32mPASS\e[0m"
            ((pass_counter++))
        else
            echo -e "\e[31mFAIL\e[0m"
        fi

    echo -n "Testing successful map open (2) - "
    ./maze data/valid_maze_2.txt < data/opening_map_upper_case.txt > out
    # -p enables Perl-compatible regular expressions, allowing multi line grep
    # the -z treats the input as a set of lines, each terminated by a null character.
    ((all_counter++))
    if grep -qPz '########\n#   # ##\n### ## #\n# X ####\n# # ####\n#S#E####' out
        then
            echo -e "\e[32mPASS\e[0m"
            ((pass_counter++))
        else
            echo -e "\e[31mFAIL\e[0m"
        fi

    echo -n "Testing unsuccessful map open - "
    ./maze data/valid_maze_1.txt < data/opening_map_lower_case.txt > out
    # -p enables Perl-compatible regular expressions, allowing multi line grep
    # the -z treats the input as a set of lines, each terminated by a null character.
    ((all_counter++))
    if grep -q 'Error: something went wrong while opening the map!!' out
        then
            echo -e "\e[32mPASS\e[0m"
            ((pass_counter++))
        else
            echo -e "\e[31mFAIL\e[0m"
        fi

echo -e "~~ Testing end of game ~~"
    echo -n "Testing successful end of game (1)- "
    ./maze data/valid_maze_1.txt < data/moving_to_end_1.txt > out
    ((all_counter++))
    if grep -q 'You won!' out
    then
        echo -e "\e[32mPASS\e[0m"
        ((pass_counter++))
    else
        echo -e "\e[31mFAIL\e[0m"
    fi

    echo -n "Testing successful end of game (2)- "
    ./maze data/valid_maze_2.txt < data/moving_to_end_1.txt > out
    ((all_counter++))
    if grep -q 'You won!' out
    then
        echo -e "\e[32mPASS\e[0m"
        ((pass_counter++))
    else
        echo -e "\e[31mFAIL\e[0m"
    fi

echo -e "Total tests: $all_counter"
echo -e "Total passed tests: $pass_counter"

# rm -f out