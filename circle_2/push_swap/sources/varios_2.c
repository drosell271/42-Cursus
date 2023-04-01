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

#include "./so_long.h"

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

int	gestion_errores(t_list *d, int nbr)
{
	nbr = 0;
	d->atoierror = 1;
	return (nbr);
}

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

int	preparar(t_list *d)
{
	d->sa = malloc(sizeof(int) * d->argc);
	if (!d->sa)
	{
		liberar(d);
		return (-1);
	}
	d->sp = malloc(sizeof(int) * d->argc);
	if (!d->sp)
	{
		liberar(d->sa);
		liberar(d);
		return (-1);
	}
	d->sb = malloc(sizeof(int) * d->argc);
	if (!d->sb)
	{
		liberar(d->sp);
		liberar(d->sa);
		liberar(d);
		return (-1);
	}
	d->sia = d->argc;
	d->sib = 0;
	d->sip = d->argc;
	return (0);
}
