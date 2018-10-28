# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jauplat <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/05 14:04:17 by jauplat           #+#    #+#              #
#    Updated: 2018/07/19 18:14:15 by jauplat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
FLAG = -Wall -Wextra -Werror
OPTION = -o
LIBFT = ./libft/libft.a

FILE = src/lem_in.c src/error.c src/lstnew.c src/parse.c src/room.c \
	   src/ants.c src/property.c src/tube.c src/end_room.c src/algo.c \
	   src/check_param.c src/moove.c src/ft_lentab.c src/init.c src/ft_strncmp.c

OBJ = $(FILE:src/%.c=src/%.o)

.PHONY: all clean fclean re

all: $(OBJ) $(NAME)

$(OBJ): src/%.o: src/%.c
	gcc $(FLAG) $(OPTION) $@ -c $<

$(NAME): $(OBJ)
	cd libft && make && cd ..
	gcc $(FLAG) $(OPTION) $(NAME) $(LIBFT) $(OBJ)

clean:
	cd libft && make clean && cd ..
	rm -rf $(OBJ)

fclean:
	make clean
	cd libft && make fclean && cd ..
	rm -rf $(NAME)

re:
	make fclean
	make all
