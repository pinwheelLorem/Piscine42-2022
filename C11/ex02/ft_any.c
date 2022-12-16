/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 08:17:13 by fgabri            #+#    #+#             */
/*   Updated: 2022/10/02 08:51:42 by fgabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int (*f)(char *))
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (f(tab[i]))
			return (1);
		i++;
	}
	return (0);
}
/*
int	main()
{
	char **tab;
	tab = malloc(sizeof(char *)*3);
	tab[0] = "hello";
	tab[1] = "A";
	printf("%d",ft_any(tab,&ft));
	free(tab);
}
*/
