/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 01:32:11 by gemartin          #+#    #+#             */
/*   Updated: 2023/03/12 17:52:12 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

//int	ft_error(t_list *d, int nbr);


/*
La función "ft_atoi" convierte una cadena de caracteres "str" en un número entero. La función también recibe una estructura "t_list" como argumento.
*/
int	ft_atoi(const char *str, t_list *d)
{
	int				i;
	int				valorfinal;
	long long int	nbr;

	nbr = 0;
	i = 0;
	valorfinal = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			valorfinal = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
		if (nbr > ((long long int)INT_MAX + 1) && valorfinal == -1)
			return (ft_error(d, nbr));
		if (nbr > INT_MAX && valorfinal == 1)
			return (ft_error(d, nbr));
	}
	return (nbr * valorfinal);
}


/*
La función "ft_error" probablemente se utiliza para manejar errores en un programa que utiliza la función "ft_atoi" para convertir una cadena de caracteres en un número entero. La función recibe una estructura "t_list" y un número entero "nbr".

La función establece el valor de "nbr" a cero, lo que probablemente indica que se ha producido un error al convertir la cadena en un número entero.
*/
int	ft_error(t_list *d, int nbr)
{
	nbr = 0;
	d->atoierror = 1;
	return (nbr);
}
