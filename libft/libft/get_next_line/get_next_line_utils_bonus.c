/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenau-v <jrenau-v@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:32:43 by jrenau-v          #+#    #+#             */
/*   Updated: 2022/11/17 12:18:32 by jrenau-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*twk_lazzy_calloc(size_t ammount, size_t size)
{
	char	*result;
	size_t	total;
	size_t	i;

	total = ammount * size;
	result = malloc(total);
	if (!result)
		return (NULL);
	i = total - size;
	while (i < total)
	{
		result[i] = 0;
		i++;
	}
	return ((void *)result);
}

int	twk_strchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (i);
	else
		return (-1);
}

char	*twk_substr(char *s, size_t start, size_t len)
{	
	char	*result;
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	if (i < start)
		return (NULL);
	i = 0;
	while (s[i + start])
		i++;
	if (i < len)
		result = malloc(sizeof(char) * (i + 1));
	else
		result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

size_t	twk_strlen(char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*twk_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	len;
	size_t	i;

	len = twk_strlen(s1) + twk_strlen(s2);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2 && *s2)
	{
		result[i] = *s2;
		i++;
		s2++;
	}
	result[i] = '\0';
	return (result);
}
