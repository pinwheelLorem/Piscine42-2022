/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:25:05 by fgabri            #+#    #+#             */
/*   Updated: 2022/09/25 00:35:36 by fgabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	condition(int x, int *board)
{
	int	i;
	int	diff;

	i = 0;
	while (i < x)
	{
		diff = board[i] - board[x];
		if (diff < 0)
			diff *= -1;
		if (!(diff) || x - i == diff)
			return (0);
		i++;
	}
	return (1);
}

void	print_board(int *board)
{
	int	i;
	int	value;	

	i = 0;
	while (i < 10)
	{
		value = board[i] + '0';
		write(1, &value, 1);
		i++;
	}
	write(1, "\n", 1);
}

void	queen_algo(int x, int *sol, int *board)
{
	int	i;

	i = 0;
	if (x == 10)
	{	
		*sol = *sol + 1;
		print_board(board);
		return ;
	}
	while (i < 10)
	{
		board[x] = i;
		if (condition(x, board))
			queen_algo(x + 1, sol, board);
		i++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	sol;
	int	i;
	int	board[10];

	sol = 0;
	i = 0;
	while (i < 10)
		board[i++] = 0;
	queen_algo(0, &sol, board);
	return (sol);
}
