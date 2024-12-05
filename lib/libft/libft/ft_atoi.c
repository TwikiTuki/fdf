
#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

	while ((*str >= 9 && *str <= 13) || *str == ' ' )
		str++;
	if (*str == '-')
		sign = -1;
	else
		sign = 1;
	if (*str == '+' || *str == '-')
		str++;
	result = 0;
	while (ft_isdigit(*str))
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	result *= sign;
	return (result);
}
