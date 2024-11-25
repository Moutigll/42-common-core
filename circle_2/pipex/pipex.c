/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:36:20 by ele-lean          #+#    #+#             */
/*   Updated: 2024/11/25 15:55:42 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_init_pipex(t_pipex *pipex)
{
	pipex->in_fd = -1;
	pipex->out_fd = -1;
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
			int j = 0;
			while (pipex->cmd_args[i][j])
				free(pipex->cmd_args[i][j++]);
			free(pipex->cmd_args[i]);
			i++;
		}
		free(pipex->cmd_args);
	}
	if (pipex->cmd_paths)
	{
		i = 0;
		while (pipex->cmd_paths[i])
			free(pipex->cmd_paths[i++]);
		free(pipex->cmd_paths);
	}
	if (pipex->in_fd != -1)
		close(pipex->in_fd);
	if (pipex->out_fd != -1)
		close(pipex->out_fd);
	if (error)
		perror(error);
	exit(exit_status);
}

void	check_args(int argc, char **argv, t_pipex *pipex)
{
	char	buffer[1024];
	ssize_t	bytes_read;
	int		temp_fd;

	if (argc < 5)
		clean_pipex(pipex, "Not enough arguments", 1);
	if (ft_strcmp(argv[1], "here_doc") == 0)
	{
		pipex->here_doc = 1;
		if (argc < 6)
			clean_pipex(pipex, "Not enough arguments for here_doc", 1);
		pipex->out_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (pipex->out_fd == -1)
			clean_pipex(pipex, "Failed to open outfile", 1);
	}
	else
	{
		if (ft_strcmp(argv[1], "/dev/urandom") == 0)
		{
			pipex->in_fd = open(argv[1], O_RDONLY);
			if (pipex->in_fd == -1)
				clean_pipex(pipex, "Failed to open /dev/urandom", 1);
			bytes_read = read(pipex->in_fd, buffer, sizeof(buffer));
			if (bytes_read == -1)
				clean_pipex(pipex, "Failed to read from /dev/urandom", 1);
			temp_fd = open("tempfile.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
			if (temp_fd == -1)
				clean_pipex(pipex, "Failed to create temporary file", 1);
			write(temp_fd, buffer, bytes_read);
			close(pipex->in_fd);
			pipex->in_fd = temp_fd;
		}
		else
			pipex->in_fd = open(argv[1], O_RDONLY);
		if (pipex->in_fd == -1)
			clean_pipex(pipex, "Failed to open infile", 1);
		pipex->out_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (pipex->out_fd == -1)
			clean_pipex(pipex, "Failed to open outfile", 1);
	}
}

void	handle_here_doc(char *delimiter, t_pipex *pipex)
{
	char	*line;
	int		pipe_fd[2];

	if (pipe(pipe_fd) == -1)
		clean_pipex(pipex, "Pipe error", 1);
	while (1)
	{
		write(1, "here_doc> ", 10);
		line = get_next_line(0);
		if (!line || ft_strcmp(line, delimiter) == 0)
			break ;
		write(pipe_fd[1], line, ft_strlen(line));
		free(line);
	}
	if (line)
		free(line);
	close(pipe_fd[1]);
	pipex->in_fd = pipe_fd[0];
}

void	get_path(t_pipex *pipex, char **envp)
{
	char	*path;

	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
		{
			path = ft_strdup(*envp + 5);
			if (!path)
				clean_pipex(pipex, "Failed to copy PATH", 1);
			pipex->cmd_paths = ft_split(path, ':');
			free(path);
			if (!pipex->cmd_paths)
				clean_pipex(pipex, "Failed to split PATH", 1);
			return ;
		}
		envp++;
	}
	clean_pipex(pipex, "PATH not found in environment", 1);
}

void	ft_parse_cmds(t_pipex *pipex, char **argv, int argc)
{
	int		i;
	int		j;
	char	*tmp;
	char	*full_cmd;

	pipex->cmd_count = argc - 3 - pipex->here_doc;
	pipex->cmd_args = malloc(sizeof(char **) * (pipex->cmd_count + 1));
	if (!pipex->cmd_args)
		clean_pipex(pipex, "Failed to allocate memory for commands", 1);
	i = 0;
	while (i < pipex->cmd_count)
	{
		pipex->cmd_args[i] = ft_split(argv[i + 2 + pipex->here_doc], ' ');
		if (!pipex->cmd_args[i])
			clean_pipex(pipex, "Failed to split command", 1);
		j = 0;
		full_cmd = NULL;
		while (pipex->cmd_paths[j])
		{
			tmp = ft_strjoin(pipex->cmd_paths[j], "/");
			if (!tmp)
				clean_pipex(pipex, "Memory allocation error", 1);
			full_cmd = ft_strjoin(tmp, pipex->cmd_args[i][0]);
			free(tmp);
			if (!full_cmd)
				clean_pipex(pipex, "Memory allocation error", 1);
			if (access(full_cmd, X_OK) == 0)
				break ;
			free(full_cmd);
			full_cmd = NULL;
			j++;
		}
		if (!full_cmd)
			clean_pipex(pipex, "Command not found in PATH", 127);
		free(pipex->cmd_args[i][0]);
		pipex->cmd_args[i][0] = full_cmd;
		i++;
	}
	pipex->cmd_args[i] = NULL;
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
		execve(pipex->cmd_args[i][0], pipex->cmd_args[i], envp);
		clean_pipex(pipex, "Failed to execute command", 127);
	}
	else
	{
		close(pipe_fd[1]);
		pipex->pipe_fd[0] = pipe_fd[0];
		waitpid(pid, NULL, 0);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		i;

	ft_init_pipex(&pipex);
	check_args(argc, argv, &pipex);
	get_path(&pipex, envp);
	if (pipex.here_doc)
		handle_here_doc(argv[2], &pipex);
	ft_parse_cmds(&pipex, argv, argc);
	i = 0;
	while (i < pipex.cmd_count)
	{
		exec_cmd(&pipex, i, envp);
		i++;
	}
	clean_pipex(&pipex, NULL, 0);
	return (0);
}
