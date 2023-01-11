/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:07:08 by pompote           #+#    #+#             */
/*   Updated: 2023/01/11 15:36:50 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2 && !is_sorted(*stack_a))
		sa(stack_a);
	else if (stack_size == 3)
		sort_three(stack_a);
	else if (stack_size > 3 && !is_sorted(*stack_a))
		sort(stack_a, stack_b);
}

void	free_all(t_stack *stack_a, t_stack *stack_b)
{
	free_stack(&stack_a);
	free_stack(&stack_b);
}

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	int			stack_size;
	char		**tab;

	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		tab = ft_split(argv[1], ' ');
		if (!check_inputs(tab))
			exit_error(NULL, NULL);
		stack_a = fill_stack(tab_len(tab), tab);
	}
	else
	{
		if (!check_inputs(argv))
			exit_error(NULL, NULL);
		stack_a = fill_stack(argc, argv);
	}
	stack_size = get_stack_size(stack_a);
	index_stack_element(stack_a, stack_size + 1);
	push_swap(&stack_a, &stack_b, stack_size);
	free_all(stack_a, stack_b);
}
