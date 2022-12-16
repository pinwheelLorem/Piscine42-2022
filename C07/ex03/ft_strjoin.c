/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 21:10:41 by fgabri            #+#    #+#             */
/*   Updated: 2022/09/26 02:57:47 by fgabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_lenstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

char	*algo_join(char *dest, char **strs, int size, char *sep)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{		
		ft_strcpy(dest + j, strs[i]);
		j += ft_lenstr(strs[i]);
		if (i < size - 1)
		{
			ft_strcpy(dest + j, sep);
			j += ft_lenstr(sep);
		}
		i++;
	}
	dest[j] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		nb_tot;
	char	*dest;

	i = 0;
	nb_tot = 0;
	while (i < size)
		nb_tot += ft_lenstr(strs[i++]);
	if (size > 0)
		nb_tot += (size - 1) * ft_lenstr(sep);
	dest = malloc((nb_tot + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	algo_join(dest, strs, size, sep);
	return (dest);
}
