/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:57:33 by drosell-          #+#    #+#             */
/*   Updated: 2022/10/07 19:01:15 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	mode_c(va_list ptr)
{
	char input;
	
	input = va_arg (ptr, int);
	return (write(1, &input, 1));
}

int	mode_s(va_list ptr)
{
	char *input;
	int counter;

	input = va_arg (ptr, char *);
	counter = 0;
	while(input[counter])
	{
		write(1, &input[counter], 1);
		counter++;
	}
	return (counter);
}

int mode_d_i(int n, int output)
{
	char	caracter;

	if (n < 0)
	{
		if (n == -2147483648)
			return (write(1, "-2147483648", 11));
		output += write(1, "-", 1);
		n = n * -1;
	}
	if (n >= 10)
	{
		output = mode_d_i(n / 10, output);
		n = n % 10;
	}
	if (n < 10)
	{
		caracter = n + 48;
		output += write(1, &caracter, 1);
	}
	return (output);
}

int mode_u(unsigned int n , int output)
{
	char	caracter;

	if (n >= 10)
	{
		output = mode_d_i(n / 10, output);
		n = n % 10;
	}
	if (n < 10)
	{
		caracter = n + 48;
		output += write(1, &caracter, 1);
	}
	return (output);
}
