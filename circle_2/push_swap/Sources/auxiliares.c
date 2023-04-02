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

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_isdigit(int i)
{
	if (i < 48 || i > 57)
		return (0);
	return (1);
}

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