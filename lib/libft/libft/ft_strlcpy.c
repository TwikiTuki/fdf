
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && i < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	if (i == dstsize && i)
		dst[i - 1] = '\0';
	else if (dstsize)
		dst[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}
