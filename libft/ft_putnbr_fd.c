/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: gmiorcec <guilhemmdk@gmail.com>            +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/04/08 17:06:46 by gmiorcec          #+#    #+#             */
/*   Updated: 2024/04/08 17:06:46 by gmiorcec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	a;

	if (fd < 0)
		return ;
	a = n;
	if (a < 0)
	{
		ft_putchar_fd('-', fd);
		a = -a;
	}
	if (a >= 10)
	{
		ft_putnbr_fd(a / 10, fd);
		a %= 10;
		ft_putchar_fd(a + '0', fd);
	}
	else
	{
		ft_putchar_fd(a + '0', fd);
	}
}
