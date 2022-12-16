/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:00:57 by fgabri            #+#    #+#             */
/*   Updated: 2022/10/04 23:03:43 by fgabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	ft_map_rv(int max_sq, int col_max, int row_max, int **map)
{
	int	col;
	int	row;

	row = 0;
	while (row < max_sq)
	{
		col = 0;
		while (col < max_sq)
		{
			map[row_max - row][col_max - col] = 2;
			col++;
		}
		row++;
	}
}

int	ft_min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

typedef struct s_map_coor {
	int	row;
	int	col;
	int	row_max;
	int	col_max;
	int	max_sq;
}	t_map_coor;

int	ft_resolve(int **map, int **ms, t_map_info map_info)
{
	t_map_coor	cr;

	cr.max_sq = 0;
	cr.row = -1;
	cr.col_max = 0;
	cr.row_max = 0;
	while (++cr.row < map_info.height)
	{
		cr.col = -1;
		while (++cr.col < map_info.length)
		{
			if (map[cr.row][cr.col] != 0)
				ms[cr.row + 1][cr.col + 1] = ft_min(ms[cr.row][cr.col + 1],
						ft_min(ms[cr.row][cr.col], ms[cr.row + 1][cr.col])) + 1;
			if (ms[cr.row + 1][cr.col + 1] > cr.max_sq)
			{
				cr.max_sq = ms[cr.row + 1][cr.col + 1];
				cr.row_max = cr.row;
				cr.col_max = cr.col;
			}
		}
	}
	ft_map_rv(cr.max_sq, cr.col_max, cr.row_max, map);
	ft_print_map_symbol(map, map_info);
	return (cr.max_sq);
}
