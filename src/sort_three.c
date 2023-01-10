/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:13:19 by pompote           #+#    #+#             */
/*   Updated: 2023/01/10 12:58:39 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_top_index(t_stack *stack)
{
	int		index;

	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}

void	sort_three(t_stack **stack)
{
	int	top;

	if (is_sorted(*stack))
		return ;
	top = find_top_index(*stack);
	if ((*stack)->index == top)
		ra(stack);
	else if ((*stack)->next->index == top)
		rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		sa(stack);
}
