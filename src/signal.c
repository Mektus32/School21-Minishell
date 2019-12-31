#include "minishell.h"

void	fun(int param)
{
	if (param == SIGINT)
	{
		ft_printf("\n%s", g_path);
	}
}

void	sign(int param)
{
	if (param == SIGINT)
	{
		ft_putchar('\n');
	}
}
