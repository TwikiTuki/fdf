
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int				direction;
	unsigned int	i;
	char			*dest;
	char			*source;

	if (dst == src)
		return (dst);
	if (dst > src)
	{
		direction = -1;
		i = len - 1;
	}
	else
	{
		direction = 1;
		i = 0;
	}
	source = (char *) src;
	dest = (char *) dst;
	while (len--)
	{
		*(dest + i) = *(source + i);
		i += direction;
	}
	return (dst);
}
