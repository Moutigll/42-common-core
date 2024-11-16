/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:49:28 by ele-lean          #+#    #+#             */
/*   Updated: 2024/11/16 17:12:15 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	next = presorted;
	temp = stack_a->head;
	return (presorted);
}

void	execute_command(const char *command, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strncmp(command, "sa", 2) == 0 && ft_strlen(command) == 3)
		swap_stack(stack_a, "");
	else if (ft_strncmp(command, "sb", 2) == 0 && ft_strlen(command) == 3)
		swap_stack(stack_b, "");
	else if (ft_strncmp(command, "ss", 2) == 0 && ft_strlen(command) == 3)
		swap_both(stack_a, stack_b);
	else if (ft_strncmp(command, "pa", 2) == 0 && ft_strlen(command) == 3)
		push_stack(stack_b, stack_a, "");
	else if (ft_strncmp(command, "pb", 2) == 0 && ft_strlen(command) == 3)
		push_stack(stack_a, stack_b, "");
	else if (ft_strncmp(command, "ra", 2) == 0 && ft_strlen(command) == 3)
		rotate_stack(stack_a, "");
	else if (ft_strncmp(command, "rb", 2) == 0 && ft_strlen(command) == 3)
		rotate_stack(stack_b, "");
	else if (ft_strncmp(command, "rr", 2) == 0 && ft_strlen(command) == 3)
		rotate_both(stack_a, stack_b);
	else if (ft_strncmp(command, "rra", 3) == 0 && ft_strlen(command) == 4)
		reverse_rotate_stack(stack_a, "");
	else if (ft_strncmp(command, "rrb", 3) == 0 && ft_strlen(command) == 4)
		reverse_rotate_stack(stack_b, "");
	else if (ft_strncmp(command, "rrr", 3) == 0 && ft_strlen(command) == 4)
		reverse_rotate_both(stack_a, stack_b);
}

int	is_valid_command(const char *line)
{
	int					i;
	static const char	*valid_commands[] = {
		"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra",
		"rrb", "rrr"};

	if (!line)
		return (0);
	i = 0;
	while (valid_commands[i])
	{
		if (ft_strncmp(line, valid_commands[i],
				ft_strlen(valid_commands[i])) == 0
			&& ft_strlen(line) - 1 == ft_strlen(valid_commands[i]))
			return (1);
		i++;
	}
	return (0);
}

void	main2(struct sorted_list *presorted, t_stack *stack_a, t_stack *stack_b)
{
	char	*line;

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
		else
			execute_command(line, stack_a, stack_b);
		free(line);
	}
	is_stack_a_sorted(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	free_list(presorted);
}

int	main(int argc, char **argv)
{
	struct sorted_list	*presorted;
	t_stack				*stack_a;
	t_stack				*stack_b;

	if (check_args(argc, argv) == 1)
		return (0);
	stack_a = (t_stack *)malloc(sizeof(t_stack));
	stack_b = (t_stack *)malloc(sizeof(t_stack));
	if (!stack_a || !stack_b)
		return (1);
	presorted = init_lists(stack_a, stack_b, argc, argv);
	main2(presorted, stack_a, stack_b);
	return (0);
}
