/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenau-v <jrenau-v@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 10:28:57 by jrenau-v          #+#    #+#             */
/*   Updated: 2022/09/29 17:03:14 by jrenau-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*cpy;

	cpy = (char *) b;
	while (len)
	{
		*cpy = (unsigned char) c;
		len--;
		cpy++;
	}
	return (b);
}
