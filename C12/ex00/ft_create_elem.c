/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:26:38 by fgabri            #+#    #+#             */
/*   Updated: 2022/10/03 12:44:34 by fgabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (!elem)
		return (0);
	elem->next = NULL;
	elem->data = data;
	return (elem);
}

/*
void	print_data(t_list *t)
{
	while (t != NULL)
	{
		printf("%d\n", *(int*)t->data);
		t = t->next;
	}
}

int main()
{
	t_list *n;
	int a = 223;
	void *pt = &a;
	n = ft_create_elem(pt);
	print_data(n);
}*/
