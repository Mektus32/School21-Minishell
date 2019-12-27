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