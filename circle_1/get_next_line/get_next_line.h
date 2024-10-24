/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:26:13 by ele-lean          #+#    #+#             */
/*   Updated: 2024/10/24 17:18:18 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <unistd.h>
#include <stdlib.h>

typedef struct s_list
{
	int				fd;
	int				index;
	char			*buffer;
	struct s_list	*next;
}						t_list;

t_list	*ft_lstnew(int fd, int index);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstiter(t_list *lst, int fd);
char	*get_next_line(int fd);