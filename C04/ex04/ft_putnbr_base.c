/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 21:00:13 by fgabri            #+#    #+#             */
/*   Updated: 2022/12/03 22:00:09 by fgabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_len(char *str)
{
	int	len;

	len = 0;
	while (*(str++))
		len++;
	return (len);
}

int	checkbase(char *str)
{
	int	i;
	int	j;
	int	len_base;

	i = 0;
	len_base = ft_len(str);
	if (!(str[i]) || len_base == 1)
		return (0);
	while (str[i])
	{
		if (str[i] <= 32 || str[i] >= 127 || str[i] == '-' || str[i] == '+')
			return (0);
		j = i;
		while (++j < ft_len(str))
		{
			if (str[i] == str[j])
				return (0);
		}
		i++;
	}
	return (1);
}

void	into_base(unsigned int n, char *base)
{
	unsigned int	len;

	len = ft_len(base);
	if (n > len - 1)
	{
		into_base(n / len, base);
		n %= len;
	}
	ft_putchar(base[n]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	if (!(checkbase(base)))
		return ;
	if (nbr < 0)
	{
		nbr *= -1;
		ft_putchar('-');
	}
	into_base(nbr, base);
}

#include <stdio.h>
int main()
{

	ft_putnbr_base(-123, "0123456789abcdef");
	ft_putchar('\n');
	printf("%x", -123);
}
