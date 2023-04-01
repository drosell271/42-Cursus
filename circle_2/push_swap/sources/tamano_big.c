/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tamano_big.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 21:00:45 by drosell-          #+#    #+#             */
/*   Updated: 2023/04/01 21:00:45 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	tamano_100(t_list *d)
{
	d->lsp = d->argc - 1;
	d->control = 0;
	d->percentage = 1;
	d->cont = 4;
	d->size_block = (d->argc / d->cont) / 2;
	d->argmax = d->argc;
	sort(d);
	newnum(d);
	if (d->argc >= 20)
		ordenenar(d);
	else
		ordenenar_s(d);
}

void	tamano_500(t_list *d)
{
	d->lsp = d->argc -1;
	d->control = 0;
	d->percentage = 1;
	d->cont = 7;
	d->size_block = (d->argc / d->cont) / 2;
	d->argmax = d->argc;
	sort(d);
	newnum(d);
	ordenenar(d);
}