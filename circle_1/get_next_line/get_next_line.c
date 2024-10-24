/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:25:41 by ele-lean          #+#    #+#             */
/*   Updated: 2024/10/24 17:20:48 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4096
#endif

char	*get_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static t_list	*fd_list = NULL;
	t_list			*current_fd;
	char			buffer[BUFFER_SIZE + 1];
	char			*line;
	int				bytes_read;

	current_fd = ft_lstiter(fd_list, fd);
	if (!current_fd)
	{
		current_fd = ft_lstnew(fd, 0);
		ft_lstadd_back(&fd_list, current_fd);
	}
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
		return (NULL);
	buffer[bytes_read] = '\0';
	line = get_line(buffer);
	return (line);
}
