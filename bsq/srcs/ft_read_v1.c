/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_v1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 20:09:15 by fgabri            #+#    #+#             */
/*   Updated: 2022/10/05 18:56:28 by minh-ngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int	ft_ck_mapinfo(char *s, t_map_info *map_info, char *lines, char *types)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	map_info->height = ft_atoi(lines);
	if (map_info->height < 1)
		return (0);
	map_info->length = i;
	if (map_info->length < 1)
		return (0);
	map_info->empty = types[0];
	if (!ft_is_printable(map_info->empty))
		return (0);
	map_info->obstacle = types[1];
	if (!ft_is_printable(map_info->obstacle))
		return (0);
	map_info->full = types[2];
	if (!ft_is_printable(map_info->full))
		return (0);
	return (1);
}

int	ft_get_info(char *s, t_map_info *map_info)
{
	int		i;
	char	lines[100];
	char	*types;

	i = 0;
	while (*s && *s != '\n')
	{
		if (*s >= '0' && *s <= '9')
		{
			lines[i] = *s;
			i++;
		}
		else
		{
			types = s;
			break ;
		}
		s++;
	}
	lines[i] = 0;
	while (*s && *s != '\n')
		s++;
	s++;
	return (ft_ck_mapinfo(s, map_info, lines, types));
}

void	ft_init_map(int **map, int height, int length, int val)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < length)
			map[i][j++] = val;
		i++;
	}
}

void	ft_print_map(int **map, int height, int length)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < length)
		{
			ft_putnbr(1, map[i][j]);
			if (j < length - 1)
				ft_putchar(1, ' ');
			j++;
		}
		ft_putchar(1, '\n');
		i++;
	}
}

void	ft_print_map_symbol(int **map, t_map_info map_info)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_info.height)
	{
		j = 0;
		while (j < map_info.length)
		{
			if (map[i][j] == 0)
				ft_putchar(1, map_info.obstacle);
			else if (map[i][j] == 1)
				ft_putchar(1, map_info.empty);
			else
				ft_putchar(1, map_info.full);
			j++;
		}
		ft_putchar(1, '\n');
		i++;
	}
}
