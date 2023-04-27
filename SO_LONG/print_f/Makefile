# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdi-russ <rdi-russ@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 14:21:22 by agenoves          #+#    #+#              #
#    Updated: 2022/01/26 11:59:43 by rdi-russ         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
AR = ar rcs

FILES = ft_printchar \
		ft_printf \
		ft_printhexalower \
		ft_printhexaupper \
		ft_printinteger \
		ft_printpercent \
		ft_printptr \
		ft_printstring \
		ft_printunsint \
		ft_putchar \
		ft_putnbr_hexalower \
		ft_putnbr_hexaupper \
		ft_putnbr \
		ft_putstr \
		ft_strlen \
		

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))	

.c.o: $(SOURCES)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(AR) $@ $^

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	
re: clean all

.PHONY: bonus all clean fclean re
