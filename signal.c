/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 12:09:01 by agoichon          #+#    #+#             */
/*   Updated: 2023/02/05 13:22:00 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

void handle_sigint(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void) info;
	(void) context;
	printf("^C");
}

void	handle_eof(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void) info;
	(void) context;
	printf("exit\n");
	exit (0);
}

void	handle_sigquit(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)info;
	(void)context;
	exit(0);

}	
