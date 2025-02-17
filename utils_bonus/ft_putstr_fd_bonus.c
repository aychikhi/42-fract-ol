/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:41:12 by aychikhi          #+#    #+#             */
/*   Updated: 2025/02/17 17:46:59 by aychikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus/fractol_bonus.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	while (*s)
		ft_putchar_fd(*s++, fd);
}
