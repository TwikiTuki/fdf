/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenau-v <jrenau-v@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 11:05:40 by jrenau-v          #+#    #+#             */
/*   Updated: 2022/09/23 14:27:58 by jrenau-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_i;

	dst_i = 0;
	while (dst[dst_i] != '\0')
		dst_i++;
	if (dst_i >= dstsize)
		return (ft_strlen(src) + dstsize);
	while (*src != '\0' && dst_i < dstsize)
	{
		dst[dst_i] = *src;
		src++;
		dst_i++;
	}
	if (dst_i == dstsize)
		dst[dst_i - 1] = '\0';
	else
		dst[dst_i] = '\0';
	while (*(src++) != '\0')
		dst_i++;
	return (dst_i);
}
