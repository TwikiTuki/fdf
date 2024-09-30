/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenau-v <jrenau-v@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:24:06 by jrenau-v          #+#    #+#             */
/*   Updated: 2022/11/17 12:17:47 by jrenau-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*abort_buffer(char **buffer)
{
	if (1 || *buffer)
		free(*buffer);
	*buffer = NULL;
	return (NULL);
}

ssize_t	fill_buffer(char **buffer, int fd)
{
	char		*nw_buffer;
	char		nw_str[BUFFER_SIZE + 1];
	ssize_t		readed;

	readed = read(fd, nw_str, BUFFER_SIZE);
	if (readed <= 0)
		return (readed);
	nw_str[readed] = '\0';
	nw_buffer = twk_strjoin(*buffer, nw_str);
	if (*buffer)
		free(*buffer);
	*buffer = nw_buffer;
	if (!(*buffer))
		return (-1);
	return (readed);
}

char	*twk_get_line(char **buffer)
{
	int		end;
	char	*result;
	char	*nw_buffer;

	end = twk_strchr(*buffer, '\n') + 1;
	result = twk_substr(*buffer, 0, end);
	if (!result)
		return (abort_buffer(buffer));
	nw_buffer = twk_substr(*buffer, end, twk_strlen(*buffer) - end);
	free(*buffer);
	*buffer = nw_buffer;
	if (!buffer)
		return (abort_buffer(&result));
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*buffer_list[_SC_OPEN_MAX];
	char		*buffer2;
	ssize_t		readed;

	if (fd < 0 || fd > _SC_OPEN_MAX)
		return (NULL);
	if (!buffer_list[fd])
		buffer_list[fd] = twk_lazzy_calloc(1, sizeof(char));
	if (!buffer_list[fd])
		return (NULL);
	readed = 1;
	while (readed > 0 && twk_strchr(buffer_list[fd], '\n') == -1)
		readed = fill_buffer(&buffer_list[fd], fd);
	if (readed == -1)
		return (abort_buffer(&buffer_list[fd]));
	else if (twk_strchr(buffer_list[fd], '\n') == -1)
	{
		buffer2 = NULL;
		if (twk_strlen(buffer_list[fd]) != 0)
			buffer2 = twk_substr(buffer_list[fd],
					0, twk_strlen(buffer_list[fd]));
		abort_buffer(&buffer_list[fd]);
		return (buffer2);
	}
	return (twk_get_line(&buffer_list[fd]));
}
