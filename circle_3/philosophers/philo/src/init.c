/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:45:18 by ele-lean          #+#    #+#             */
/*   Updated: 2025/02/13 20:15:08 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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

t_philo	*init_philosophers(t_data *data)
{
	t_philo	*philos;
	int		i;

	philos = malloc(sizeof(t_philo) * data->philo_count);
	if (!philos)
		return (printf("Error: malloc failed\n"), NULL);
	i = 0;
	while (i < data->philo_count)
	{
		philos[i].id = i + 1;
		philos[i].eat_count = 0;
		philos[i].last_meal = data->start_time;
		philos[i].data = data;
		philos[i].left_fork = &data->forks[i];
		philos[i].right_fork = &data->forks[(i + 1) % data->philo_count];
		i++;
	}
	return (philos);
}

int	init_simulation(t_data *data)
{
	int	i;

	data->someone_died = 0;
	data->start_time = get_time_in_ms();
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_count);
	if (!data->forks)
		return (printf("Error: malloc failed\n"), 1);
	i = 0;
	while (i < data->philo_count)
	{
		if (pthread_mutex_init(&data->forks[i], NULL))
			return (printf("Error: mutex init failed\n"), 1);
		i++;
	}
	if (pthread_mutex_init(&data->write_mutex, NULL)
		|| pthread_mutex_init(&data->death_mutex, NULL))
		return (printf("Error: mutex init failed\n"), 1);
	return (0);
}
