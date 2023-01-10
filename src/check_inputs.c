/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 18:44:04 by pompote           #+#    #+#             */
/*   Updated: 2023/01/10 12:55:35 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_arg_nbr(char *argv)
{
	int	i;

	i = 0;
	if (check_sign(argv[i]) && argv[i + 1] != '\0')
		i++;
	while (argv[i] && ft_isdigit(argv[i]))
		i++;
	if (argv[i] != '\0' && !ft_isdigit(argv[i]))
		return (0);
	return (1);
}

static int	check_doubles(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 1;
		while (argv[j])
		{
			if (j != i && str_nbcmp(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_zeros(char *argv)
{
	int	i;

	i = 0;
	if (check_sign(argv[i]))
		i++;
	while (argv[i] && argv[i] == '0')
		i++;
	if (argv[i] != '\0')
		return (0);
	return (1);
}

int	check_inputs(char **argv)
{
	int	i;
	int	zeros;

	zeros = 0;
	i = 1;
	while (argv[i])
	{
		if (!check_arg_nbr(argv[i]))
			return (0);
		zeros += check_zeros(argv[i]);
		i++;
	}
	if (zeros > 1)
		return (0);
	if (check_doubles(argv))
		return (0);
	return (1);
}
