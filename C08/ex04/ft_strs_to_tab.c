/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 03:25:36 by fgabri            #+#    #+#             */
/*   Updated: 2022/09/28 04:38:16 by fgabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_stock_str.h"
#include <stdlib.h>

int	len_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	i = -1;
	dest = malloc(sizeof(char) * (len_str(src) + 1));
	if (!dest)
		return (NULL);
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*tab;
	int			i;

	i = -1;
	if (ac < 0)
		ac = 0;
	tab = malloc((ac + 1) * sizeof(t_stock_str));
	if (!tab)
		return (NULL);
	while (++i < ac)
	{
		tab[i].size = len_str(av[i]);
		tab[i].str = av[i];
		tab[i].copy = ft_strdup(av[i]);
	}
	tab[i].str = 0;
	return (tab);
}
