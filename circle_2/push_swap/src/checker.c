/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:49:28 by ele-lean          #+#    #+#             */
/*   Updated: 2024/11/16 14:08:32 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	argc--;
	if (argc)
	{
		if (ft_strncmp(argv[1], "pa", 3) != 0 && ft_strncmp(argv[1], "pb", 3)
			!= 0 && ft_strncmp(argv[1], "sa", 3) != 0
			&& ft_strncmp(argv[1], "sb", 3) != 0
			&& ft_strncmp(argv[1], "ss", 3) != 0
			&& ft_strncmp(argv[1], "ra", 3) != 0
			&& ft_strncmp(argv[1], "rb", 3) != 0
			&& ft_strncmp(argv[1], "rr", 3) != 0
			&& ft_strncmp(argv[1], "rra", 4) != 0
			&& ft_strncmp(argv[1], "rrb", 4) != 0
			&& ft_strncmp(argv[1], "rrr", 4) != 0)
		{
			write_error();
		}
	}
	return (0);
}
