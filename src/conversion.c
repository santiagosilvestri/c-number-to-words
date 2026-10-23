/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasilves <sasilves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 20:00:00 by sasilves          #+#    #+#             */
/*   Updated: 2026/10/23 20:00:00 by sasilves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "numwords.h"

static char	*convert_tens(t_dictionary *dict, const char *number)
{
	char	tens[3];
	char	*left;
	char	*right;

	if (number[0] < '2' || number[1] == '0')
		return (NULL);
	tens[0] = number[0];
	tens[1] = '0';
	tens[2] = '\0';
	left = lookup_word(dict, tens);
	right = lookup_word(dict, number + 1);
	if (!left || !right)
		return (NULL);
	return (join_words(left, right));
}

char	*convert(t_dictionary *dict, const char *number)
{
	char	*word;
	size_t	length;

	number = skip_zeros(number);
	if (!*number)
		number = "0";
	length = ft_strlen(number);
	if (length > MAX_DIGITS)
		return (NULL);
	word = lookup_word(dict, number);
	if (word && !is_scale_key(number))
		return (ft_strdup(word));
	if (length >= 3)
		return (convert_scale(dict, number));
	if (length == 2)
		return (convert_tens(dict, number));
	return (NULL);
}
