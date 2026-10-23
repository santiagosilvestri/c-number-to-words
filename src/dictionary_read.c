/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary_read.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasilves <sasilves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 20:00:00 by sasilves          #+#    #+#             */
/*   Updated: 2026/10/23 20:00:00 by sasilves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "numwords.h"
#include <errno.h>

static int	feed_dictionary(t_reader *reader, char *data, ssize_t n)
{
	ssize_t	i;

	i = 0;
	while (i < n)
	{
		if (data[i] == '\0')
			return (0);
		if (data[i] == '\n')
		{
			reader->line[reader->len] = '\0';
			if (!add_dict_line(reader, reader->line))
				return (0);
			reader->len = 0;
		}
		else
		{
			if (reader->len >= MAX_DICT_LINE)
				return (0);
			reader->line[reader->len++] = data[i];
		}
		i++;
	}
	return (1);
}

int	read_dictionary(int fd, t_reader *reader)
{
	char	data[READ_CHUNK];
	ssize_t	n;

	while (1)
	{
		n = read(fd, data, sizeof(data));
		if (n == 0)
			break ;
		if (n < 0)
		{
			if (errno == EINTR)
				continue ;
			return (0);
		}
		if (!feed_dictionary(reader, data, n))
			return (0);
	}
	if (!reader->len)
		return (1);
	reader->line[reader->len] = '\0';
	return (add_dict_line(reader, reader->line));
}
