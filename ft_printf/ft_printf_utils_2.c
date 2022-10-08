/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 19:36:05 by drosell-          #+#    #+#             */
/*   Updated: 2022/10/08 13:42:23 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	mode_xx(int n, int output, char *base)
{	
	long	intermedio;
	long	base_size;

	base_size = 16;
	if (n < 0)
		output += write(1, "-", 1);
	intermedio = (unsigned int) n;
	if (intermedio >= base_size)
	{
		output = mode_xx(intermedio / base_size, output, base);
		intermedio = intermedio % base_size;
	}
	if (intermedio < 16)
		output += write(1, &base[intermedio % base_size], 1);
	return (output);
}

int	mode_percent(void)
{
	return (write(1, "%", 1));
}

unsigned long long	mode_p(unsigned long long n, int output, char *base)
{	
	unsigned long long	intermedio;
	unsigned long long	base_size;

	base_size = 16;
	intermedio = (unsigned long long) n;
	if (intermedio >= base_size)
	{
		output = mode_p(intermedio / base_size, output, base);
		intermedio = intermedio % base_size;
	}
	if (intermedio < 16)
		output += write(1, &base[intermedio % base_size], 1);
	return (output);
}
