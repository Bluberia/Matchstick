/*
** EPITECH PROJECT, 2018
** read player move
** File description:
** read player move
*/

#include "proto.h"

void check_matches(int *game, int lines, int matches, int *check)
{
	if (game[lines - 1] < matches) {
		my_putstr("Error: not enough matches on this line\n");
		*check = 1;
	}
}

int fill_line(char **entry, int *lines, int *check, int nb_lines)
{
	my_putstr("Line: ");
	*entry = get_next_line(0);
	if (*entry != NULL)
		*lines = manage_lines(*entry, check, nb_lines);
	else
		return (84);
	if (*check == 1)
		return (1);
	free(*entry);
	return (0);
}

void finish_game(int matches, int lines, int **game, int nb_lines)
{
	my_printf("Player removed %i match(es) from line %i\n", \
matches, lines);
	print_updated_board_game(game, lines, matches, nb_lines);
}

int read_player_move(int **game, int nb_lines, int nb_matches)
{
	char *entry = malloc(sizeof(char));
	int check = 0;
	int lines = 0;
	int matches = 0;

	if (entry == NULL || fill_line(&entry, &lines, &check, nb_lines) == 84)
		return (84);
	if (check == 1)
		return (1);
	my_putstr("Matches: ");
	entry = get_next_line(0);
	if (entry != NULL) {
		matches = manage_matches(entry, &check, lines, nb_matches);
		check_matches(*game, lines, matches, &check);
	} else
		return (84);
	if (check == 1)
		return (1);
	finish_game(matches, lines, game, nb_lines);
	return (0);
}
