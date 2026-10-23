/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_join.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasilves <sasilves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 20:00:00 by sasilves          #+#    #+#             */
/*   Updated: 2026/10/23 20:00:00 by sasilves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "numwords.h"

char	*join_words(const char *s1, const char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len1 > (size_t)-1 - len2 - 2)
		return (NULL);
	result = malloc(len1 + len2 + 2);
	if (!result)
		return (NULL);
	ft_memcpy(result, s1, len1);
	result[len1] = ' ';
	ft_memcpy(result + len1 + 1, s2, len2 + 1);
	return (result);
}

char	*join_parts(char *left, const char *word, char *right)
{
	char	*result;
	char	*joined;

	result = join_words(left, word);
	free(left);
	if (!result)
		return (free(right), NULL);
	if (!right)
		return (result);
	joined = join_words(result, right);
	free(result);
	free(right);
	return (joined);
}
