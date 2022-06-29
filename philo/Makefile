# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/25 22:15:48 by gcosta-d          #+#    #+#              #
#    Updated: 2022/06/29 02:23:13 by lkrebs-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CFLAGS = -Wall -Wextra -Werror -pthread -g3

CC = gcc

VPATH = source utils

FILES = main.c \
		check_arguments.c \
		ft_atoi.c \
		ft_init.c \
		is_str_numeric.c \
		create_philo.c \
		ft_exit.c

OBJ_PATH = ./objs/

OBJS = $(FILES:%.c=$(OBJ_PATH)%.o)

$(OBJ_PATH)%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ_PATH) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_PATH):
	mkdir -p objs

clean:
	rm -f $(OBJS)

fclean: clean
	rm -rf $(OBJ_PATH)
	rm -rf $(NAME)

re: fclean all