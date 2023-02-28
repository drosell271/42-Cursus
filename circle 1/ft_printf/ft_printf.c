/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:12:11 by drosell-          #+#    #+#             */
/*   Updated: 2022/10/08 19:48:23 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ok_mode(char input_1, char *flags)
{
	int		counter;

	counter = 0;
	while (flags[counter])
	{
		if (input_1 == flags[counter])
			return (0);
		counter++;
	}
	return (-1);
}

int	select_mode(char input_2, va_list ptr)
{
	if (input_2 == 'c')
		return (mode_c(ptr));
	else if (input_2 == 's')
		return (mode_s(ptr));
	else if (input_2 == 'p')
	{
		write(1, "0x", 2);
		return (mode_p (va_arg (ptr, unsigned long long),
				2, "0123456789abcdef"));
	}
	else if (input_2 == 'd' || input_2 == 'i')
		return (mode_d_i(va_arg (ptr, int), 0));
	else if (input_2 == 'u')
		return (mode_u(va_arg (ptr, unsigned int), 0));
	else if (input_2 == 'x')
		return (mode_xx(va_arg (ptr, int), 0, "0123456789abcdef"));
	else if (input_2 == 'X')
		return (mode_xx(va_arg (ptr, int), 0, "0123456789ABCDEF"));
	else if (input_2 == '%')
		return (mode_percent());
	else
		return (0);
}

int	ft_printf(const char *input, ...)
{
	va_list	ptr;
	int		c_input;
	int		total_print;

	c_input = 0;
	total_print = 0;
	va_start (ptr, input);
	while ((char) input[c_input])
	{
		if ((char) input[c_input] == '%')
		{	
			if (ok_mode((char) input[c_input + 1], "cspdiucxX%") == 0)
			{
				total_print += select_mode((char) input[c_input + 1], ptr);
				c_input++;
			}
		}
		else
			total_print += (write(1, &input[c_input], 1));
		c_input++;
	}
	va_end (ptr);
	return (total_print);
}
