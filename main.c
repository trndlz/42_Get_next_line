/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 11:51:52 by tmervin           #+#    #+#             */
/*   Updated: 2018/04/17 15:44:05 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	int fd1;
//	int fd2;
//	int fd3;
	char *line1;
//	char *line2;
//	char *line3;

	line1 = NULL;
	//line2 = NULL;
	//line3 = NULL;
	ac += 0;
	fd1 = open(av[1], O_RDONLY);
	//fd2 = open(av[2], O_RDONLY);
	//fd3 = open(av[3], O_RDONLY);
	//printf("fd1 %d / fd2 %d / fd3 %d\n", fd1, fd2, fd3);

	while ((get_next_line(fd1, &line1) == 1))
	{
		ft_putstr(line1);
		ft_putchar('\n');
	}
		free(line1);
	/*
	printf("%d\n", get_next_line(fd3, &line3));
	printf("FD3 >> %s\n", line3);
	printf("%d\n", get_next_line(fd1, &line1));
	printf("FD1 >> %s\n", line1);

	printf("%d\n", get_next_line(fd2, &line2));
	printf("FD2 >> %s\n", line2);
	printf("%d\n", get_next_line(fd1, &line1));
	printf("FD1 >> %s\n", line1);
	printf("%d\n", get_next_line(fd3, &line3));
	printf("FD3 >> %s\n", line3);
	printf("%d\n", get_next_line(fd2, &line2));
	printf("FD2 >> %s\n", line2);
		
	
	printf("%d\n", get_next_line(fd1, &line1));
	printf("FD1 >> %s\n", line1);
	printf("%d\n", get_next_line(fd2, &line2));
	printf("FD2 >> %s\n", line2);
*
/
	close (fd1); 
//	close (fd2); 
//	close (fd3); 
*/

	return (0);
}

