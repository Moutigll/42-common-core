/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:36:20 by ele-lean          #+#    #+#             */
/*   Updated: 2024/12/14 20:28:15 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_here_doc(char *delimiter, t_pipex *pipex)
{
	char	*line;
	int		pipe_fd[2];
	size_t	delimiter_len;

	delimiter_len = ft_strlen(delimiter);
	if (pipe(pipe_fd) == -1)
		clean_pipex(pipex, "Pipe error", 1);
	while (1)
	{
		write(1, "here_doc> ", 10);
		line = get_next_line(0);
		if (!line || (ft_strncmp(line, delimiter, delimiter_len) == 0
				&& line[delimiter_len] == '\n'
				&& line[delimiter_len + 1] == '\0'))
			break ;
		write(pipe_fd[1], line, ft_strlen(line));
		free(line);
	}
	if (line)
		free(line);
	close(pipe_fd[1]);
	pipex->in_fd = pipe_fd[0];
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		i;

	if (argc != 5)
	{
		ft_putstr_fd("Usage: ./pipex file1 cmd1 cmd2 file2\n", 2);
		return (1);
	}
	ft_init_pipex(&pipex);
	check_args(argc, argv, &pipex);
	get_path(&pipex, envp);
	ft_parse_cmds(&pipex, argv, argc);
	i = 0;
	while (i < pipex.cmd_count)
	{
		exec_cmd(&pipex, i, envp);
		i++;
	}
	clean_pipex(&pipex, NULL, -1);
	return (0);
}
