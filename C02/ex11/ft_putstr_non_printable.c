/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 21:16:58 by fgabri            #+#    #+#             */
/*   Updated: 2022/09/20 22:11:16 by fgabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_hex(char c)
{
	int		negative_c;
	char	hex_num1;
	char	hex_num2;

	ft_putchar('\\');
	if (c < 0)
	{
		negative_c = (-128 - (c)) * -1 + 128;
		hex_num1 = negative_c / 16;
		hex_num2 = negative_c % 16;
	}
	else
	{
		hex_num1 = c / 16;
		hex_num2 = c % 16;
	}
	if (hex_num1 < 10)
		ft_putchar(hex_num1 + '0');
	else
		ft_putchar(hex_num1 + 87);
	if (hex_num2 < 10)
		ft_putchar(hex_num2 + '0');
	else
		ft_putchar(hex_num2 + 87);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 32 && str[i] <= 126)
			ft_putchar(str[i]);
		else
		{
			ft_print_hex(str[i]);
		}
		i++;
	}
}
