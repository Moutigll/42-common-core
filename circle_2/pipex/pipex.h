/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:36:41 by ele-lean          #+#    #+#             */
/*   Updated: 2024/11/25 17:39:45 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

#include "printf.h"

typedef struct s_pipex
{
	int		in_fd;
	int		out_fd;
	int		pipe_fd[2];
	int		cmd_count;
	char	**cmd_paths;
	char	***cmd_args;
	int		*pids;
	int		here_doc;
}	t_pipex;

void	ft_init_pipex(t_pipex *pipex);
void	clean_pipex(t_pipex *pipex, char *error, int exit_status);