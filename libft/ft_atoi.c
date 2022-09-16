/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:25:44 by drosell-          #+#    #+#             */
/*   Updated: 2022/09/16 18:06:03 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int special(char test, int num)
{
	if (test == ' ' || test == '\f' || test == '\n' || test == '\r' 
	|| test == '\t' || test == '\v' )
	{
		return (1);
	}
	return(0);
}

int check_signo(char test, int signo)
{
	if(signo == 0)
	{
		if (test == '-')
			return (1);
		if (test == '+')
			return (2);
	}
	if
}

int	atoi(const char *str)
{
	int	c;
	int signo;
	int value;

	c = 0;
	signo = 0;
	value = 0;
	while(str[c] != '\0')
	{
		if (signo == 0 )
		{
			if (str[c] == '-')
				signo = 1;
			if (str[c] == '+')
				signo = 2;
		}
		else
		{
			
		}
		c++;
	}
}
