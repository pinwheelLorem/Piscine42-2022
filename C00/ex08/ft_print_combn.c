/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 18:34:09 by fgabri            #+#    #+#             */
/*   Updated: 2022/09/17 18:40:57 by fgabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_combn(int n)
{
	int		i;
	char	tab[11];

	i = 0;
	*tab = '0';
	if (n < 1 || n > 9)
		return ;
	while (++i < n)
		tab[i] = tab[i - 1] + 1;
	tab[n] = ',';
	tab[n + 1] = ' ';
	while (*tab <= 58 - n)
	{
		if (*tab != 58 - n)
			write (1, tab, n + 2);
		else if (!(*tab != 58 - n))
			write (1, tab, n);
		i = n;
		while (i--)
			if (++tab[i] <= 58 - n + i)
				break ;
		while (++i > 0 && i < n)
				tab[i] = tab[i - 1] + 1;
	}
}
