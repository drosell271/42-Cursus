/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_100-500.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:44:13 by drosell-          #+#    #+#             */
/*   Updated: 2023/03/12 17:44:13 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

/*
La función size100 ordena un array de enteros que contiene 100 o menos elementos utilizando una variedad de algoritmos de ordenamiento que se aplican en función del tamaño del array. Primero se inicializan algunas variables importantes, como lsp, control, percentage, cont, size_block y argmax. A continuación, se utiliza la función sortnum para ordenar una sección del array. Luego, se llama a la función changenum para cambiar de posición algunos números del array, con el fin de mejorar su ordenamiento. A continuación, se verifica el tamaño del array y se llama a la función ordernums si el tamaño es mayor o igual a 20, o a ordernums_peq si el tamaño es menor a 20.
*/
void	size100(t_list *d)
{
	d->lsp = d->argc - 1;
	d->control = 0;
	d->percentage = 1;
	d->cont = 4;
	d->size_block = (d->argc / d->cont) / 2;
	d->argmax = d->argc;
	sortnum(d);
	changenum(d);
	if (d->argc >= 20)
		ordernums(d);
	else
		ordernums_peq(d);
}

/*
Esta función implementa el algoritmo de ordenamiento para una lista de 500 números. En primer lugar, se inicializan algunas variables que se utilizan en el proceso de ordenamiento. A continuación, se ordenan los primeros 20 números de la lista utilizando la función sortnum(). Después, se agrupan los números en bloques de tamaño size_block y se ordenan utilizando la función changenum(). Finalmente, se ordenan los números de manera global utilizando la función ordernums().
*/
void	size500(t_list *d)
{
	d->lsp = d->argc -1;
	d->control = 0;
	d->percentage = 1;
	d->cont = 7;
	d->size_block = (d->argc / d->cont) / 2;
	d->argmax = d->argc;
	sortnum(d);
	changenum(d);
	ordernums(d);
}
