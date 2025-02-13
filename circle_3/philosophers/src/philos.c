/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:41:55 by ele-lean          #+#    #+#             */
/*   Updated: 2025/02/13 20:45:43 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_action(philo, "has taken a fork");
	pthread_mutex_lock(philo->right_fork);
	print_action(philo, "has taken a fork");
	return (0);
}

int	eat(t_philo *philo)
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

void	*routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;
	int		current_eat;

	philo = (t_philo *)arg;
	data = philo->data;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (1)
	{
		pthread_mutex_lock(&data->death_mutex);
		current_eat = philo->eat_count;
		if (data->someone_died || (data->must_eat_count != -1
				&& current_eat >= data->must_eat_count))
		{
			pthread_mutex_unlock(&data->death_mutex);
			break ;
		}
		pthread_mutex_unlock(&data->death_mutex);
		print_action(philo, "is thinking");
		if (take_forks(philo))
			break ;
		if (eat(philo))
			break ;
		print_action(philo, "is sleeping");
		usleep(data->time_to_sleep * 1000);
	}
	return (NULL);
}

int	check_philosopher_death(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->philo_count)
	{
		pthread_mutex_lock(&data->death_mutex);
		if (get_time_in_ms() - data->philosophers[i].last_meal > data->time_to_die)
		{
			print_action(&data->philosophers[i], "died");
			data->someone_died = 1;
			pthread_mutex_unlock(&data->death_mutex);
			return (1);
		}
		pthread_mutex_unlock(&data->death_mutex);
		i++;
	}
	return (0);
}

int	check_all_philosophers_eat(t_data *data)
{
	int		i;
	int		finished;

	if (data->must_eat_count == -1)
		return (0);
	finished = 1;
	i = 0;
	while (i < data->philo_count)
	{
		pthread_mutex_lock(&data->death_mutex);
		if (data->philosophers[i].eat_count < data->must_eat_count)
			finished = 0;
		pthread_mutex_unlock(&data->death_mutex);
		i++;
	}
	if (finished)
	{
		pthread_mutex_lock(&data->death_mutex);
		data->someone_died = 1;
		pthread_mutex_unlock(&data->death_mutex);
		return (1);
	}
	return (0);
}

void	*check_death(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (1)
	{
		if (data->philo_count == 1)
		{
			usleep(1000);
			continue ;
		}
		if (check_philosopher_death(data))
			return (NULL);
		if (check_all_philosophers_eat(data))
			return (NULL);
		usleep(1000);
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
	if (pthread_create(&death_checker, NULL, check_death, data))
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
