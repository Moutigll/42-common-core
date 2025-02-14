/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:06:48 by ele-lean          #+#    #+#             */
/*   Updated: 2025/02/14 19:00:13 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

static void	cleanup(t_data *data)
{
	sem_close(data->sem_forks);
	sem_unlink("/forks");
	sem_close(data->sem_write);
	sem_unlink("/write");
	free(data->pids);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 5 || argc > 6)
		return (printf("Usage: ./philo <philos> <time_to_die> <time_to_eat> "
				"<time_to_sleep> [must_eat]\n"), 1);
	if (parse_args(&data, argc, argv))
		return (1);
	if (init_semaphores(&data))
		return (1);
	if (init_semaphores(&data))
		return (1);
	data.start_time = get_time_in_ms();
	if (init_processes(&data))
		return (1);
	if (wait_processes(&data))
		return (1);
	cleanup(&data);
	return (0);
}
