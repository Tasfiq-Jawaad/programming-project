#!/bin/bash

gcc ./maze.c -o maze

all_counter=0
pass_counter=0

echo -e "~~ Width Tests ~~"

 # In this case, we are not expecting any success message
 # a message would mean the test failed
echo -n "Testing invalid data/invalid_maze/empty_maze.txt - "
    timeout 0.2s ./maze data/invalid_maze/empty_maze.txt > out
    ((all_counter++))
    if grep -q "Width of the maze file: 0" out;
    then
            echo -e "\e[32mPASS\e[0m"
        else
            echo -e "\e[31mFAIL\e[0m"
            ((pass_counter++))
        fi

    #     rm -f out

echo -n "Testing invalid data/invalid_maze/invalid_characters_maze.txt - "
    timeout 0.2s ./maze data/invalid_maze/invalid_characters_maze.txt > out
    ((all_counter++))
    if grep -q "Width of the maze file: 8" out;
    then
            echo -e "\e[32mPASS\e[0m"
        else
            echo -e "\e[31mFAIL\e[0m"
            ((pass_counter++))
        fi

        # rm -f out

echo -n "Testing invalid data/invalid_maze/invalid_maze_inconsistent_columns_1.txt - "
    timeout 0.2s ./maze data/invalid_maze/invalid_maze_inconsistent_columns_1.txt > out
    ((all_counter++))
    if grep -q "Width of the maze file: 11" out;
    then
            echo -e "\e[32mPASS\e[0m"
        else
            echo -e "\e[31mFAIL\e[0m"
            ((pass_counter++))
        fi

        # rm -f out

    
echo -n "Testing invalid data/invalid_maze/invalid_maze_inconsistent_columns_2.txt - "
    timeout 0.2s ./maze data/invalid_maze/invalid_maze_inconsistent_columns_2.txt > out
    ((all_counter++))
    if grep -q "Width of the maze file: 11" out;
    then
            echo -e "\e[32mPASS\e[0m"
        else
            echo -e "\e[31mFAIL\e[0m"
            ((pass_counter++))
        fi

        # rm -f out

    
echo -n "Testing invalid data/invalid_maze/invalid_maze_inconsistent_columns_3.txt - "
    timeout 0.2s ./maze data/invalid_maze/invalid_maze_inconsistent_columns_3.txt > out
    ((all_counter++))
    if grep -q "Width of the maze file: 5" out;
    then
            echo -e "\e[32mPASS\e[0m"
        else
            echo -e "\e[31mFAIL\e[0m"
            ((pass_counter++))
        fi

        # rm -f out

    
echo -n "Testing invalid data/invalid_maze/invalid_maze_inconsistent_columns_4.txt - "
    timeout 0.2s ./maze data/invalid_maze/invalid_maze_inconsistent_columns_4.txt > out
    ((all_counter++))
    if grep -q "Width of the maze file: 5" out;
    then
            echo -e "\e[32mPASS\e[0m"
        else
            echo -e "\e[31mFAIL\e[0m"
            ((pass_counter++))
        fi

        # rm -f out

    
echo -n "Testing invalid data/invalid_maze/invalid_maze_inconsistent_columns_5.txt - "
    timeout 0.2s ./maze data/invalid_maze/invalid_maze_inconsistent_columns_5.txt > out
    ((all_counter++))
    if grep -q "Width of the maze file: 5" out;
    then
            echo -e "\e[32mPASS\e[0m"
        else
            echo -e "\e[31mFAIL\e[0m"
            ((pass_counter++))
        fi

        # rm -f out

    
echo -n "Testing invalid data/invalid_maze/invalid_maze_inconsistent_rows_1.txt - "
    timeout 0.2s ./maze data/invalid_maze/invalid_maze_inconsistent_rows_1.txt > out
    ((all_counter++))
    if grep -q "Width of the maze file: 8" out;
    then
            echo -e "\e[32mPASS\e[0m"
        else
            echo -e "\e[31mFAIL\e[0m"
            ((pass_counter++))
        fi

        # rm -f out

    
