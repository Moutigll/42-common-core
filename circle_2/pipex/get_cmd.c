/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:25:30 by ele-lean          #+#    #+#             */
/*   Updated: 2024/12/17 14:12:18 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

int	ft_str_is_space(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

char	*find_cmd_in_paths(t_pipex *pipex, char *cmd)
{
	int		j;
	char	*tmp;
	char	*full_cmd;

	j = 0;
	full_cmd = NULL;
	while (pipex->cmd_paths[j])
	{
		tmp = ft_strjoin(pipex->cmd_paths[j], "/");
		if (!tmp)
			clean_pipex(pipex, "Memory allocation error", 1);
		full_cmd = ft_strjoin(tmp, cmd);
		free(tmp);
		if (!full_cmd)
			clean_pipex(pipex, "Memory allocation error", 1);
		if (access(full_cmd, X_OK) == 0)
			break ;
		free(full_cmd);
		full_cmd = NULL;
		j++;
	}
	return (full_cmd);
}

char	*get_cmd(t_pipex *pipex, char **argv, int i)
{
	char	*full_cmd;

	pipex->cmd_args[i] = ft_split(argv[i + 2 + pipex->here_doc], ' ');
	if (!pipex->cmd_args[i] || !pipex->cmd_args[i][0]
		|| ft_str_is_space(pipex->cmd_args[i][0]))
		return (NULL);
	full_cmd = ft_strdup(pipex->cmd_args[i][0]);
	if (full_cmd[0] == '/' || full_cmd[0] == '.')
	{
		if (access(full_cmd, X_OK) == 0)
			return (full_cmd);
	}
	free(full_cmd);
	full_cmd = find_cmd_in_paths(pipex, pipex->cmd_args[i][0]);
	return (full_cmd);
}

void	ft_parse_cmds(t_pipex *pipex, char **argv, int argc)
{
	int		i;
	char	*full_cmd;

	pipex->cmd_count = argc - 3 - pipex->here_doc;
	pipex->cmd_args = malloc(sizeof(char **) * (pipex->cmd_count + 1));
	if (!pipex->cmd_args)
		clean_pipex(pipex, "Failed to allocate memory for commands", 1);
	i = 0;
	while (i < pipex->cmd_count)
	{
		full_cmd = get_cmd(pipex, argv, i);
		if (!full_cmd)
		{
			perror("Command not found in PATH");
			free(pipex->cmd_args[i][0]);
			pipex->cmd_args[i][0] = NULL;
		}
		else
		{
			free(pipex->cmd_args[i][0]);
			pipex->cmd_args[i][0] = full_cmd;
		}
		i++;
	}
	pipex->cmd_args[i] = NULL;
}
