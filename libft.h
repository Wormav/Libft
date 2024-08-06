/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:04:10 by jlorette          #+#    #+#             */
/*   Updated: 2024/08/06 13:21:41 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

void	ft_bzero(void *s, size_t n);
int		ft_isalpha(int c);
int		ft_isalnum(int i);
int		ft_isascii(int i);
int		ft_isdigit(char c);
int		ft_isprint(int i);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
size_t	ft_strlcat(char *dest, const char *src, unsigned int size);
size_t	ft_strlcpy(char *dest, const char *src, unsigned int size);
int		ft_strlen(const char *str);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
int		ft_tolower(int c);
int		ft_toupper(int c);

#endif
