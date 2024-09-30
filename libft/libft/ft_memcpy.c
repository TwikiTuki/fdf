/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenau-v <jrenau-v@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:56:20 by jrenau-v          #+#    #+#             */
/*   Updated: 2022/09/25 19:43:18 by jrenau-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dest;
	size_t	i;

	if ((dst == NULL && src == NULL))
		return (dst);
	dest = (char *) dst;
	i = 0;
	while (i < n)
	{
		dest[i] = ((char *)(src))[i];
		i++;
	}
	return (dst);
}
