/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:36:20 by ele-lean          #+#    #+#             */
/*   Updated: 2024/11/21 16:41:31 by ele-lean         ###   ########.fr       */
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
	pipex->pids = NULL;
	pipex->here_doc = 0;
}

void	check_args(int argc, char **argv, t_pipex *pipex)
{
	if (argc < 5)
	{
		perror("Not enough arguments");
		exit(1);
	}
	if (strcmp(argv[1], "here_doc") == 0)
	{
		pipex->here_doc = 1;
		if (argc < 6)
		{
			perror("Not enough arguments for here_doc");
			exit(1);
		}
		pipex->out_fd = open(argv[argc - 1],
				O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (pipex->out_fd == -1)
		{
			perror("Failed to open output file");
			exit(1);
		}
	}
	else
	{
		if (access(argv[1], R_OK) == -1)
		{
			perror("Can't read infile");
			exit(1);
		}
		pipex->in_fd = open(argv[1], O_RDONLY);
		if (pipex->in_fd == -1)
		{
			perror("Failed to open infile");
			exit(1);
		}
		if (access(argv[argc - 1], W_OK) == -1)
		{
			perror("Can't write to outfile");
			exit(1);
		}
		pipex->out_fd = open(argv[argc - 1],
				O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (pipex->out_fd == -1)
		{
			perror("Failed to open outfile");
			exit(1);
		}
	}
}

void	handle_here_doc(char *delimiter, t_pipex *pipex)
{
	char	*line;
	int		pipe_fd[2];

	if (pipe(pipe_fd) == -1)
	{
		perror("Pipe error");
		exit(1);
	}
	while (1)
	{
		write(1, "here_doc> ", 10);
		line = get_next_line(0);
		if (!line || strcmp(line, delimiter) == 0)
			break ;
		write(pipe_fd[1], line, strlen(line));
		free(line);
	}
	free(line);
	close(pipe_fd[1]);
	pipex->in_fd = pipe_fd[0];
}

int	main(int argc, char **argv)
{
	t_pipex	*pipex;

	pipex = (t_pipex *)malloc(sizeof(t_pipex));
	if (!pipex)
	{
		perror("Failed to allocate memory");
		exit(1);
	}
	ft_init_pipex(pipex);
	check_args(argc, argv, pipex);
	if (pipex->here_doc)
		handle_here_doc(argv[2], pipex);
	return (0);
}
