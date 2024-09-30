/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenau-v <jrenau-v@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:38:40 by jrenau-v          #+#    #+#             */
/*   Updated: 2022/09/23 14:29:17 by jrenau-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/errno.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*result;
	size_t	len;

	len = count * size;
	result = malloc(len);
	if (!result)
	{
		errno = ENOMEM;
		return ((void *)result);
	}
	while (len--)
	{
		result[len] = 0;
	}
	return ((void *)result);
}
