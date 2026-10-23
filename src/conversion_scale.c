/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_scale.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasilves <sasilves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 20:00:00 by sasilves          #+#    #+#             */
/*   Updated: 2026/10/23 20:00:00 by sasilves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "numwords.h"

static size_t	make_scale(char *scale, size_t length)
{
	size_t	exponent;

	exponent = ((length - 1) / 3) * 3;
	if (length == 3)
		exponent = 2;
	scale[0] = '1';
	ft_memset(scale + 1, '0', exponent);
	scale[exponent + 1] = '\0';
	return (exponent);
}

static char	*convert_prefix(t_dictionary *dict, const char *number,
		size_t length)
{
	char	*prefix;
	char	*result;

	prefix = ft_substr(number, 0, length);
	if (!prefix)
		return (NULL);
	result = convert(dict, prefix);
	free(prefix);
	return (result);
}

char	*convert_scale(t_dictionary *dict, const char *number)
{
	char	scale[MAX_DIGITS + 1];
	char	*word;
	char	*left;
	char	*right;
	size_t	prefix_length;

	prefix_length = ft_strlen(number);
	prefix_length -= make_scale(scale, prefix_length);
	word = lookup_word(dict, scale);
	if (!word)
		return (NULL);
	left = convert_prefix(dict, number, prefix_length);
	if (!left)
		return (NULL);
	number = skip_zeros(number + prefix_length);
	right = NULL;
	if (*number)
		right = convert(dict, number);
	if (*number && !right)
		return (free(left), NULL);
	return (join_parts(left, word, right));
}
