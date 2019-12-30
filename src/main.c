/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 16:34:18 by ojessi            #+#    #+#             */
/*   Updated: 2019/12/29 16:34:20 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sh_init(t_min *sh, const char **av, const char **env)
{
	sh->prev_path = getcwd(NULL, INT_MAX);
	sh->cur_path = getcwd(NULL, INT_MAX);
	sh->av = ft_twarrcpy(av, INT_MAX);
	sh->env = ft_twarrcpy(env, INT_MAX);
}

void	sh_free(t_min *sh, char **line)
{
	ft_frtwarr((void **)sh->line, INT_MAX);
	ft_frtwarr((void **)sh->av, INT_MAX);
	ft_frtwarr((void **)sh->env, INT_MAX);
	free(*line);
	free(sh->cur_path);
	free(sh->prev_path);
}

//void	fun(int param)
//{
//	ft_putchar('\n');
//}

int		main(int ac, const char **av, const char **env)
{
	t_min	sh;
	char	*line;
	char	*tmp;

	if (ac > 1)
	{
		ft_printf("usage: ./minishell\n");
		return (0);
	}
	sh_init(&sh, av, env);
	while (1)
	{
//		signal(SIGINT, fun);
		input_prompt(sh);
		get_next_line(0, &line);
		if (ft_strlen(line))
		{
			tmp = ft_replaceonspaces(line);
			free(line);
			line = tmp;
			sh.line = ft_strsplit(line, ' ');
			if (*sh.line && !check_command(&sh))
			{
				sh_free(&sh, &line);
				return (0);
			}
			sh.line ? ft_frtwarr((void **)sh.line, INT_MAX) : 0;
		}
		line ? free(line) : 0;
	}
}
