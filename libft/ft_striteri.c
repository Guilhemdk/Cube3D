/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiorcec <guilhemmdk@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:17:54 by gmiorcec          #+#    #+#             */
/*   Updated: 2024/04/08 16:17:54 by gmiorcec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	if (s && f)
	{
		i = 0;
		while (*s)
			f(i++, s++);
	}
}
/*

void uppercase(unsigned int i, char *c)
{
	*c = ft_toupper(*c);
}
int main()
{
	char str[] = "Hello";
	ft_striteri(str, uppercase);
	printf("%s", str);
}
*/
