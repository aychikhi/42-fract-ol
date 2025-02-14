/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:22:43 by aychikhi          #+#    #+#             */
/*   Updated: 2025/02/14 17:27:08 by aychikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	int	offset;

	offset = y * data->line_length + x * (data->bits_per_pixel / 8);
	*(unsigned int*)(offset + data->addr) = color;
}

void	mandelbrot_or_julia(t_complexe *z, t_complexe *c, t_fractol *fractol)
{
	if (!ft_strcmp(fractol->name, "mandelbrot"))
	{
		c->x = z->x;
		c->y = z->y;
	}
	else
	{
		c->x = fractol->julia_x;
		c->y = fractol->julia_y;
	}
}

void	handel_pixel(int x, int y, t_fractol *fractol)
{
	t_complexe	z;
	t_complexe	c;
	int			i;
	int			color;
	
	i = 0;
	z.x = scale_value(x, -2, 2, WIDTH) * fractol->zoom;
	z.y = scale_value(y, 2, -2, HEIGHT) * fractol->zoom;
	mandelbrot_or_julia(&z, &c, fractol);
	while (i < fractol->iterations)
	{
		z = sum_complexe(square_complex(z), c);
		if (z.x * z.x + z.y * z.y > fractol->escape_point)
		{
			color = scale_value(i, BLACK, WHITE, fractol->iterations);
			my_mlx_pixel_put(&fractol->img, x, y, color);
			return;	
		}
		i++;
	}
	my_mlx_pixel_put(&fractol->img, x, y, BLACK);
}

void	fractol_render(t_fractol *fractol)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			handel_pixel(x, y, fractol);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fractol->mlx_connection, fractol->mlx_win, fractol->img.img_ptr, 0, 0);
}