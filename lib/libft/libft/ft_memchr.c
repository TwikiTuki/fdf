#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	if (!n)
		return (0);
	str = (unsigned char *) s;
	while (n && (*str != (unsigned char) c))
	{
		str++;
		n--;
	}
	if (n && (*str == (unsigned char) c))
		return ((void *) str);
	return (0);
}
