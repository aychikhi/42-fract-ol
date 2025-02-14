/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:35:08 by aychikhi          #+#    #+#             */
/*   Updated: 2025/02/14 20:26:47 by aychikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	points(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (str[i])
	{
		if (str[i] == '.')
			flag++;
		if (flag > 1)
			error_mess2();
		i++;
	}
}

static void	is_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isspace(str[i]))
			return ;
		i++;
	}
	error_mess2();
}

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

static void	check_num(char *ptr)
{
	points(ptr);
	while (*ptr)
	{
		while (ft_isspace(*ptr))
			ptr++;
		if ((*ptr == '+' || *ptr == '-') && *(ptr + 1) && ft_isdigit(*(ptr
					+ 1)))
			ptr++;
		if (ft_isdigit(*ptr))
		{
			while (ft_isdigit(*ptr) || *ptr == '.')
				ptr++;
			if (*ptr == '+' || *ptr == '-')
				error_mess2();
		}
		else
			error_mess2();
		while (ft_isspace(*ptr))
			ptr++;
	}
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
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	is_empty(str);
	check_num(str);
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
