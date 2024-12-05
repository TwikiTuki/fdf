
#include "ft_printf.h"

int	ft_flchar(char **str, va_list args, t_flags flags)
{	
	char	c;

	if (flags.type != 'c')
		return (-1);
	c = (char)(va_arg(args, int));
	if (!c)
	{
		*str = malloc(sizeof(char) * (1));
		if (!*str)
			return (-1);
		(*str)[0] = '\0';
	}
	else
	{
		*str = malloc(sizeof(char) * (2));
		if (!*str)
			return (-1);
		(*str)[0] = c;
		(*str)[1] = '\0';
	}
	return (ft_strlen(*str));
}

int	ft_flstring(char **str, va_list args, t_flags flags)
{
	char	*print_str;

	if (flags.type != 's')
		return (-1);
	print_str = va_arg(args, char *);
	if (!(print_str))
	{
		*str = ft_strdup("(null)");
	}
	else
	{
		*str = ft_strdup(print_str);
	}
	if (!*str)
		return (-1);
	return (ft_strlen(*str));
}
