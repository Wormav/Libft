/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 12:39:44 by jlorette          #+#    #+#             */
/*   Updated: 2024/12/02 23:46:36 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static void	string_gestion(char format, va_list *args, int *count, int fd)
{
	char	*s;

	if (format == 'c')
	{
		ft_putchar_fd(va_arg(*args, int), fd);
		(*count)++;
	}
	else
	{
		s = va_arg(*args, char *);
		if (!s)
			s = "(null)";
		ft_putstr_fd(s, fd);
		(*count) += ft_strlen(s);
	}
}

static void	decimal_gestion(char format, va_list *args, int *count, int fd)
{
	void	*ptr;

	if (format == 'p')
	{
		ptr = va_arg(*args, void *);
		if (!ptr)
		{
			ft_putstr_fd("(nil)", fd);
			*count += 5;
		}
		else
			*count += putptr(ptr, fd);
	}
	else if (format == 'd' || format == 'i')
		ft_putnbr_count(va_arg(*args, int), count, fd);
	else if (format == 'u')
		putnbr_unsigned_fd(va_arg(*args, unsigned int), count, fd);
	else if (format == 'x')
		putnbr_hex_fd(va_arg(*args, unsigned int), count, 'x', fd);
	else if (format == 'X')
		putnbr_hex_fd(va_arg(*args, unsigned int), count, 'X', fd);
}

static void	process(char format, va_list *args, int *count, int fd)
{
	if (format == '%')
		print_pourcent(count, fd);
	else if (format == 'c' || format == 's')
		string_gestion(format, args, count, fd);
	else if (format == 'd' || format == 'i' || format == 'u' || format == 'x'
		|| format == 'p' || format == 'X')
		decimal_gestion(format, args, count, fd);
}

int	ft_printf(int fd, const char *str, ...)
{
	va_list	args;
	int		count;

	if (!str)
		return (-1);
	va_start(args, str);
	count = 0;
	while (*str)
	{
		if (*str == '%' && *(str + 1) != '\0')
		{
			str++;
			process(*str, &args, &count, fd);
		}
		else
		{
			ft_putchar_fd(*str, fd);
			count++;
		}
		str++;
	}
	va_end(args);
	return (count);
}
