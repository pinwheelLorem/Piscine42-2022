/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minh-ngu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:30:01 by minh-ngu          #+#    #+#             */
/*   Updated: 2022/10/05 20:59:52 by minh-ngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

char	*ft_read_file(char *file_name)
{
	int		ret;
	int		fd;
	char	*s;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (0);
	s = malloc(sizeof(char) * (BUF_SIZE + 1));
	if (!s)
		return (0);
	ret = read(fd, s, BUF_SIZE);
	s[ret] = 0;
	close(fd);
	return (s);
}

int	ft_check_line(char *s, int *n_char, int *n_line, t_map_info map_info)
{
	if (s[1] == '\n')
		return (0);
	if (*n_char != 0 && *n_char < map_info.length)
		return (0);
	*n_char = 0;
	*n_line += 1;
	return (1);
}

int	get_n_lines(char *s)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s == '\n')
			i++;
		s++;
	}
	return (i);
}

int	ft_get_cells(char *s, int *map_line, t_map_info map_info, int n_char)
{
	if (*s == map_info.empty)
	{
		map_line[n_char - 1] = 1;
		return (1);
	}
	else if (*s == map_info.obstacle)
	{
		map_line[n_char - 1] = 0;
		return (1);
	}
	return (0);
}

int	ft_read_map(char *s, int **map, t_map_info map_info)
{
	int		n_line;
	int		n_char;

	if (get_n_lines(s) != (map_info.height + 1))
		return (0);
	n_char = 0;
	n_line = 0;
	while (*s)
	{
		if (*s == '\n')
			if (!(ft_check_line(s, &n_char, &n_line, map_info)))
				return (0);
		if (n_line > 0 && n_line <= map_info.height && *s != '\n')
		{
			n_char++;
			if (n_char > map_info.length)
				return (0);
			if (!ft_get_cells(s, map[n_line - 1], map_info, n_char))
				return (0);
		}
		s++;
	}
	return (1);
}
