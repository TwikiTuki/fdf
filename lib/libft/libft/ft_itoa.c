
#include "libft.h"

static int	ft_intlen(int n);

char	*ft_itoa(int n)
{
	int		len;
	char	*result;

	len = ft_intlen(n);
	if (n == MAL_INT_MIN)
		return (ft_strdup("-2147483648"));
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (n < 0)
	{
		result[0] = '-';
		n *= -1;
	}
	while (1)
	{
		len--;
		result[len] = n % 10 + '0';
		n /= 10;
		if (!n)
			break ;
	}
	return (result);
}

static int	ft_intlen(int n)
{
	int	result;
	int	sign;

	sign = n < 0;
	result = 0;
	while (n)
	{
		result++;
		n /= 10;
	}
	if (!result)
		result++;
	if (sign)
		result++;
	return (result);
}
