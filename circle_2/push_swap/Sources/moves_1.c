/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 20:53:59 by drosell-          #+#    #+#             */
/*   Updated: 2023/04/01 20:53:59 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

/*
La función pa realiza la operación "push" en un arreglo de enteros d->sa y un
arreglo de enteros d->sb, simulando una operación de pila. La función mueve
el elemento superior del arreglo d->sb al arreglo d->sa, actualiza los
índices de los arreglos y escribe el mensaje "pa" en la salida estándar.
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
La función ra realiza la operación "rotate" en un arreglo de enteros d->sa,
simulando una operación de pila. La función mueve todos los elementos
del arreglo d->sa una posición hacia arriba, dejando el primer elemento
en la última posición del arreglo, y escribe el mensaje "ra" en
la salida estándar.
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
La función rra realiza la operación "reverse rotate" en un arreglo de
enteros d->sa, simulando una operación de pila. La función mueve todos
los elementos del arreglo d->sa una posición hacia abajo, dejando el
último elemento en la primera posición del arreglo, y escribe el
mensaje "rra" en la salida estándar.
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
La función sa realiza la operación "swap" en un arreglo de enteros sa,
simulando una operación de pila. La función intercambia los dos
primeros elementos del arreglo sa y escribe el mensaje "sa"
en la salida estándar.
*/
void	sa(int *sa)
{
	int	temp;

	temp = sa[0];
	sa[0] = sa[1];
	sa[1] = temp;
	write(1, "sa\n", 3);
}
