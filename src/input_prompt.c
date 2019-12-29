/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 16:08:49 by ojessi            #+#    #+#             */
/*   Updated: 2019/12/29 16:08:50 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	input_prompt(t_min sh)
{
	char	*home;
	char	*user;

	home = ft_getenv("HOME", sh);
	user = ft_getenv("USER", sh);
	if (home)
		if (!strcmp(sh.cur_path, home))
			ft_printf("\033[4;32m%s\033[0;32m:\033[1;35m~$>\033[0m ",
					ft_strrchr(home, '/') + 1);
		else
			ft_printf("\033[4;32m%s\033[0;32m:\033[1;35m%s$>\033[0m ", user,
	(ft_strlen(sh.cur_path) > 1 ? ft_strrchr(sh.cur_path, '/') + 1 : "/"));
	else
		ft_printf("error getting directory$>");
}
