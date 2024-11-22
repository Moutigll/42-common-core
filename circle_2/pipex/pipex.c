/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:36:20 by ele-lean          #+#    #+#             */
/*   Updated: 2024/11/22 19:15:00 by ele-lean         ###   ########.fr       */
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

void	ft_clean_pipex(t_pipex *pipex)
{
	int	i;
	int	j;

	if (pipex->cmd_args)
	{
		i = 0;
		while (i < pipex->cmd_count)
		{
			j = 0;
			while (pipex->cmd_args[i][j])
			{
				free(pipex->cmd_args[i][j]);
				j++;
			}
			i++;
		}
		free(pipex->cmd_args);
	}
	if (pipex->cmd_paths)
	{
		i = 0;
		while (pipex->cmd_paths[i])
		{
			free(pipex->cmd_paths[i]);
			i++;
		}
		free(pipex->cmd_paths);
	}
	if (pipex->in_fd != -1)
		close(pipex->in_fd);
	if (pipex->out_fd != -1)
		close(pipex->out_fd);
	free(pipex);
}

void	check_args(int argc, char **argv, t_pipex *pipex)
{
	if (argc < 5)
	{
		perror("Not enough arguments");
		exit(1);
	}
	if (ft_strcmp(argv[1], "here_doc") == 0)
	{
		pipex->here_doc = 1;
		if (argc < 6)
		{
			perror("Not enough arguments for here_doc");
			exit(1);
		}
		pipex->out_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (pipex->out_fd == -1)
		{
			perror("Failed to open output file");
			exit(1);
		}
	}
	else
	{
		pipex->in_fd = open(argv[1], O_RDONLY);
		if (pipex->in_fd == -1)
		{
			perror("Failed to open infile");
			exit(1);
		}
		pipex->out_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
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
		if (!line || ft_strcmp(line, delimiter) == 0)
			break ;
		write(pipe_fd[1], line, ft_strlen(line));
		free(line);
	}
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
			{
				perror("Failed to allocate memory for PATH");
				exit(1);
			}
			pipex->cmd_paths = ft_split(path, ':');
			free(path);
			if (!pipex->cmd_paths)
			{
				perror("Failed to split PATH");
				exit(1);
			}
			return ;
		}
		envp++;
	}
	perror("PATH variable not found in environment");
	exit(1);
}

void	ft_parse_cmds(t_pipex *pipex, char **argv, int argc)
{
	int		i;
	int		j;
	char	*cmd;
	char	*full_cmd;

	pipex->cmd_count = argc - 3 - pipex->here_doc;
	pipex->cmd_args = malloc(sizeof(char **) * (pipex->cmd_count + 1));
	if (!pipex->cmd_args)
	{
		perror("Failed to allocate memory for commands");
		exit(1);
	}
	i = 0;
	while (i < pipex->cmd_count)
	{
		cmd = argv[i + 2 + pipex->here_doc];
		pipex->cmd_args[i] = ft_split(cmd, ' ');
		if (!pipex->cmd_args[i])
		{
			perror("Failed to split command arguments");
			ft_clean_pipex(pipex);
			exit(1);
		}
		j = 0;
		while (pipex->cmd_paths[j])
		{
			full_cmd = ft_strjoin(pipex->cmd_paths[j], "/");
			full_cmd = ft_strjoin(full_cmd, pipex->cmd_args[i][0]);
			if (access(full_cmd, X_OK) == 0)
				break ;
			free(full_cmd);
			j++;
		}
		free(full_cmd);
		i++;
	}
}

void	exec_com(t_pipex *pipex, int i)
{}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;
	int		i;

	pipex = (t_pipex *)malloc(sizeof(t_pipex));
	if (!pipex)
	{
		perror("Failed to allocate memory");
		exit(1);
	}
	ft_init_pipex(pipex);
	check_args(argc, argv, pipex);
	get_path(pipex, envp);
	if (pipex->here_doc)
		handle_here_doc(argv[2], pipex);
	ft_parse_cmds(pipex, argv, argc);
	i = 0;
	while (i < pipex->cmd_count)
	{
		exec_com(pipex, i);
	}
	ft_clean_pipex(pipex);
	return (0);
}
