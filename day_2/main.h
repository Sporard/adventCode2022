#ifndef HEADER_H_
#define HEADER_H_
const int MAX_LENGTH = 255;
const int ROCK_PTS = 1;
const int PAPER_PTS = 2;
const int SCISSORS_PTS = 3;
const int WIN = 6;
const int DRAW = 3;
const int LOSS = 0;
void solve(char* filename);
int win_part_1(char move_1, char move_2);
int win_part_2(char move_1, char move_2);
#endif
