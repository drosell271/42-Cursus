/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:44:17 by drosell-          #+#    #+#             */
/*   Updated: 2023/03/12 17:44:17 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	rr(t_list *d)
{
	int	i;

	i = 0;
	while (i + 1 < d->sia)
	{
		swap(&d->sa[i], &d->sa[i + 1]);
		i++;
	}
	i = 0;
	while (i + 1 < d->sib)
	{
		swap(&d->sb[i], &d->sb[i + 1]);
		i++;
	}
	write(1, "rr\n", 3);
}

void	rrr(t_list *d)
{
	int	i;

	i = d->sia - 1;
	while (i > 0)
	{
		swap(&d->sa[i], &d->sa[i - 1]);
		i--;
	}
	i = d->sib - 1;
	while (i - 1 >= 0)
	{
		swap(&d->sb[i], &d->sb[i - 1]);
		i--;
	}
	write(1, "rrr\n", 4);
}

void	swap(int *argv1, int *argv2)
{
	int	temp;

	temp = *argv1;
	*argv1 = *argv2;
	*argv2 = temp;
}