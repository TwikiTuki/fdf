
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (n == 0)
		return (0);
	n--;
	while (*(char *)s1 == *(char *)s2 && n)
	{
		s1++;
		s2++;
		n--;
	}	
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
