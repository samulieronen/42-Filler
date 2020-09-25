# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/27 13:33:57 by seronen           #+#    #+#              #
#    Updated: 2020/09/25 17:23:59 by seronen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = seronen.filler

SRCS =	srcs/algo.c srcs/defeat_enemy.c srcs/filler.c srcs/get.c \
		srcs/helpers.c srcs/piece.c

FLAGS = -Wall -Wextra -Werror

INCL = -I includes/ -I libft/includes/

LIB = -L libft -lftprintf

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): libftmake
	@gcc -o $(NAME) $(FLAGS) $(INCL) $(SRCS) $(LIB) 

libftmake:
	@make re -C libft

clean: 
	@make clean -C libft

re: fclean all
