/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiorcec <guilhemmdk@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:30:56 by gmiorcec          #+#    #+#             */
/*   Updated: 2024/04/15 16:15:24 by gmiorcec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;
	size_t	final_size;

	if ((!dst || !src) && !dstsize)
		return (0);
	final_size = ft_strlen(dst) + ft_strlen(src);
	dst_len = ft_strlen(dst);
	i = 0;
	if (dstsize <= dst_len)
		return (ft_strlen(src) + dstsize);
	while (i < dstsize - dst_len - 1)
	{
		if (src[i] == '\0')
			break ;
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (final_size);
}
