/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replaceonspaces.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 19:03:04 by ojessi            #+#    #+#             */
/*   Updated: 2020/01/08 19:04:37 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*create_new_str(char **str)
{
	size_t	size;
	size_t	i;
	char	*res;

	size = ft_strlen(*str);
	if (!(res = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while ((*str)[i] != '\0')
	{
		res[i] = (*str)[i];
		++i;
	}
	res[i] = '\0';
	free(*str);
	return (res);
}

char		*ft_replaceonspaces(char *str)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	if (!str)
		return (NULL);
	if (!(new_str = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] != '\0')
		if (ft_isspace(str[i]))
		{
			new_str[j++] = ' ';
			while (ft_isspace(str[i]))
				++i;
		}
		else
		{
			new_str[j++] = str[i];
			++i;
		}
	new_str[j] = '\0';
	return (create_new_str(&new_str));
}
