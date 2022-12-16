/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 19:30:39 by fgabri            #+#    #+#             */
/*   Updated: 2022/09/25 19:48:08 by fgabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	range;
	int	i;

	range = max - min;
	i = -1;
	tab = malloc(range * sizeof(int));
	if (!tab || range <= 0)
		return (NULL);
	while (i++ < range - 1)
		tab[i] = min++;
	return (tab);
}
