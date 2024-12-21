/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiorcec <guilhemmdk@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:45:36 by gmiorcec          #+#    #+#             */
/*   Updated: 2024/04/15 18:39:39 by gmiorcec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void		*tdest;

	tdest = dst;
	if (!dst && !src)
		return (0);
	if (dst == src)
		return (dst);
	if (dst > src)
	{
		while (len--)
			((char *)dst)[len] = ((char *)src)[len];
	}
	else
	{
		while (len--)
			*(char *)dst++ = *(const char *)src++;
	}
	return (tdest);
}
/*
#include <stdio.h>

int main()
{
	char src[] = "abc";
	char dst[] = "xs";
	ft_memmove(dst, src, 2);
	printf("%s\n", dst);
}
*/