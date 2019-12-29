/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_repetition.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 16:01:51 by ojessi            #+#    #+#             */
/*   Updated: 2019/12/29 16:01:52 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_replace_repetition(char **str, char ch)
{
	char	*res;
	int		size;
	int		i;
	int		j;

	if (!str || !*str || !ft_strlen(*str))
		return ;
	size = ft_strlen(*str);
	if (!(res = (char*)malloc(sizeof(char) * (size + 1))))
		return ;
	res[size] = '\0';
	i = -1;
	j = -1;
	while ((*str)[++i] != '\0')
	{
		res[++j] = (*str)[i];
		while ((*str)[i] == ch && (*str)[i + 1] == ch)
			++i;
	}
	res[++j] = '\0';
	free(*str);
	*str = ft_strdup(res);
	free(res);
}
