/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenau-v <jrenau-v@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:54:47 by jrenau-v          #+#    #+#             */
/*   Updated: 2022/09/29 16:59:54 by jrenau-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (n == 0)
		return (0);
	n--;
	while (*(char *)s1 == *(char *)s2 && n)
	{
		s1++;
		s2++;
		n--;
	}	
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
