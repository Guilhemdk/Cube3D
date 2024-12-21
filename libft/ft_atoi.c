/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiorcec <guilhemmdk@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:26:26 by gmiorcec          #+#    #+#             */
/*   Updated: 2024/04/08 17:26:26 by gmiorcec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_sign(const char *str, int i)
{
	int	count;

	count = 1;
	if (str[i] == '-')
		count = -1;
	if (str[i] == '+')
		count = 1;
	return (count);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				count;
	long long int	check;
	long long int	num;

	num = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	count = check_sign(str, i);
	if (count != 0 && (str[i] == '-' || str[i] == '+'))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		check = num;
		num = num * 10 + (str[i] - 48);
		if (num < check && count == -1)
			return (0);
		if (num < check && count == 1)
			return (-1);
		i++;
	}
	return (num * count);
}
/*
#include <stdio.h>

int main()
{
	const char x[] = " 922332513781523517831578802";
	
	printf("%d\n", ft_atoi(x));
	printf("%d", atoi(x));
}
*/