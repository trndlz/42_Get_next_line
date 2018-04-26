/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 11:51:52 by tmervin           #+#    #+#             */
/*   Updated: 2018/04/17 16:14:28 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int ac, char **av)
{
	int		fd1;
	char	*line1;

	line1 = NULL;
	ac += 0;
	fd1 = open(av[1], O_RDONLY);
	while ((get_next_line(fd1, &line1) == 1))
	{
		ft_putstr(line1);
		free(line1);
		ft_putchar('\n');
	}
	return (0);
}
