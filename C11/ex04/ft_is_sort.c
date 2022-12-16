/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 09:07:48 by fgabri            #+#    #+#             */
/*   Updated: 2022/10/02 09:48:00 by fgabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab,int length, int (*f)(int, int))
{
	int	i;
	int	diff1;
	int	diff2;

	i = 1;
	while ((i < length) && !(f(tab[i],tab[i - 1])))
		i++;
	while (i < length)
	{
		diff1 = f(tab[i],tab[i-1]);
		diff2 = f(tab[i+1],tab[i]);
		if (!((diff1 > 0 && diff2 < 0) || (diff1 < 0 && diff2 > 0)))
			return (0);
		i++;
	}
	return (1);
}
