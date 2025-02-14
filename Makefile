CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c ./utils/ft_putchar_fd.c ./utils/ft_putstr_fd.c ./utils/ft_putendl_fd.c ./utils/ft_strcmp.c\

OBJCS = $(SRCS:.c=.o)

all: fractol

fractol: $(OBJCS) fractol.h
	$(CC) $(CFLAGS) $(OBJCS) -o fractol -L./minilibx -lmlx -framework OpenGL -framework AppKit

clean:
	rm -rf $(OBJCS)

fclean: clean
	rm -rf fractol

re: fclean all

.PHONY: clean