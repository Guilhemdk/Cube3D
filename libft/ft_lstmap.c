/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiorcec <guilhemmdk@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:36:13 by gmiorcec          #+#    #+#             */
/*   Updated: 2024/04/22 15:36:13 by gmiorcec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*malle;
	void	*transfer;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		transfer = f(lst->content);
		malle = ft_lstnew(transfer);
		if (!malle)
		{
			del(transfer);
			ft_lstclear(&new_list, (*del));
			return (new_list);
		}
		ft_lstadd_back(&new_list, malle);
		lst = lst->next;
	}
	return (new_list);
}
