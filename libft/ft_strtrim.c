/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiorcec <guilhemmdk@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:02:54 by gmiorcec          #+#    #+#             */
/*   Updated: 2024/04/08 17:02:54 by gmiorcec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	char_check(char const *str, char const c)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (*(str + i))
	{
		if (*(str + i) == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (*(s1 + start) && char_check(set, *(s1 + start)))
		start++;
	end = ft_strlen(s1);
	while (end > start && char_check(set, *(s1 + (end - 1))))
		end--;
	trim = ft_substr(s1, start, end - start);
	return (trim);
}

/*
#include <stdio.h>

int main()
{
	char str[] = "jeee m appelle groot je";
	char set[] = "je";
	char *final = ft_strtrim(str, set);
	printf("%s\n", final);
}
*/