/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frtwarr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <ojessi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 09:25:06 by ojessi            #+#    #+#             */
/*   Updated: 2019/06/10 17:05:41 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_frtwarr(void **arr, int size)
{
	int		i;

	if (!arr || !*arr)
		return ;
	i = -1;
	while (++i < size && arr[i] != NULL)
		free(arr[i]);
	free(arr);
}
