##
## EPITECH PROJECT, 2023
## My_MAKEFILE
## File description:
## makefile.
##

NAME	=	my_hunter

SRCS 	=	my_window.c	\
		button.c	\
		manage_mouse_click.c	\
		my_putchar.c	\
		my_putstr.c	\
		my_put_nbr.c	\
		init.c	\
		moving.c	\
		my_strlen.c	\
		my_strcmp.c	\
		draw_game.c	\
		int_tochar.c	\
		fs_get_number_from_first_line.c	\
		my_getnbr.c	\
		my_strcat.c	\
		spawning.c	\
		score.c	\
		sprite.c	\


OBJS	=	$(SRCS:.c=.o)

CFLAGS 	=	-Wall -Wextra

CSFMLFLAGS	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all:	$(NAME)

$(NAME):	$(OBJS)
	gcc -o $(NAME) $(OBJS) $(CSFMLFLAGS) -g3

clean:
	rm -f $(OBJS)
	rm -f *~

fclean: 	clean
	rm -f $(NAME)

re:	fclean all
