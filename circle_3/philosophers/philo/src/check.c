/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moutig <moutig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:10:13 by ele-lean          #+#    #+#             */
/*   Updated: 2025/02/19 00:28:50 by moutig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	check_philosopher_death(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_count)
	{
		pthread_mutex_lock(&data->death_mutex);
		if (get_time_in_ms() - data->philosophers[i].last_meal
			> data->time_to_die)
		{
			printf("%ld %d died\n", get_time_in_ms() - data->start_time,
				data->philosophers[i].id + 1);
			data->someone_died = 1;
			pthread_mutex_unlock(&data->death_mutex);
			return (1);
		}
		pthread_mutex_unlock(&data->death_mutex);
		i++;
	}
	return (0);
}

static int	check_all_philosophers_eat(t_data *data)
{
	int	i;
	int	finished;

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

void	*check(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (1)
	{
		if (check_philosopher_death(data))
			return (NULL);
		if (check_all_philosophers_eat(data))
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}
