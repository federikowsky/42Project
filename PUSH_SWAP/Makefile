# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fefilipp <fefilipp@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/19 23:53:15 by fefilipp          #+#    #+#              #
#    Updated: 2022/02/20 03:05:48 by fefilipp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBA = push_swap.a

LIBFT = libft

SRCS = ft_exchange_lists.c \
		ft_list_utils.c \
		ft_printer.c \
		ft_rotate_list.c \
		ft_rotate_list2.c \
		ft_sort_list.c \
		ft_sort_utils.c \
		array_utils.c \
		prova.c \
		main.c \

OBJS	= $(SRCS:.c=.o)
RM		= rm -f
LIBC	= ar -rcs
FLAGS	= -Wall -Wextra -Werror
CC		= gcc
INCS	= .

all: $(NAME)

$(NAME): $(OBJS)
	make all -C ./libft
	$(CC) $(FLAGS) $(SRCS) $(LIBFT)/libft.a
	$(LIBC) $(LIBA) $(OBJS) $(LIBFT)/*.o

%.o: %.c
	${CC} $(FLAGS) -c $^ -o $@ 
    
fclean: clean
	$(RM) $(NAME) $(LIBA)
	make clean -C $(LIBFT)

clean:
	$(RM) $(OBJS)
	
re: fclean all

.PHONY: all clean fclean re .c.o