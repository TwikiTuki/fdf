/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenau-v <jrenau-v@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:09:27 by jrenau-v          #+#    #+#             */
/*   Updated: 2022/09/29 16:59:20 by jrenau-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int				direction;
	unsigned int	i;
	char			*dest;
	char			*source;

	if (dst == src)
		return (dst);
	if (dst > src)
	{
		direction = -1;
		i = len - 1;
	}
	else
	{
		direction = 1;
		i = 0;
	}
	source = (char *) src;
	dest = (char *) dst;
	while (len--)
	{
		*(dest + i) = *(source + i);
		i += direction;
	}
	return (dst);
}
