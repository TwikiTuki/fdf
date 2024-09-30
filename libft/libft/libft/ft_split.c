/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenau-v <jrenau-v@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:31:03 by jrenau-v          #+#    #+#             */
/*   Updated: 2022/09/28 11:34:48 by jrenau-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	**ft_charcount(char **s, size_t len, char *val);

static size_t	ft_count_char(const char *str, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (1)
	{
		if (str[i] == c || str[i] == '\0')
		{
			if (i != 0)
				count++;
			if (str[i] == '\0')
				break ;
			while (str[i] == c)
				i++;
			if (str[i] == '\0')
				break ;
		}
		else
			i++;
	}
	return (count);
}

static char	**clean(char **list, size_t len)
{
	while (len--)
		free(list[len]);
	free(list);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	np;
	unsigned int	lp;
	char			**res;

	np = ft_count_char(s, c);
	res = (char **)malloc((np + 1) * sizeof(char **));
	if (res)
		res[np] = NULL;
	np = 0;
	while (*s != '\0' && res)
	{
		lp = 0;
		while (*s == c)
			s++;
		while (s[lp] != c && s[lp] != '\0')
			lp++;
		if (!lp)
			break ;
		res[np] = ft_substr(s, 0, lp);
		if (!res[np])
			return (clean(res, np));
		s += lp;
		np++;
	}
	return (res);
}
/*
char **ft_push(char **s, size_t len, char *val)
{
	char	**result;
	size_t	i;

	printf("hallo\n");
	if(!s)
	{
		printf("first time\n");
		result = malloc(sizeof(char**));
		printf("result: %p\n", result);
		if (result)
			*result = NULL;
		else
			printf("memory not reserved\n");
		printf("result: %p\n", result);
		return (result);
	}
	result = malloc(sizeof(char**) * len + 1);
	i = 0;
	while(s[i])
	{
		result[i] = s[i];
		i++;
	}
	result[i] = val;
	result[i + 1] = NULL;

	free(s)
	return	(result);
}*/
