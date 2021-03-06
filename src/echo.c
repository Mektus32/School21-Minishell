/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 16:11:55 by ojessi            #+#    #+#             */
/*   Updated: 2019/12/29 16:12:01 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		echo_quotes(int *count_solo, int *count_doub, char **res, char ch)
{
	if (ch == '\'')
	{
		if (*count_doub == 0)
			if (*count_solo == 0)
				++(*count_solo);
			else
				--(*count_solo);
		else
			*res = ft_strplussymb(*res, ch);
		return (1);
	}
	else if (ch == '\"')
	{
		if (*count_solo == 0)
			if (*count_doub == 0)
				++(*count_doub);
			else
				--(*count_doub);
		else
			*res = ft_strplussymb(*res, ch);
		return (1);
	}
	return (0);
}

void	echo_variable(t_min sh, int i, int *j, char **res)
{
	char	*var;
	char	*com;

	var = ft_strnew(0);
	while (sh.line[i][*j] != '\'' && sh.line[i][*j] != '\"' &&
			sh.line[i][*j] != '\0')
	{
		var = ft_strplussymb(var, sh.line[i][*j]);
		(*j)++;
		if (sh.line[i][*j] == '$')
			break ;
	}
	if (!(com = ft_getenv(var + 1, sh)))
		*res = ft_free_join(*res, var);
	else
		*res = ft_free_join(*res, com);
	free(var);
}

void	echo_output(int count_solo, int count_doub, char **res)
{
	if (!*res)
		ft_putendl_fd("", 1);
	else if (!count_solo && !count_doub)
		ft_putendl_fd(*res, 1);
	else
		ft_printf("error quote`s\n");
	*res ? free(*res) : 0;
}

void	echo(t_min sh)
{
	int		count_solo;
	int		count_doub;
	int		i;
	int		j;
	char	*res;

	res = NULL;
	count_doub = 0;
	count_solo = 0;
	i = 0;
	while (sh.line[++i])
	{
		res = i != 1 ? ft_strplussymb(res, ' ') : ft_strnew(0);
		j = 0;
		while ((sh.line[i][j] = sh.line[i][j]) != '\0')
			if (echo_quotes(&count_solo, &count_doub, &res, sh.line[i][j]))
				++j;
			else if (sh.line[i][j] == '$')
				echo_variable(sh, i, &j, &res);
			else
				res = ft_strplussymb(res, sh.line[i][j++]);
	}
	echo_output(count_solo, count_doub, &res);
}
