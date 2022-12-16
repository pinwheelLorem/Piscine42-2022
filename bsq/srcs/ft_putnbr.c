/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minh-ngu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 08:45:31 by minh-ngu          #+#    #+#             */
/*   Updated: 2022/10/04 07:28:57 by minh-ngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putnbrn(int fd, int nb)
{
	char	c;

	if (nb > 9)
		ft_putnbrn(fd, (nb - nb % 10) / 10);
	c = nb % 10 + '0';
	write(fd, &c, 1);
}

void	ft_putnbr(int fd, int nb)
{
	char	c;

	if (nb == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (nb == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		c = '-';
		write(fd, &c, 1);
		nb = -nb;
	}
	ft_putnbrn(fd, nb);
}
