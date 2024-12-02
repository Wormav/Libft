/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_convert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 21:33:11 by jlorette          #+#    #+#             */
/*   Updated: 2024/12/02 23:43:27 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	putnbr_hex(unsigned long n, int fd)
{
	char	*hex_digits;
	int		result;

	hex_digits = "0123456789abcdef";
	result = 0;
	if (n >= 16)
		result += putnbr_hex(n / 16, fd);
	result += write(fd, &hex_digits[n % 16], 1);
	return (result);
}

int	putptr(void *ptr, int fd)
{
	int	result;

	result = write(fd, "0x", 2);
	result += putnbr_hex((unsigned long)ptr, fd);
	return (result);
}

void	print_pourcent(int *count, int fd)
{
	ft_putchar_fd('%', fd);
	(*count)++;
}
