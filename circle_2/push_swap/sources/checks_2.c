/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:48:25 by drosell-          #+#    #+#             */
/*   Updated: 2023/03/12 17:48:25 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
Esta función, llamada "check_same_nums", comprueba si hay números repetidos en la pila "sa" de la estructura "t_list".
*/
int	check_same_nums(t_list *d)
{
	int	i;

	i = 0;
	while (i <= d->sia - 1)
	{
		if (ft_check(d, d->sa[i], i) == 1)
			i++;
		else
			return (-1);
	}
	return (0);
}