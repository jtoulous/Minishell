/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 12:09:01 by agoichon          #+#    #+#             */
/*   Updated: 2023/02/05 12:38:43 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <bits/types/siginfo_t.h>

int	handle_sigint(int sig, siginfo_t *info, void *context)
{
	printf("^C\n");
	return (130);
}

void	handle_eof(int sig, siginfo_t *info, void *context)
{
	printf("exit\n");
	exit (0);
}

int	handle_sigquit(int sig, siginfo_t *info, void *context)
{
	return (0);
}	
