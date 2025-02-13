/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:06:48 by ele-lean          #+#    #+#             */
/*   Updated: 2025/02/13 18:51:35 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	cleanup(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_count)
		pthread_mutex_destroy(&data->forks[i++]);
	pthread_mutex_destroy(&data->write_mutex);
	pthread_mutex_destroy(&data->death_mutex);
	free(data->forks);
	free(data->philosophers);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 5 || argc > 6)
		return (printf("Usage: ./philo <philos> <time_to_die> <time_to_eat> "
				"<time_to_sleep> [must_eat]\n"), 1);
	if (parse_args(&data, argc, argv))
		return (1);
	if (init_simulation(&data))
		return (1);
	if (start_simulation(&data))
		return (1);
	cleanup(&data);
	return (0);
}
