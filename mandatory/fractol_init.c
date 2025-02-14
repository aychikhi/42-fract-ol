/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:04:49 by aychikhi          #+#    #+#             */
/*   Updated: 2025/02/14 16:16:22 by aychikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	malloc_error(void)
{
	ft_putstr_fd("problem with malloc", 2);
	exit(EXIT_FAILURE);
}

void	data_init(t_fractol *fractol)
{
	fractol->iterations = 42;
	fractol->escape_point = 4;
}

void	fractol_init(t_fractol	*fractol)
{
	fractol->mlx_connection = mlx_init();
	if (!fractol->mlx_connection)
		malloc_error();
	fractol->mlx_win = mlx_new_window(fractol->mlx_connection, WIDTH, HEIGHT, fractol->name);
	if (!fractol->mlx_win)
	{
		mlx_destroy_window(fractol->mlx_connection, fractol->mlx_win);
		malloc_error();
	}
	fractol->img.img_ptr = mlx_new_image(fractol->mlx_connection, WIDTH, HEIGHT);
	if (!fractol->img.img_ptr)
	{
		mlx_destroy_window(fractol->mlx_connection, fractol->mlx_win);
		mlx_destroy_image(fractol->mlx_connection, fractol->img.img_ptr);
		malloc_error();
	}
	fractol->img.addr = mlx_get_data_addr(fractol->img.img_ptr, &fractol->img.bits_per_pixel, &fractol->img.line_length,
								&fractol->img.endian);
	// my_mlx_pixel_put1(fractol->img, 0, 0, RED);//hh
	// my_mlx_pixel_put2(fractol->img, 400, 0, BLUE);//hh
	// my_mlx_pixel_put3(fractol->img, 0, 400, WHITE);//hh
	// my_mlx_pixel_put4(fractol->img, 400, 400, CYAN);//hh
}
