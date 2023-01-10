/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yperonne <yperonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:36:54 by yperonne          #+#    #+#             */
/*   Updated: 2023/01/10 18:55:11 by yperonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*rstr;

	rstr = NULL;
	if (!str)
		return (NULL);
	if (start >= ft_strlen(str))
	{
		rstr = ft_calloc(1, sizeof(char));
		if (!rstr)
			return (NULL);
		return (rstr);
	}
	if (ft_strlen(str) < len)
		rstr = malloc((ft_strlen(str) + 1) * sizeof(char));
	else if (ft_strlen(str) >= len)
		rstr = malloc((len + 1) * sizeof(char));
	if (!rstr)
		return (NULL);
	ft_strlcpy(rstr, str + start, len + 1);
	return (rstr);
}

int	countset(char const *str, char c)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			if (str[i + 1] == c || str[i + 1] == '\0')
				k++;
		}
		i++;
	}
	return (k);
}

char	**filltab(char **tab, int nbrl, char const *str, char c)
{
	size_t	i;
	int		k;
	size_t	p;

	i = 0;
	k = 1;
	p = 0;
	while (k < nbrl)
	{
		if (str[i] != c && str[i])
		{
			while (str[i + p] != c && str[i + p])
				p++;
			tab[k++] = ft_substr(str, i, p);
			i = i + p - 1;
			p = 0;
		}
		i++;
	}
	return (tab);
}

char	**ft_split(char const *str, char c)
{
	char	**tab;

	tab = NULL;
	if (!str)
		return (NULL);
	tab = ft_calloc((countset(str, c) + 2), sizeof(char *));
	if (!tab)
		return (NULL);
	tab[countset(str, c) + 1] = (char *) '\0';
	tab = filltab(tab, countset(str, c) + 1, str, c);
	return (tab);
}
