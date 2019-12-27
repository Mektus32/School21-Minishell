#include "minishell.h"

void echo(t_min sh)
{
	int		count_solo;
	int		count_doub;
	int		i;
	int		j;
	char	ch;
	char	*res = ft_strnew(0);

	count_doub = 0;
	count_solo = 0;
	i = 0;
	while (sh.line[++i])
	{
		i != 1 ? res = ft_strplussymb(res, ' ') : 0;
		j = 0;
		while ((ch = sh.line[i][j]) != '\0')
		{
			if (ch == '\'')
			{
				if (count_doub == 0)
				{
					if (count_solo == 0)
					{
						++count_solo;
					}
					else
					{
						--count_solo;
					}
				}
				else
				{
					res = ft_strplussymb(res, ch);
				}
				j++;
			}
			else if (ch == '\"')
			{
				if (count_solo == 0)
				{
					if (count_doub == 0)
					{
						++count_doub;
					}
					else
					{
						--count_doub;
					}
				}
				else
				{
					res = ft_strplussymb(res, ch);
				}
				j++;
			}
			else if (ch == '$')
			{
				char	*var = ft_strnew(0);
				while (sh.line[i][j] != '\'' && sh.line[i][j] != '\"' &&  sh.line[i][j] != '\0')
				{
					var = ft_strplussymb(var, sh.line[i][j]);
					j++;
				}
				char	*com;
				if (!(com = ft_getenv(var + 1, sh)))
				{
					res = ft_free_join(res, var);
				}
				else
				{
					res = ft_free_join(res, com);
				}
			}
			else
			{
				res = ft_strplussymb(res, ch);
				j++;
			}
		}
	}
	if (!count_solo && !count_doub)
	{
		ft_putendl_fd(res, 1);
	}
	else
	{
		ft_printf("error quote`s\n");
	}
}