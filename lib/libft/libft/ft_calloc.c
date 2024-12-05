
#include <sys/errno.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*result;
	size_t	len;

	len = count * size;
	result = malloc(len);
	if (!result)
	{
		errno = ENOMEM;
		return ((void *)result);
	}
	while (len--)
	{
		result[len] = 0;
	}
	return ((void *)result);
}
