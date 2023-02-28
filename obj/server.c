/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 22:26:33 by drosell-          #+#    #+#             */
/*   Updated: 2023/02/28 16:23:06 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "../libft/libft.h"

// Definición de la función que maneja la señal recibida
static void	handler(int sig, siginfo_t *info, void *context)
{
	static int				bit_index = 0;
	static pid_t			client_pid = 0;
	static unsigned char	message = 0;

	(void)context;
	if (!client_pid)
		client_pid = info->si_pid;
	message |= (sig == SIGUSR2);
	if (++bit_index == 8)
	{
		bit_index = 0;
		if (!message)
		{
			kill(client_pid, SIGUSR2);
			client_pid = 0;
			return ;
		}
		ft_putchar_fd(message, 1);
		message = 0;
		kill(client_pid, SIGUSR1);
	}
	else
		message <<= 1;
}

int	main(void)
{
	struct sigaction	signal_action;

	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	signal_action.sa_sigaction = handler;
	signal_action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &signal_action, 0);
	sigaction(SIGUSR2, &signal_action, 0);
	while (1)
		pause();
	return (0);
}
