/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_twarrcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 16:04:32 by ojessi            #+#    #+#             */
/*   Updated: 2019/12/29 16:04:33 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_twarrcpy(const char **arr, size_t size)
{
	char	**new_arr;
	size_t	new_size;
	size_t	i;

	if (!arr || !*arr)
		return (NULL);
	new_size = 0;
	while (arr[new_size] && new_size < size)
		++new_size;
	if (!(new_arr = (char**)malloc(sizeof(char*) * (new_size + 1))))
		return (NULL);
	i = -1;
	while (++i < new_size)
		if (!(new_arr[i] = ft_strdup(arr[i])))
		{
			ft_frtwarr((void **)new_arr, i);
			return (NULL);
		}
	new_arr[i] = NULL;
	return (new_arr);
}
