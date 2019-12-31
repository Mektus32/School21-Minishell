/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 16:06:30 by ojessi            #+#    #+#             */
/*   Updated: 2019/12/29 16:07:01 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	change_paths(t_min *sh, char *new_cur, char *new_prev)
{
	free(sh->cur_path);
	free(sh->prev_path);
	sh->cur_path = new_cur;
	sh->prev_path = new_prev;
}

void	cd_second_param_etc(t_min *sh, char *str, char **home)
{
	if (!ft_strcmp(str, "~"))
	{
		if (!chdir((*home = ft_getenv("HOME", *sh))))
			change_paths(sh, ft_strdup(*home), ft_strdup(sh->cur_path));
	}
	else if (str[0] == '~')
	{
		*home = ft_getenv("HOME", *sh);
		*home = ft_strjoin(*home, str + 1);
		if (!chdir(*home))
			change_paths(sh, ft_strdup(*home), ft_strdup(sh->cur_path));
		free(*home);
	}
	else
		ft_printf("~bash: cd: %s:No such file or directory\n", sh->line[1]);
}

void	cd_second_param(t_min *sh)
{
	char	*home;
	char	*str;

	str = ft_strdup(sh->line[1]);
	ft_replace_repetition(&str, '/');
	if (!chdir(str))
		change_paths(sh, getcwd(NULL, INT_MAX), ft_strdup(sh->cur_path));
	else if (!ft_strcmp(str, "-"))
	{
		if (!ft_strcmp(sh->prev_path, sh->cur_path))
			ft_printf("~bash: cd: OLDPWD not set\n");
		else if (!chdir(sh->prev_path))
			change_paths(sh, ft_strdup(sh->prev_path), ft_strdup(sh->cur_path));
	}
	else
		cd_second_param_etc(sh, str, &home);
	free(str);
}

void	cd(t_min *sh)
{
	size_t	i;
	char	*home;

	i = -1;
	while (sh->line[++i])
		if (i > 2)
		{
			ft_printf("~bash: cd: too many arguments\n");
			return ;
		}
	if (i == 2)
		cd_second_param(sh);
	else if (!chdir((home = ft_getenv("HOME", *sh))))
		change_paths(sh, ft_strdup(home), ft_strdup(sh->cur_path));
}
