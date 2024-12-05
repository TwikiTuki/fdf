#include "libft.h"

char	*ft_strndup(const char *src, size_t n)
{
	size_t	len;
	char	*dst;

	len = ft_strlen(src);
	if (n < len)
		len = n;
	dst = (char *)ft_calloc(len + 1, sizeof(char));
	if (!dst)
		return (NULL);
	if (dst)
		ft_memcpy(dst, src, len);
	return (dst);
}
