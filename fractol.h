/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:23:28 by aychikhi          #+#    #+#             */
/*   Updated: 2025/02/16 18:35:51 by aychikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 800
# define HEIGHT 800

# define ESC_KEY 53
# define UP_KEY 126
# define DOWN_KEY 125
# define LEFT_KEY 123
# define RIGHT_KEY 124
# define PLUS_KEY 69
# define MINUS_KEY 78
# define MOUSE_BUTTON_UP 5
# define MOUSE_BUTTON_DOWN 4

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define YELLOW 0xFFFF00
# define PURPLE 0xFF00FF
# define CYAN 0x00FFFF
# define GRAY 0x808080
# define ORANGE 0xFFA500
# define HOT_PINK 0xFF69B4
# define ELECTRIC_BLUE 0x00FF9F
# define ACID_GREEN 0x7FFF00
# define NEON_PURPLE 0x9400D3
# define ELECTRIC_LIME 0xCCFF00
# define PSYCHEDELIC_PURPLE 0xD300C9
# define PLASMA_BLUE 0x00FFEF
# define LASER_RED 0xFF003C
# define UV_PURPLE 0x9B30FF
# define TOXIC_GREEN 0x39FF14
# define RADIOACTIVE_YELLOW 0xFFFF33
# define COSMIC_PURPLE 0x6B3FA0
# define NEON_ORANGE 0xFF6600
# define ALIEN_GREEN 0x00FF8F
# define SYNTHWAVE_PINK 0xFF10F0
# define CYBER_CYAN 0x00FFFF
# define PLASMA_MAGENTA 0xFF00CC
# define VAPORWAVE_PURPLE 0xB19CD9
# define DIGITAL_LIME 0xBFFF00
# define QUANTUM_TURQUOISE 0x40E0D0

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <mlx.h>

typedef struct s_data
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_fractol
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_win;
	t_data	img;
	int		iterations;
	int		escape_point;
	double	julia_x;
	double	julia_y;
	double	shift_x;
	double	shift_y;
	double	zoom;
}				t_fractol;

typedef struct s_complexe
{
	double	x;
	double	y;
}				t_complexe;

void		error_mess(void);
void		error_mess2(void);
int			ft_isspace(int c);
int			ft_isdigit(int c);
double		ft_atod(char *str);
t_complexe	square_complex(t_complexe z);
void		data_init(t_fractol *fractol);
void		ft_putstr_fd(char *s, int fd);
int			close_win(t_fractol *fractol);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		events_init(t_fractol *fractol);
void		fractol_init(t_fractol	*fractol);
void		fractol_render(t_fractol *fractol);
int			key_fun(int key, t_fractol *fractol);
t_complexe	sum_complexe(t_complexe z, t_complexe c);
int			ft_strcmp(const char *s1, const char *s2);
void		handel_pixel(int x, int y, t_fractol *fractol);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			mouse_fun(int button, int x, int y, t_fractol *fractol);
double		scale_value(int pixel, double min, double max, int dimension);
void		mandelbrot_or_julia(t_complexe *z, t_complexe *c, 
				t_fractol *fractol);

#endif