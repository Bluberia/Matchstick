/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "proto.h"

int manage_error(int ac, char **av, int *nb_1, int *nb_2)
{
	if (ac != 3 || my_str_isnum(av[1]) == 1 || my_str_isnum(av[2]) == 1) {
		my_error("Error in the number of arguments.\n");
		return (1);
	}
	*nb_1 = my_getnbr(av[1]);
	*nb_2 = my_getnbr(av[2]);
	if (1 > *nb_1 || *nb_1 > 100) {
		my_error("Your first argument must be between 1 and 100.\n");
		return (1);
	}
	if (0 >= *nb_2) {
		my_error("Your second argument must be greater than 0.\n");
		return (1);
	}
	return (0);
}

void print_man(char *exec)
{
	my_printf("Usage: %s nb_of_lines nb_of_max_matches\n", exec);
}

int main(int ac, char **av)
{
	int *game;
	int nb_1 = 0;
	int nb_2 = 0;

	if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
		print_man(av[0]);
		return (0);
	}
	if (manage_error(ac, av, &nb_1, &nb_2) == 1)
		return (84);
	game = malloc(sizeof(int) * (nb_1 + 1));
	if (game == NULL)
		return (84);
	fill_game(&game, nb_1);
	return (matchstick(&game, nb_1, nb_2));
}
