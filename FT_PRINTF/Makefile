# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fefilipp <fefilipp@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/28 14:54:38 by fefilipp          #+#    #+#              #
#    Updated: 2022/01/30 19:34:50 by fefilipp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c \
		ft_printf_utils.c \
		ft_putnbr_base.c \
		ft_putnbr_address.c \

OBJS = ${SRCS:.c=.o}
RM = rm -f
FLAGS = -Wall -Wextra -Werror
INCS = .
LIBC = ar -rcs

.c.o :
	${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I${INCS}
	
$(NAME) : ${OBJS}
	${LIBC} ${NAME} ${OBJS}
	
all: $(NAME)

fclean:  clean
	$(RM) $(NAME)
	
clean:
	$(RM) -f $(OBJS)
	
re: fclean all

.PHONY: all clean fclean re .c.o