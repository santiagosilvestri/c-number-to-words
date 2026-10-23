/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasilves <sasilves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 20:00:00 by sasilves          #+#    #+#             */
/*   Updated: 2026/10/23 20:00:00 by sasilves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "numwords.h"
#include <errno.h>

static int	write_all(const char *text, size_t length)
{
	ssize_t	written;

	while (length > 0)
	{
		written = write(STDOUT_FILENO, text, length);
		if (written < 0 && errno == EINTR)
			continue ;
		if (written <= 0)
			return (0);
		text += written;
		length -= written;
	}
	return (1);
}

int	write_line(const char *line)
{
	if (!write_all(line, ft_strlen(line)))
		return (0);
	return (write_all("\n", 1));
}
