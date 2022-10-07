/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:12:11 by drosell-          #+#    #+#             */
/*   Updated: 2022/10/07 19:01:09 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	select_mode(char input_2, va_list ptr)
{
	if (input_2 == 'c')
		return (mode_c(ptr));
	else if (input_2 == 's')
		return (mode_s(ptr));
	/*else if (input_2 == 'p')
		return (mode_p((char *) va_arg (ptr, int)));*/
	else if (input_2 == 'd' || input_2 == 'i')
		return (mode_d_i(va_arg (ptr, int), 0));
	else if (input_2 == 'u')
		return (mode_u(va_arg (ptr, unsigned int), 0));
	/*else if (input_2 == 'x')
		mode_x();
	else if (input_2 == 'X')
		mode_X_mayus();
	else if (input_2 == '%')
		mode_percent();
	else*/
		return (0);
}

int	ft_printf(const char *input, ...)
{
	va_list	ptr;
	int		counter_input;
	int		total_print;

	counter_input = 0;
	total_print = 0;
	va_start (ptr, input);
	while ((char) input[counter_input])
	{
		if ((char) input[counter_input] == '%')
		{
			total_print += select_mode((char) input[counter_input + 1], ptr);
			counter_input++;
		}
		else
		{
			write(1, &input[counter_input], 1);
			total_print++;
		}
		if ((char) input[counter_input] == '%'
			&& (char) input[counter_input + 1] == '%')
			counter_input += 2;
		else
			counter_input++;
	}
	va_end (ptr);
	return (total_print);
}

int	main()
{
	int var1;
	int var2;
	
	printf("P11: hola como estás\n");
	ft_printf("P12: hola como estás\n");

	var1 = printf("P21: hola %u adios\n", 1234);
	var2 = ft_printf("P22: hola %u adios\n", 1234);
	printf("%d\n", var1);
	printf("%d\n", var2);
	return (0);
}