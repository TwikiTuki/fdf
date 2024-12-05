
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dest;
	size_t	i;

	if ((dst == NULL && src == NULL))
		return (dst);
	dest = (char *) dst;
	i = 0;
	while (i < n)
	{
		dest[i] = ((char *)(src))[i];
		i++;
	}
	return (dst);
}
