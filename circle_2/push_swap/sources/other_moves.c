/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:44:17 by drosell-          #+#    #+#             */
/*   Updated: 2023/03/12 17:44:17 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

/*
La función rr realiza un intercambio circular en ambas pilas, es decir, desplaza todos los elementos una posición hacia arriba. Primero se realiza el intercambio en la pila a y luego en la pila b. Al final, se escribe en la salida estándar el mensaje "rr\n".
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
La función rrr es similar a la función rr, pero en lugar de rotar hacia arriba los elementos de las pilas sa y sb, rota hacia abajo. Es decir, se toma el último elemento de cada pila y se mueve al primer lugar. Luego, se mueve el segundo elemento de cada pila al segundo lugar, y así sucesivamente hasta que se ha rotado toda la pila. La función también escribe "rrr\n" en la salida estándar para indicar que se ha ejecutado el comando rrr.
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
La función swap recibe dos punteros a enteros y los intercambia. Primero se guarda el valor del primer puntero en una variable temporal, luego se sobreescribe el valor del primer puntero con el valor del segundo puntero y, finalmente, se sobreescribe el valor del segundo puntero con el valor temporal. Es decir, esta función se utiliza para intercambiar dos elementos de una lista.
*/
void	swap(int *argv1, int *argv2)
{
	int	temp;
	
	temp = *argv1;
	*argv1 = *argv2;
	*argv2 = temp;
}