
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*s2;

	len = 0;
	while (s1[len] != '\0')
		len++;
	len++;
	s2 = malloc(len);
	if (!s2)
	{
		errno = ENOMEM;
		return (NULL);
	}
	while (len--)
	{
		s2[len] = s1[len];
	}
	return (s2);
}
