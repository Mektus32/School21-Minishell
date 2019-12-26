#include "minishell.h"

char	*get_program(const char **dirs, const char *name, t_min sh)
{
	DIR	*fd_dir;
	size_t	i;
	struct dirent	*file;

	i = -1;
	while (dirs[++i])
	{
		if ((fd_dir = opendir(dirs[i])))
		{
			while ((file = readdir(fd_dir)))
			{
				if (!strcmp(name, file->d_name))
				{
					closedir(fd_dir);
					return (ft_free_strjoin_rev(dirs[i], ft_strjoin("/", file->d_name)));
				}
			}
			closedir(fd_dir);
		}
	}
	return (NULL);
}

void	start_program(const char *name, t_min sh)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		execve(name, sh.line, sh.env);
	}
	wait(-1);
}

void	check_command(t_min *sh)
{
	char	**dirs;
	char	*program;

	dirs = ft_strsplit(ft_getenv("PATH", *sh), ':');
	if ((program = get_program((const char**)dirs, sh->line[0], *sh)))
	{
		start_program(program, *sh);
	}
	start_program("min", *sh);//don`t understand how to start program with ./
}