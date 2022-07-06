# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/25 22:15:48 by gcosta-d          #+#    #+#              #
#    Updated: 2022/07/06 02:31:12 by gcosta-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CFLAGS = -Wall -Wextra -Werror -g3 -pthread

CC = gcc

VPATH = source utils

FILES = main.c \
		check_arguments.c \
		create_philo.c \
		routines.c \
		ft_atoi.c \
		ft_exit.c \
		ft_init.c \
		ft_lstadd_back.c \
		ft_lstnew.c \
		is_str_numeric.c

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