NAME		= ft_ping

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -O2
RM			= rm -f

SRCS		= ft_ping.c
OBJS		= $(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -lm

%.o:		%.c ft_ping.h
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

valgrind:	$(NAME)
			@echo "\033[32m=== Running Valgrind Memory Check ===\033[0m"
			@sudo valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
			--verbose --log-file=valgrind.log ./$(NAME) -c 4 localhost
			@echo "\033[33m=== Valgrind Summary ===\033[0m"
			@grep -E "definitely lost:|indirectly lost:|possibly lost:|still reachable:" valgrind.log || echo "\033[32mNo memory leaks detected!\033[0m"
			@grep "ERROR SUMMARY:" valgrind.log
			@echo "\033[33mFull log saved in valgrind.log\033[0m"

run:		$(NAME)
			@echo "\033[32m=== Testing ft_ping ===\033[0m"
			@echo "\033[33mNote: ft_ping requires root privileges (use sudo)\033[0m"
			@echo "\033[36mExample: sudo ./ft_ping google.com\033[0m"
			@echo "\033[36mExample: sudo ./ft_ping -v 8.8.8.8\033[0m"
			@echo "\033[36mExample: sudo ./ft_ping -c 4 localhost\033[0m"

help:
			@echo "\033[32m=== Available Makefile Rules ===\033[0m"
			@echo "make          - Build ft_ping"
			@echo "make clean    - Remove object files"
			@echo "make fclean   - Remove object files and executable"
			@echo "make re       - Rebuild everything"
			@echo "make valgrind - Check for memory leaks"
			@echo "make run      - Show usage examples"
			@echo "make help     - Show this help"

.PHONY:		all clean fclean re valgrind run help