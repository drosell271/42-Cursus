/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 20:56:40 by drosell-          #+#    #+#             */
/*   Updated: 2023/04/01 20:56:40 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

/*
La función rr realiza la operación "rotate" en dos arreglos de enteros d->sa y
d->sb, simulando una operación de pila. La función mueve todos los elementos
de los arreglos una posición hacia arriba, dejando el primer elemento en la
última posición de cada arreglo, y escribe el mensaje "rr" en la salida
estándar.
*/
void	rr(t_list *d)
{
	int	i;

	i = 0;
	while (i + 1 < d->sia)
	{
		swap(&d->sa[i], &d->sa[i + 1]);
		i++;
	}
	i = 0;
	while (i + 1 < d->sib)
	{
		swap(&d->sb[i], &d->sb[i + 1]);
		i++;
	}
	write(1, "rr\n", 3);
}

/*
La función rrr realiza la operación "reverse rotate" en dos arreglos de
enteros d->sa y d->sb, simulando una operación de pila. La función mueve
todos los elementos de los arreglos una posición hacia abajo, dejando
el último elemento en la primera posición de cada arreglo, y escribe
el mensaje "rrr" en la salida estándar.
*/
void	rrr(t_list *d)
{
	int	i;

	i = d->sia - 1;
	while (i > 0)
	{
		swap(&d->sa[i], &d->sa[i - 1]);
		i--;
	}
	i = d->sib - 1;
	while (i - 1 >= 0)
	{
		swap(&d->sb[i], &d->sb[i - 1]);
		i--;
	}
	write(1, "rrr\n", 4);
}

/*
La función swap intercambia los valores de dos enteros a través de
punteros. La función recibe como parámetros dos punteros a enteros,
argv1 y argv2, y almacena temporalmente el valor del primer entero
en una variable temp. Luego, la función intercambia los valores de
los dos enteros, asignando el valor de argv2 a argv1 y el valor de
temp a argv2.
*/
void	swap(int *argv1, int *argv2)
{
	int	temp;

	temp = *argv1;
	*argv1 = *argv2;
	*argv2 = temp;
}
