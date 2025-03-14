/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlorette <jlorette@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:04:10 by jlorette          #+#    #+#             */
/*   Updated: 2025/02/25 00:44:47 by jlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_list_gnl
{
	char				*content;
	struct s_list_gnl	*next;
}					t_list_gnl;

// libft legacy
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t element_count, size_t element_size);
int					ft_isalnum(int i);
int					ft_isalpha(int c);
int					ft_isascii(int i);
int					ft_isdigit(int c);
int					ft_isprint(int i);
char				*ft_itoa(int n);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
t_list				*ft_lstnew(void *content);
int					ft_lstsize(t_list *lst);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				**ft_split(char const *s, char c);
char				*ft_strchr(const char *s, int c);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_strdup(const char *src);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dest, const char *src, unsigned int size);
size_t				ft_strlcpy(char *dest, const char *src, unsigned int size);
int					ft_strlen(const char *str);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strncmp(const char *s1, const char *s2, unsigned int n);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_tolower(int c);
int					ft_toupper(int c);

// ft_printf
int					ft_printf(int fd, const char *str, ...);
void				ft_putnbr_count(int n, int *count, int fd);
void				print_pourcent(int *count, int fd);
void				putnbr_hex_fd(unsigned int n, int *count, char format,
						int fd);
void				putnbr_unsigned_fd(unsigned int n, int *count, int fd);
int					putptr(void *ptr, int fd);

// get_next_line
void				alloc_line(char **line, t_list_gnl *storage);
char				*copy_after_newline(const char *content, int start);
void				free_storage(t_list_gnl *storage);
char				*get_next_line(int fd);
int					search_new_line(t_list_gnl *storage);
t_list_gnl			*last_node(t_list_gnl *storage);

// leaks_protector
void				lp_free(void *address);
void				*lp_alloc(size_t size);

#endif
