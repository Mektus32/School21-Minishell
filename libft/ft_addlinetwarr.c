/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addlinetwarr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 16:00:29 by ojessi            #+#    #+#             */
/*   Updated: 2019/12/29 16:00:33 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_addlinetwarr(const char **arr, const char *str, size_t size)
{
	char	**new_arr;
	size_t	i;
	size_t	real_size;

	if (!arr || !*arr || !str)
		return (NULL);
	real_size = 0;
	while (arr[real_size] && real_size < size)
		++real_size;
	if (!(new_arr = (char**)malloc(sizeof(char*) * (real_size + 2))))
		return (NULL);
	i = 0;
	while (i < real_size)
	{
		if (!(new_arr[i] = ft_strdup(arr[i])))
		{
			ft_frtwarr((void **)new_arr, i);
			return (NULL);
		}
		++i;
	}
	new_arr[i] = ft_strdup(str);
	new_arr[i + 1] = NULL;
	return (new_arr);
}
