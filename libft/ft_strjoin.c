/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiorcec <guilhemmdk@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:28:57 by gmiorcec          #+#    #+#             */
/*   Updated: 2024/04/08 16:28:57 by gmiorcec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buffer_ptr;
	char	*buffer;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	buffer = (char *) malloc ((i + j + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	buffer_ptr = buffer;
	while (*s1)
		*buffer++ = *s1++;
	while (*s2)
		*buffer++ = *s2++;
	*buffer = '\0';
	return (buffer_ptr);
}
