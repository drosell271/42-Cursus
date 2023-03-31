/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_normal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 01:47:42 by gemartin          #+#    #+#             */
/*   Updated: 2023/03/12 17:52:12 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
La función "calc" se utiliza para calcular la próxima operación en la secuencia de operaciones a realizar en las pilas "sa" y "sb" en la estructura "t_list". La función recibe un puntero a la estructura "t_list" como argumento y no devuelve ningún valor.

La función utiliza una estructura de control "if-else" para determinar qué operación realizar a continuación en función del valor del primer elemento de la pila "sb" y de los valores de las variables de control "lsp" y "control".

Si el primer elemento de la pila "sb" es igual al valor de "lsp" - 1, la función realiza la operación "pa" en las pilas y establece la variable de control "control" en 1.

Si el primer elemento de la pila "sb" es igual al valor de "lsp", la función realiza la operación "pa" en las pilas y reduce el valor de "lsp" en 1. A continuación, la función utiliza la variable de control "control" para determinar la siguiente operación a realizar en las pilas:

Si "control" es igual a 1, la función reduce el valor de "lsp" en 1, establece "control" en 0 y realiza la operación "sa" en la pila "sa".
Si "control" es igual a 2, la función reduce el valor de "lsp" en 2, establece "control" en 0, realiza la operación "sa" en la pila "sa" y la operación "rra" en la pila "sa".
Si el primer elemento de la pila "sb" no coincide con ninguno de los valores anteriores, la función realiza la operación "rb" en la pila "sb".

En resumen, la función "calc" se utiliza para calcular la próxima operación en la secuencia de operaciones a realizar en las pilas "sa" y "sb" en la estructura "t_list", en función del valor del primer elemento de la pila "sb" y de los valores de las variables de control "lsp" y "control".
*/
void	calc(t_list *d)
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
		if (d->control == 2)
		{
			d->lsp = d->lsp - 2;
			d->control = 0;
			sa(d->sa);
			rra(d);
		}
	}
	else
		rb(d);
}

/*
La función "check_mov" se utiliza para comprobar si la operación "rb" o "rrb" en la pila "sb" debería ser utilizada para optimizar la secuencia de operaciones en las pilas "sa" y "sb" en la estructura "t_list". La función recibe un puntero a la estructura "t_list" como argumento y devuelve un entero.

La función utiliza una estructura de control "if-else" para determinar si la operación "rb" o "rrb" debería ser utilizada en la pila "sb". Para ello, la función calcula la distancia entre el valor de "lsp" y la posición del primer elemento de la pila "sb" que es igual a "lsp", y compara esta distancia con la mitad de la longitud de la pila "sb". Si la distancia es menor o igual que la mitad de la longitud de la pila "sb", la función devuelve 0, lo que indica que la operación "rb" debería ser utilizada. Si la distancia es mayor que la mitad de la longitud de la pila "sb", la función devuelve -1, lo que indica que la operación "rrb" debería ser utilizada.

En resumen, la función "check_mov" se utiliza para determinar si la operación "rb" o "rrb" debería ser utilizada en la pila "sb" para optimizar la secuencia de operaciones en las pilas "sa" y "sb" en la estructura "t_list", en función de la posición del primer elemento de la pila "sb" que es igual a "lsp" y la longitud de la pila "sb".
*/
int	check_mov(t_list *d)
{
	int	i;

	i = 0;
	while (i <= d->sib - 1)
	{
		if (d->sb[i] == d->lsp)
			break ;
		i++;
	}
	if ((d->sib / 2) - i >= 0)
		return (0);
	else
		return (-1);
}

