/*
** EPITECH PROJECT, 2018
** utils
** File description:
** utils functions
*/

#include "proto.h"

int my_error(char *str)
{
	write(1, str, my_strlen(str));
	return (84);
}
