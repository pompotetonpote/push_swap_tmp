/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:13:14 by pompote           #+#    #+#             */
/*   Updated: 2023/01/10 15:35:30 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

/* Stack & Tab */

t_stack		*fill_stack(int argc, char **argv);
void		index_stack_element(t_stack *stack_a, int stack_size);
char		**argv_tab(char **argv);

/* Sorting */

void		sort_three(t_stack **stack);
int			is_sorted(t_stack *stack);
void		sort(t_stack **stack_a, t_stack **stack_b);
int			get_stack_size(t_stack *stack);
t_stack		*get_last_stack_element(t_stack *stack);
t_stack		*get_before_last_stack_element(t_stack *stack);
t_stack		*new_stack_element(int nb);
void		add_last_stack_element(t_stack **stack, t_stack *new);

/* Position & Costs */

void		get_target_position(t_stack **stack_a, t_stack **stack_b);
int			get_lowest_index_position(t_stack **stack);
void		get_cost(t_stack **stack_a, t_stack **stack_b);
void		cheapest_operation(t_stack **stack_a, t_stack **stack_b);
void		operate(t_stack **a, t_stack **b, int cost_a, int cost_b);

/*Checking and Utils*/

int			check_inputs(char **argv);
int			check_sign(char c);
int			str_nbcmp(const char *str1, const char *str2);
int			check_inputs(char **argv);
long int	ft_atoi(const char *str);
void		ft_putstr(char *str);
int			ft_isdigit(char c);
void		exit_error(t_stack **stack_a, t_stack **stack_b);
void		free_stack(t_stack **stack);
int			nb_abs(int nb);
char		**ft_split(char const *str, char c);
size_t		ft_strlen(const char *str);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
void		*ft_calloc(size_t count, size_t size);
int			countset(char const *str, char c);
int			parse_long_string(char *str, char c);

/* Operations */

void		pa(t_stack **stack_a, t_stack **stack_b);
void		pb(t_stack **stack_a, t_stack **stack_b);
void		sa(t_stack **stack_a);
void		sb(t_stack **stack_b);
void		ss(t_stack **stack_a, t_stack **stack_b);
void		ra(t_stack **stack_a);
void		rb(t_stack **stack_b);
void		rr(t_stack **stack_a, t_stack **stack_b);
void		rra(t_stack **stack_a);
void		rrb(t_stack **stack_b);
void		rrr(t_stack **stack_a, t_stack **stack_b);

#endif