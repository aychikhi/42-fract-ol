/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aychikhi <aychikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:40:27 by aychikhi          #+#    #+#             */
/*   Updated: 2025/02/17 17:46:53 by aychikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus/fractol_bonus.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
