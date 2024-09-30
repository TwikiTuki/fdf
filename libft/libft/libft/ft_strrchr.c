/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenau-v <jrenau-v@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 11:24:15 by jrenau-v          #+#    #+#             */
/*   Updated: 2022/09/22 15:30:17 by jrenau-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	const char	*ret;

	ret = 0;
	while (*s != '\0')
	{
		if (*s == (char)c)
			ret = s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *) s);
	return ((char *) ret);
}
