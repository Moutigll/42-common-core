/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutig <moutig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:45:18 by ele-lean          #+#    #+#             */
/*   Updated: 2025/02/16 22:12:08 by moutig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

int	parse_args(t_data *data, int argc, char **argv)
{
	if (!is_positive_number(argv[1]) || !is_positive_number(argv[2])
		|| !is_positive_number(argv[3]) || !is_positive_number(argv[4])
		|| (argc == 6 && !is_positive_number(argv[5])))
	{
		printf("Error: Arguments must be positive numbers\n");
		return (1);
	}
	data->philo_count = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->must_eat_count = ft_atoi(argv[5]);
	else
		data->must_eat_count = -1;
	if (data->philo_count < 1 || data->time_to_die < 1 || data->time_to_eat < 1
		|| data->time_to_sleep < 1 || (argc == 6 && data->must_eat_count < 1))
	{
		printf("Error: Invalid argument values\n");
		return (1);
	}
	return (0);
}

int	init_semaphores(t_data *data)
{
	data->sem_forks = sem_open("/forks", O_CREAT, 0644, data->philo_count);
	if (data->sem_forks == SEM_FAILED)
	{
		printf("Error: sem_open failed for forks\n");
		return (1);
	}
	data->sem_write = sem_open("/write", O_CREAT, 0644, 1);
	if (data->sem_write == SEM_FAILED)
	{
		sem_close(data->sem_forks);
		sem_unlink("/forks");
		printf("Error: sem_open failed for write\n");
		return (1);
	}
	data->sem_death = sem_open("/death", O_CREAT, 0644, 0);
	if (data->sem_death == SEM_FAILED)
	{
		sem_close(data->sem_forks);
		sem_unlink("/forks");
		sem_close(data->sem_write);
		sem_unlink("/write");
		printf("Error: sem_open failed for death\n");
		return (1);
	}
	return (0);
}

int	init_processes(t_data *data)
{
	int		i;
	pid_t	pid;

	data->pids = malloc(sizeof(pid_t) * data->philo_count);
	if (!data->pids)
	{
		printf("Error: malloc failed for pids\n");
		return (1);
	}
	i = 0;
	while (i < data->philo_count)
	{
		pid = fork();
		if (pid < 0)
			return (printf("Error: fork failed\n"), 1);
		if (pid == 0)
		{
			philosopher_routine(data, i);
			exit(0);
		}
		else
			data->pids[i] = pid;
		i++;
	}
	return (0);
}
