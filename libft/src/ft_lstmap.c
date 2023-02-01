/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:47:27 by agoichon          #+#    #+#             */
/*   Updated: 2022/10/18 19:59:34 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*s;
	t_list	*tmp;

	if (!lst || !f || ! del)
		return (0);
	s = ft_lstnew(f(lst->content));
	if (!s)
	{
		ft_lstclear((t_list **)s, del);
		return (0);
	}
	tmp = s;
	lst = lst->next;
	while (lst)
	{
		s->next = ft_lstnew(f(lst->content));
		if (!s->next)
		{
			ft_lstclear((t_list **)s, del);
			return (0);
		}
		lst = lst->next;
		s = s->next;
	}
	return (tmp);
}
