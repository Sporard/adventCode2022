#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"



void solve(char* filename)
{
    printf("Reading for part 1\n");
    FILE* fptr = fopen(filename, "r");
    char buffer[MAX_LENGTH];
    int sum = 0;
    int sum_2 = 0;
    while(fgets(buffer, MAX_LENGTH, fptr)){
        buffer[strcspn(buffer, "\n")] = 0;
        char opponent_move = buffer[0];
        char my_move = buffer[2];
        int res = win_part_1(opponent_move, my_move);
        int res_2 = win_part_2(opponent_move, my_move);
        sum += res;
        sum_2 += res_2;
    }
    printf("sum : %d\n", sum);
    printf("sum 2 : %d\n", sum_2);
    fclose(fptr);

}
/*
 * move_1 = opponent_move
 * move_2 = my_move
 * 
*/
int win_part_1(char move_1, char move_2){
    if(strcmp(&move_2, "X") > 2 ){
        if (strcmp(&move_1, "C") > 2){
            return ROCK_PTS + WIN;
        }
        else if (strcmp(&move_1, "B") > 2){
            return ROCK_PTS + LOSS;
        }
        else {
            return ROCK_PTS + DRAW;
        }
    }
    if(strcmp(&move_2, "Y") > 2){
        if (strcmp(&move_1, "A") > 2){
            return PAPER_PTS + WIN;
        }
        else if (strcmp(&move_1, "C") > 2){
            return PAPER_PTS + LOSS;
        }
        else {
            return PAPER_PTS + DRAW;
        }
    }
     if (strcmp(&move_2, "Z") > 2){
        if (strcmp(&move_1, "B") > 2){
            return SCISSORS_PTS + WIN;
        }
        else if (strcmp(&move_1, "A") > 2){
            return SCISSORS_PTS + LOSS;
        }
        else {
            return SCISSORS_PTS + DRAW;
        }
    }
    return LOSS;
}

int win_part_2(char move_1, char move_2){

    if(move_2 == 88){
        if (move_1 == 65){
            return SCISSORS_PTS + LOSS;
        }
        else if (move_1 == 66){
            return ROCK_PTS + LOSS;
        }
        else if (move_1 == 67){
            return PAPER_PTS + LOSS;
        }
    }
    if(move_2 == 89){
        if (move_1 == 65){
            return ROCK_PTS + DRAW;
        }
        else if (move_1 == 66){
            return PAPER_PTS + DRAW;
        }
        else if (move_1 == 67){
            return SCISSORS_PTS + DRAW;
        }
    }
     if (move_2 == 90){
        if (move_1 == 65){
            return PAPER_PTS + WIN;
        }
        else if (move_1 == 66){
            return SCISSORS_PTS + WIN;
        }
        else if (move_1 == 67){
            return ROCK_PTS + WIN;
        }
    }
    return LOSS;
}
int main()
{

    printf("Begining of day 2 advent of code\n");
    solve("input.txt");
    printf("End of day 2 advent of code");

    return 0;
}



