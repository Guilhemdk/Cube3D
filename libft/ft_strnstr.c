/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiorcec <guilhemmdk@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:40:25 by gmiorcec          #+#    #+#             */
/*   Updated: 2024/04/08 16:40:25 by gmiorcec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *haystack, char const *needle, size_t len)
{
	size_t	j;

	if (!haystack && !len)
		return (NULL);
	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len--)
	{
		j = 0;
		while (*(haystack + j) == *(needle + j)
			&& *(needle + j) && j <= len)
		{
			if (!*(needle + j + 1))
				return ((char *)haystack);
			j++;
		}
		haystack++;
	}
	return (NULL);
}
