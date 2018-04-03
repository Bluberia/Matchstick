/*
** EPITECH PROJECT, 2018
** print game board
** File description:
** print game board
*/

#include "proto.h"

void print_first_last_lines(int nb_lines)
{
	int i = 0;
	int goal = nb_lines * 2 + 1;

	while (i < goal) {
		my_putchar('*');
		i++;
	}
	my_putchar('\n');
}

void print_board(int nb_lines, int lines_display, int *game, int y)
{
	int alr_disp = 1;

	for (int i = 0; i < (nb_lines - lines_display); i++) {
		my_putchar(' ');
		alr_disp++;
	}
	for (int i = 0; i < game[y]; i++) {
		my_putchar('|');
		alr_disp++;
	}
	for (int i = 0; i < (nb_lines - lines_display); i++) {
		my_putchar(' ');
		alr_disp++;
	}
	for (; alr_disp < (nb_lines * 2); alr_disp++)
		my_putchar(' ');
}

void print_game_board(int *game, int nb_lines)
{
	int lines_display = 1;
	int y = 0;

	print_first_last_lines(nb_lines);
	while (y < nb_lines) {
		my_putchar('*');
		print_board(nb_lines, lines_display, game, y);
		my_putchar('*');
		my_putchar('\n');
		y++;
		lines_display++;
	}
	print_first_last_lines(nb_lines);
}
