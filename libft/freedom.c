/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:44:28 by jtoulous          #+#    #+#             */
/*   Updated: 2023/01/14 16:44:34 by jtoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_loop(char **str)
{
	int	z;

	z = 0;
	if (str)
	{
		while (str[z])
		{
			free (str[z]);
			z++;
		}
		free (str);
	}
}

void	mega_free(char *s1, char *s2, char *s3, char *s4)
{
	if (s1)
		free (s1);
	if (s2)
		free (s1);
	if (s3)
		free (s1);
	if (s4)
		free (s1);			
}
