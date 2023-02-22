/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 22:26:33 by drosell-          #+#    #+#             */
/*   Updated: 2023/02/22 22:26:33 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"

static void	action(int sig, siginfo_t *info, void *context)
{
	// Usamos variables estáticas para mantener el estado entre las llamadas a esta función
	static int				i = 0;
	static pid_t			client_pid = 0;
	static unsigned char	c = 0;

	(void)context;

	// Si es la primera vez que recibimos una señal, guardamos el PID del cliente
	if (!client_pid)
		client_pid = info->si_pid;

	// Agregamos un bit a nuestro búfer dependiendo de la señal recibida
	c |= (sig == SIGUSR2);

	// Cuando llegamos al octavo bit, procesamos el byte
	if (++i == 8)
	{
		i = 0;

		// Si el byte es cero, enviamos una señal al cliente y reiniciamos el estado
		if (!c)
		{
			kill(client_pid, SIGUSR2);
			client_pid = 0;
			return ;
		}

		// Si el byte no es cero, escribimos el carácter en la salida estándar
		ft_putchar_fd(c, 1);
		c = 0;

		// Enviamos una señal al cliente indicando que hemos procesado el byte
		kill(client_pid, SIGUSR1);
	}
	else
	{
		// Desplazamos el último bit recibido para prepararnos para recibir el siguiente
		c <<= 1;
	}
}

int	main(void)
{
	struct sigaction	s_sigaction;

	// Mostramos el PID del servidor
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);

	// Configuramos las señales para que llamen a nuestra función de manejo
	s_sigaction.sa_sigaction = action;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);

	// Esperamos por señales
	while (1)
	{
		pause();
	}

	// Este return nunca se alcanza
	return (0);
}
