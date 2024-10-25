/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:25:41 by ele-lean          #+#    #+#             */
/*   Updated: 2024/10/25 19:08:52 by ele-lean         ###   ########.fr       */
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

void	create_list(t_list *list, int fd, t_newline *line)
{
	char	*buffer;
	int		size;

	while (!find_newline(&list[fd], line))
	{
		buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
		size = read(fd, buffer, BUFFER_SIZE);
		if (!size)
		{
			free(buffer);
			return ;
		}
		buffer[size] = '\0';
		ft_lstadd_back(list, buffer, fd);
	}
}

char	get_line(t_list *list, t_newline *line)
{
	char	*char_line;
	int		i;
	int		c;

	line = malloc(sizeof(char) * line->size + 1);
	c = 0;
	while (list)
	{
		i = 0;
		while (list->buffer[i] && i < BUFFER_SIZE)
		{
			char_line[c] = list->buffer[i];
			if (list->buffer[i] == '\n')
				break ;
			i++;
			c++;
		}
		list = list->next;
	}
	char_line[c + 1] = '\0';
	return (char_line);
}

void	polish_list(t_list *list, t_newline *line)
{
	int		i;
	int		c;
	t_list	*temp;
	t_list	*start;

	start = list->next;
	i = 0;
	while (i < line->buffers - 1)
	{
		temp = start->next;
		free(start);
		start = temp;
		i++;
	}
	i = 0;
	while (start->buffer[i - 1] != '\n')
		i++;
	c = 0;
	while (start->buffer[i])
	{
		list->buffer[c] = start->buffer[i];
		i++;
		c++;
	}
	free(start);
	list->next = NULL;
}

char	*get_next_line(int fd)
{
	static t_list	*list[4096];
	char			*next_line;
	t_newline		*line;

	if (fd < 0 || fd > 4095 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	create_list(list, fd, line);
	if (list[fd] == NULL)
		return (NULL);
	next_line = get_line(list, line);
	polish_list(&list[fd], line);
	return (next_line);
}
