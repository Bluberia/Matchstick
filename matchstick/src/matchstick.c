/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** matchstick
*/

#include "proto.h"

void manage_result(int result)
{
	if (result == 1)
		my_putstr("I lost... snif... but I'll get you next time!!\n");
	if (result == 2)
		my_putstr("You lost, too bad...\n");
}

int matchstick(int **game, int nb_lines, int nb_max_matches)
{
	int result = 0;

	srandom(time(0));
	print_game_board(*game, nb_lines);
	result = make_human_and_ai_play_a_round(game, nb_lines, nb_max_matches);
	while (result == 0)
		result = make_human_and_ai_play_a_round(game, nb_lines, \
nb_max_matches);
	if (result == 84)
		return (0);
	manage_result(result);
	free(*game);
	return (result);
}
