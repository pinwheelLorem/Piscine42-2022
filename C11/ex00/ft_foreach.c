/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 06:30:55 by fgabri            #+#    #+#             */
/*   Updated: 2022/10/02 06:52:28 by fgabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		f(tab[i]);
		i++;
	}
}

/*
int main()
{
	int *tab;
	tab = malloc(sizeof(int)*3);
	tab[0] = 1;
	tab[1] = 2;
	tab[2] = 3;
	//ft_putnbr(77);
	ft_foreach(tab,3,&ft_putnbr);
	free(tab);
}
*/
