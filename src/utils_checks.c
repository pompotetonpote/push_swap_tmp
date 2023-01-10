/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:59:43 by pompote           #+#    #+#             */
/*   Updated: 2023/01/10 13:00:32 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	check_sign(char c)
{
	if (c >= '+' && c <= '-')
		return (1);
	return (0);
}

int	str_nbcmp(const char *str1, const char *str2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str1[i] == '+')
	{
		if (str2[j] != '+')
			i++;
	}
	else
	{
		if (str2[j] == '+')
			j++;
	}
	while (str1[i] != '\0' && str2[j] != '\0' && str1[i] == str2[j])
	{
		i++;
		j++;
	}
	return ((unsigned char) str1[i] - (unsigned char) str2[j]);
}
