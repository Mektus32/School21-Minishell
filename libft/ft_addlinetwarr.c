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
	if (!(new_arr = (char**)malloc(sizeof(char*) * (real_size + 1))))
		return (NULL);
	i = -1;
	while (++i < real_size)
	{
		if (!(new_arr[i] = ft_strdup(arr[i])))
		{
			ft_frtwarr((void **)new_arr, i);
			return (NULL);
		}
	}
	new_arr[real_size] = ft_strdup(str);
	new_arr[real_size + 1] = NULL;
	return (new_arr);
}