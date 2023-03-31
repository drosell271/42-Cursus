/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:44:57 by drosell-          #+#    #+#             */
/*   Updated: 2023/03/12 17:44:57 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

/*
Esta función recibe un puntero a una estructura t_list que contiene información sobre los datos a ordenar, y se encarga de ordenar los números contenidos en el array sp de la estructura de forma ascendente utilizando el algoritmo de burbuja. Primero inicializa tres variables: i en 0, c en 0 y j en el tamaño del array sp. Luego, ejecuta un ciclo while que se ejecuta mientras c sea menor a j. Dentro de este ciclo, ejecuta otro ciclo while que se ejecuta mientras i sea menor a j - 1. Dentro de este segundo ciclo, compara el elemento i del array sp con el elemento i + 1, y si el primero es mayor que el segundo, intercambia los valores utilizando la función swap. Al final de cada iteración del ciclo while interno, incrementa i en 1. Cuando se completa un ciclo while interno, reinicia i a 0 y aumenta c en 1. Esto se repite hasta que se hayan comparado todos los elementos del array sp y estén en orden ascendente.
*/
void	sortnum(t_list *d)
{
	int	i;
	int	c;
	int	j;

	i = 0;
	c = 0;
	j = d->argc;
	while (c < j)
	{
		while (i < j - 1)
		{
			if (d->sp[i] > d->sp[i + 1])
				swap(&d->sp[i], &d->sp[i + 1]);
			i++;
		}
		i = 0;
		c++;
	}
}