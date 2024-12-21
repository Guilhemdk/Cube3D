/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiorcec <guilhemmdk@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:54:51 by gmiorcec          #+#    #+#             */
/*   Updated: 2024/09/13 13:23:46 by gmiorcec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *tmp)
{
	if (!tmp || !lst)
		return ;
	if (!(*lst))
	{
		*lst = tmp;
		return ;
	}
	ft_lstlast(*lst)->next = tmp;
}
