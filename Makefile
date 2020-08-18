# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/27 13:33:57 by seronen           #+#    #+#              #
#    Updated: 2020/08/18 15:09:22 by seronen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = seronen.filler

SRCS =	srcs/algo.c srcs/defeat_enemy.c srcs/filler.c srcs/get.c \
		srcs/helpers.c srcs/piece.c

FLAGS = -Wall -Wextra -Werror

INCL = -I incl/ -I libft/incl/

LIB = -L libft -lftprintf

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): libftmake
	@gcc -o $(NAME) $(FLAGS) $(INCL) $(SRCS) $(LIB) 

libftmake:
	@make -C libft

clean: 
	@make clean -C libft

re: fclean all
