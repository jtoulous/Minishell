/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:41:24 by jtoulous          #+#    #+#             */
/*   Updated: 2022/10/18 12:59:45 by jtoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(char *content)
{
	unsigned char	*tmp;
	t_list			*fnl;

	//tmp = (unsigned char *)content;
	fnl = malloc(sizeof(t_list));
	if (fnl)
	{
		fnl->env_copy = content;
		fnl->next = NULL;
	}
	return (fnl);
}
