/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenau-v <jrenau-v@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:02:50 by jrenau-v          #+#    #+#             */
/*   Updated: 2022/11/26 13:12:37 by jrenau-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_getflags(const char **format);
int		ft_caller(va_list args, t_flags flags);
int		va_args_clean(va_list args);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_flags	flags;
	int		count;
	int		wrote;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			flags = ft_getflags(&format);
			if (flags.error)
				return (va_args_clean(args));
			wrote = ft_caller(args, flags);
		}
		else
			wrote = write(1, format, 1);
		if (wrote == -1)
			return (va_args_clean(args));
		count += wrote;
		format++;
	}
	va_end(args);
	return (count);
}

int	va_args_clean(va_list args)
{
	va_end(args);
	return (-1);
}

int	ft_caller(va_list args, t_flags flags)
{
	char	*str;	
	int		len;

	str = NULL;
	len = 0;
	if (flags.type == '%')
		return (write(1, "%", 1));
	else if (ft_strchr("c", flags.type))
		len = ft_flchar(&str, args, flags);
	else if (ft_strchr("s", flags.type))
		len = ft_flstring(&str, args, flags);
	else if (ft_strchr("pdiuxX", flags.type))
		len = ft_flnums(&str, args, flags);
	if (len == -1)
		return (-1);
	if (!str)
		return (-1);
	if (!str[0] && flags.type == 'c')
		len += 1;
	len = write(1, str, len);
	free(str);
	return (len);
}

void	get_pad_precision(char **format, t_flags *flags)
{
	while (**format >= '0' && **format <= '9')
	{
		flags->padding *= 10;
		flags->padding += **format + '0';
		(*format)++;
	}	
	if (**format != '.')
		return ;
	(*format)++;
	while (**format >= '0' && **format <= '9')
	{
		flags->precision *= 10;
		flags->precision += **format + '0';
		(*format)++;
	}
}

t_flags	ft_getflags(const char **format)
{
	t_flags	result;

	(*format)++;
	ft_bzero(&result, sizeof(t_flags));
	while (**format && ft_strchr("cspdiuxX%", **format) == NULL)
	{
		if (**format == '-')
			result.dash = 1;
		if (**format == '0')
			result.zero = 1;
		if (**format == '.')
			result.dot = 1;
		if (**format == '#')
			result.hashtag = 1;
		if (**format == ' ')
			result.space = 1;
		if (**format == '+')
			result.plus = 1;
		if (**format >= '1' || **format <= '9')
			get_pad_precision((char **)format, &result);
		(*format)++;
	}
	result.error = **format == '\0';
	result.type = **format;
	return (result);
}

/*
void print_flags(t_flags flags)
{
	printf(" flags: %c err %d, -%d, 0%d, .%d, #%d, sp%d, +%d\n",
			flags.type,
			flags.error,
			flags.dash,
			flags.zero,
			flags.dot,
			flags.hashtag,
			flags.space,
			flags.plus
			);

}*/
