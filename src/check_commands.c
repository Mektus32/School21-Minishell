/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 16:40:43 by ojessi            #+#    #+#             */
/*   Updated: 2019/12/29 16:41:45 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_command_etc(t_min *sh)
{
	if (!ft_strcmp("cd", sh->line[0]))
		cd(sh);
	else if (!ft_strcmp("echo", sh->line[0]))
		echo(*sh);
	else if (!ft_strcmp("env", sh->line[0]))
		env(*sh);
	else if (!ft_strcmp("unsetenv", sh->line[0]))
		ft_unsetenv(sh->line[1], sh);
	else if (!ft_strcmp("setenv", sh->line[0]))
		ft_setenv(sh);
	else
		ft_printf("Command '%s' not found\n", sh->line[0]);
}

int		check_command(t_min *sh)
{
	char	**dirs;
	char	*program;

	dirs = ft_strsplit(ft_getenv("PATH", *sh), ':');
	if ((program = get_program((const char **)dirs, sh->line[0])))
	{
		start_program(program, *sh);
		free(program);
	}
	else if (!ft_strncmp(sh->line[0], "./", 2))
		if (!access(sh->line[0], 1))
			start_program(sh->line[0], *sh);
		else if (!get_program((const char **)dirs, sh->line[0] + 2))
			ft_printf("~bash: %s: No such file or directory\n", sh->line[0]);
		else
			ft_printf("~bash: %s: Permission denied\n", sh->line[0]);
	else if (!ft_strcmp("exit", sh->line[0]))
	{
		ft_frtwarr((void **)dirs, INT_MAX);
		return (0);
	}
	else
		check_command_etc(sh);
	ft_frtwarr((void **)dirs, INT_MAX);
	return (1);
}
