/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_1a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:44:03 by drosell-          #+#    #+#             */
/*   Updated: 2023/03/12 17:44:03 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	pa(t_list *d)
{
	int	i;

	i = d->sia;
	d->sib = d->sib - 1;
	d->sia = d->sia + 1;
	while (i > 0)
	{
		swap(&d->sa[i], &d->sa[i - 1]);
		i--;
	}
	d->sa[0] = d->sb[0];
	i = 0;
	while (i <= d->sib)
	{
		d->sb[i] = d->sb[i + 1];
		i++;
	}
	write(1, "pa\n", 3);
}

void	ra(t_list *d)
{
	int	i;

	i = 0;
	while (i + 1 < d->sia)
	{
		swap(&d->sa[i], &d->sa[i + 1]);
		i++;
	}
	write(1, "ra\n", 3);
}

void	rra(t_list *d)
{
	int	i;

	i = d->sia - 1;
	while (i > 0)
	{
		swap(&d->sa[i], &d->sa[i - 1]);
		i--;
	}
	write(1, "rra\n", 4);
}

void	sa(int *sa)
{
	int	temp;

	temp = sa[0];
	sa[0] = sa[1];
	sa[1] = temp;
	write(1, "sa\n", 3);
}
