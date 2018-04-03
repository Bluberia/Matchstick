/*
** EPITECH PROJECT, 2017
** proto
** File description:
** all proto of program
*/

#ifndef __PROTO_H_
#define __PROTO_H_

#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "my.h"
#include "get_next_line.h"

int my_error(char *);
void print_game_board(int *, int);
int matchstick(int **, int, int);
void fill_game(int **, int);
void print_updated_board_game(int **, int, int, int);
int read_player_move(int **, int, int);
int manage_lines(char *, int *, int);
int manage_matches(char *, int *, int, int);
int make_human_and_ai_play_a_round(int **, int, int);

#endif
