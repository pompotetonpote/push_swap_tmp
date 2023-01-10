/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:22:15 by pompote           #+#    #+#             */
/*   Updated: 2023/01/10 12:56:43 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_stack_element(t_stack *stack_a, int stack_size)
{
	t_stack	*ptr;
	t_stack	*topnbr;
	int		nbr;

	while (--stack_size > 0)
	{
		ptr = stack_a;
		nbr = INT_MIN;
		topnbr = NULL;
		while (ptr)
		{
			if (ptr->value == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->value > nbr && ptr->index == 0)
			{
				nbr = ptr->value;
				topnbr = ptr;
				ptr = stack_a;
			}
			else
				ptr = ptr->next;
		}
		if (topnbr != NULL)
			topnbr->index = stack_size;
	}
}
