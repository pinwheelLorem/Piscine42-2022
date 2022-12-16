/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 06:42:36 by fgabri            #+#    #+#             */
/*   Updated: 2022/09/27 22:06:55 by fgabri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>

typedef enum f_bool{
	false = 0,
	true = 1,
}	t_bool;

# define EVEN_MSG "I have an even number of arguments.\n"
# define ODD_MSG "I have an odd number of arguments.\n" 
# define EVEN(nbr)  ((nbr) % 2 == 0)  
# define TRUE true
# define FALSE false
# define SUCCESS 0
#endif
