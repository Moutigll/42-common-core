/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:38:00 by ele-lean          #+#    #+#             */
/*   Updated: 2024/12/17 13:06:16 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_files_for_here_doc(int argc, char **argv, t_pipex *pipex)
{
	pipex->out_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (pipex->out_fd == -1)
		clean_pipex(pipex, "Failed to open outfile", 1);
}

void	handle_urandom(t_pipex *pipex)
{
	char	buffer[1024];
	ssize_t	bytes_read;
	int		temp_fd;

	pipex->in_fd = open("/dev/urandom", O_RDONLY);
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

void	open_input_file(t_pipex *pipex, char *filename)
{
	pipex->in_fd = open(filename, O_RDONLY);
	if (pipex->in_fd == -1)
		clean_pipex(pipex, "Failed to open infile", 1);
}

void	open_output_file(int argc, char **argv, t_pipex *pipex)
{
	pipex->out_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->out_fd == -1)
		clean_pipex(pipex, "Failed to open outfile", 1);
}

void	check_args(int argc, char **argv, t_pipex *pipex)
{
	if (argc < 5)
		clean_pipex(pipex, "Not enough arguments", 1);
	if (ft_strcmp(argv[1], "here_doc") == 0)
	{
		pipex->here_doc = 1;
		if (argc < 6)
			clean_pipex(pipex, "Not enough arguments for here_doc", 1);
		open_files_for_here_doc(argc, argv, pipex);
	}
	else
	{
		if (ft_strcmp(argv[1], "/dev/urandom") == 0)
			handle_urandom(pipex);
		else
			open_input_file(pipex, argv[1]);
		open_output_file(argc, argv, pipex);
	}
}
