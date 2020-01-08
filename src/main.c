/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 16:34:18 by ojessi            #+#    #+#             */
/*   Updated: 2020/01/08 19:14:23 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sh_init(t_min *sh, const char **av, const char **env, int ac)
{
	if (ac > 1)
	{
		ft_printf("usage: ./minishell\n");
		exit(0);
	}
	sh->prev_path = getcwd(NULL, INT_MAX);
	sh->cur_path = getcwd(NULL, INT_MAX);
	sh->av = ft_twarrcpy(av, INT_MAX);
	sh->env = ft_twarrcpy(env, INT_MAX);
}

int		sh_free(t_min *sh, char **line, char **new_line, char **split_line)
{
	ft_frtwarr((void **)sh->line, INT_MAX);
	ft_frtwarr((void **)sh->av, INT_MAX);
	ft_frtwarr((void **)sh->env, INT_MAX);
	ft_frtwarr((void**)split_line, INT_MAX);
	ft_strdel(new_line);
	ft_strdel(line);
	ft_strdel(&g_path);
	free(sh->cur_path);
	free(sh->prev_path);
	return (0);
}

char	*get_line(t_min sh)
{
	char	*line;

	input_prompt(sh);
	get_next_line(0, &line);
	return (line);
}

int		main(int ac, const char **av, const char **env)
{
	t_min	sh;
	char	*line;
	char	*new_line;
	char	**split_line;
	size_t	i;

	sh_init(&sh, av, env, ac);
	while (1)
	{
		signal(SIGINT, fun);
		line = get_line(sh);
		new_line = ft_replaceonspaces(line);
		ft_strdel(&line);
		split_line = ft_strsplit(new_line, ';');
		i = -1;
		while (split_line[++i])
		{
			sh.line = ft_strsplit(split_line[i], ' ');
			if (*sh.line && !check_command(&sh))
				return (sh_free(&sh, &line, &new_line, split_line));
			sh.line ? ft_frtwarr((void **)sh.line, INT_MAX) : 0;
		}
		ft_frtwarr((void **)split_line, INT_MAX);
		ft_strdel(&new_line);
	}
}