echo -n "Testing invalid data/invalid_maze/invalid_maze_inconsistent_rows_2.txt - "
    timeout 0.2s ./maze data/invalid_maze/invalid_maze_inconsistent_rows_2.txt > out
    ((all_counter++))
    if grep -q "Width of the maze file: 8" out;
    then
            echo -e "\e[32mPASS\e[0m"
        else
            echo -e "\e[31mFAIL\e[0m"
            ((pass_counter++))
        fi

        # rm -f out

    
echo -n "Testing invalid data/invalid_maze/invalid_maze_inconsistent_rows_3.txt - "
    timeout 0.2s ./maze data/invalid_maze/invalid_maze_inconsistent_rows_3.txt > out
    ((all_counter++))
    if grep -q "Width of the maze file: 10" out;
    then
            echo -e "\e[32mPASS\e[0m"
        else
            echo -e "\e[31mFAIL\e[0m"
            ((pass_counter++))
        fi

        # rm -f out

    
echo -n "Testing invalid data/invalid_maze/invalid_maze_inconsistent_rows_4.txt - "
    timeout 0.2s ./maze data/invalid_maze/invalid_maze_inconsistent_rows_4.txt > out
    ((all_counter++))
    if grep -q "Width of the maze file: 11" out;
    then
            echo -e "\e[32mPASS\e[0m"
        else
            echo -e "\e[31mFAIL\e[0m"
            ((pass_counter++))
        fi

        # rm -f out

    
echo -n "Testing invalid data/invalid_maze/invalid_maze_inconsistent_rows_5.txt - "
    timeout 0.2s ./maze data/invalid_maze/invalid_maze_inconsistent_rows_5.txt > out
    ((all_counter++))
    if grep -q "Width of the maze file: 13" out;
    then
            echo -e "\e[32mPASS\e[0m"
        else
            echo -e "\e[31mFAIL\e[0m"
            ((pass_counter++))
        fi

        # rm -f out

    
echo -n "Testing invalid data/invalid_maze/invalid_maze_too_large_cols.txt - "
    timeout 0.2s ./maze data/invalid_maze/invalid_maze_too_large_cols.txt > out
    ((all_counter++))
    if grep -q "Width of the maze file: 111" out;
    then
            echo -e "\e[32mPASS\e[0m"
        else
            echo -e "\e[31mFAIL\e[0m"
            ((pass_counter++))
        fi

        # rm -f out

    
echo -n "Testing invalid data/invalid_maze/invalid_maze_too_large_rows.txt - "
    timeout 0.2s ./maze data/invalid_maze/invalid_maze_too_large_rows.txt > out
    ((all_counter++))
    if grep -q "Width of the maze file: 10" out;
    then
            echo -e "\e[32mPASS\e[0m"
        else
            echo -e "\e[31mFAIL\e[0m"
            ((pass_counter++))
        fi

        # rm -f out

    
echo -n "Testing invalid data/invalid_maze/invalid_maze_too_small_cols.txt - "
    timeout 0.2s ./maze data/invalid_maze/invalid_maze_too_small_cols.txt > out
    ((all_counter++))
    if grep -q "Width of the maze file: 4" out;
    then
            echo -e "\e[32mPASS\e[0m"
        else
            echo -e "\e[31mFAIL\e[0m"
            ((pass_counter++))
        fi

        # rm -f out

    
echo -n "Testing invalid data/invalid_maze/invalid_maze_too_small_rows.txt - "
    timeout 0.2s ./maze data/invalid_maze/invalid_maze_too_small_rows.txt > out
    ((all_counter++))
    if grep -q "Width of the maze file: 6" out;
    then
            echo -e "\e[32mPASS\e[0m"
        else
            echo -e "\e[31mFAIL\e[0m"
            ((pass_counter++))
        fi

        # rm -f out

    
echo -n "Testing invalid data/invalid_maze/invalid_multiple_ending_point_maze.txt - "
    timeout 0.2s ./maze data/invalid_maze/invalid_multiple_ending_point_maze.txt > out
    ((all_counter++))
    if grep -q "Width of the maze file: 8" out;
    then
            echo -e "\e[32mPASS\e[0m"
        else
            echo -e "\e[31mFAIL\e[0m"
            ((pass_counter++))
        fi

        # rm -f out

    
