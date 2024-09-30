/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenau-v <jrenau-v@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:45:59 by jrenau-v          #+#    #+#             */
/*   Updated: 2022/09/26 16:06:10 by jrenau-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*result;
	size_t		len;
	size_t		r;
	size_t		l;

	if (s1 == NULL)
		return (NULL);
	len = ft_strlen(s1);
	if (set == NULL)
		return (ft_substr(s1, 0, len));
	l = 0;
	while (ft_strchr(set, s1[l]) && l < len)
		l++;
	r = len;
	if (r)
		r--;
	while (ft_strrchr(set, s1[r]) && r)
		r--;
	if (r < l)
		return (ft_strdup(""));
	else
		result = ft_substr(s1, l, r - l + 1);
	return (result);
}
