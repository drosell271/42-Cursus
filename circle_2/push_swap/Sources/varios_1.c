/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   varios_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 21:13:05 by drosell-          #+#    #+#             */
/*   Updated: 2023/04/01 21:13:05 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	liberar(t_list *d)
{
	if (d->sa)
	{
		free(d->sa);
	}
	if (d->sb)
	{
		free(d->sb);
	}
	if (d->sp)
	{
		free(d->sp);
	}
	if (d)
	{
		free(d);
	}
	write(2, "Error\n", 6);
	exit(0);
}

void	liberar2(t_list *d)
{
	if (d->sa)
	{
		free(d->sa);
		d->sa = NULL;
	}
	if (d->sb)
	{
		free(d->sb);
		d->sb = NULL;
	}
	if (d->sp)
	{
		free(d->sp);
		d->sp = NULL;
	}
	if (d)
	{
		free(d);
		d = NULL;
	}
	exit(0);
}

void	calcular(t_list *d)
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
		if (d->control == 2)
		{
			d->lsp = d->lsp - 2;
			d->control = 0;
			sa(d->sa);
			rra(d);
		}
	}
	else
		rb(d);
}

int	comprueba_movimiento(t_list *d)
{
	int	i;

	i = 0;
	while (i <= d->sib - 1)
	{
		if (d->sb[i] == d->lsp)
			break ;
		i++;
	}
	if ((d->sib / 2) - i >= 0)
		return (0);
	else
		return (-1);
}

void	sort(t_list *d)
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