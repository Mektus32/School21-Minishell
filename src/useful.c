/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 16:14:23 by ojessi            #+#    #+#             */
/*   Updated: 2019/12/29 16:15:01 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getenv(const char *name, t_min sh)
{
	size_t	i;

	i = -1;
	while (sh.env[++i])
		if (!ft_strncmp(sh.env[i], name, ft_strlen(name)) &&
				sh.env[i][ft_strlen(name)] == '=')
			return (sh.env[i] + ft_strlen(name) + 1);
	return (NULL);
}

void	sign(int param)
{
	ft_putchar('\n');
}

void	start_program(const char *name, t_min sh)
{
	pid_t	pid;

	if (!access(name, 1))
	{
		pid = fork();
		signal(SIGINT, sign);
		if (pid == 0)
			execve(name, sh.line, sh.env);
		wait(NULL);
	}
	else
		ft_printf("~bash: %s: Permission denied\n", name);
}

char	*get_program_full_dir(const char *name)
{
	if (!access(name, 0) && !access(name, 1))
		return ((ft_strdup(name)));
	else if (!access(name, 0))
		return (ft_strdup(name));
	return (NULL);
}

char	*get_program(const char **dirs, const char *name)
{
	DIR				*fd_dir;
	size_t			i;
	struct dirent	*file;

	if (name && name[0] == '/')
		return (get_program_full_dir(name));
	else if (name && ft_strcmp(name, "echo") && ft_strcmp("env", name)
		&& ft_strcmp("cd", name) && dirs)
	{
		i = -1;
		while (dirs[++i])
			if ((fd_dir = opendir(dirs[i])))
			{
				while ((file = readdir(fd_dir)))
					if (!ft_strcmp(name, file->d_name))
					{
						closedir(fd_dir);
						return (ft_free_strjoin_rev((char *) dirs[i],
													ft_strjoin("/",
															   file->d_name)));
					}
				closedir(fd_dir);
			}
	}
	return (NULL);
}
