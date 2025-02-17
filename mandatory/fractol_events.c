/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:51:33 by aychikhi          #+#    #+#             */
/*   Updated: 2025/02/17 16:13:09 by aychikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	key_fun(int key, t_fractol *fractol)
{
	if (key == ESC_KEY)
	{
		mlx_destroy_image(fractol->mlx_connection, fractol->img.img_ptr);
		mlx_destroy_window(fractol->mlx_connection, fractol->mlx_win);
		exit(0);
	}
	return (0);
}

int	mouse_fun(int key, int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;
	if (key == MOUSE_BUTTON_UP)
		fractol->zoom *= 0.9;
	else if (key == MOUSE_BUTTON_DOWN)
		fractol->zoom *= 1.1;
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
