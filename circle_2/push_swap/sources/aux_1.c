/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:46:48 by drosell-          #+#    #+#             */
/*   Updated: 2023/03/12 17:46:48 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
/*
Esta función, llamada "ft_substr", toma una cadena de caracteres "s" y devuelve una subcadena que comienza en la posición "start" y tiene una longitud "len".
*/
char	*ft_substr(char *s, int start, int len)
{
	int		i;
	char	*copia;

	i = 0;
	if (!s)
		return (0);
	if (len > ft_strlen(s))
		copia = malloc(sizeof(char) * (ft_strlen(s) + 1));
	else
		copia = malloc(sizeof(char) * (len + 1));
	if (!copia)
		return (0);
	while (start < ft_strlen(s) && i < len && s[start])
	{
		copia[i] = s[start];
		i++;
		start++;
	}
	copia[i] = '\0';
	return (copia);
}

/*
Esta función, llamada "ft_strlen", toma una cadena de caracteres "s" como entrada y devuelve la longitud de la cadena.
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
Esta función, llamada "ft_isdigit", toma un entero "i" como entrada y devuelve 1 si el valor representa un dígito y 0 en caso contrario.
*/
int	ft_isdigit(int i)
{
	if (i < 48 || i > 57)
		return (0);
	return (1);
}

/*
Esta función, llamada "ft_free", libera la memoria asignada por la estructura "t_list" y es llamada en caso de que ocurra algún error.
*/
void	ft_free(t_list *d)
{
	if (d->sa)
	{
		free(d->sa);
	}
	if (d->sb)
	{
		free(d->sb);
	}
	if (d->sp)
	{
		free(d->sp);
	}
	if (d)
	{
		free(d);
	}
	write(2, "Error\n", 6);
	exit(0);
}

/*
Esta función, llamada "ft_free2", libera la memoria asignada por la estructura "t_list" y es llamada en caso de que ocurra algún error.
*/
void	ft_free2(t_list *d)
{
	if (d->sa)
	{
		free(d->sa);
		d->sa = NULL;
	}
	if (d->sb)
	{
		free(d->sb);
		d->sb = NULL;
	}
	if (d->sp)
	{
		free(d->sp);
		d->sp = NULL;
	}
	if (d)
	{
		free(d);
		d = NULL;
	}
	exit(0);
}