/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiorcec <guilhemmdk@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:39:54 by gmiorcec          #+#    #+#             */
/*   Updated: 2024/04/08 15:39:54 by gmiorcec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len(long long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	if (n == 0)
		len = 1;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void	isneg(long long n, int i, char *str)
{
	str[0] = '-';
	str[i] = '\0';
	i--;
	n *= -1;
	while (i > 0)
	{
		str[i] = '0' + (n % 10);
		n /= 10;
		i--;
	}
}

char	*ft_itoa(int n)
{
	int		i;
	char	*str;

	i = ft_len(n);
	str = (char *)malloc((i + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (n < 0)
		isneg(n, i, str);
	else
	{
		str[i] = '\0';
		i--;
		while (i >= 0)
		{
			str[i] = '0' + (n % 10);
			n /= 10;
			i--;
		}
	}
	return (str);
}

/*
#include <stdio.h>
int main()
{
	int x = 123;
	printf("%s\n", ft_itoa(x));
}
*/