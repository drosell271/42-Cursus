/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 20:55:23 by drosell-          #+#    #+#             */
/*   Updated: 2023/04/01 20:55:23 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

/*
La función pb realiza la operación "push" en un arreglo de enteros d->sa y un
arreglo de enteros d->sb, simulando una operación de pila. La función mueve el
elemento superior del arreglo d->sa al arreglo d->sb, actualiza los índices
de los arreglos y escribe el mensaje "pb" en la salida estándar.
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
La función rb realiza la operación "rotate" en un arreglo de enteros d->sb,
simulando una operación de pila. La función mueve todos los elementos del
arreglo d->sb una posición hacia arriba, dejando el primer elemento en la
última posición del arreglo, y escribe el mensaje "rb" en
la salida estándar.
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
La función rrb realiza la operación "reverse rotate" en un arreglo de
enteros d->sb, simulando una operación de pila. La función mueve todos
los elementos del arreglo d->sb una posición hacia abajo, dejando el
último elemento en la primera posición del arreglo, y escribe el
mensaje "rrb" en la salida estándar.
*/
void	rrb(t_list *d)
{
	int	i;

	i = d->sib - 1;
	while (i - 1 >= 0)
	{
		swap(&d->sb[i], &d->sb[i - 1]);
		i--;
	}
	write(1, "rrb\n", 4);
}

/*
La función sb realiza la operación "swap" en un arreglo de enteros sb,
simulando una operación de pila. La función intercambia los dos
rimeros elementos del arreglo sb y escribe el mensaje "sb"
en la salida estándar.
*/
void	sb(int *sb)
{
	int	temp;

	temp = sb[0];
	sb[0] = sb[1];
	sb[1] = temp;
	write(1, "sb\n", 3);
}
