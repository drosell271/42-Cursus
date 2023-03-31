/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:25:41 by gemartin          #+#    #+#             */
/*   Updated: 2023/03/12 17:50:41 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

//int		arg_to_int(t_list *d, int arc, char **args);
//int		ft_choose_size(int arc, t_list *d);
//int		init_data(t_list *d);

/*
Esta es la función principal del programa. Primero se verifica si se ingresaron argumentos, y si no es así, el programa termina. Se reserva memoria para la estructura 'd' y se inicializan algunas de sus variables.

Luego, se verifica que los argumentos sean válidos mediante la función 'check_args', que retorna -1 en caso de que se haya encontrado algún problema en los argumentos. Si esto sucede, se libera la memoria y se termina el programa.

Luego se obtiene la cantidad de argumentos y se convierten de formato de cadena de caracteres a números enteros mediante la función 'arg_to_int'. Si en algún momento se detecta un error, se libera la memoria y se termina el programa.

A continuación, se verifica si los números ya están ordenados mediante la función 'check_order'. Si no están ordenados, se procede a realizar el algoritmo de ordenamiento. Finalmente, se libera la memoria y se termina el programa.

Cabe destacar que si en cualquier momento se detecta un error, se libera la memoria y se termina el programa.
*/
int	main(int arc, char **args)
{
	t_list	*d;

	if (arc == 1)
		return (0);
	d = malloc(sizeof(t_list));
	if (!d)
		return (0);
	if (check_args(args, arc - 1) == -1)
		ft_free(d);
	d->argc = arc - 1;
	d->error = 0;
	if (init_data(d) == -1)
		ft_free(d);
	if (arg_to_int(d, arc, args) == -1)
	{
		ft_free(d);
		return (0);
	}
	if (check_order(d) == -1)
		ft_free2(d);
	if (ft_choose_size(arc, d) == -1)
		ft_free(d);
	ft_free2(d);
	return (0);
}

/*
La función ft_choose_size es llamada desde la función main y se encarga de seleccionar el tamaño del algoritmo a utilizar en función de la cantidad de elementos que se quieren ordenar. Primero, se verifica que los números de entrada no sean todos iguales utilizando la función check_same_nums. Luego, dependiendo del tamaño del arreglo, se elige el algoritmo a utilizar.

Si hay 3 o 4 elementos, se utiliza el algoritmo size3 para ordenarlos. Si hay entre 5 y 101 elementos, se utiliza el algoritmo size5 para ordenarlos. Si hay entre 102 y 500 elementos, se utiliza el algoritmo size100 para ordenarlos. Y si hay más de 500 elementos, se utiliza el algoritmo size500 para ordenarlos.

La función retorna 0 si todo el proceso se realizó correctamente o -1 en caso contrario.
*/
int	ft_choose_size(int arc, t_list *d)
{
	if (check_same_nums(d) == -1)
		return (-1);
	else
	{
		if (arc == 3 || arc == 4)
			size3(d->sa, d);
		if (arc < 7 && arc > 4)
			size5(d->sa, d);
		if (arc < 102 && arc > 6)
			size100(d);
		if (arc > 101)
			size500(d);
	}
	return (0);
}

/*
Esta función convierte los argumentos del programa, que vienen en formato de cadenas de caracteres (char **args), en números enteros (int) y los almacena en dos arreglos: d->sa y d->sp. También verifica que cada argumento sea un número válido mediante la función check_num, y que el número no cause un error de conversión con la función ft_atoi. Si se encuentra algún error en la conversión, la función retorna -1, de lo contrario retorna 0.
*/
int	arg_to_int(t_list *d, int arc, char **args)
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
La función "init_data" inicializa la estructura de datos "t_list" para ser utilizada en el programa. En primer lugar, la función asigna memoria dinámica para tres arreglos de enteros: "sa", "sp" y "sb". "sa" almacena los números originales que se deben ordenar, "sp" es una copia de "sa" que se usará para ordenar, mientras que "sb" se usa como pila auxiliar para el algoritmo de ordenamiento.

Después, la función inicializa algunos campos de la estructura "t_list": "sia" se establece en la cantidad de argumentos recibidos, "sib" se establece en 0, y "sip" se establece en la cantidad de argumentos recibidos.

Si ocurre algún error al asignar memoria dinámica para los arreglos de enteros, la función devuelve -1 para indicar un error. En caso contrario, devuelve 0 para indicar que la estructura de datos se ha inicializado correctamente.
*/
int	init_data(t_list *d)
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