/*
La función "ordernums_sb_rotate" es una función que se utiliza para ordenar la pila "sb" en la estructura "t_list" cuando se está implementando el algoritmo de ordenamiento "push_swap". La función recibe un puntero a la estructura "t_list" como argumento y no devuelve ningún valor.

La función utiliza una estructura de control "if-else" para comprobar el valor del primer elemento de la pila "sb" ("d->sb[0]") en comparación con el valor de "lsp" en la estructura "t_list". Si el valor del primer elemento de la pila "sb" es igual a "lsp-2" y "control" es igual a 1, la función realiza las operaciones "pa", "ra" y "rrb" en las pilas "sa" y "sb" para colocar el valor en la posición correcta. Si el valor del primer elemento de la pila "sb" es igual a "lsp-1", la función realiza la operación "pa" en la pila "sa" para mover el valor de la pila "sb" a la pila "sa". Si el valor del primer elemento de la pila "sb" es igual a "lsp", la función realiza las operaciones "pa" y "sa" en la pila "sa" para colocar el valor en la posición correcta.

Si el valor del primer elemento de la pila "sb" no es igual a "lsp-2", "lsp-1" o "lsp", la función realiza la operación "rrb" en la pila "sb" para rotar la pila y posiblemente mover el valor a una posición donde se pueda aplicar otra operación para colocarlo en la posición correcta.

En resumen, la función "ordernums_sb_rotate" se utiliza para ordenar la pila "sb" en la estructura "t_list" cuando se está implementando el algoritmo de ordenamiento "push_swap", mediante la realización de operaciones "pa", "ra", "sa" y "rrb" en las pilas "sa" y "sb", según el valor del primer elemento de la pila "sb" y la posición en la que debe ser colocado.
*/
void	ordernums_sb_rotate(t_list *d)
{
	if (d->sb[0] == d->lsp -2 && d->control == 1)
	{
		pa(d);
		ra(d);
		d->control = 2;
	}
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
		rrb(d);
}

/*
Esta función ordena los números de la pila b en orden ascendente y los va pasando uno por uno a la pila a. Primero, se entra en un bucle mientras que la cantidad de elementos en la pila a sea menor al total de elementos que se deben ordenar. Luego, se verifican tres casos diferentes:

1 Si el primer elemento de la pila b es igual al número que debería ser el siguiente en la pila a, entonces se pasa ese número de la pila b a la pila a y se decrementa la variable lsp (la cual representa el número más grande que aún debe ser ordenado).
2 Si el primer elemento de la pila b es igual al número que debería ser el siguiente en la pila a - 2, y la variable control es igual a 1, entonces se pasa ese número de la pila b a la pila a, se rota la pila a hacia arriba, y se cambia el valor de control a 2.
3 Si el primer elemento de la pila b no está en su posición correcta, entonces se ejecuta la función calc(d), que intenta colocar ese número en su posición correcta mediante rotaciones de la pila b y la pila a.
La función check_mov(d) se utiliza para verificar si es más eficiente rotar la pila b hacia arriba o hacia abajo para colocar el número en su posición correcta. Si el número está en la mitad superior de la pila b, entonces se girará hacia abajo para acercarlo a su posición correcta en la parte inferior de la pila b, y viceversa.
*/
void	ordernums_sb(t_list *d)
{
	while (d->sia < d->argc)
	{
		if (d->sb[0] == d->lsp && d->control == 0)
		{
			pa(d);
			d->lsp--;
		}
		if (d->sb[0] == d->lsp -2 && d->control == 1)
		{
			pa(d);
			ra(d);
			d->control = 2;
		}
		if (check_mov(d) == -1)
			ordernums_sb_rotate(d);
		else
			calc(d);
	}
}

/*
Esta función implementa un algoritmo de ordenamiento para una pila de enteros utilizando el método de "quick sort". La función divide la pila en bloques más pequeños, ordena los bloques individualmente y luego combina los bloques para obtener la pila ordenada completa.

El parámetro "d" es una estructura que contiene información relevante para el algoritmo de ordenamiento, como las pilas a ordenar y los límites de los bloques. La función utiliza operaciones como "pb" y "ra" para mover elementos de una pila a otra o rotarlos en una pila.

En general, la función divide la pila en bloques de tamaño "arguments", los ordena y luego utiliza una pila auxiliar "sb" para combinar los bloques ordenados en la pila original. La función utiliza también varias técnicas para optimizar el ordenamiento, como el uso de una variable "lsp" para guardar el valor más alto de un bloque y el uso de un control "control" para identificar la posición de un bloque en relación a otro.

En resumen, la función implementa un algoritmo eficiente de ordenamiento para pilas de enteros utilizando el método de "quick sort" y varias técnicas de optimización.
*/
void	ordernums(t_list *d)
{
	d->arguments = (d->argc / d->cont) * (d->percentage);
	if (d->percentage == d->cont)
		d->arguments = d->argmax - 3;
	while (d->sib < d->arguments && d->percentage <= d->cont)
	{
		if (d->sa[0] < d->arguments)
		{
			pb(d);
			if (d->sb[0] > d->arguments - d->size_block && d->sib > 1)
				rb(d);
		}
		else
			ra(d);
	}
	d->percentage++;
	if (d->sib == d->argmax - 3)
	{
		size3(d->sa, d);
		d->lsp = d->lsp - 3;
	}
	if (d->percentage <= d->cont)
		ordernums(d);
	while (d->percentage-- > 0)
		ordernums_sb(d);
}
