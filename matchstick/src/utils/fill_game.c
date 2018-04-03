/*
** EPITECH PROJECT, 2018
** fill game
** File description:
** fill game
*/

void fill_game(int **game, int nb_1)
{
	int stick = 1;
	int i = 0;

	while (i < nb_1) {
		(*game)[i] = stick;
		stick += 2;
		i++;
	}
	(*game)[i] = -1;
}
