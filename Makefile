# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebresser <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/13 12:56:04 by ebresser          #+#    #+#              #
#    Updated: 2020/07/13 12:15:58 by ebresser         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libftprintf.a
SRC = ft_fieldstorage.c\
	  ft_fillflags.c\
	  ft_fillprecision.c\
	  ft_fillspecifier.c\
	  ft_fillwidth.c\
	  ft_getnumber.c\
	  ft_printchar.c\
	  ft_printf.c\
	  ft_printpercent.c\
	  ft_printhex.c\
	  ft_printint.c\
	  ft_min.c\
	  ft_len_u.c\
	  ft_len_int.c\
	  ft_printpointer.c\
	  ft_printspacezero.c\
	  ft_printstr.c\
	  ft_putchar.c\
	  ft_putnbr.c\
	  ft_putnbr_hex.c\
	  ft_putnbr_u.c\
	  ft_putstr.c\
	  ft_specifier_redirect.c\
	  ft_strformat_init.c
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror
CC = gcc $(FLAGS) -c
all : $(NAME)
$(NAME): $(OBJ)
	ar rc libftprintf.a $(OBJ)
clean:
	@/bin/rm -f $(OBJ)
fclean: clean
	@/bin/rm -f $(NAME)
re: fclean all
#test: $(NAME)
#	gcc main.c -L. -lftprintf
#	./a.out
