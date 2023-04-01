/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 21:12:35 by drosell-          #+#    #+#             */
/*   Updated: 2023/04/01 21:12:35 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	main(int arc, char **args)
{
	t_list	*d;

	if (arc == 1)
		return (0);
	d = malloc(sizeof(t_list));
	if (!d)
		return (0);
	if (check_input(args, arc - 1) == -1)
		liberar(d);
	d->argc = arc - 1;
	d->error = 0;
	if (preparar(d) == -1)
		liberar(d);
	if (input_process(d, arc, args) == -1)
	{
		liberar(d);
		return (0);
	}
	if (check_order(d) == -1)
		liberar2(d);
	if (elige_size(arc, d) == -1)
		liberar(d);
	liberar2(d);
	return (0);
}

