/*
** EPITECH PROJECT, 2018
** read_player_move_and_print_updated_board_game
** File description:
** read_player_move_and_print_updated_board_game
*/

#include "proto.h"

int check_entry(char *entry, int *check)
{
	if (my_str_isnum(entry) == 1) {
		my_putstr("Error: invalid input (positive number expected)\n");
		*check = 1;
		return (1);
	}
	return (0);
}

int manage_lines(char *entry, int *check, int nb_lines)
{
	int lines = 0;

	if (entry != NULL) {
		lines = my_getnbr(entry);
		if (check_entry(entry, check) == 1)
			return (lines);
		else if (lines > nb_lines || lines <= 0) {
			my_putstr("Error: this line is out of range\n");
			*check = 1;
		}
	}
	return (lines);
}

void manage_matches_two(int matches, int *check, int nb_matches, int lines)
{
	if (matches > (2 * lines - 1))
		*check = 1;
	else if (matches > nb_matches) {
		my_printf("Error: you cannot remove more than %i \
mathes per turn\n", nb_matches);
		*check = 1;
	}
}

int manage_matches(char *entry, int *check, int lines, int nb_matches)
{
	int matches = 0;

	if (entry != NULL) {
		matches = my_getnbr(entry);
		if (check_entry(entry, check) == 1)
			return (matches);
		else if (matches < 1) {
			my_putstr("Error: you have to remove at least \
on match\n");
			*check = 1;
		} else
			manage_matches_two(matches, check, nb_matches, lines);
	}
	return (matches);
}
