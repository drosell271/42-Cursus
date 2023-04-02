/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordenar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 21:10:28 by drosell-          #+#    #+#             */
/*   Updated: 2023/04/01 21:10:28 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

/*
La función ordenar_sbr es una función auxiliar utilizada para ordenar el
arreglo sb en el contexto del algoritmo de ordenamiento de pilas. Recibe
una estructura t_list que contiene los arreglos sa y sb, así como otras
variables de control y límites del arreglo. La función utiliza una serie
de condicionales para determinar qué operaciones realizar en sb. Si el
primer elemento de sb es igual al segundo elemento más grande en sa, y
la variable control es igual a 1, la función llama a las funciones pa y ra,
y establece control en 2. Si el primer elemento de sb es igual al elemento
más grande en sa, la función llama a la función pa y establece control en 1.
Si el primer elemento de sb es igual al siguiente elemento más grande en sa,
la función llama a pa, establece lsp en lsp - 1, y comprueba si control es
igual a 1. Si es así, la función también establece control en 0 y llama a la
función sa en sa. Si el primer elemento de sb no coincide con ninguno de los
valores anteriores, la función llama a la función rrb en sb.
*/
void	ordenenar_sbr(t_list *d)
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
La función ordenenar_sb es una función auxiliar del algoritmo de ordenamiento
de pilas y se encarga de ordenar el arreglo d->sb. Utiliza un ciclo while para
iterar mientras la cantidad de elementos en d->sa es menor que d->argc. Luego,
utiliza condicionales para determinar qué operaciones realizar en d->sb, como
llamar a la función pa si el primer elemento de d->sb es igual a d->lsp,
llamar a las funciones pa y ra si el primer elemento de d->sb es igual al
segundo elemento más grande en d->sa y establecer d->control en 2, o llamar
a la función ordenenar_sbr o calcular según el valor devuelto por la función
comprueba_movimiento.
*/
void	ordenenar_sb(t_list *d)
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
		if (comprueba_movimiento(d) == -1)
			ordenenar_sbr(d);
		else
			calcular(d);
	}
}

/*
La función "ordenenar" es la principal del algoritmo de ordenamiento
de pilas en este código. Utiliza un ciclo while para mover elementos
de la pila A a la pila B hasta que se hayan movido suficientes
elementos. Luego incrementa un porcentaje de elementos a mover y
continúa hasta que se hayan movido todos los elementos. Después
de eso, se llama a la función "ordenenar_sb" para ordenar los
elementos en la pila B.
*/
void	ordenenar(t_list *d)
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
		tamano_3(d->sa, d);
		d->lsp = d->lsp - 3;
	}
	if (d->percentage <= d->cont)
		ordenenar(d);
	while (d->percentage-- > 0)
		ordenenar_sb(d);
}

/*
La función ordenenar_s_sb es utilizada para ordenar los
elementos de d->sb después de que se han movido todos
los elementos de d->sa a d->sb en la función ordenenar.
La función utiliza un ciclo while para mover los
elementos de d->sb de vuelta a d->sa en orden ascendente.

En cada iteración del ciclo while, la función comprueba
si el primer elemento de d->sb es igual a d->lsp - 1.
Si es así, la función llama a la función pa para
mover el elemento a d->sa y establece la variable
d->control en 1.

Si el primer elemento de d->sb es igual a d->lsp,
la función llama a la función pa para mover el elemento
a d->sa, decrementa d->lsp y comprueba si d->control
es igual a 1. Si d->control es igual a 1, se decrementa
d->lsp nuevamente y se llama a la función sa para
ordenar los tres elementos finales de d->sa.

Si el primer elemento de d->sb no es igual a
d->lsp - 1 o d->lsp, la función llama a la función
rb para rotar el arreglo d->sb.

La función continúa iterando hasta que d->sib es igual
a 0, lo que indica que todos los elementos de d->sb se
han movido a d->sa en orden ascendente.
*/
void	ordenenar_s_sb(t_list *d)
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
