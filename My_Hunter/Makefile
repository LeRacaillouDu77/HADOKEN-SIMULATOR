##
## EPITECH PROJECT, 2023
## my_ls
## File description:
## re fclean all rules
## clean
##
SRC		= 	game.c			\
			int_to_str.c	\
			gameover.c		\
			str_functions.c \
			ken_ryu_menu.c  \
			lifebar.c 		\
			menu_elts.c 	\
			menu_rect.c     \
			music.c 		\
			score.c 		\
			menu_textures.c \
			game_functions.c\
			button.c\
			challenge.c\
			defi_completed.c\

OBJ		=	$(SRC:.c=.o)

NAME	=	my_hunter

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) menu.c -lcsfml-graphics \
	-lcsfml-window -lcsfml-system -lcsfml-audio $(OBJ)
	rm *.o

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
