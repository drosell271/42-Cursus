/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_1b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:44:01 by drosell-          #+#    #+#             */
/*   Updated: 2023/03/12 17:44:01 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
La función "pb" se utiliza para mover el primer elemento de la pila "sa" a la pila "sb" en la estructura "t_list". La función no devuelve ningún valor.
*/
void	pb(t_list *d)
{
	int	i;

	i = d->sib;
	d->sib = d->sib + 1;
	d->sia = d->sia - 1;
	while (i > 0)
	{
		swap(&d->sb[i], &d->sb[i - 1]);
		i--;
	}
	d->sb[0] = d->sa[0];
	i = 0;
	while (i <= d->sia - 1)
	{
		d->sa[i] = d->sa[i + 1];
		i++;
	}
	write(1, "pb\n", 3);
}

/*
La función "rb" se utiliza para rotar hacia arriba los elementos de la pila "sb" en la estructura "t_list". La función no devuelve ningún valor.
*/
void	rb(t_list *d)
{
	int	i;

	i = 0;
	while (i + 1 < d->sib)
	{
		swap(&d->sb[i], &d->sb[i + 1]);
		i++;
	}
	write(1, "rb\n", 3);
}

/*
La función "rrb" se utiliza para rotar hacia abajo los elementos de la pila "sb" en la estructura "t_list". La función no devuelve ningún valor.
*/
void	rrb(t_list *d)
{
	int	i;
	int	j;

	i = d->sib - 1;
	j = 0;
	while (i - 1 >= 0)
	{
		swap(&d->sb[i], &d->sb[i - 1]);
		i--;
	}
	write(1, "rrb\n", 4);
}

/*
La función "sb" se utiliza para intercambiar los dos primeros elementos de la pila "sb" en la estructura "t_list". La función recibe un puntero a la pila "sb" como argumento y no devuelve ningún valor.
*/
void	sb(int *sb)
{
	int	temp;

	temp = sb[0];
	sb[0] = sb[1];
	sb[1] = temp;
	write(1, "sb\n", 3);
}
