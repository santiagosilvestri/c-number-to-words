/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_validate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasilves <sasilves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 20:00:00 by sasilves          #+#    #+#             */
/*   Updated: 2026/10/23 20:00:00 by sasilves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "numwords.h"

const char	*skip_zeros(const char *number)
{
	while (*number == '0')
		number++;
	return (number);
}

int	is_valid_number(const char *str)
{
	if (!str || !*str)
		return (0);
	while (*str)
	{
		if (!ft_isdigit((unsigned char)*str))
			return (0);
		str++;
	}
	return (1);
}

int	is_scale_key(const char *number)
{
	size_t	exponent;

	if (*number != '1')
		return (0);
	exponent = ft_strlen(number) - 1;
	if (exponent != 2 && (exponent < 3 || exponent % 3 != 0))
		return (0);
	number++;
	while (*number == '0')
		number++;
	return (*number == '\0');
}
