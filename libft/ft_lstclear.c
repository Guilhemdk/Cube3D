/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiorcec <guilhemmdk@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:08:20 by gmiorcec          #+#    #+#             */
/*   Updated: 2024/04/15 17:34:32 by gmiorcec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (!lst || !del || !(*lst))
		return ;
	ft_lstclear(&(*lst)->next, del);
	(del)((*lst)->content);
	free(*lst);
	*lst = NULL;
}

/*
void del_content(void *content)
{
	free(content);
}

int main()
{
	t_list *lst = ft_lstnew("Je m'appelle");
	ft_lstadd_back(&lst, ft_lstnew("groot"));
	ft_lstclear(&lst, del_content);
}
*/