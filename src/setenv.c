#include "minishell.h"

void	ft_setenv_origin(const char **name, const char **value, int overwrite, t_min *sh)
{
	int		i;
	int		f;
	char *tmp;
	char **env;

	i = -1;
	f = 0;
	while (sh->env[++i])
		if (!ft_strncmp((char*)name, sh->env[i], ft_strlen((char*)name)) && sh->env[i][ft_strlen((char*)name)] == '=')
		{
			if (overwrite)
			{
				free(sh->env[i]);
				sh->env[i] = ft_free_strjoin_rev((char*)name, ft_strjoin("=", (char*)value));
			}
			f = 1;
		}
	if (!f)
	{
		tmp = ft_free_strjoin_rev((char*)name, ft_strjoin("=", (char*)value));
		if ((env = ft_addlinetwarr((const char **)sh->env, tmp, INT_MAX)))
		{
			ft_frtwarr((void **)sh->env, INT_MAX);
			free(tmp);
			sh->env = env;
		}
	}
}

void	ft_setenv(t_min *sh)
{
	int		i;
	int		overwrite;

	i = 0;
	while (sh->line[i])
		++i;
	if (i != 4)
	{
		i < 4 ? ft_printf("setenv: too less arguments\n") : ft_printf("setenv: too many arguments\n");
		return ;
	}
	if (!ft_isdigit(sh->line[3][0]))
	{
		if ((sh->line[3][0] == '-' || sh->line[3][0] == '+') && ft_isdigit(sh->line[3][1]))
				overwrite = ft_atoi(sh->line[3]);
		else
		{
			ft_printf("setenv: expected number in 3 arg, but get: %s\n",
					  sh->line[3]);
			return;
		}
	}
	else
		overwrite = ft_atoi(sh->line[3]);
	ft_setenv_origin((const char **)sh->line[1], (const char **)sh->line[2], overwrite, sh);
}