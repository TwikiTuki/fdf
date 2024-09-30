/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenau-v <jrenau-v@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:23:07 by jrenau-v          #+#    #+#             */
/*   Updated: 2022/11/17 14:51:19 by jrenau-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 420
# endif

char	*get_next_line(int fd);
ssize_t	fill_buffer(char **buffer, int fd);
char	*twk_get_line(char **buffer);

int		twk_strchr(char *str, char c);
char	*twk_substr(char *s, size_t start, size_t len);
char	*twk_strjoin(char *s1, char *s2);
void	*twk_lazzy_calloc(size_t ammount, size_t size);
size_t	twk_strlen(char *s);
#endif
