/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 22:26:30 by drosell-          #+#    #+#             */
/*   Updated: 2023/02/28 16:34:17 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "../libft/libft.h"

static void	signal_handler(int signal)
{
	static int	received_signals = 0;

	if (signal == SIGUSR1)
		++received_signals;
	else
	{
		ft_putnbr_fd(received_signals, 1);
		ft_putchar_fd('\n', 1);
		exit(0);
	}
}

static void	send_signals(int pid, char *string)
{
	int		i;
	char	c;

	while (*string)
	{
		i = 8;
		c = *string++;
		while (i--)
		{
			if (c >> i & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(250);
		}
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR1);
		usleep(300);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !ft_strlen(argv[2]))
		return (1);
	ft_putstr_fd("Sent : ", 1);
	ft_putnbr_fd(ft_strlen(argv[2]), 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("Received: ", 1);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	send_signals(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}
