/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiorcec <guilhemmdk@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:45:30 by gmiorcec          #+#    #+#             */
/*   Updated: 2024/04/15 19:11:25 by gmiorcec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*tdest;

	tdest = dst;
	if (!tdest && !src)
		return (NULL);
	while (n--)
		*(char *)dst++ = *(char *)src++;
	return (tdest);
}

/*
#include <stdio.h>
#include <string.h>
int main()
{
	char src[] = "Code42";
	char dest[] = "abc";
	char src2[] = "Code42";
	char dest2[] = "abc";

	ft_memcpy(dest, src, 1);
	printf("%s\n", dest);
	memcpy(dest2, src2, 1);
	printf("%s\n", dest2);
}
*/