/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:26:13 by ele-lean          #+#    #+#             */
/*   Updated: 2024/12/01 19:12:12 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <unistd.h>
#include <stdlib.h>

typedef struct s_list
{
	char			*buffer;
	struct s_list	*next;
}						t_list;

typedef struct s_newline
{
	int	size;
	int	buffers;
}		t_newline;

void	ft_lstaddd_back(t_list **list, char *buffer, int fd);
char	*get_next_line(int fd);
t_list	*ft_lstlast(t_list *lst);
void	freegnl_list(t_list **list, t_list *clean_node, char *buf);