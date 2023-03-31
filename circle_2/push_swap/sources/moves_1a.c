/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_1a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:44:03 by drosell-          #+#    #+#             */
/*   Updated: 2023/03/12 17:44:03 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
La función "pa" se utiliza para mover el primer elemento de la pila "sb" a la pila "sa" en la estructura "t_list". La función no devuelve ningún valor.
*/
void	pa(t_list *d)
{
	int	i;

	i = d->sia;
	d->sib = d->sib - 1;
	d->sia = d->sia + 1;
	while (i > 0)
	{
		swap(&d->sa[i], &d->sa[i - 1]);
		i--;
	}
	d->sa[0] = d->sb[0];
	i = 0;
	while (i <= d->sib)
	{
		d->sb[i] = d->sb[i + 1];
		i++;
	}
	write(1, "pa\n", 3);
}

/*
La función "ra" se utiliza para rotar hacia arriba los elementos de la pila "sa" en la estructura "t_list". La función no devuelve ningún valor.
*/
void	ra(t_list *d)
{
	int	i;

	i = 0;
	while (i + 1 < d->sia)
	{
		swap(&d->sa[i], &d->sa[i + 1]);
		i++;
	}
	write(1, "ra\n", 3);
}

/*
La función "rra" se utiliza para rotar hacia abajo los elementos de la pila "sa" en la estructura "t_list". La función no devuelve ningún valor.
*/

void	rra(t_list *d)
{
	int	i;

	i = d->sia - 1;
	while (i > 0)
	{
		swap(&d->sa[i], &d->sa[i - 1]);
		i--;
	}
	write(1, "rra\n", 4);
}

/*
La función "sa" se utiliza para intercambiar los dos primeros elementos de la pila "sa". La función recibe un puntero a la pila "sa" como argumento y no devuelve ningún valor.
*/
void	sa(int *sa)
{
	int	temp;

	temp = sa[0];
	sa[0] = sa[1];
	sa[1] = temp;
	write(1, "sa\n", 3);
}
