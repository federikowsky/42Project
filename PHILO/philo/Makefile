# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fefilipp <fefilipp@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/14 20:22:14 by anolivei          #+#    #+#              #
#    Updated: 2022/09/20 03:51:24 by fefilipp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRC_DIR = philo_buono
OBJ_DIR = .objs

SRC =	handling_forks.c \
		actions.c \
		handling_philos.c \
		handling_threads.c \
		handling_time.c \
		main.c \
		philo_utils.c \
		routine.c

OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))

CC = clang
HEAD = -I./includes
CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address -O3
LFLAGS = -pthread
RM = /bin/rm -rf

all: $(NAME)

$(NAME): $(OBJ)
		@$(CC) $(OBJ) $(HEAD) $(CFLAGS) $(LFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		@mkdir -p $(OBJ_DIR)
		@$(CC) $(CFLAGS) $(HEAD) -c $< -o $@

clean:
		@$(RM) $(OBJ_DIR)

fclean: clean
		@$(RM) $(NAME)

re: fclean all

.PONY: all clean fclean re
