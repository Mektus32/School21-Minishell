/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 19:07:33 by ojessi            #+#    #+#             */
/*   Updated: 2020/01/08 19:07:34 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fun(int param)
{
	if (param == SIGINT)
	{
		ft_printf("\n%s", g_path);
	}
}

void	sign(int param)
{
	if (param == SIGINT)
	{
		ft_putchar('\n');
	}
}
