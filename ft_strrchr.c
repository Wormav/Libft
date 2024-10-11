/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:22:41 by jlorette          #+#    #+#             */
/*   Updated: 2024/10/08 13:22:42 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	target;
	size_t			i;

	target = (unsigned char)c;
	i = ft_strlen(s);
	while (i > 0)
	{
		if (s[i] == target)
			return ((char *)&s[i]);
		if (i == 0)
			break ;
		i--;
	}
	if (s[i] == target)
		return ((char *)&s[i]);
	return (NULL);
}
