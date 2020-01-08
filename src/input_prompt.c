/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 16:08:49 by ojessi            #+#    #+#             */
/*   Updated: 2020/01/08 19:08:50 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	input_prompt_user(t_min sh, char *user)
{
	g_path ? free(g_path) : 0;
	g_path = ft_free_join(ft_free_join(ft_free_join(
	ft_strjoin("\033[4;32m", user), "\033[0;32m:\033[1;35m"),
	ft_strlen(sh.cur_path) > 1 ?
	ft_strrchr(sh.cur_path, '/') + 1 : "/"), "$>\033[0m ");
	ft_printf("%s", g_path);
}

void	input_prompt_home(char *home)
{
	g_path ? free(g_path) : 0;
	g_path = ft_free_join(ft_strjoin("\033[4;32m",
	ft_strrchr(home, '/') + 1), "\033[0;32m:\033[1;35m~$>\033[0m ");
	ft_printf("%s", g_path);
}

void	input_prompt(t_min sh)
{
	char	*home;
	char	*user;

	home = ft_getenv("HOME", sh);
	user = ft_getenv("USER", sh);
	if (home)
		if (!strcmp(sh.cur_path, home))
			input_prompt_home(home);
		else
			input_prompt_user(sh, user);
	else
	{
		ft_printf("error getting directory$>");
		g_path ? free(g_path) : 0;
		g_path = ft_strdup("error getting directory$>");
	}
}
