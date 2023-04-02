/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tamano_big.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 21:00:45 by drosell-          #+#    #+#             */
/*   Updated: 2023/04/01 21:00:45 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

/*
La función tamano_100() se encarga de ordenar un array de tamaño 100 o mayor.
Primero, se inicializan varias variables necesarias para el algoritmo de
ordenamiento, luego se llama a la función sort() que ordena los números de
manera ascendente y a la función newnum() que crea una lista de los números
únicos y cuántas veces aparecen en el array original. Luego, se verifica si
el tamaño del array es mayor o igual a 20, y se llama a la función ordenenar()
o a la función ordenenar_s(), según sea el caso, para ordenar el array.
*/
void	tamano_100(t_list *d)
{
	d->lsp = d->argc - 1;
	d->control = 0;
	d->percentage = 1;
	d->cont = 4;
	d->size_block = (d->argc / d->cont) / 2;
	d->argmax = d->argc;
	sort(d);
	newnum(d);
	if (d->argc >= 20)
		ordenenar(d);
	else
		ordenenar_s(d);
}

/*
La función tamano_500 se encarga de ordenar una lista de números cuando su
tamaño es de 500 elementos.

Primero se establecen los parámetros iniciales como el valor de lsp
(el cual es el valor más grande en la lista), control, percentage, cont,
size_block y argmax. Luego, se ordena la lista utilizando la función sort
y se crean los nuevos números utilizando la función newnum. Finalmente,
se llama a la función ordenenar para ordenar la lista en general.
*/
void	tamano_500(t_list *d)
{
	d->lsp = d->argc -1;
	d->control = 0;
	d->percentage = 1;
	d->cont = 7;
	d->size_block = (d->argc / d->cont) / 2;
	d->argmax = d->argc;
	sort(d);
	newnum(d);
	ordenenar(d);
}
