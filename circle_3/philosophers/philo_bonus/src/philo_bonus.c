/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutig <moutig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:21:25 by ele-lean          #+#    #+#             */
/*   Updated: 2025/02/16 23:33:42 by moutig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

static void	exit_child(t_philo_bonus *philo, int exit_code)
{
	sem_close(philo->data->sem_forks);
	sem_close(philo->data->sem_write);
	sem_close(philo->data->sem_death);
	free(philo->data->pids);
	free(philo);
	exit(exit_code);
}

static void	*monitor_philosopher(void *arg)
{
	t_philo_bonus	*philo;

	philo = (t_philo_bonus *)arg;
	while (1)
	{
		if (get_time_in_ms() - philo->last_meal > philo->data->time_to_die)
		{
			print_action_bonus(philo, "died");
			sem_post(philo->data->sem_death);
			exit_child(philo, 1);
		}
		usleep(1000);
	}
	return (NULL);
}

static void	philosopher_think_and_eat(t_philo_bonus *philo)
{
	print_action_bonus(philo, "is thinking");
	sem_wait(philo->data->sem_forks);
	print_action_bonus(philo, "has taken a fork");
	sem_wait(philo->data->sem_forks);
	print_action_bonus(philo, "has taken a fork");
	if (get_time_in_ms() - philo->last_meal > philo->data->time_to_die)
	{
		print_action_bonus(philo, "died");
		sem_post(philo->data->sem_death);
		exit_child(philo, 1);
	}
	philo->last_meal = get_time_in_ms();
	print_action_bonus(philo, "is eating");
	philo->eat_count++;
	usleep(philo->data->time_to_eat * 1000);
	sem_post(philo->data->sem_forks);
	sem_post(philo->data->sem_forks);
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
		exit_child(philo, 1);
	pthread_detach(monitor);
	while (data->must_eat_count == -1
		|| philo->eat_count < data->must_eat_count)
	{
		philosopher_think_and_eat(philo);
		print_action_bonus(philo, "is sleeping");
		usleep(data->time_to_sleep * 1000);
	}
	sem_post(data->sem_death);
	exit_child(philo, 0);
}

int	wait_processes(t_data *data)
{
	int		i;
	int		status;

	sem_wait(data->sem_death);
	i = 0;
	while (i < data->philo_count)
	{
		kill(data->pids[i], SIGTERM);
		i++;
	}
	i = 0;
	while (i < data->philo_count)
	{
		waitpid(data->pids[i], &status, 0);
		i++;
	}
	return (0);
}
