/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 19:51:20 by fgabri            #+#    #+#             */
/*   Updated: 2022/09/27 04:37:54 by fgabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	diff;
	int	i;

	diff = max - min;
	i = -1;
	if (diff <= 0)
	{
		*range = NULL;
		return (0);
	}
	*range = malloc(diff * sizeof(int));
	if (!(*range))
		return (-1);
	while (++i < diff)
		(*range)[i] = min + i;
	return (diff);
}
