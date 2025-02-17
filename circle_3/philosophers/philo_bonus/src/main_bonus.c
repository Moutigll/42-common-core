/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:06:48 by ele-lean          #+#    #+#             */
/*   Updated: 2025/02/17 18:50:06 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

static void	cleanup(t_data *data)
{
	sem_close(data->sem_forks);
	sem_unlink("/forks");
	sem_close(data->sem_write);
	sem_unlink("/write");
	sem_close(data->sem_death);
	sem_unlink("/death");
	sem_close(data->max_eat);
	sem_unlink("/max_eat");
	sem_close(data->sem_death_check);
	sem_unlink("/death_check");
	free(data->pids);
}

static int	init_sem2(t_data *data)
{
	data->max_eat = sem_open("/max_eat", O_CREAT, 0644, 1);
	if (data->max_eat == SEM_FAILED)
	{
		printf("Error: sem_open failed for max_eat\n");
		return (cleanup(data), 1);
	}
	data->sem_death_check = sem_open("/death_check", O_CREAT, 0644, 1);
	if (data->sem_death_check == SEM_FAILED)
	{
		printf("Error: sem_open failed for death_check\n");
		return (cleanup(data), 1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	sem_unlink("/forks");
	sem_unlink("/write");
	sem_unlink("/death");
	sem_unlink("/max_eat");
	sem_unlink("/death_check");
	if (argc < 5 || argc > 6)
		return (printf("Usage: ./philo <philos> <time_to_die> <time_to_eat> "
				"<time_to_sleep> [must_eat]\n"), 1);
	if (parse_args(&data, argc, argv))
		return (1);
	if (init_semaphores(&data))
		return (1);
	if (init_sem2(&data))
		return (1);
	data.start_time = get_time_in_ms();
	if (init_processes(&data))
		return (1);
	if (wait_processes(&data))
		return (1);
	cleanup(&data);
	return (0);
}
