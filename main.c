/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:28:48 by aychikhi          #+#    #+#             */
/*   Updated: 2025/02/14 16:15:39 by aychikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_mess(void)
{
	ft_putendl_fd("Please enter \n\t\"./fractol mandelbrot\" or \
	\n\t\"./fractol julia <value_1> <value_2>", 2);
	exit(1);
}

int main(int ac, char **av)
{
	t_fractol	fractol;

	if ((ac == 2 && !ft_strcmp(av[1], "mandelbrot")) || (ac == 4 && !ft_strcmp(av[1], "julia")))
	{
		fractol.name = av[1];
		fractol_init(&fractol);
		data_init(&fractol);
		fractol_render(&fractol);
		mlx_loop(fractol.mlx_connection);
	}
	else
		error_mess();
}