/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks_protector.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 00:36:43 by jlorette          #+#    #+#             */
/*   Updated: 2025/03/25 17:45:16 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	**alloc_collector(void)
{
	static t_list	*lst;

	return (&lst);
}

__attribute__((destructor))
static void	free_alloc_collector(void)
{
	t_list	**lst;
	t_list	*tmp;

	lst = alloc_collector();
	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
}

void	lp_free(void *address)
{
	t_list	**lst;
	t_list	*current;
	t_list	*prev;

	if (!address)
		return ;
	lst = alloc_collector();
	current = *lst;
	prev = NULL;
	while (current->content != address)
	{
		prev = current;
		current = current->next;
	}
	if (!current)
		return ;
	if (prev == NULL)
		*lst = current->next;
	else
		prev->next = current->next;
	free(current->content);
	free(current);
}

static void	lp_push(void *malloc_address)
{
	t_list	**lst;
	t_list	*new_node;

	if (!malloc_address)
		return ;
	lst = alloc_collector();
	new_node = ft_lstnew(malloc_address);
	if (!new_node)
		return ;
	ft_lstadd_front(lst, new_node);
}

void	*lp_alloc(size_t size)
{
	void	*ptr;

	ptr = ft_calloc(1, size);
	if (!ptr)
		return (NULL);
	lp_push(ptr);
	return (ptr);
}
