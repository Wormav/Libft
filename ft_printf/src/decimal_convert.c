/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_convert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 21:33:11 by jlorette          #+#    #+#             */
/*   Updated: 2024/12/02 23:42:37 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	putnbr_unsigned_fd(unsigned int n, int *count, int fd)
{
	if (n >= 10)
	{
		putnbr_unsigned_fd(n / 10, count, fd);
		putnbr_unsigned_fd(n % 10, count, fd);
	}
	else
	{
		ft_putchar_fd(n + '0', fd);
		*count += 1;
	}
}

void	putnbr_hex_fd(unsigned int n, int *count, char format, int fd)
{
	char	*hex_digits;

	if (format == 'x')
		hex_digits = "0123456789abcdef";
	else if (format == 'X')
		hex_digits = "0123456789ABCDEF";
	if (n >= 16)
	{
		putnbr_hex_fd(n / 16, count, format, fd);
		putnbr_hex_fd(n % 16, count, format, fd);
	}
	else
	{
		ft_putchar_fd(hex_digits[n], fd);
		*count += 1;
	}
}

void	ft_putnbr_count(int n, int *count, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		(*count) += 11;
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		(*count)++;
		n = -n;
	}
	if (n < 10)
	{
		ft_putchar_fd(n + '0', fd);
		(*count)++;
		return ;
	}
	ft_putnbr_count(n / 10, count, fd);
	ft_putnbr_count(n % 10, count, fd);
}
