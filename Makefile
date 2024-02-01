# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maax <maax@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/31 11:41:45 by maax              #+#    #+#              #
#    Updated: 2024/01/31 11:41:53 by maax             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -I./include -Imlx_linux -O3

SRC = src/main.c src/handle_pixel.c src/check_map.c src/print_map.c\

OBJ = $(SRC:.c=.o)

NAME = so_long

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C mlx_linux
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L./mlx_linux/ -L./libft/ -lmlx -lXext -lX11 -lm -lft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C mlx_linux clean
	$(MAKE) -C libft clean
	rm -rf $(OBJ) 

fclean: clean
	$(MAKE) -C libft fclean
	rm -rf $(NAME)

re: fclean all