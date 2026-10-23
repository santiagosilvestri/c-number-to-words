/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numwords.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasilves <sasilves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 20:00:00 by sasilves          #+#    #+#             */
/*   Updated: 2026/10/23 20:00:00 by sasilves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NUMWORDS_H
# define NUMWORDS_H

# include "libft.h"

# define MAX_DICT_ENTRIES 100
# define MAX_DICT_LINE 2047
# define READ_CHUNK 1024
# define MAX_DIGITS 45

typedef struct s_entry
{
	char	*key;
	char	*value;
}	t_entry;

typedef struct s_dictionary
{
	t_entry	entries[MAX_DICT_ENTRIES];
	int		count;
}	t_dictionary;

typedef struct s_reader
{
	t_dictionary	*dict;
	char			line[MAX_DICT_LINE + 1];
	size_t			len;
}	t_reader;

int			load_dict(t_dictionary *dict, const char *filename);
void		free_dict(t_dictionary *dict);
char		*lookup_word(t_dictionary *dict, const char *key);
int			add_dict_line(t_reader *reader, char *line);
int			read_dictionary(int fd, t_reader *reader);
int			is_valid_number(const char *str);
int			is_scale_key(const char *number);
const char	*skip_zeros(const char *number);
char		*convert(t_dictionary *dict, const char *number);
char		*convert_scale(t_dictionary *dict, const char *number);
char		*join_words(const char *left, const char *right);
char		*join_parts(char *left, const char *word, char *right);
int			write_line(const char *line);

#endif
