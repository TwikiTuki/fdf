/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subsrt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenau-v <jrenau-v@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:33:08 by jrenau-v          #+#    #+#             */
/*   Updated: 2022/09/29 13:35:55 by jrenau-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	start_ok(char const *s, unsigned int start)
{
	size_t	ln;

	ln = 0;
	while (s[ln] != '\0' && ln < start)
		ln++;
	return (start == ln);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	ln;
	size_t	i;
	char	*result;

	if (!start_ok(s, start))
	{
		result = malloc(sizeof(char) * 1);
		if (result)
			result[0] = '\0';
		return (result);
	}
	ln = 0;
	while (s[start + ln] != '\0' && ln < len)
		ln++;
	result = malloc(sizeof(char) * ln + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < ln)
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
