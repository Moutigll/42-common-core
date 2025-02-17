/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:08:57 by ele-lean          #+#    #+#             */
/*   Updated: 2025/02/17 18:48:08 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <semaphore.h>
#include <sys/types.h>
#include <pthread.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/wait.h>
#include <string.h>

typedef struct s_data
{
	int			philo_count;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			must_eat_count;
	long		start_time;
	sem_t		*sem_forks;
	sem_t		*sem_write;
	sem_t		*sem_death;
	sem_t		*max_eat;
	sem_t		*sem_death_check;
	pid_t		*pids;
}	t_data;

typedef struct s_philo_bonus
{
	int			id;
	int			eat_count;
	long		last_meal;
	t_data		*data;
}	t_philo_bonus;

// utils_bonus.c
int		is_positive_number(char *str);
int		ft_atoi(const char *str);
long	get_time_in_ms(void);
void	print_action_bonus(t_philo_bonus *philo, char *action);

// init_bonus.c
int		parse_args(t_data *data, int argc, char **argv);
int		init_semaphores(t_data *data);
int		init_processes(t_data *data);

// philo_bonus.c
void	philosopher_routine(t_data *data, int index);
void	*monitor_philosopher(void *arg);
int		wait_processes(t_data *data);
