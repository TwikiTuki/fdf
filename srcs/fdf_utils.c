/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenau-v <jrenau-v@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:30:58 by jrenau-v          #+#    #+#             */
/*   Updated: 2023/07/24 15:09:27 by jrenau-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_cols_from_line(char *line);

static int	get_cols_from_line(char *line)
{
	char	**numbers;
	size_t	result;

	numbers = ft_split(line, ' ');
	if (!numbers)
		return (-2);
	result = 0;
	while (numbers[result] && numbers[result][0] != '\n')
	{
		result++;
	}
	free_matrix((void **) numbers);
	return (result);
}

t_point	get_dims_from_file(char *file)
{
	int			f;
	char		*line;
	t_point		p;

	p = fdf_set_point(0, 0, 1);
	f = open(file, O_RDONLY);
	if (f < 0)
		return (fdf_set_point(0, 0, 0));
	line = get_next_line(f);
	while (line && p.z != 2 && ++p.y)
	{
		if (p.z != 1 && p.x != get_cols_from_line(line))
			free(line);
		if (p.z != 1 && p.x != get_cols_from_line(line))
			exit (0);
		else
			p.z = 0;
		p.x = get_cols_from_line(line);
		free(line);
		line = get_next_line(f);
	}
	close(f);
	if (p.z)
		p = fdf_set_point(0, 0, 0);
	return (p);
}

void	*free_matrix(void **list)
{
	size_t	i;

	if (!list)
		return (NULL);
	i = 0;
	while (list[i])
	{
		free(list[i++]);
	}
	free(list);
	return (NULL);
}

int	fdf_hex_int_atoi(char *str, char *base)
{
	int		result;
	int		i;
	int		c;

	result = 0;
	c = 0;
	while (str[c] && c <= 6)
	{
		i = 0;
		while (base[i] && base[i] != str[c])
		{
			i++;
		}
		if (i >= 16)
			return (result);
		result *= 16;
		result += i;
		c++;
	}
	return (result);
}

int	fdf_check_extension(char *file, char *ext)
{
	size_t	len_f;
	int		len_ext;

	len_f = ft_strlen(file);
	len_ext = ft_strlen(ext);
	while (--len_ext >= 0)
	{
		if (--len_f < 0)
			return (0);
		if (file[len_f] != ext[len_ext])
			return (0);
	}
	return (1);
}
