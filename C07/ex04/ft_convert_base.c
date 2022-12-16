/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 03:13:28 by fgabri            #+#    #+#             */
/*   Updated: 2022/09/26 06:34:26 by fgabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_checkbase(char *str);

int	ft_inbase(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base, int size)
{
	int		sign;
	long	n;

	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	while (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign *= -1;
	n = 0;
	while (ft_inbase(*str, base) >= 0)
	{
		n = n * size + ft_inbase(*str, base);
		str++;
	}
	if (sign < 0)
		n *= -1;
	return (n);
}

int	ft_nbrstr(unsigned int n, unsigned int base_len)
{
	if (n < base_len)
		return (1);
	return (1 + ft_nbrstr(n / base_len, base_len));
}

int	find_len_dest(int *num, unsigned int *n, char *base_to)
{
	int	len;

	if (*num < 0)
	{
		*n = -*num;
		len = ft_nbrstr(*n, ft_checkbase(base_to)) + 1;
	}
	else
	{
		*n = *num;
		len = ft_nbrstr(*n, ft_checkbase(base_to));
	}
	return (len);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	unsigned int	n;
	int				len_dest;
	int				num;
	char			*dest;

	if (ft_checkbase(base_from) == -1 || ft_checkbase(base_to) == -1)
		return (NULL);
	num = ft_atoi_base(nbr, base_from, ft_checkbase(base_from));
	len_dest = find_len_dest(&num, &n, base_to);
	dest = malloc((len_dest + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	dest[len_dest] = '\0';
	while (len_dest--)
	{
		dest[len_dest] = base_to[n % ft_checkbase(base_to)];
		n /= ft_checkbase(base_to);
	}
	if (num < 0)
		dest[0] = '-';
	return (dest);
}