echo -n "Testing invalid data/invalid_maze/invalid_multiple_starting_point.txt - "
    timeout 0.2s ./maze data/invalid_maze/invalid_multiple_starting_point.txt > out
    ((all_counter++))
    if grep -q "Width of the maze file: 14" out;
    then
            echo -e "\e[32mPASS\e[0m"
        else
            echo -e "\e[31mFAIL\e[0m"
            ((pass_counter++))
        fi

        # rm -f out

    
echo -n "Testing invalid data/invalid_maze/invalid_no_ending_point_maze.txt - "
    timeout 0.2s ./maze data/invalid_maze/invalid_no_ending_point_maze.txt > out
    ((all_counter++))
    if grep -q "Width of the maze file: 14" out;
    then
            echo -e "\e[32mPASS\e[0m"
        else
            echo -e "\e[31mFAIL\e[0m"
            ((pass_counter++))
        fi

        # rm -f out

    
echo -n "Testing invalid data/invalid_maze/invalid_no_starting_point_maze.txt - ".
    timeout 0.2s ./maze data/invalid_maze/invalid_no_starting_point_maze.txt > out
    ((all_counter++))
    if grep -q "Width of the maze file: 8" out;
    then
            echo -e "\e[32mPASS\e[0m"
        else
            echo -e "\e[31mFAIL\e[0m"
            ((pass_counter++))
        fi

        # rm -f out

    

echo -n "Testing valid data/valid_maze/valid_maze_1.txt - ".
    timeout 0.2s ./maze data/valid_maze/valid_maze_1.txt > out
    ((all_counter++))
        if grep -q "Width of the maze file: 8" out;
        then
                echo -e "\e[32mPASS\e[0m"
            else
                echo -e "\e[31mFAIL\e[0m"
                ((pass_counter++))
            fi

            # rm -f out

echo -n "Testing valid data/valid_maze/valid_maze_2.txt - ".
    timeout 0.2s ./maze data/valid_maze/valid_maze_2.txt > out
    ((all_counter++))
        if grep -q "Width of the maze file: 8" out;
        then
                echo -e "\e[32mPASS\e[0m"
            else
                echo -e "\e[31mFAIL\e[0m"
                ((pass_counter++))
            fi

            # rm -f out

echo -n "Testing valid data/valid_maze/valid_maze_3.txt - ".
    timeout 0.2s ./maze data/valid_maze/valid_maze_3.txt > out
    ((all_counter++))
        if grep -q "Width of the maze file: 25" out;
        then
                echo -e "\e[32mPASS\e[0m"
            else
                echo -e "\e[31mFAIL\e[0m"
                ((pass_counter++))
            fi

            # rm -f out

echo -n "Testing valid data/valid_maze/valid_maze_blocked_x.txt - ".
    timeout 0.2s ./maze data/valid_maze/valid_maze_blocked_x.txt > out
    ((all_counter++))
        if grep -q "Width of the maze file: 25" out;
        then
                echo -e "\e[32mPASS\e[0m"
            else
                echo -e "\e[31mFAIL\e[0m"
                ((pass_counter++))
            fi

            # rm -f out

echo -n "Testing valid data/valid_maze/valid_maze_blocked_y.txt - ".
    timeout 0.2s ./maze data/valid_maze/valid_maze_blocked_y.txt > out
    ((all_counter++))
        if grep -q "Width of the maze file: 25" out;
        then
                echo -e "\e[32mPASS\e[0m"
            else
                echo -e "\e[31mFAIL\e[0m"
                ((pass_counter++))
            fi

            # rm -f out

echo -n "Testing valid data/valid_maze/valid_maze_start_at_bottom.txt - ".
    timeout 0.2s ./maze data/valid_maze/valid_maze_start_at_bottom.txt > out
    ((all_counter++))
        if grep -q "Width of the maze file: 25" out;
        then
                echo -e "\e[32mPASS\e[0m"
            else
                echo -e "\e[31mFAIL\e[0m"
                ((pass_counter++))
            fi

            # rm -f out

