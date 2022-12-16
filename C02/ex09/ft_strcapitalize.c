/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 04:42:31 by fgabri            #+#    #+#             */
/*   Updated: 2022/09/20 01:28:14 by fgabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_upcase(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int	ft_lowcase(char c)
{
	return (c >= 'a' && c <= 'z');
}

int	alpha(char c)
{
	return (ft_upcase(c) || ft_lowcase(c));
}

char	*ft_convert(char *c)
{
	if (*c >= 'a' && *c <= 'z')
		*c -= 32;
	else
		*c += 32;
	return (c);
}

char	*ft_strcapitalize(char *str)
{
	int		i;
	char	c;
	int		j;

	i = 1;
	j = -1;
	while (str[++j] != '\0')
	{
		if (ft_upcase(str[j]))
				str[j] += 32;
	}
	if (str[0] != '\0' && ft_lowcase(str[0]))
		str[0] -= 32;
	while (str[i] != '\0')
	{
		c = str[i - 1];
		if (alpha(str[i]) && (!(alpha(c)) && !(c >= '0' && c <= '9')))
			ft_convert(&str[i]);
		i++;
	}
	return (str);
}
