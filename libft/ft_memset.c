/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiorcec <guilhemmdk@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:45:42 by gmiorcec          #+#    #+#             */
/*   Updated: 2024/04/15 19:03:06 by gmiorcec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	void	*temp;

	temp = b;
	while (len--)
		*(unsigned char *) b++ = (unsigned char)c;
	return (temp);
}
/*
#include <stdio.h>
#define BUF_SIZE 20
int main()
{
	char buffer[BUF_SIZE + 1];
	char *string;
 
	ft_memset(buffer, 0, sizeof(buffer));
	string = (char *) ft_memset(buffer,'A', 10);
	printf("\nBuffer contents: %s\n", string);
	ft_memset(buffer+10, 'B', 10);
	printf("\nBuffer contents: %s\n", buffer);
}
*/