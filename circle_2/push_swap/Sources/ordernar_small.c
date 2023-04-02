/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordernar_small.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 20:59:37 by drosell-          #+#    #+#             */
/*   Updated: 2023/04/01 20:59:37 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

/*
La función ordenenar_3 recibe un puntero a una estructura t_list y un número
entero i. Esta función es utilizada para ordenar una lista de tres elementos.

Primero, se entra en un bucle while que se ejecutará mientras i sea mayor o
igual a 0. Dentro del bucle, se verifica si el primer elemento de la lista sa
es igual a i. Si es así, se llama a la función pb para mover el elemento de
la lista sa a la lista sb, y se decrementa i. Si no es así, se llama a la
función ra para rotar la lista sa.

Después de salir del bucle, se llama a la función ordenenar_s_sb para ordenar
la lista sb.
*/
void	ordenenar_3(t_list *d, int i)
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
	ordenenar_s_sb(d);
}

/*
La función ordenenar_2 recibe una estructura t_list y tiene como objetivo
ordenar la pila sa cuando solo hay dos elementos.

Primero se inicializa la variable i con el valor de lsp, que representa
el número más grande en la pila. Luego, mientras la pila sb tenga menos
de un elemento, se ejecuta un bucle que comprueba si el primer elemento
de la pila sa es igual a i. Si es así, se mueve el elemento a la pila sb
con la función pb(). Si no es igual a i, se rota la pila sa hacia arriba
con la función ra().
*/
void	ordenenar_2(t_list *d)
{
	int	i;

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
La función "ordenenar_s" es parte del algoritmo de ordenamiento
"push_swap". Esta función se encarga de mover un bloque de elementos
del array "sa" al array "sb", y luego ordenarlos dentro del array "sb".

Primero, la función recorre el array "sa" y verifica si el elemento
actual es igual a "i" (que inicialmente es el valor del "lsp" o last
significant position). Si es así, lo mueve del array "sa" al array "sb"
mediante la función "pb". Luego, decrementa el valor de "i" en uno.

Si el elemento actual de "sa" no es igual a "i", mueve todos los
elementos del array "sa" un lugar a la derecha mediante la función "ra".

Después de mover todos los elementos necesarios al array "sb", se
llama a la función "ordenenar_s_sb" para ordenarlos en el array "sb",
y luego se llama a la función "ordenenar_3" para ordenar los elementos
restantes en el array "sa".
*/
void	ordenenar_s(t_list *d)
{
	int	i;

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
	ordenenar_s_sb(d);
	ordenenar_3(d, i);
}
