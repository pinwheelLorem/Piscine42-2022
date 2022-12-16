/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 06:54:54 by fgabri            #+#    #+#             */
/*   Updated: 2022/10/02 08:24:09 by fgabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*t;
	int	i;

	i = 0;
	t = malloc(sizeof(int) * length);
	if (!t || (length < 1))
		return (0);
	while (i < length)
	{
		t[i] = f(tab[i]);
		i++;
	}
	return (t);
}
