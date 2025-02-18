/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutig <moutig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:41:55 by ele-lean          #+#    #+#             */
/*   Updated: 2025/02/19 00:37:25 by moutig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	take_forks(t_philo *philo)
{
	if (philo->data->philo_count == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		print_action(philo, "has taken a fork");
		usleep(philo->data->time_to_die * 1000);
		pthread_mutex_unlock(philo->left_fork);
		return (1);
	}
	pthread_mutex_lock(philo->right_fork);
	print_action(philo, "has taken a fork");
	pthread_mutex_lock(philo->left_fork);
		print_action(philo, "has taken a fork");

	return (0);
}

static int	eat(t_philo *philo)
{
	print_action(philo, "is eating");
	pthread_mutex_lock(&philo->data->death_mutex);
	philo->last_meal = get_time_in_ms();
	philo->eat_count++;
	pthread_mutex_unlock(&philo->data->death_mutex);
	usleep(philo->data->time_to_eat * 1000);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (0);
}

static void	*routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	if (philo->id % 2 == 0)
		usleep(100);
	while (1)
	{
		pthread_mutex_lock(&data->death_mutex);
		if (data->someone_died || (data->must_eat_count != -1
				&& philo->eat_count >= data->must_eat_count))
		{
			pthread_mutex_unlock(&data->death_mutex);
			break ;
		}
		pthread_mutex_unlock(&data->death_mutex);
		print_action(philo, "is thinking");
		if (take_forks(philo) || eat(philo))
			break ;
		print_action(philo, "is sleeping");
		usleep(data->time_to_sleep * 1000);
	}
	return (NULL);
}

int	start_simulation(t_data *data)
{
	int			i;
	pthread_t	death_checker;

	data->philosophers = init_philosophers(data);
	if (!data->philosophers)
		return (1);
	if (pthread_create(&death_checker, NULL, check, data))
		return (printf("Error: thread creation failed\n"), 1);
	i = 0;
	while (i < data->philo_count)
	{
		if (pthread_create(&data->philosophers[i].thread, NULL, routine,
				&data->philosophers[i]))
			return (printf("Error: thread creation failed\n"), 1);
		i++;
	}
	pthread_join(death_checker, NULL);
	i = 0;
	while (i < data->philo_count)
	{
		pthread_join(data->philosophers[i].thread, NULL);
		i++;
	}
	return (0);
}
