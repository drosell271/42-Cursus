/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_small.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:49:23 by gemartin          #+#    #+#             */
/*   Updated: 2023/03/12 17:52:12 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
La función "ordernums_peq_sb" se encarga de ordenar los números que quedan en la pila "sb" cuando se ha llegado al final del algoritmo y ésta tiene un tamaño menor a un cierto umbral determinado. Básicamente, mueve los números de la pila "sb" a la pila "sa" de forma ordenada, usando las operaciones "pa", "sa" y "rb" según corresponda.
*/
void	ordernums_peq_sb(t_list *d)
{
	while (d->sib > 0)
	{
		if (d->sb[0] == d->lsp - 1)
		{
			pa(d);
			d->control = 1;
		}
		if (d->sb[0] == d->lsp)
		{
			pa(d);
			d->lsp--;
			if (d->control == 1)
			{
				d->lsp--;
				d->control = 0;
				sa(d->sa);
			}
		}
		else
			rb(d);
	}
}

/*
Esta función recibe como parámetros un puntero a una estructura de tipo t_list y un entero i. La función es utilizada para ordenar un conjunto de números almacenados en un array sa de la estructura t_list cuando dicho array tiene como máximo 3 elementos.

La función se encarga de ordenar los elementos del array sa en el array sb utilizando las funciones pb y ra. En primer lugar, la función itera sobre los elementos del array sa desde la posición 0 hasta la posición i. Si el elemento en la posición 0 del array sa es igual a i, entonces se llama a la función pb para insertar el elemento en la posición 0 del array sb, y se decrementa el valor de i. Si el elemento en la posición 0 del array sa no es igual a i, entonces se llama a la función ra para rotar el array sa hacia arriba. Este proceso se repite hasta que todos los elementos del array sa han sido movidos al array sb.

Finalmente, se llama a la función ordernums_peq_sb para ordenar los elementos del array sb.
*/
void	ordernums_peq3(t_list *d, int i)
{
	while (i >= 0)
	{
		if (d->sa[0] == i)
		{
			pb(d);
			i--;
		}
		else
			ra(d);
	}
	ordernums_peq_sb(d);
}

/*
La función ordernums_peq2 tiene como objetivo ordenar los números en la pila sa cuando la cantidad de elementos en dicha pila es menor o igual a 2.

La función comienza declarando dos variables enteras i y j inicializadas en 0, y asigna el valor de d->lsp a la variable i.

Luego, se entra en un bucle while que continúa mientras la cantidad de elementos en la pila sb sea menor que 1.

Dentro del bucle, se verifica si el elemento en el tope de la pila sa es igual a i, y si es así se ejecuta la función pb para colocarlo en la pila sb. Si no, se ejecuta la función ra para rotar los elementos en la pila sa.

En resumen, la función coloca los elementos en la pila sa en la pila sb en orden decreciente, de manera que el elemento más grande quede en el tope de la pila sb. Sin embargo, en caso de que haya un solo elemento en la pila sa, la función no hace nada ya que no es necesario ordenarlo.
*/
void	ordernums_peq2(t_list *d)
{
	int	i;
	int	j;

	j = 0;
	i = d->lsp;
	while (d->sib < 1)
	{
		if (d->sa[0] == i)
			pb(d);
		else
			ra(d);
	}
}

/*
Esta función se encarga de ordenar los números en el caso de que la cantidad de números en la pila b sea menor o igual a la mitad de la cantidad total de números.

Lo que hace la función es mover los elementos mayores a la mitad de la pila a a la pila b hasta que la cantidad de elementos en la pila b sea mayor a la mitad de la cantidad total de elementos.

Luego, llama a la función ordernums_peq_sb para ordenar la pila b.

Finalmente, llama a la función ordernums_peq3 para ordenar los últimos 3 elementos de la pila a.Esta función se encarga de ordenar los números en el caso de que la cantidad de números en la pila b sea menor o igual a la mitad de la cantidad total de números.

Lo que hace la función es mover los elementos mayores a la mitad de la pila a a la pila b hasta que la cantidad de elementos en la pila b sea mayor a la mitad de la cantidad total de elementos.

Luego, llama a la función ordernums_peq_sb para ordenar la pila b.

Finalmente, llama a la función ordernums_peq3 para ordenar los últimos 3 elementos de la pila a.
*/
void	ordernums_peq(t_list *d)
{
	int	i;
	int	j;

	j = 0;
	i = d->lsp;
	while (d->sib <= (d->argc / 2))
	{
		if (d->sa[0] == i)
		{
			pb(d);
			i--;
		}
		else
			ra(d);
	}
	ordernums_peq_sb(d);
	ordernums_peq3(d, i);
}
