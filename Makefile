CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c ./utils/ft_putchar_fd.c ./utils/ft_putstr_fd.c ./utils/ft_putendl_fd.c ./utils/ft_strcmp.c ./utils/ft_isdigit.c ./utils/ft_isspace.c ./utils/ft_atod.c\
		./mandatory/fractol_init.c ./mandatory/fractol_render.c ./mandatory/maths_utils.c ./mandatory/fractol_events.c ./utils/pars1.c ./utils/pars2.c\

SRCSB = ./bonus/main_bonus.c ./utils_bonus/ft_putchar_fd_bonus.c ./utils_bonus/ft_putstr_fd_bonus.c ./utils_bonus/ft_putendl_fd_bonus.c ./utils_bonus/ft_strcmp_bonus.c \
	./utils_bonus/ft_isdigit_bonus.c ./utils_bonus/ft_isspace_bonus.c ./utils_bonus/ft_atod_bonus.c ./bonus/fractol_init_bonus.c ./bonus/fractol_render_bonus.c \
	./bonus/maths_utils_bonus.c ./bonus/fractol_events_bonus.c ./utils_bonus/pars1_bonus.c ./utils_bonus/pars2_bonus.c\

OBJCS = $(SRCS:.c=.o)

OBJCSB = $(SRCSB:.c=.o)

all: fractol

fractol: $(OBJCS) fractol.h
	$(CC) $(CFLAGS) $(OBJCS) -lmlx -framework OpenGL -framework AppKit -o fractol

bonus: $(OBJCSB) ./bonus/fractol_bonus.h
	$(CC) $(CFLAGS) $(OBJCSB) -lmlx -framework OpenGL -framework AppKit -o fractol

clean:
	rm -rf $(OBJCS) $(OBJCSB)

fclean: clean
	rm -rf fractol

re: fclean all

.PHONY: clean