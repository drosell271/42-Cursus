/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   varios_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 21:14:01 by drosell-          #+#    #+#             */
/*   Updated: 2023/04/01 21:14:01 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

/*
Esta función recibe un puntero a una estructura t_list llamada d que contiene
información sobre la lista a ordenar. La función recorre los elementos de la
lista original (almacenados en el arreglo sa de d) y para cada elemento
encuentra su posición en el arreglo ordenado (almacenado en el arreglo sp
de d). Luego actualiza el valor del elemento en el arreglo sa con su nueva
posición en el arreglo ordenado. De esta manera, los elementos de la lista
original están representados por números enteros que indican su posición en
la lista ordenada, lo que facilita el proceso de ordenamiento.
*/
void	newnum(t_list *d)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (j < d->argc)
	{
		if (d->sa[j] != d->sp[i])
			i++;
		else
		{
			d->sa[j] = i;
			j++;
			i = 0;
		}
	}
}

/*
La función gestion_errores parece estar diseñada para gestionar errores en
la conversión de cadenas de caracteres a enteros (atoi). Recibe como
parámetros un puntero a una estructura t_list y un número entero nbr,
pero en realidad el valor de nbr no se utiliza en la función y se
inicializa a 0 al principio de la función. La función establece el
valor del campo atoierror en la estructura t_list en 1, lo que indica
que se ha producido un error en la conversión de una cadena de caracteres
a un número entero. Luego, la función devuelve el valor de nbr, que
siempre es 0. En resumen, esta función parece estar diseñada para actualizar
el estado de la estructura t_list para indicar que se ha producido un
error en la conversión de una cadena de caracteres a un número entero.
*/
int	gestion_errores(t_list *d, int nbr)
{
	nbr = 0;
	d->atoierror = 1;
	return (nbr);
}

/*
La función elige_size determina el tamaño del conjunto de números
que se va a ordenar y luego llama a la función correspondiente para
ordenar el conjunto. Si hay números repetidos en la entrada, la función
devuelve -1. Si el tamaño del conjunto es de 3 o 4, llama a la función
tamano_3, si es entre 5 y 6, llama a la función tamano_5_1, si es entre
7 y 101, llama a la función tamano_100, y si es mayor a 101, llama a la
función tamano_500.
*/
int	elige_size(int arc, t_list *d)
{
	if (check_iguales(d) == -1)
		return (-1);
	else
	{
		if (arc == 3 || arc == 4)
			tamano_3(d->sa, d);
		if (arc < 7 && arc > 4)
			tamano_5_1(d->sa, d);
		if (arc < 102 && arc > 6)
			tamano_100(d);
		if (arc > 101)
			tamano_500(d);
	}
	return (0);
}

/*
Esta función procesa los argumentos de entrada del programa, convirtiendo
cada argumento en un número entero y almacenándolos en dos arreglos
diferentes (d->sa y d->sp). También comprueba si hay errores en los
argumentos de entrada y devuelve -1 si encuentra algún error.
*/
int	input_process(t_list *d, int arc, char **args)
{
	int	i;

	i = 0;
	while (i != arc - 1)
	{
		if (check_num(args[i + 1]) == -1)
			return (-1);
		d->sa[i] = ft_atoi(args[i + 1], d);
		if (d->atoierror == 1)
			return (-1);
		d->sp[i] = ft_atoi(args[i + 1], d);
		i++;
	}
	return (0);
}

/*
La función preparar es utilizada para inicializar una lista t_list en la
que se almacenarán los valores a ordenar. La función reserva memoria para
tres arreglos de enteros (sa, sb, y sp) de tamaño argc y los inicializa
con los valores de entrada. También inicializa las variables sia, sib, y
sip en base al tamaño de la lista de entrada. Si ocurre algún error
durante la asignación de memoria, se liberan todas las estructuras
previamente asignadas.
*/
int	preparar(t_list *d)
{
	d->sa = malloc(sizeof(int) * d->argc);
	if (!d->sa)
	{
		free(d);
		return (-1);
	}
	d->sp = malloc(sizeof(int) * d->argc);
	if (!d->sp)
	{
		free(d->sa);
		free(d);
		return (-1);
	}
	d->sb = malloc(sizeof(int) * d->argc);
	if (!d->sb)
	{
		free(d->sp);
		free(d->sa);
		free(d);
		return (-1);
	}
	d->sia = d->argc;
	d->sib = 0;
	d->sip = d->argc;
	return (0);
}
