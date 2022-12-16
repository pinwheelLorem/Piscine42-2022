/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minh-ngu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:37:41 by minh-ngu          #+#    #+#             */
/*   Updated: 2022/10/05 23:35:32 by minh-ngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# define BUF_SIZE 2090000

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_map_info {
	int		height;
	int		length;
	char	empty;
	char	obstacle;
	char	full;
}			t_map_info;

void	ft_putstr(int fd, char *str);
void	ft_putnbr(int fd, int nb);
int		ft_strcmp(char *s1, char *s2);
char	*ft_dict(char **str, char *z);
int		ft_strlen(char *str);
char	*ft_strcat(char *dest, char *src, int f);
char	*ft_strdup(char *src);
int		ft_atoi(char *str);
void	ft_putchar(int fd, char c);
int		ft_is_printable(char str);
char	**ft_read(char *file_name);
int		ft_read_map(char *s, int **map, t_map_info map_info);
void	ft_init_map(int **map, int height, int length, int val);
void	ft_print_map(int **map, int height, int length);
int		**ft_create_map(int height, int length);
void	ft_free_map(int **map, int size);
void	ft_print_map_symbol(int **map, t_map_info map_info);
char	*ft_read_file(char *file_name);
int		ft_resolve(int **map, int **max_square, t_map_info map_info);
int		ft_check(char *s, int *n_char, int *n_line, t_map_info map_info);
int		ft_get_info(char *s, t_map_info *map_info);
int		ft_ck_mapinfo(char *s, t_map_info *map_info, char *lines, char *types);
int		ft_i_map(char *s, int **map, int **map_square, t_map_info map_info);

#endif
