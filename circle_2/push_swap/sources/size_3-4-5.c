/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_3-4-5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:44:11 by drosell-          #+#    #+#             */
/*   Updated: 2023/03/12 17:44:11 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	size3(int *s, t_list *d)
{
	if (d->argc == 2)
	{
		if (s[0] > s[1])
			sa(s);
	}
	else if (s[0] < s[1] && s[0] < s[2] && s[1] < s[2])
		;
	else if (s[0] < s[1] && s[0] < s[2] && s[1] > s[2])
	{
		rra(d);
		sa(s);
	}
	else if (s[0] > s[1] && s[0] < s[2] && s[1] < s[2])
		sa(s);
	else if (s[0] < s[1] && s[0] > s[2] && s[1] > s[2])
		rra(d);
	else if (s[1] < s[2] && s[0] > s[1] && s[0] > s[2])
		ra(d);
	else if (s[1] > s[2] && s[0] > s[1] && s[0] > s[2])
	{
		ra(d);
		sa(s);
	}
}

void	size4(int *s, t_list *d)
{
	if (d->sia == 4)
	{
		if (s[0] < s[1] && s[0] < s[2] && s[0] < s[3] && d->sia == 4)
			pb(d);
		if (s[0] > s[1] && s[1] < s[2] && s[1] < s[3] && d->sia == 4)
		{
			sa(d->sa);
			pb(d);
		}
		if (s[0] > s[2] && s[1] > s[2] && s[2] < s[3] && d->sia == 4)
		{
			ra(d);
			sa(d->sa);
			pb(d);
		}
		if (s[0] > s[3] && s[1] > s[3] && s[2] > s[3] && d->sia == 4)
		{
			rra(d);
			pb(d);
		}
	}
	if (d->sia == 3)
		size3(d->sa, d);
	pa(d);
}

int	size5_2(int *s, t_list *d, int i)
{
	if (s[0] > s[2] && s[1] > s[2] && s[2] < s[3] && s[2] < s[4] && i == 0)
	{
		ra(d);
		sa(d->sa);
		pb(d);
		i++;
	}
	if (s[0] > s[3] && s[1] > s[3] && s[2] > s[3] && s[3] < s[4] && i == 0)
	{
		rra(d);
		rra(d);
		pb(d);
		i++;
	}
	if (s[0] > s[4] && s[1] > s[4] && s[2] > s[4] && s[3] > s[4] && i == 0)
	{
		rra(d);
		pb(d);
		i++;
	}
	return (i);
}

void	size5(int *s, t_list *d)
{
	int	i;

	i = 0;
	if (d->sia == 5)
	{
		if (s[0] < s[1] && s[0] < s[2] && s[0] < s[3] && s[0] < s[4] && i == 0)
		{
			pb(d);
			i++;
		}
		if (s[0] > s[1] && s[1] < s[2] && s[1] < s[3] && s[1] < s[4] && i == 0)
		{
			sa(d->sa);
			pb(d);
			i++;
		}
		i = size5_2(d->sa, d, i);
	}
	size4(d->sa, d);
	if (i == 1)
	{
		pa(d);
		if (s[0] > s[1])
			sa(d->sa);
	}
}