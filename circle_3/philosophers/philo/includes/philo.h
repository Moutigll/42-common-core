/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:08:57 by ele-lean          #+#    #+#             */
/*   Updated: 2025/02/14 16:11:32 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct s_philo	t_philo;

typedef struct s_data
{
	int				philo_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_count;
	long			start_time;
	int				someone_died;
	t_philo			*philosophers;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	death_mutex;
	pthread_mutex_t	*forks;
}	t_data;

typedef struct s_philo
{
	int				id;
	int				eat_count;
	long			last_meal;
	pthread_t		thread;
	t_data			*data;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_philo;

// utils.c
int		is_positive_number(char *str);
int		ft_atoi(const char *str);
void	print_action(t_philo *philo, char *action);
long	get_time_in_ms(void);

// init.c

int		parse_args(t_data *data, int argc, char **argv);
t_philo	*init_philosophers(t_data *data);
int		init_simulation(t_data *data);

// philos.c
int		start_simulation(t_data *data);

// check.c
void	*check(void *arg);