/*
** EPITECH PROJECT, 2018
** make_human_and_ai_play_a_round
** File description:
** make_human_and_ai_play_a_round
*/

#include "proto.h"

int check_end(int *game)
{
	int i = 0;

	while (game[i] != -1) {
		if (game[i] != 0)
			return (0);
		i++;
	}
	return (1);
}

void ia_turn(int matches, int lines, int **game, int nb_lines)
{
	my_printf("\nAI's turn...\nAI removed %i match(es) from line %i\n", \
matches, lines);
	print_updated_board_game(game, lines, matches, nb_lines);
}

void have_great_lines(int *game, int *lines, int nb_lines)
{
	while (game[*lines - 1] == 0)
		*lines = random() % nb_lines + 1;
}

void have_great_matches(int *game, int lines, int *matches, int nb_max_matches)
{
	while (game[lines - 1] < *matches || game[lines - 1] == 0)
		*matches = random() % nb_max_matches + 1;
}

int make_human_and_ai_play_a_round(int **game, int nb_lines, \
int nb_max_matches)
{
	int lines = random() % nb_lines + 1;
	int matches = random() % nb_max_matches + 1;
	int check = 0;

	my_printf("\nYour turn:\n");
	check = read_player_move(game, nb_lines, nb_max_matches);
	while (check != 0) {
		if (check == 84)
			return (84);
		if (check == 1)
			check = read_player_move(game, nb_lines, \
nb_max_matches);
	}
	if (check_end(*game) == 1)
		return (2);
	have_great_lines(*game, &lines, nb_lines);
	have_great_matches(*game, lines, &matches, nb_max_matches);
	ia_turn(matches, lines, game, nb_lines);
	if (check_end(*game) == 1)
		return (1);
	return (0);
}
