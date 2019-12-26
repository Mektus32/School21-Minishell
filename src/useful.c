#include "minishell.h"

char	*ft_getenv(const char *name, t_min sh)
{
	size_t	i;

	i = -1;
	while (sh.env[++i])
	{
		if (!ft_strncmp(sh.env[i], name, ft_strlen(name)))
		{
			return (sh.env[i] + ft_strlen(name) + 1);
		}
	}
	return (NULL);
}