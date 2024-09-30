/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenau-v <jrenau-v@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 11:20:30 by jrenau-v          #+#    #+#             */
/*   Updated: 2022/09/29 13:25:47 by jrenau-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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
