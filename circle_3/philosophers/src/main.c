/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:06:48 by ele-lean          #+#    #+#             */
/*   Updated: 2025/01/31 19:01:56 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	parse_args(t_data *data, int argc, char **argv)
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

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 5 || argc > 6)
		return (printf("Usage: ./philo <philos> <time_to_die> <time_to_eat> "
				"<time_to_sleep> [must_eat]\n"), 1);
	if (parse_args(&data, argc, argv))
		return (1);
	return (0);
}
