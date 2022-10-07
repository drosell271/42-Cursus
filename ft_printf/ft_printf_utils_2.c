/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 19:36:05 by drosell-          #+#    #+#             */
/*   Updated: 2022/10/07 19:42:49 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	mode_X(int n , int output, char *base)
{	
	long	intermedio;
	long	base_size;

	base_size = 16;
	if (n < 0)
		output += write(1, "-", 1);
	intermedio = (unsigned int) n;
	if (intermedio >= base_size)
	{
		output = mode_x(intermedio / base_size, output, base);
		intermedio = intermedio % base_size;
	}
	if (intermedio < 16)
		output += write(1, &base[intermedio % base_size], 1);
	return (output);
}

int	mode_percent()
{
	return (write(1, "%", 1));
}

