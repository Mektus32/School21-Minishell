#include "minishell.h"

void	cd(t_min *sh)
{
	size_t	i;
	char	*home;
	char	*tmp;

	i = 0;
	while (sh->line[i])
	{
		++i;
		if (i > 2)
		{
			ft_printf("~bash: cd: too many arguments\n");
			return ;
		}
	}
	if (i == 2)
	{
		if (!chdir(sh->line[1]))
		{
			free(sh->prev_path);
			sh->prev_path = sh->cur_path;
			sh->cur_path = getcwd(NULL, INT_MAX);
		}
		else
		{
			if (!ft_strcmp(sh->line[1], "-"))
			{
				if (!ft_strcmp(sh->prev_path, sh->cur_path))
				{
					ft_printf("~bash: cd: OLDPWD not set\n");
				}
				else
				{
					if (!chdir(sh->prev_path))
					{
						tmp = sh->prev_path;
						sh->prev_path = sh->cur_path;
						sh->cur_path = tmp;
					}
				}
			}
			else if (!ft_strcmp(sh->line[1], "~"))
			{
				if (!chdir((home = ft_getenv("HOME", *sh))))
				{
					free(sh->prev_path);
					sh->prev_path = sh->cur_path;
					sh->cur_path = ft_strdup(home);
				}
			}
			else
			{
				ft_printf("~bash: cd: %s:No such file or directory\n", sh->line[1]);
			}
		}
	}
	else
	{
		if (!chdir((home = ft_getenv("HOME", *sh))))
		{
			free(sh->prev_path);
			sh->prev_path = sh->cur_path;
			sh->cur_path = ft_strdup(home);
		}
	}

}