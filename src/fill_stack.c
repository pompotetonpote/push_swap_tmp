/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:46:52 by pompote           #+#    #+#             */
/*   Updated: 2023/01/10 18:55:22 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*fill_stack(int argc, char **argv)
{
	t_stack		*stack_a;
	long int	nb;
	int			i;

	stack_a = NULL;
	nb = 0;
	i = 1;
	while (i < argc)
	{
		nb = ft_atoi(argv[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			exit_error(&stack_a, NULL);
		if (i == 1)
			stack_a = new_stack_element((int)nb);
		else
			add_last_stack_element(&stack_a, new_stack_element(nb));
		i++;
	}
	return (stack_a);
}

// int	parse_long_string(char *str, char c)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == c && str[i + 1] != '\0')
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// char	**argv_tab(char **argv)
// {
// 	char	**tab;

// 	tab = NULL;
// 	if (parse_long_string(argv[1], ' '))
// 	{
// 		tab = ft_split(argv[1], ' ');
// 		return (tab);
// 	}
// 	return (argv);
// }
