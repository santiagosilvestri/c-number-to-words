/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasilves <sasilves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 20:00:00 by sasilves          #+#    #+#             */
/*   Updated: 2026/10/23 20:00:00 by sasilves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "numwords.h"
#include <fcntl.h>

int	load_dict(t_dictionary *dict, const char *filename)
{
	t_reader	reader;
	int			fd;
	int			valid;

	dict->count = 0;
	reader.dict = dict;
	reader.len = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	valid = read_dictionary(fd, &reader);
	if (close(fd) != 0)
		valid = 0;
	if (!valid || !dict->count)
	{
		free_dict(dict);
		return (0);
	}
	return (1);
}

void	free_dict(t_dictionary *dict)
{
	int	i;

	i = 0;
	while (i < dict->count)
	{
		free(dict->entries[i].key);
		free(dict->entries[i].value);
		i++;
	}
	dict->count = 0;
}

char	*lookup_word(t_dictionary *dict, const char *key)
{
	int		i;
	size_t	length;

	length = ft_strlen(key);
	i = 0;
	while (i < dict->count)
	{
		if (ft_strncmp(dict->entries[i].key, key, length + 1) == 0)
			return (dict->entries[i].value);
		i++;
	}
	return (NULL);
}
