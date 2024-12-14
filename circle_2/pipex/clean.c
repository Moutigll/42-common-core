/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:37:02 by ele-lean          #+#    #+#             */
/*   Updated: 2024/12/14 20:52:02 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_init_pipex(t_pipex *pipex)
{
	pipex->in_fd = -1;
	pipex->out_fd = -1;
	pipex->pipe_fd[0] = -1;
	pipex->cmd_paths = NULL;
	pipex->cmd_args = NULL;
	pipex->cmd_count = 0;
	pipex->here_doc = 0;
}

void	clean_pipex(t_pipex *pipex, char *error, int exit_status)
{
	int	i;

	if (pipex->cmd_args)
	{
		i = 0;
		while (i < pipex->cmd_count && pipex->cmd_args[i])
		{
			free_tab((void **)pipex->cmd_args[i]);
			i++;
		}
		free(pipex->cmd_args);
	}
	if (pipex->cmd_paths)
		free_tab((void **)pipex->cmd_paths);
	if (pipex->in_fd != -1)
		close(pipex->in_fd);
	if (pipex->out_fd != -1)
		close(pipex->out_fd);
	if (pipex->pipe_fd[0] != -1)
		close(pipex->pipe_fd[0]);
	if (error)
		perror(error);
	if (exit_status != -1)
		exit(exit_status);
}
