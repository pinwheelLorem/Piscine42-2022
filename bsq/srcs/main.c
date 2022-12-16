/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minh-ngu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:10:38 by minh-ngu          #+#    #+#             */
/*   Updated: 2022/10/05 23:35:54 by minh-ngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

char	*ft_rd_from_input(void)
{
	int		i;
	int		len;
	char	c;
	char	*input;
	char	s[10000 + 1];

	i = 0;
	len = 0;
	while (read(0, &c, 1) > 0)
	{
		s[i] = c;
		i++;
	}
	s[i] = '\0';
	while (s[len])
		len++;
	if (len <= 3)
		return (0);
	input = ft_strdup(s);
	return (input);
}

int	resolve_maps(char *s)
{
	int			**map;
	int			**max_square;
	t_map_info	map_info;

	if (!(s[0] >= '0' && s[0] <= '9'))
	{
		write(2, "map error\n", 10);
		return (0);
	}
	ft_get_info(&s[0], &map_info);
	map = ft_create_map(map_info.height, map_info.length);
	if (!map)
		return (0);
	max_square = ft_create_map(map_info.height + 1, map_info.length + 1);
	if (!max_square)
		return (0);
	if (!ft_i_map(&s[0], map, max_square, map_info))
		return (0);
	ft_resolve(map, max_square, map_info);
	ft_free_map(map, map_info.height);
	ft_free_map(max_square, map_info.height + 1);
	return (1);
}

int	ft_input(void)
{
	char	*s;

	s = ft_rd_from_input();
	if (!s)
	{
		write(2, "map error\n", 10);
		return (0);
	}
	if (!resolve_maps(s))
	{
		free(s);
		return (0);
	}
	free(s);
	return (1);
}

void	ft_wr(int i, int argc)
{
	write(2, "map error\n", 10);
	if (i < (argc - 1))
		write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	int		i;
	char	*s;

	if (argc < 2)
		return (!(ft_input()));
	else
	{
		i = 1;
		while (i < argc)
		{
			s = ft_read_file(argv[i]);
			if (!s)
				ft_wr(i, argc);
			else
			{
				resolve_maps(s);
				if (i < (argc - 1))
					write(1, "\n", 1);
			}
			free(s);
			i++;
		}
	}
	return (0);
}
