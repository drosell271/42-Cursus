/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   changenum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 01:40:05 by gemartin          #+#    #+#             */
/*   Updated: 2023/03/12 17:52:12 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
Esta función, llamada "changenum", cambia los valores numéricos de una cadena de caracteres "sa" en una estructura "t_list" por valores que indican la posición que ocupan en otra cadena de caracteres "sp" dentro de la misma estructura.
*/
void	changenum(t_list *d)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (j < d->argc)
	{
		if (d->sa[j] != d->sp[i])
			i++;
		else
		{
			d->sa[j] = i;
			j++;
			i = 0;
		}
	}
}
