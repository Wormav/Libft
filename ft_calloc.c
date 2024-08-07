/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:58:41 by jlorette          #+#    #+#             */
/*   Updated: 2024/08/07 16:08:29 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc( size_t elementCount, size_t elementSize )
{
	void	*result;

	if (elementSize && elementCount * elementSize / elementSize != elementCount)
		return (NULL);
	result = malloc(elementCount * elementSize);
	if (!result)
		return (NULL);
	ft_bzero(result, elementCount * elementSize);
	return (result);
}
