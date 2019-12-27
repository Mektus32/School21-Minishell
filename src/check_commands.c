#include "minishell.h"

void	check_command(t_min *sh)
{
	char	**dirs;
	char	*program;

	dirs = ft_strsplit(ft_getenv("PATH", *sh), ':');
	if ((program = get_program((const char**)dirs, sh->line[0], *sh)))
	{
		for (int i = 0; sh->line[i]; ++i) {
			ft_printf("%s\n", sh->line[i]);
		}
		start_program(program, *sh);
	}
	else if (!strncmp(sh->line[0], "./", 2))
	{
		if (!access(sh->line[0], 1))
		{
			start_program(sh->line[0], *sh);
		}
		else if (get_program((const char**)dirs, sh->line[0] + 2, *sh))
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
		exit(0);
	}
	else if (!strcmp("cd", sh->line[0]))
	{
		cd(sh);
	}
}