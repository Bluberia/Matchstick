/*
** EPITECH PROJECT, 2018
** print_updated_board_game
** File description:
** print_updated game_board
*/

#include "proto.h"

void print_updated_board_game(int **game, int lines, int matches, int nb_lines)
{
	if (lines > nb_lines || matches > (*game)[lines - 1])
		my_error("Error in your arguments.\n");
	else {
		(*game)[lines - 1] -= matches;
		print_game_board(*game, nb_lines);
	}
}
