/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasilves <sasilves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 20:00:00 by sasilves          #+#    #+#             */
/*   Updated: 2026/10/23 20:00:00 by sasilves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "numwords.h"

static int	parse_args(int argc, char **argv, const char **path)
{
	if (argc < 2 || argc > 3 || !is_valid_number(argv[argc - 1]))
		return (0);
	if (ft_strlen(skip_zeros(argv[argc - 1])) > MAX_DIGITS)
		return (0);
	*path = "dictionaries/en.dict";
	if (argc == 3)
		*path = argv[1];
	return (1);
}

int	main(int argc, char **argv)
{
	t_dictionary	dict;
	char			*result;
	const char		*path;
	int				written;

	if (!parse_args(argc, argv, &path))
		return (write_line("Error"), 1);
	if (!load_dict(&dict, path))
		return (write_line("Dict Error"), 1);
	result = convert(&dict, argv[argc - 1]);
	free_dict(&dict);
	if (!result)
		return (write_line("Dict Error"), 1);
	written = write_line(result);
	free(result);
	return (!written);
}
