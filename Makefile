CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

SRCS = main.c ./utils/ft_putchar_fd.c ./utils/ft_putstr_fd.c ./utils/ft_putendl_fd.c ./utils/ft_strcmp.c ./mandatory/fractol_init.c\
		./mandatory/fractol_render.c ./mandatory/maths_utils.c
OBJCS = $(SRCS:.c=.o)

all: fractol

fractol: $(OBJCS) fractol.h
	$(CC) $(CFLAGS) $(OBJCS) -lmlx -framework OpenGL -framework AppKit -o fractol

clean:
	rm -rf $(OBJCS)

fclean: clean
	rm -rf fractol

re: fclean all

.PHONY: clean