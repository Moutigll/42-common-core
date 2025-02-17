/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:21:25 by ele-lean          #+#    #+#             */
/*   Updated: 2025/02/17 18:49:35 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

static void	exit_child(t_philo_bonus *philo, int exit_code, int mode)
{
	int	i;

	i = 0;
	while (i < philo->data->philo_count)
	{
		if (mode == 1)
			sem_post(philo->data->sem_death);
		i++;
	}
	sem_close(philo->data->sem_forks);
	sem_close(philo->data->sem_write);
	sem_close(philo->data->sem_death);
	free(philo->data->pids);
	free(philo);
	exit(exit_code);
}

void	*monitor_philosopher(void *arg)
{
	t_philo_bonus	*philo;

	philo = (t_philo_bonus *)arg;
	while (1)
	{
		sem_wait(philo->data->sem_death_check);
		if (get_time_in_ms() - philo->last_meal > philo->data->time_to_die)
		{
			print_action_bonus(philo, "died");
			sem_post(philo->data->sem_death);
			exit_child(philo, 1, 1);
		}
		sem_post(philo->data->sem_death_check);
		usleep(1000);
	}
	return (NULL);
}

static void	philosopher_think_and_eat(t_philo_bonus *philo)
{
	print_action_bonus(philo, "is thinking");
	sem_wait(philo->data->max_eat);
	sem_wait(philo->data->sem_forks);
	print_action_bonus(philo, "has taken a fork");
	sem_wait(philo->data->sem_forks);
	print_action_bonus(philo, "has taken a fork");
	sem_post(philo->data->max_eat);
	sem_wait(philo->data->sem_death_check);
	print_action_bonus(philo, "is eating");
	philo->eat_count++;
	philo->last_meal = get_time_in_ms();
	sem_post(philo->data->sem_death_check);
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
		exit_child(philo, 1, 1);
	pthread_detach(monitor);
	while (data->must_eat_count == -1
		|| philo->eat_count < data->must_eat_count)
	{
		philosopher_think_and_eat(philo);
		print_action_bonus(philo, "is sleeping");
		usleep(data->time_to_sleep * 1000);
	}
	sem_post(data->sem_death);
	exit_child(philo, 0, 0);
}

int	wait_processes(t_data *data)
{
	int		i;

	sem_wait(data->sem_death);
	if (data->must_eat_count != -1)
	{
		i = 0;
		while (i < data->philo_count - 1)
		{
			sem_wait(data->sem_death);
			i++;
		}
	}
	i = 0;
	while (i < data->philo_count)
	{
		kill(data->pids[i], SIGTERM);
		i++;
	}
	return (0);
}
