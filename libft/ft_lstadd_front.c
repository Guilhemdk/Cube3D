/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiorcec <guilhemmdk@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:08:00 by gmiorcec          #+#    #+#             */
/*   Updated: 2024/09/13 13:23:12 by gmiorcec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *tmp)
{
	if (!lst || !tmp)
		return ;
	tmp->next = *lst;
	*lst = tmp;
}

/*
int main()
t_list *lst = NULL;
t_list *new_str = "groot";
ft_lstadd_front(&lst, new_str);
*/
