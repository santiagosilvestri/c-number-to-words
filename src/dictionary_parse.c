/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary_parse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasilves <sasilves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 20:00:00 by sasilves          #+#    #+#             */
/*   Updated: 2026/10/23 20:00:00 by sasilves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "numwords.h"

static int	store_entry(t_reader *reader, char *key, char *value)
{
	int	count;

	count = reader->dict->count;
	if (!key || !value || !is_valid_number(key) || !*value
		|| ft_strlen(key) > MAX_DIGITS
		|| (key[0] == '0' && key[1])
		|| lookup_word(reader->dict, key))
	{
		free(key);
		free(value);
		return (0);
	}
	reader->dict->entries[count].key = key;
	reader->dict->entries[count].value = value;
	reader->dict->count = count + 1;
	return (1);
}

int	add_dict_line(t_reader *reader, char *line)
{
	char	*cursor;
	char	*sep;
	char	*key;
	char	*value;

	cursor = line;
	while (*cursor == ' ' || *cursor == '\t' || *cursor == '\r')
		cursor++;
	if (!*cursor || *cursor == '#')
		return (1);
	if (reader->dict->count >= MAX_DICT_ENTRIES)
		return (0);
	sep = ft_strchr(cursor, ':');
	if (!sep)
		return (0);
	*sep = '\0';
	key = ft_strtrim(cursor, " \t\r");
	value = ft_strtrim(sep + 1, " \t\r");
	return (store_entry(reader, key, value));
}
