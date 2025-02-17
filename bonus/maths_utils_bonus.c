/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:42:28 by aychikhi          #+#    #+#             */
/*   Updated: 2025/02/17 17:34:16 by aychikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

double	scale_value(int pixel, double min, double max, int dimension)
{
	return (min + (max - min) * ((double)pixel / (double)dimension));
}

t_complexe	sum_complexe(t_complexe z, t_complexe c)
{
	t_complexe	res;

	res.x = z.x + c.x;
	res.y = z.y + c.y;
	return (res);
}

t_complexe	square_complex(t_complexe z)
{
	t_complexe	res;

	res.x = (z.x * z.x) - (z.y * z.y);
	res.y = z.x * 2 * z.y;
	return (res);
}
