/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:32:03 by ele-lean          #+#    #+#             */
/*   Updated: 2024/11/15 17:49:12 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	write_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

int	is_invalid_number(char *arg)
{
	long	num;
	int		sign;
	int		c;

	num = 0;
	sign = 1;
	c = 0;
	if (arg[0] == '-' || arg[0] == '+')
	{
		if (arg[0] == '-')
			sign = -1;
		c = 1;
	}
	if (arg[c] == '\0')
		return (write_error());
	while (arg[c])
	{
		if (arg[c] < '0' || arg[c] > '9')
			return (write_error());
		num = num * 10 + (arg[c] - '0');
		c++;
	}
	if (num * sign > 2147483647 || num * sign < -2147483648)
		return (write_error());
	return (0);
}

void	has_duplicates(char **argv, int argc, int i)
{
	int		j;
	long	num_i;

	num_i = ft_atoi(argv[i]);
	j = i + 1;
	while (j < argc)
	{
		if (num_i == ft_atoi(argv[j]))
			write_error();
		j++;
	}
}

int	check_args(int argc, char **argv)
{
	int	i;

	if (argc < 2)
		return (1);
	i = 1;
	while (i < argc)
	{
		if (is_invalid_number(argv[i]))
			return (1);
		has_duplicates(argv, argc, i);
		i++;
	}
	return (0);
}
