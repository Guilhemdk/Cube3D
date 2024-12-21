/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiorcec <guilhemmdk@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:09:06 by gmiorcec          #+#    #+#             */
/*   Updated: 2024/04/15 16:11:27 by gmiorcec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*
void printsyst(void *s)
{
	printf("%s\n", (char *)s);
}

int main()
{
	t_list *lst = ft_lstnew("je m'appelle")
	ft_lstadd_back(&lst, ft_lstnew("groot"));
	ft_lstiter(lst, printsyst);
}
*/