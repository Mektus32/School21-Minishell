#include "minishell.h"

int check_command(t_min *sh)
{
	char	**dirs;
	char	*program;

	dirs = ft_strsplit(ft_getenv("PATH", *sh), ':');
	if ((program = get_program((const char **) dirs, sh->line[0])))
	{
		start_program(program, *sh);
	}
	else if (!strncmp(sh->line[0], "./", 2))
	{
		if (!access(sh->line[0], 1))
		{
			start_program(sh->line[0], *sh);
		}
		else if (!get_program((const char **) dirs, sh->line[0] + 2))
		{
			ft_printf("~bash: %s: No such file or directory\n", sh->line[0]);
		}
		else
		{
			ft_printf("~bash: %s: Permission denied\n", sh->line[0]);
		}
	}
	else if (!strcmp("exit", sh->line[0]))
	{
		ft_frtwarr((void**)dirs, INT_MAX);
		return 0;
	}
	else if (!strcmp("cd", sh->line[0]))
	{
		cd(sh);
	}
	else if (!strcmp("echo", sh->line[0]))
	{
		echo(*sh);
	}
	else if (!strcmp("env", sh->line[0]))
	{
		env(*sh);
	}
	ft_frtwarr((void**)dirs, INT_MAX);
	return 1;
}