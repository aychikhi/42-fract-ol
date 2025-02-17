/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:28:52 by aychikhi          #+#    #+#             */
/*   Updated: 2025/02/17 13:37:54 by aychikhi         ###   ########.fr       */
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

void	pars1(char *ptr)
{
	is_empty(ptr);
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
