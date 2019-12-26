#include "minishell.h"

void input_prompt(t_min sh)
{
	char	*path;
	char	*home;
	char	*user;

	path = getcwd(NULL, INT_MAX);
	home = ft_getenv("HOME", sh);
	user = ft_getenv("USERNAME", sh);
	if (!strcmp(path, home))
		ft_printf("\033[4;32m%s\033[0;32m:\033[1;35m~$>\033[0m> ", ft_strrchr(home, '/') + 1);
	else
		ft_printf("\033[4;32m%s\033[0;32m:\033[1;35m%s$>\033[0m ", user, ft_strrchr(path, '/') + 1);
	free(path);
}