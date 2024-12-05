
#include "libft.h"

void	*ft_bzero(void *b, size_t len)
{
	char	*cpy;

	cpy = (char *) b;
	while (len)
	{
		*cpy = 0;
		len--;
		cpy++;
	}
	return (b);
}
