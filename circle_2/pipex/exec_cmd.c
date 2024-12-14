/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:47:26 by ele-lean          #+#    #+#             */
/*   Updated: 2024/12/14 20:57:14 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_child_process(t_pipex *pipex, int i, int *pipe_fd, char **envp)
{
	if (i == 0)
		dup2(pipex->in_fd, STDIN_FILENO);
	else
		dup2(pipex->pipe_fd[0], STDIN_FILENO);
	if (i == pipex->cmd_count - 1)
		dup2(pipex->out_fd, STDOUT_FILENO);
	else
		dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close(pipex->in_fd);
	close(pipex->out_fd);
	if (pipex->cmd_args[i] && pipex->cmd_args[i][0])
	{
		if (access(pipex->cmd_args[i][0], X_OK) == 0)
			execve(pipex->cmd_args[i][0], pipex->cmd_args[i], envp);
		else
			perror("Failed to execute command");
	}
	clean_pipex(pipex, NULL, 127);
}

void	exec_cmd(t_pipex *pipex, int i, char **envp)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (pipe(pipe_fd) == -1)
		return ;
	pid = fork();
	if (pid == -1)
		return ;
	if (pid == 0)
		handle_child_process(pipex, i, pipe_fd, envp);
	else
	{
		close(pipe_fd[1]);
		if (i > 0)
			close(pipex->pipe_fd[0]);
		pipex->pipe_fd[0] = pipe_fd[0];
		waitpid(pid, NULL, 0);
	}
}
