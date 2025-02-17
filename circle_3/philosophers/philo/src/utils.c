/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:17:53 by ele-lean          #+#    #+#             */
/*   Updated: 2025/02/17 19:36:02 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	is_positive_number(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int		sign;
	int		i;
	int		result;

	sign = 1;
	i = 0;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (sign * result);
}

long	get_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*str1;
	unsigned char	*str2;
	int				i;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (str1[i] && str2[i] && str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}

void	print_action(t_philo *philo, char *action)
{
	long	timestamp;
	t_data	*data;

	data = philo->data;
	timestamp = get_time_in_ms() - data->start_time;
	pthread_mutex_lock(&data->death_mutex);
	pthread_mutex_lock(&data->write_mutex);
	if (data->someone_died && ft_strcmp(action, "died") != 0)
	{
		pthread_mutex_unlock(&data->write_mutex);
		pthread_mutex_unlock(&data->death_mutex);
		return ;
	}
	printf("%ld %d %s\n", timestamp, philo->id, action);
	pthread_mutex_unlock(&data->write_mutex);
	pthread_mutex_unlock(&data->death_mutex);
}
