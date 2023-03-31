/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_3-4-5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:44:11 by drosell-          #+#    #+#             */
/*   Updated: 2023/03/12 17:44:11 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

/*
La primera función size3 recibe un puntero a un array de enteros s y un puntero a una estructura t_list llamada d. Esta función se encarga de ordenar un array de 3 enteros utilizando distintas operaciones como sa, rra, ra, entre otras.
*/
void	size3(int *s, t_list *d)
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
La segunda función size4 también recibe un puntero a un array de enteros s y un puntero a una estructura t_list llamada d. En esta función se ordena un array de 4 enteros utilizando distintas operaciones como sa, ra, rra, pb, entre otras.
*/
void	size4(int *s, t_list *d)
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
		size3(d->sa, d);
	pa(d);
}

/*
La tercera función size5_2 recibe un puntero a un array de enteros s, un puntero a una estructura t_list llamada d y un entero i. En esta función se ordena un array de 5 enteros utilizando distintas operaciones como ra, rra, pb, sa. La variable i es utilizada como un flag para determinar si ya se realizó alguna operación de intercambio en el array.
*/
int	size5_2(int *s, t_list *d, int i)
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

/*
Esta función, llamada size5, es una función que se encarga de ordenar una lista de 5 números utilizando el algoritmo de ordenamiento conocido como "sort de selección", donde se selecciona el número más pequeño y se lo coloca al principio de la lista, y se repite este proceso con los números restantes. Si la lista es de tamaño 5, la función verifica en primer lugar si el número más pequeño está en la primera posición, y si no lo está, lo mueve allí utilizando la función pb para enviar el número a la pila b. Luego, la función llama a size4 para ordenar los cuatro números restantes en la pila a. Finalmente, si el número más pequeño fue movido al principio de la lista (y por lo tanto se encuentra en la pila b), la función lo mueve de regreso a la pila a utilizando pa, y verifica si es necesario ordenar la lista utilizando la función sa para colocar los números en orden ascendente.
*/
void	size5(int *s, t_list *d)
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
		i = size5_2(d->sa, d, i);
	}
	size4(d->sa, d);
	if (i == 1)
	{
		pa(d);
		if (s[0] > s[1])
			sa(d->sa);
	}
}