/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 22:23:19 by fgabri            #+#    #+#             */
/*   Updated: 2022/10/05 23:35:43 by minh-ngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	ft_free_map(int **map, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	**ft_create_map(int height, int length)
{
	int	i;
	int	**map;

	map = malloc(sizeof(int *) * height);
	if (!map)
		return (0);
	i = 0;
	while (i < height)
	{
		map[i] = malloc(sizeof(int) * length);
		if (!map[i])
			return (0);
		i++;
	}
	return (map);
}

int	ft_i_map(char *s, int **map, int **max_square, t_map_info map_info)
{
	ft_init_map(map, map_info.height, map_info.length, 0);
	ft_init_map(max_square, map_info.height + 1, map_info.length + 1, 0);
	if (!ft_read_map(&s[0], map, map_info))
	{
		ft_free_map(map, map_info.height);
		ft_free_map(max_square, map_info.height + 1);
		write(2, "map error\n", 10);
		return (0);
	}
	return (1);
}
