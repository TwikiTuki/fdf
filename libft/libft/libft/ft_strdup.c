/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenau-v <jrenau-v@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:45:58 by jrenau-v          #+#    #+#             */
/*   Updated: 2022/09/22 17:21:35 by jrenau-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*s2;

	len = 0;
	while (s1[len] != '\0')
		len++;
	len++;
	s2 = malloc(len);
	if (!s2)
	{
		errno = ENOMEM;
		return (NULL);
	}
	while (len--)
	{
		s2[len] = s1[len];
	}
	return (s2);
}
