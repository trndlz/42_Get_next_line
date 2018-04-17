/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 10:48:49 by tmervin           #+#    #+#             */
/*   Updated: 2018/04/16 20:15:32 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 50000
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft/includes/libft.h"
# include <stdio.h> //////////////////////////////////

int		get_next_line(const int fd, char **line);
int		get_endl_index(char *s);

#endif
