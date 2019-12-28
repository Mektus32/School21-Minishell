#include "minishell.h"

void	env_print_error(char *name)
{
	struct stat 	buf;

	lstat(name, &buf);
	if (!S_ISDIR(buf.st_mode))
		ft_printf("env: `%s`: Permission denied\n", name);
	else
		ft_printf("env: `%s`: No such file or directory\n", name);
}

void	env(t_min sh)
{
	int		i;

	i = -1;
	if (sh.line[1])
		if (!ft_strcmp(sh.line[1], "-i"))
			if (!sh.line[2])
				return ;
			else
				env_print_error(sh.line[2]);
		else if (!ft_strcmp(sh.line[1], "-0"))
			if (!sh.line[2])
				while (sh.env[++i])
					ft_printf("%s", sh.env[i]);
			else
				ft_printf("env: cannot specify --null (-0) with command\n");
		else
			env_print_error(sh.line[1]);
	else
		while (sh.env[++i])
			ft_printf("%s\n", sh.env[i]);
}

void	ft_unsetenv_new_env(const char *name, t_min *sh, int size)
{
	int		i;
	int		j;
	char	**env;

	if (!(env = (char**)malloc(sizeof(char*) * size)))
		return ;
	i = -1;
	j = -1;
	while (sh->env[++i])
	{
		if (!ft_strncmp(name, sh->env[i], ft_strlen(name)) && sh->env[i][ft_strlen(name)] == '=')
			continue ;
		else
			if (!(env[++j] = ft_strdup(sh->env[i])))
			{
				ft_frtwarr((void **)env, j);
				return ;
			}
	}
	env[++j] = NULL;
	ft_frtwarr((void **)sh->env, INT_MAX);
	sh->env = env;
}

void	ft_unsetenv(const char *name, t_min *sh)
{
	int		i;
	int		f;

	i = -1;
	f = 0;
	if (!sh->line[1])
	{
		ft_printf("unsetenv: expected variable name\n");
		return ;
	}
	if (sh->line[2])
	{
		ft_printf("unsetenv: too many arguments\n");
		return ;
	}
	while (sh->env[++i])
		if (!ft_strncmp(name, sh->env[i], ft_strlen(name)) && sh->env[i][ft_strlen(name)] == '=')
			f = 1;
	if (f)
		ft_unsetenv_new_env(name, sh, i);
}
