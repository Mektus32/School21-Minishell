#include "minishell.h"

void	env(t_min sh)
{
	int		i;

	i = -1;
	while (sh.env[++i])
		ft_printf("%s\n", sh.env[i]);
}
