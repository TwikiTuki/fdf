
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		ln1;
	int		ln2;

	if (s1)
		ln1 = ft_strlen(s1);
	else
		ln1 = 0;
	if (s2)
		ln2 = ft_strlen(s2);
	else
		ln2 = 0;
	result = malloc(ln1 + ln2 + 1);
	if (!result)
		return (NULL);
	if (s1)
		ft_strlcpy(result, s1, ln1 + 1);
	if (s2)
	{
		result[ln1] = 1;
		ft_strlcpy(result + ln1, s2, ln2 + 1);
	}
	return (result);
}