echo -n "Testing valid data/valid_maze/valid_maze_start_at_left.txt - ".
    timeout 0.2s ./maze data/valid_maze/valid_maze_start_at_left.txt > out
    ((all_counter++))
        if grep -q "Width of the maze file: 25" out;
        then
                echo -e "\e[32mPASS\e[0m"
            else
                echo -e "\e[31mFAIL\e[0m"
                ((pass_counter++))
            fi

            # rm -f out

echo -n "Testing valid data/valid_maze/valid_maze_start_at_right.txt - ".
    timeout 0.2s ./maze data/valid_maze/valid_maze_start_at_right.txt > out
    ((all_counter++))
        if grep -q "Width of the maze file: 25" out;
        then
                echo -e "\e[32mPASS\e[0m"
            else
                echo -e "\e[31mFAIL\e[0m"
                ((pass_counter++))
            fi

            # rm -f out

echo -n "Testing valid data/valid_maze/valid_maze_start_at_top.txt - ".
    timeout 0.2s ./maze data/valid_maze/valid_maze_start_at_top.txt > out
    ((all_counter++))
        if grep -q "Width of the maze file: 25" out;
        then
                echo -e "\e[32mPASS\e[0m"
            else
                echo -e "\e[31mFAIL\e[0m"
                ((pass_counter++))
            fi

            # rm -f out

echo -n "Testing valid data/valid_maze/valid_maze_white_space_down.txt - ".
    timeout 0.2s ./maze data/valid_maze/valid_maze_white_space_down.txt > out
    ((all_counter++))
        if grep -q "Width of the maze file: 16" out;
        then
                echo -e "\e[32mPASS\e[0m"
            else
                echo -e "\e[31mFAIL\e[0m"
                ((pass_counter++))
            fi

            # rm -f out

echo -n "Testing valid data/valid_maze/valid_maze_white_space_left.txt - ".
    timeout 0.2s ./maze data/valid_maze/valid_maze_white_space_left.txt > out
    ((all_counter++))
        if grep -q "Width of the maze file: 17" out;
        then
                echo -e "\e[32mPASS\e[0m"
            else
                echo -e "\e[31mFAIL\e[0m"
                ((pass_counter++))
            fi

            # rm -f out

echo -n "Testing valid data/valid_maze/valid_maze_white_space_right.txt - ".
    timeout 0.2s ./maze data/valid_maze/valid_maze_white_space_right.txt > out
    ((all_counter++))
        if grep -q "Width of the maze file: 17" out;
        then
                echo -e "\e[32mPASS\e[0m"
            else
                echo -e "\e[31mFAIL\e[0m"
                ((pass_counter++))
            fi

            # rm -f out

echo -n "Testing valid data/valid_maze/valid_maze_white_space_up.txt - ".
    timeout 0.2s ./maze data/valid_maze/valid_maze_white_space_up.txt > out
    ((all_counter++))
        if grep -q "Width of the maze file: 16" out;
        then
                echo -e "\e[32mPASS\e[0m"
            else
                echo -e "\e[31mFAIL\e[0m"
                ((pass_counter++))
            fi

            # rm -f out

echo -n "Testing valid data/valid_maze/valid_single_ending_point_maze.txt - ".
    timeout 0.2s ./maze data/valid_maze/valid_single_ending_point_maze.txt > out
    ((all_counter++))
        if grep -q "Width of the maze file: 14" out;
        then
                echo -e "\e[32mPASS\e[0m"
            else
                echo -e "\e[31mFAIL\e[0m"
                ((pass_counter++))
            fi

            # rm -f out

echo -n "Testing valid data/valid_maze/valid_single_starting_point.txt - ".
    timeout 0.2s ./maze data/valid_maze/valid_single_starting_point.txt > out
    ((all_counter++))
        if grep -q "Width of the maze file: 8" out;
        then
                echo -e "\e[32mPASS\e[0m"
            else
                echo -e "\e[31mFAIL\e[0m"
                ((pass_counter++))
            fi

            # rm -f out
