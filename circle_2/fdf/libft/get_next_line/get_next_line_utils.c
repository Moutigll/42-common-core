/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:25:58 by ele-lean          #+#    #+#             */
/*   Updated: 2024/12/01 19:12:22 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstaddd_back(t_list **list, char *buffer, int fd)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = ft_lstlast(list[fd]);
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	if (!last_node)
		list[fd] = new_node;
	else
		last_node->next = new_node;
	new_node->buffer = buffer;
	new_node->next = NULL;
}

void	freegnl_list(t_list **list, t_list *clean_node, char *buf)
{
	t_list	*tmp;

	if (NULL == *list)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->buffer);
		free(*list);
		*list = tmp;
	}
	*list = NULL;
	if (clean_node->buffer[0])
		*list = clean_node;
	else
	{
		free(buf);
		free(clean_node);
	}
}
