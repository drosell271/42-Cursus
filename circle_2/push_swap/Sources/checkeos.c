/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkeos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 21:01:34 by drosell-          #+#    #+#             */
/*   Updated: 2023/04/01 21:01:34 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

/*
La función check_input toma un arreglo de cadenas de caracteres args y un
número entero argc que representa el número de elementos en el arreglo.
La función verifica si cada elemento en el arreglo es un número válido.
Si alguno de los elementos no es un número válido, la función devuelve -1.
Si todos los elementos son números válidos, la función devuelve 0.
*/
int	check_input(char **args, int argc)
{
	int	i;

	i = -1;
	while (++i < argc)
	{
		if (check_num(args[i + 1]) == -1 || *args[i + 1] == '\0')
		{
			return (-1);
		}
	}
	return (0);
}

/*
La función check_num toma una cadena de caracteres s como entrada y verifica
si la cadena representa un número válido. Si la cadena representa un número
válido, la función devuelve 0. Si la cadena no representa un número válido,
la función devuelve -1.
*/
int	check_num(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (
		(s[j] == '-' && (s[j + 1] >= '0' && s[j + 1] <= '9'))
		|| (s[j] >= '0' && s[j] <= '9'))
	{
		i++;
	j++;
		while (s[j])
		{
			if (s[j] >= '0' && s[j] <= '9')
				i++;
			j++;
		}
	}
	if (i == ft_strlen(s))
		return (0);
	return (-1);
}

/*
La función check_order toma un puntero a una estructura de lista d como
entrada y verifica si los elementos en el arreglo d->sa están en orden
ascendente. Si los elementos están en orden ascendente, la función
devuelve 0. Si los elementos no están en orden ascendente, la función
devuelve -1.
*/
int	check_order(t_list *d)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < d->argc - 1)
	{
		if (d->sa[j] < d->sa[j + 1])
			i++;
		j++;
	}
	if (i == j)
		return (-1);
	else
		return (0);
}

/*
La función checkeos toma un puntero a una estructura de lista d,
un número entero num y un índice entero j como entrada. La función
verifica si el número num ya está presente en los primeros j elementos
del arreglo d->sa. Si el número no está presente en el arreglo, la
función devuelve 1. Si el número ya está presente en el arreglo,
la función devuelve 0.
*/
int	checkeos(t_list *d, int num, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		if (d->sa[i] == num)
			return (0);
		i++;
	}
	return (1);
}

/*
La función check_iguales toma un puntero a una estructura de
lista d como entrada y verifica si todos los elementos en
el arreglo d->sa son únicos (es decir, si no hay elementos duplicados).
Si todos los elementos son únicos, la función devuelve 0.
Si hay elementos duplicados, la función devuelve -1.
*/
int	check_iguales(t_list *d)
{
	int	i;

	i = 0;
	while (i <= d->sia - 1)
	{
		if (checkeos(d, d->sa[i], i) == 1)
			i++;
		else
			return (-1);
	}
	return (0);
}
