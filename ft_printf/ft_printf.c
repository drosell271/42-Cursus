/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:12:11 by drosell-          #+#    #+#             */
/*   Updated: 2022/10/07 15:00:12 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libftprintf.h"

int ft_printf(const char *input, ...)
{
	va_list	ptr;
	int		counter_input;
	int		total_print;

	counter_input = 0;
	va_start (ptr, input);
	while (input[counter_input])
	{
		if (input[counter_input] == '%')
		{
			if (input[counter_input + 1] != '%')
			{
					
			}
			else
			{
				write (1, '%', 1);
				counter_input++;
			}
		}
		else
		{
			write(1, &input[counter_input], 1);
		}
		if (input[counter_input])
			counter_input++;
	}
	
	


	return (total_print);
}