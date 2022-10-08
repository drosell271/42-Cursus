/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:12:11 by drosell-          #+#    #+#             */
/*   Updated: 2022/10/08 13:41:33 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
			total_print += select_mode((char) input[c_input + 1], ptr);
			c_input++;
		}
		else
		{
			total_print += (write(1, &input[c_input], 1));
		}
		if ((char) input[c_input] == '%' && (char) input[c_input + 1] == '%')
			c_input += 2;
		else
			c_input++;
	}
	va_end (ptr);
	return (total_print);
}

/*int	main()
{
	int var1;
	int var2;
	int x = 50;

	var1 = printf("real: hola %p adios\n", &x);
	var2 = ft_printf("fake: hola %p adios\n", &x);
	printf("%d\n", var1);
	printf("%d\n", var2);
	return (0);
}*/

/*int main()
{
	int n = 5;
	int *p_n;

	p_n = &n;
	printf("Numero: %i\n", *p_n);

	printf("Direccion: %p", p_n);
	return 0;
}*/