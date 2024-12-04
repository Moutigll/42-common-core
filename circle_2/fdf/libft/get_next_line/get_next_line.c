/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:25:41 by ele-lean          #+#    #+#             */
/*   Updated: 2024/12/01 19:12:29 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4096
#endif

int	find_newline(t_list *list, t_newline *line)
{
	int	i;

	if (!list)
		return (0);
	line->size = 0;
	line->buffers = 0;
	while (list)
	{
		i = 0;
		line->buffers++;
		while (list->buffer[i] && i < BUFFER_SIZE)
		{
			if (list->buffer[i] == '\n')
				return (1);
			i++;
			line->size++;
		}
		list = list->next;
	}
	return (0);
}

void	create_list(t_list **list, int fd, t_newline *line)
{
	char	*buffer;
	int		size;

	while (!find_newline(list[fd], line))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return ;
		size = read(fd, buffer, BUFFER_SIZE);
		if (!size)
		{
			free(buffer);
			return ;
		}
		buffer[size] = '\0';
		ft_lstaddd_back(list, buffer, fd);
	}
}

char	*extract_line(t_list *list, t_newline *line)
{
	char	*char_line;
	int		i;
	int		k;

	char_line = malloc(sizeof(char) * (line->size + 2));
	if (!char_line || !list)
		return (NULL);
	k = 0;
	while (list)
	{
		i = 0;
		while (list->buffer[i])
		{
			if (list->buffer[i] == '\n')
			{
				char_line[k++] = '\n';
				char_line[k] = '\0';
				return (char_line);
			}
			char_line[k++] = list->buffer[i++];
		}
		list = list->next;
	}
	char_line[k] = '\0';
	return (char_line);
}

void	clean_list(t_list **list)
{
	t_list	*last_node;
	t_list	*clean_node;
	int		i;
	int		k;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_list));
	if (!buf || !clean_node)
		return ;
	last_node = ft_lstlast(*list);
	i = 0;
	k = 0;
	while (last_node->buffer[i] && last_node->buffer[i] != '\n')
		i++;
	while (last_node->buffer[i] && last_node->buffer[++i])
		buf[k++] = last_node->buffer[i];
	buf[k] = '\0';
	clean_node->buffer = buf;
	clean_node->next = NULL;
	freegnl_list(list, clean_node, buf);
}

char	*get_next_line(int fd)
{
	static t_list	*list[4096];
	char			*next_line;
	t_newline		*line;

	if (fd < 0 || fd > 4095 || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc(sizeof(t_newline));
	if (!line)
		return (NULL);
	create_list(list, fd, line);
	if (!list[fd])
	{
		free(line);
		return (NULL);
	}
	next_line = extract_line(list[fd], line);
	clean_list(&list[fd]);
	free(line);
	return (next_line);
}
