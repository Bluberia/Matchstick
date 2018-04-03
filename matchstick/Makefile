##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Compile our projects
##

NAME	=	matchstick

SRC_DIR	=	./src/

UTILS_DIR	=	./src/utils/

SRC	=	$(SRC_DIR)main.c				\
		$(SRC_DIR)matchstick.c				\
		$(UTILS_DIR)utils_function.c			\
		$(UTILS_DIR)fill_game.c				\
		$(UTILS_DIR)print_game_board.c			\
		$(UTILS_DIR)print_updated_game_board.c		\
		$(UTILS_DIR)read_player_move.c			\
		$(UTILS_DIR)manage_read.c			\
		$(UTILS_DIR)make_human_and_ai_play_a_round.c

CFLAGS	=	-W -Wall -Wextra -I ./lib/include -I ./lib/include/print

OBJ	=	$(SRC:%.c=%.o)

LIB	=	-L ./lib/my -lmy

CC	=	gcc

all:		$(NAME)

$(NAME):	$(OBJ)
		$(MAKE) -C ./lib/my/
		$(CC) -o $(NAME) $(OBJ) $(LIB)
		@echo "COMPILATION COMPLETED"

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)
		$(MAKE) clean -C ./lib/my
		@echo "CLEAR COMPLETED"

re:		fclean all

debug:		CFLAGS += -g
debug:		re
