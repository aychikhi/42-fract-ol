/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:35:08 by aychikhi          #+#    #+#             */
/*   Updated: 2025/02/14 16:36:39 by aychikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static double	convert(char *str, int i)
{
	double	res;
	double	pow;

	pow = 1;
	res = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		pow /= 10;
		res = res + (str[i] - 48) * pow;
		i++;
	}
	return (res);
}

static int	check_num(char *str, int i)
{
	while ((str[i] >= '0' && str[i] <= '9') || str[i] == '.')
		i++;
	if (!str[i + 1] || !str[i])
		return (1);
	return (0);
}

double	ft_atod(char *str)
{
	int		i;
	int		sign;
	long	con_int;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	sign = 1;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (check_num(str, i) == 0)
		return (0);
	con_int = 0;
	while (str[i] != '.' && str[i] >= '0' && str[i] <= '9')
	{
		con_int = con_int * 10 + (str[i] - 48);
		i++;
	}
	if (str[i] == '.')
		i++;
	return ((convert(str, i) + con_int) * sign);
}
