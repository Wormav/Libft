/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:30:53 by jlorette          #+#    #+#             */
/*   Updated: 2024/08/13 14:43:51 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*i;
	t_list	*j;

	if (!lst || !del || !*lst)
		return ;
	i = *lst;
	while (i)
	{
		j = i->next;
		ft_lstdelone(i, del);
		i = j;
	}
	*lst = NULL;
}
