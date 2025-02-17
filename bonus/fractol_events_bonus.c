/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_events_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:51:33 by aychikhi          #+#    #+#             */
/*   Updated: 2025/02/17 17:34:05 by aychikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	key_fun(int key, t_fractol *fractol)
{
	if (key == ESC_KEY)
	{
		mlx_destroy_image(fractol->mlx_connection, fractol->img.img_ptr);
		mlx_destroy_window(fractol->mlx_connection, fractol->mlx_win);
		exit(0);
	}
	else if (key == UP_KEY)
		fractol->shift_y -= (0.5 * fractol->zoom);
	else if (key == DOWN_KEY)
		fractol->shift_y += (0.5 * fractol->zoom);
	else if (key == LEFT_KEY)
		fractol->shift_x += (0.5 * fractol->zoom);
	else if (key == RIGHT_KEY)
		fractol->shift_x -= (0.5 * fractol->zoom);
	else if (key == PLUS_KEY)
		fractol->iterations += 10;
	else if (key == MINUS_KEY)
		fractol->iterations -= 10;
	fractol_render(fractol);
	return (0);
}

int	mouse_fun(int button, int x, int y, t_fractol *fractol)
{
	double			mouse_x;
	double			mouse_y;

	mouse_x = scale_value(x, -2, 2, WIDTH) * fractol->zoom + fractol->shift_x;
	mouse_y = scale_value(y, 2, -2, HEIGHT) * fractol->zoom + fractol->shift_y;
	if (button == MOUSE_BUTTON_DOWN)
		fractol->zoom *= 0.9;
	else if (button == MOUSE_BUTTON_UP)
		fractol->zoom *= 1.1;
	fractol->shift_x = mouse_x - scale_value(x, -2, 2, WIDTH) * fractol->zoom;
	fractol->shift_y = mouse_y - scale_value(y, 2, -2, HEIGHT) * fractol->zoom;
	fractol_render(fractol);
	return (0);
}

int	close_win(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx_connection, fractol->img.img_ptr);
	mlx_destroy_window(fractol->mlx_connection, fractol->mlx_win);
	exit(0);
	return (0);
}
