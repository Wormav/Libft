/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 15:43:26 by jlorette          #+#    #+#             */
/*   Updated: 2025/02/25 00:42:00 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*result;
	size_t	len;

	len = ft_strlen(src) + 1;
	result = lp_alloc(sizeof(char) * len);
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, src, len);
	return (result);
}
