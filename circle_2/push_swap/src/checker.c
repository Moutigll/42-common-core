/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:49:28 by ele-lean          #+#    #+#             */
/*   Updated: 2024/11/16 15:08:54 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_is_sorted(t_stack *stack_a, t_stack *stack_b,
			struct sorted_list *presorted)
{
	struct circular_list	*temp;
	struct sorted_list		*next;
	int						i;

	temp = stack_a->head;
	next = presorted;
	i = 0;
	while (i < stack_a->size)
	{
		if (temp->value != next->value)
			break ;
		i++;
		temp = temp->next;
		next = next->next;
	}
	if (i == stack_a->size)
	{
		free_list(presorted);
		free_stack(stack_a);
		free_stack(stack_b);
		exit(0);
	}
}

struct sorted_list	*init_lists(t_stack *stack_a,
						t_stack *stack_b, int argc, char **argv)
{
	struct sorted_list		*next;
	struct sorted_list		*presorted;
	struct circular_list	*temp;
	int						i;

	stack_b->head = NULL;
	stack_b->size = 0;
	i = 1;
	presorted = append_sorted(NULL, ft_atoi(argv[i]));
	stack_a->head = insert_circular(NULL, ft_atoi(argv[i]));
	next = presorted;
	temp = stack_a->head;
	while (i < argc - 1)
	{
		i++;
		temp = insert_circular(temp, ft_atoi(argv[i]));
		next = append_sorted(next, ft_atoi(argv[i]));
	}
	stack_a->size = argc - 1;
	bubblesort(presorted);
	check_is_sorted(stack_a, stack_b, presorted);
	next = presorted;
	temp = stack_a->head;
	return (presorted);
}

int	is_valid_command(const char *line)
{
	static const char	*valid_commands[] = {
		"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra",
		"rrb", "rrr", NULL};
	int					i;

	if (!line)
		return (0);
	i = 0;
	while (valid_commands[i])
	{
		if (ft_strncmp(line, valid_commands[i],
				ft_strlen(valid_commands[i])) == 0
			&& ft_strlen(line) == ft_strlen(valid_commands[i]))
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	struct sorted_list	*presorted;
	t_stack				*stack_a;
	t_stack				*stack_b;
	char				*line;

	if (check_args(argc, argv) == 1)
		return (0);
	stack_a = (t_stack *)malloc(sizeof(t_stack));
	stack_b = (t_stack *)malloc(sizeof(t_stack));
	if (!stack_a || !stack_b)
		return (1);
	presorted = init_lists(stack_a, stack_b, argc, argv);
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		if (!is_valid_command(line))
		{
			free(line);
			write_error();
		}
		free(line);
	}
	return (0);
}
