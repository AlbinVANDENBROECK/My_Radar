##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile for my_printf
##

SRC	=	my_compute_power_rec.c	\
		my_compute_square_root.c\
		my_find_prime_sup.c	\
		my_is_prime.c		\
		my_putchar.c		\
		my_put_nbr.c		\
		my_putstr.c		\
		my_revstr.c		\
		my_strcat.c		\
		my_strcmp.c		\
		my_strcpy.c		\
		my_strlen.c		\
		my_strncat.c		\
		my_strncmp.c		\
		my_strncpy.c		\
		my_strstr.c		\
		my_str_to_word_array.c	\
		my_swap.c		\
		wrapper_1.c		\
		wrapper_2.c		\
		wrapper_3.c		\
		wrapper_4.c		\
		wrapper_5.c		\
		hexa.c			\
		hexa_cap.c		\
		my_printf.c		\
		my_printf2.c	\
		my_put_float.c	\
		my_put_unbr.c	\
		oct.c		\
		point.c		\
		my_e.c		\
		my_cape.c	\
		my_ld.c		\
		my_lu.c		\
		my_lx.c		\
		my_lo.c		\
		my_hd.c		\
		my_lcapx.c	\
		my_hu.c		\
		my_hx.c		\
		my_ho.c		\
		my_hcapx.c	\
		my_n.c		\
		wrapper_6.c	\
		my_hhd.c	\
		my_hhu.c	\
		my_hhx.c	\
		my_hho.c	\
		my_hhcapx.c	\
		hexa_len.c	\
		oct_len.c	\
		point_len.c	\
		my_len_int.c\
		my_printf3.c\
		my_printf4.c\
		wrapper_bis_1.c	\
		wrapper_bis_2.c	\
		wrapper_7.c		\
		my_printf5.c	\
		my_strdup.c		\
		my_get_number_only_number.c \
		file_buff_size.c	\
		push_to_list.c		\
		my_inttostr.c

OBJ	=	$(SRC:.c=.o)

NAME 	=	libmy.a

CFLAGS	=	-g

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -c $(SRC)
	ar rc $(NAME) $(OBJ)
	cp libmy.a ../../libmy.a


clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ../../$(NAME)

re:	fclean all
