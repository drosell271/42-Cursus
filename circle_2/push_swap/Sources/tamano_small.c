/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tamano_small.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 20:57:55 by drosell-          #+#    #+#             */
/*   Updated: 2023/04/01 20:57:55 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

/*
Esta función se encarga de ordenar un arreglo de 3 elementos.

Primero se comprueba si el arreglo es de longitud 2, en cuyo caso se verifica
si el primer elemento es mayor que el segundo y si es así, se intercambian los
elementos usando la función "sa". Si el arreglo es de longitud 3, se aplican
una serie de comprobaciones y movimientos para colocar los elementos en orden
ascendente utilizando las funciones "sa", "rra" y "ra".
*/
void	tamano_3(int *s, t_list *d)
{
	if (d->argc == 2)
	{
		if (s[0] > s[1])
			sa(s);
	}
	else if (s[0] < s[1] && s[0] < s[2] && s[1] < s[2])
		;
	else if (s[0] < s[1] && s[0] < s[2] && s[1] > s[2])
	{
		rra(d);
		sa(s);
	}
	else if (s[0] > s[1] && s[0] < s[2] && s[1] < s[2])
		sa(s);
	else if (s[0] < s[1] && s[0] > s[2] && s[1] > s[2])
		rra(d);
	else if (s[1] < s[2] && s[0] > s[1] && s[0] > s[2])
		ra(d);
	else if (s[1] > s[2] && s[0] > s[1] && s[0] > s[2])
	{
		ra(d);
		sa(s);
	}
}

/*
La función "tamano_4" recibe una lista de 4 elementos "s" y un puntero a la
estructura "t_list" llamado "d". Esta función se encarga de ordenar los
elementos de la lista de manera que los 2 elementos más pequeños se coloquen
en la pila B, y los 2 elementos más grandes permanezcan en la pila A. Si la
lista tiene 3 elementos, llama a la función "tamano_3" para ordenarlos.

En ambos casos, la función termina devolviendo los elementos de la pila B a
la pila A en orden ascendente.
*/
void	tamano_4(int *s, t_list *d)
{
	if (d->sia == 4)
	{
		if (s[0] < s[1] && s[0] < s[2] && s[0] < s[3] && d->sia == 4)
			pb(d);
		if (s[0] > s[1] && s[1] < s[2] && s[1] < s[3] && d->sia == 4)
		{
			sa(d->sa);
			pb(d);
		}
		if (s[0] > s[2] && s[1] > s[2] && s[2] < s[3] && d->sia == 4)
		{
			ra(d);
			sa(d->sa);
			pb(d);
		}
		if (s[0] > s[3] && s[1] > s[3] && s[2] > s[3] && d->sia == 4)
		{
			rra(d);
			pb(d);
		}
	}
	if (d->sia == 3)
		tamano_3(d->sa, d);
	pa(d);
}

/*
La función tamano_5_1 es una función auxiliar para ordenar un array de tamaño 5.
La función utiliza la función tamano_5_2 para continuar ordenando el array de
entrada. Después de ordenar el array con la función tamano_5_2, la función
ordena los 4 elementos restantes utilizando la función tamano_4, y luego
verifica si el elemento en la cima de la pila auxiliar necesita ser devuelto a
la pila original y si es así, lo devuelve y continúa ordenando los elementos en
la pila original.
*/
void	tamano_5_1(int *s, t_list *d)
{
	int	i;

	i = 0;
	if (d->sia == 5)
	{
		if (s[0] < s[1] && s[0] < s[2] && s[0] < s[3] && s[0] < s[4] && i == 0)
		{
			pb(d);
			i++;
		}
		if (s[0] > s[1] && s[1] < s[2] && s[1] < s[3] && s[1] < s[4] && i == 0)
		{
			sa(d->sa);
			pb(d);
			i++;
		}
		i = tamano_5_2(d->sa, d, i);
	}
	tamano_4(d->sa, d);
	if (i == 1)
	{
		pa(d);
		if (s[0] > s[1])
			sa(d->sa);
	}
}

/*
La función tamano_5_2 recibe un puntero a un arreglo de enteros s, un puntero a
una estructura t_list llamada d y un entero i. La función compara los elementos
del arreglo s y realiza operaciones de push y rotación en la pila d->sa para
ordenar los elementos de manera ascendente. Si encuentra un número menor que los
otros 4, lo mueve a la pila d->sb mediante un push. Si logra mover un número a la
pila d->sb, devuelve un valor de 1. En caso contrario, devuelve el valor original
de i, que es 0.
*/
int	tamano_5_2(int *s, t_list *d, int i)
{
	if (s[0] > s[2] && s[1] > s[2] && s[2] < s[3] && s[2] < s[4] && i == 0)
	{
		ra(d);
		sa(d->sa);
		pb(d);
		i++;
	}
	if (s[0] > s[3] && s[1] > s[3] && s[2] > s[3] && s[3] < s[4] && i == 0)
	{
		rra(d);
		rra(d);
		pb(d);
		i++;
	}
	if (s[0] > s[4] && s[1] > s[4] && s[2] > s[4] && s[3] > s[4] && i == 0)
	{
		rra(d);
		pb(d);
		i++;
	}
	return (i);
}
