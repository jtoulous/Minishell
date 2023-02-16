/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 12:09:01 by agoichon          #+#    #+#             */
/*   Updated: 2023/02/16 10:22:01 by agoichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_sigint(int sig)
{
	sig = 0;
	ft_putstr_fd("\n", 1);
	rl_replace_line("", sig);
	rl_on_new_line();
	rl_redisplay();
}
