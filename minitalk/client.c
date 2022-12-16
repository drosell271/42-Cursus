/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:39:34 by drosell-          #+#    #+#             */
/*   Updated: 2022/12/16 13:52:45 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

void	int_to_binary(int input, int pid)
{	
	int	count;
	int	actual_speed;

	count = 1;
	while (count <= 8)
	{	
		if (check_sended(send_binary(input, pid), ))
		{
			input = input << 1;
			count++;
		}
	}
}

int	send_binary(int input, int pid)
{
	if (input & 128)
	{
		kill(pid, SIGUSR1);
		return (1);
	}
	else
	{
		kill(pid, SIGUSR2);
		return (0);
	}
}

int	check_sended(int sended)
{

}
