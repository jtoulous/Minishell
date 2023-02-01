/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:49:14 by agoichon          #+#    #+#             */
/*   Updated: 2023/02/01 15:10:31 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	void		*entry;
	struct 	s_list	*nxt;
}		t_list;

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstnew(void *c);
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	*ft_memset(void *p, int v, size_t i);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
void	*ft_memcpy(void *dest, const void *src, size_t size);
char	*ft_strdup(const char *src);
size_t	ft_strlen(const char *s);
int		ft_tolower(int i);
int		ft_toupper(int c);
int		ft_atoi(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *str, int s);
int		ft_strncmp(const char *s1, const char *s2, size_t x);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strrchr(const char *str, int s);
void	*ft_memchr( const void *s, int c, size_t n);
char	*ft_strnstr(const char *str, const char *to_find, size_t len);
int		ft_memcmp(const void *p1, const void *p2, size_t s);
void	ft_bzero(void *s, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int nb, int fd);
char	*ft_substr(char const *s2, unsigned int start, size_t len);
void	*ft_memmove( void *destination, const void *source, size_t size);
void	*ft_calloc(size_t n, size_t s);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_itoa(int n);
char	*get_next_line(int fd);
void	ft_sort_int_tab(char *str);
#endif
