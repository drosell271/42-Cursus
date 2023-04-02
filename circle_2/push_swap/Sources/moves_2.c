/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 20:55:23 by drosell-          #+#    #+#             */
/*   Updated: 2023/04/01 20:55:23 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	pb(t_list *d)
{
	int	i;

	i = d->sib;
	d->sib = d->sib + 1;
	d->sia = d->sia - 1;
	while (i > 0)
	{
		swap(&d->sb[i], &d->sb[i - 1]);
		i--;
	}
	d->sb[0] = d->sa[0];
	i = 0;
	while (i <= d->sia - 1)
	{
		d->sa[i] = d->sa[i + 1];
		i++;
	}
	write(1, "pb\n", 3);
}

void	rb(t_list *d)
{
	int	i;

	i = 0;
	while (i + 1 < d->sib)
	{
		swap(&d->sb[i], &d->sb[i + 1]);
		i++;
	}
	write(1, "rb\n", 3);
}

void	rrb(t_list *d)
{
	int	i;

	i = d->sib - 1;
	while (i - 1 >= 0)
	{
		swap(&d->sb[i], &d->sb[i - 1]);
		i--;
	}
	write(1, "rrb\n", 4);
}

void	sb(int *sb)
{
	int	temp;

	temp = sb[0];
	sb[0] = sb[1];
	sb[1] = temp;
	write(1, "sb\n", 3);
}
