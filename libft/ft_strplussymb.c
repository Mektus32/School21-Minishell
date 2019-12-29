/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strplussymb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 16:02:59 by ojessi            #+#    #+#             */
/*   Updated: 2019/12/29 16:03:01 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strplussymb(char *str, char ch)
{
	char	*res;
	int		size;

	if (!str)
		return (NULL);
	size = ft_strlen(str);
	if (!(res = (char*)malloc(sizeof(char) * (size + 2))))
		return (NULL);
	res = ft_strcpy(res, str);
	res[size] = ch;
	res[size + 1] = '\0';
	free(str);
	return (res);
}
