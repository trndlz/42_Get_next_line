/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 10:45:13 by tmervin           #+#    #+#             */
/*   Updated: 2018/04/16 20:45:52 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					get_endl_index(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

static t_list		*get_fd(const int fd, t_list **tamp)
{
	t_list *ret;
	size_t sfd;

	sfd = (size_t)fd;
	ret = *tamp;
	while (ret)
	{
		if (ret->content_size == sfd)
			return (ret);
		ret = ret->next;
	}
	if (!(ret = ft_lstnew("\0", fd)))
		return (NULL);
	ft_lstadd(tamp, ret);
	return (ret);
}

char				**reader(const int fd, char **line)
{
	int		ret;
	char	*tmp;
	char	b[BUFF_SIZE + 1];

	while ((ret = read(fd, &b, BUFF_SIZE)))
	{
		b[ret] = '\0';
		tmp = *line;
		*line = ft_strjoin(*line, b);
		free(tmp);
		if (ft_strchr(*line, '\n'))
			break ;
	}
	return (line);
}

char				*tamp_cutter(char *tempo, char **line)
{
	char *tmp;

	if (ft_strchr(*line, '\n'))
	{
		tmp = tempo;
		tempo = ft_strchr(*line, '\n');
		tempo++;
		tempo = ft_strdup(tempo);
		free(tmp);
	}
	else
		tempo = "\0";
	return (tempo);
}

int					get_next_line(const int fd, char **line)
{
	char			b[BUFF_SIZE + 1];
	char			*tmp;
	static t_list	*stock = NULL;
	t_list			*tamp;

	if (fd < 0 || line == NULL || read(fd, &b, 0) < 0)
		return (-1);
	if (!(*line = ft_strnew(1)))
		return (-1);
	reader(fd, line);
	if (!(tamp = get_fd(fd, &stock)))
		return (-1);
	if (tamp->content)
	{
		tmp = *line;
		*line = ft_strjoin(tamp->content, *line);
		free(tmp);
	}
	tmp = tamp->content;
	if (!**line && !*tmp)
		return (0);
	tamp->content = tamp_cutter(tamp->content, line);
	tmp = *line;
	*line = ft_strsub(*line, 0, get_endl_index(*line));
	free(tmp);
	return (1);
}
