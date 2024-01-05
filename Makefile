##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile for my_radar
##

NAME = my_radar

CFLAGS = -g -lcsfml-window -lcsfml-system -lcsfml-graphics -lcsfml-audio -lm

SRC = src/my_radar.c	\
	  src/free_file.c	\
	  src/init1.c		\
	  src/init2.c		\
	  src/calcul.c		\
	  src/draw.c		\
	  src/collisions.c	\
	  src/pointertab.c	\
	  src/main.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): do_lib $(OBJ)
	gcc $(OBJ) -o $(NAME) -L./lib/my/ -lmy $(CFLAGS)

do_lib:
	make -C lib/my

clean :
	$(MAKE) -C lib/my -f Makefile clean
	rm -f $(OBJ)

fclean : clean
	$(MAKE) -C lib/my -f Makefile fclean
	rm -f $(NAME)

re : fclean all
