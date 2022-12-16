/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 01:13:10 by fgabri            #+#    #+#             */
/*   Updated: 2022/09/22 05:34:11 by fgabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_base(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (str[i] == '\0' || str[1] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] <= 32 || str[i] == 127 || str[i] == '-' || str[i] == '+')
			return (0);
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int	in_base(char str, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == str)
			return (i);
		i++;
	}
	return (-1);
}

int	detect_space(char *str, int *indice)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			count++;
		i++;
	}
	*indice = i;
	return (count);
}

int	ft_atoi_base(char *str, char *base)
{
	int	len;
	int	n;
	int	i;
	int	count;
	int	num;

	len = check_base(base);
	n = 0;
	i = 0;
	count = detect_space(str, &i);
	if (!(len))
		return (0);
	num = in_base(str[i], base);
	while (num != -1)
	{
		n = n * len + num;
		i++;
		num = in_base(str[i], base);
	}
	if (count % 2)
		return (n *= -1);
	else
		return (n);
}
