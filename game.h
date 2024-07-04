#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <windows.h>

void draw_board(char[3][3]);
void check_win_or_tie(char[3][3], int*, int*, int*);
void reset_board(char[3][3]);
void players_input(char[3][3], int*, int*, int*, int, int);
void start_game();

#endif