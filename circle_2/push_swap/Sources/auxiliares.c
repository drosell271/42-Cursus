/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliares.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 20:59:11 by drosell-          #+#    #+#             */
/*   Updated: 2023/04/01 20:59:11 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

/*
La función ft_substr toma una cadena de caracteres s, un índice de inicio start
y una longitud len, y devuelve una nueva cadena de caracteres que es una
subcadena de s que comienza en el índice start y tiene una longitud de len.
*/
char	*ft_substr(char *s, int start, int len)
{
	int		i;
	char	*temp;

	i = 0;
	if (!s)
		return (0);
	if (len > ft_strlen(s))
		temp = malloc(sizeof(char) * (ft_strlen(s) + 1));
	else
		temp = malloc(sizeof(char) * (len + 1));
	if (!temp)
		return (0);
	while (start < ft_strlen(s) && i < len && s[start])
	{
		temp[i] = s[start];
		i++;
		start++;
	}
	temp[i] = '\0';
	return (temp);
}

/*
La función ft_strlen toma una cadena de caracteres s como entrada y devuelve
la longitud de la cadena.
*/
int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*
La función ft_isdigit toma un valor entero i que representa el código ASCII
de un carácter como entrada y devuelve 1 si el carácter es un dígito
decimal (0 a 9), y 0 en caso contrario.
*/
int	ft_isdigit(int i)
{
	if (i < 48 || i > 57)
		return (0);
	return (1);
}

/*
La función ft_atoi convierte una cadena de caracteres str que representa
un número en un entero de tipo int. La función también acepta un puntero
a una estructura de lista d que se utiliza para gestionar errores en caso
de que el número esté fuera del rango de un entero de tipo int.
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
			return (gestion_errores(d, nbr));
		if (nbr > INT_MAX && valorfinal == 1)
			return (gestion_errores(d, nbr));
	}
	return (nbr * valorfinal);
}
