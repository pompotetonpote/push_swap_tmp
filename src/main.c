/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:07:08 by pompote           #+#    #+#             */
/*   Updated: 2023/01/10 19:19:22 by yperonne         ###   ########.fr       */
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

void	fill_stack_check_inputs1(const char **tab, t_stack *stack_a)
{
	if (!check_inputs(tab))
		exit_error(NULL, NULL);
	stack_a = fill_stack(tab_len(tab), tab);
}

void	fill_stack_check_inputs2(const char **tab, t_stack *stack_a, int argc)
{
	if (!check_inputs(tab))
		exit_error(NULL, NULL);
	stack_a = fill_stack(argc, tab);
}

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	int			stack_size;
	char		**tab;

	tab = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2)
		tab = ft_split(argv[1], ' ');
	stack_b = NULL;
	if (argc == 2)
		fill_stack_check_inputs1(tab, stack_a);
	else
		fill_stack_check_inputs2(argv, stack_a, argc);
	stack_size = get_stack_size(stack_a);
	index_stack_element(stack_a, stack_size + 1);
	push_swap(&stack_a, &stack_b, stack_size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	free(tab);
	return (0);
}
