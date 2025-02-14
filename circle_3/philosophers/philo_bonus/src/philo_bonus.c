/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:21:25 by ele-lean          #+#    #+#             */
/*   Updated: 2025/02/14 18:43:35 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	*monitor_philosopher(void *arg)
{
	t_philo_bonus	*philo;

	philo = (t_philo_bonus *)arg;
	while (1)
	{
		if (get_time_in_ms() - philo->last_meal > philo->data->time_to_die)
		{
			print_action_bonus(philo, "died");
			exit(1);
		}
		usleep(1000);
	}
	return (NULL);
}

void	philosopher_routine(t_data *data, int index)
{
	t_philo_bonus	*philo;
	pthread_t		monitor;

	philo = malloc(sizeof(t_philo_bonus));
	if (!philo)
		exit(1);
	philo->id = index + 1;
	philo->eat_count = 0;
	philo->last_meal = get_time_in_ms();
	philo->data = data;
	if (pthread_create(&monitor, NULL, monitor_philosopher, philo) != 0)
		exit(1);
	pthread_detach(monitor);
	while (1)
	{
		if (data->must_eat_count != -1 && philo->eat_count >= data->must_eat_count)
			break ;
		print_action_bonus(philo, "is thinking");
		sem_wait(data->sem_forks);
		print_action_bonus(philo, "has taken a fork");
		sem_wait(data->sem_forks);
		print_action_bonus(philo, "has taken a fork");
		philo->last_meal = get_time_in_ms();
		print_action_bonus(philo, "is eating");
		philo->eat_count++;
		usleep(data->time_to_eat * 1000);
		sem_post(data->sem_forks);
		sem_post(data->sem_forks);
		print_action_bonus(philo, "is sleeping");
		usleep(data->time_to_sleep * 1000);
	}
	free(philo);
	exit(0);
}

int	wait_processes(t_data *data)
{
	int		i;
	int		status;
	pid_t	pid;

	i = 0;
	while (i < data->philo_count)
	{
		pid = waitpid(data->pids[i], &status, 0);
		if (pid < 0)
			return (printf("Error: waitpid failed\n"), 1);
		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		{
			i = 0;
			while (i < data->philo_count)
			{
				kill(data->pids[i], 9);
				i++;
			}
			break ;
		}
		i++;
	}
	return (0);
}
