/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:48:28 by drosell-          #+#    #+#             */
/*   Updated: 2023/03/12 17:48:28 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
Esta función, llamada "check_args", comprueba si los argumentos recibidos son válidos para ser utilizados en un programa determinado.
*/
int	check_args(char **args, int argc)
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
Esta función, llamada "check_num", comprueba si una cadena de caracteres "s" es un número válido.
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
Esta función, llamada "check_order", comprueba si la pila de enteros "sa" en una estructura "t_list" está ordenada de manera ascendente.
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
Esta es una función estática llamada "ft_check" que verifica si un número entero "num" ya existe en la pila "sa" de la estructura "t_list" hasta la posición "j" (no inclusivo).
*/
static	int	ft_check(t_list *d, int num, int j)
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
Esta función, llamada "check_same_nums", comprueba si hay números repetidos en la pila "sa" de la estructura "t_list".
*/
int	check_same_nums(t_list *d)
{
	int	i;

	i = 0;
	while (i <= d->sia - 1)
	{
		if (ft_check(d, d->sa[i], i) == 1)
			i++;
		else
			return (-1);
	}
	return (0);
}