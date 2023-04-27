NAME = so_long

SRC = main.c \
ft_itoa.c \
image.c \
map_check.c \
move.c \
print.c \
get_next_line/get_next_line.c \
get_next_line/get_next_line_utils.c \
accrocchio.c \
azioni.c \
enemy_move.c \
print_f/ft_printchar.c \
print_f/ft_printf.c \
print_f/ft_printhexalower.c \
print_f/ft_printhexaupper.c \
print_f/ft_printinteger.c \
print_f/ft_printpercent.c \
print_f/ft_printptr.c \
print_f/ft_printstring.c \
print_f/ft_printunsint.c \
print_f/ft_putchar.c \
print_f/ft_putnbr_hexalower.c \
print_f/ft_putnbr_hexaupper.c \
print_f/ft_putnbr.c \
print_f/ft_putstr.c 



HDRS = so_long.h

OBJ = $(SRC:.c=.o)

RM = rm -f

%.o: %.c
	gcc -Wall -Wextra -Werror -Imlx -I ${HDRS} -c $< -o $@

$(NAME): $(OBJ)
	make -C ./minilibx/
	gcc $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all: $(NAME)

ex: $(NAME)
	./$(NAME) map.ber
	# make clean
	make -C ./minilibx/ clean

clean:
	${RM} $(OBJ)
	make -C ./minilibx/ clean

fclean: clean
	${RM} $(NAME) ${OBJ}
	make -C ./minilibx/ clean

re: $(NAME)

.PHONY: all clean fclean re
