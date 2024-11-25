/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:36:41 by ele-lean          #+#    #+#             */
/*   Updated: 2024/11/25 19:47:43 by ele-lean         ###   ########.fr       */
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
void	get_path(t_pipex *pipex, char **envp);
void	ft_parse_cmds(t_pipex *pipex, char **argv, int argc);
void	check_args(int argc, char **argv, t_pipex *pipex);
void	exec_cmd(t_pipex *pipex, int i, char **envp);
