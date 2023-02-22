/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 22:26:30 by drosell-          #+#    #+#             */
/*   Updated: 2023/02/22 22:26:30 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"

// Función para manejar las señales SIGUSR1 y SIGUSR2
static void signal_handler(int signal)
{
	static int received_signals = 0;

	if (signal == SIGUSR1)
		++received_signals; // Aumenta el contador de señales recibidas
	else
	{
		ft_putnbr_fd(received_signals, 1); // Escribe en la salida estándar la cantidad de señales recibidas
		ft_putchar_fd('\n', 1);			   // Escribe un salto de línea en la salida estándar
		exit(0);						   // Termina el proceso
	}
}

// Función para enviar señales a otro proceso
static void send_signals(int pid, char *string)
{
	int i;
	char c;
	// Itera por cada caracter en la cadena a enviar
	while (*string)
	{
		i = 8;		   // Número de bits en un byte
		c = *string++; // Obtiene el caracter y avanza al siguiente
		// Itera por cada bit en el caracter
		while (i--)
		{
			if (c >> i & 1)			// Si el bit es 1
				kill(pid, SIGUSR2); // Envía la señal SIGUSR2
			else
				kill(pid, SIGUSR1); // Si el bit es 0, envía la señal SIGUSR1
			usleep(100);			// Espera un tiempo para enviar la siguiente señal
		}
	}
	i = 8;
	// Envía 8 señales SIGUSR1 para indicar que se ha terminado de enviar la cadena
	while (i--)
	{
		kill(pid, SIGUSR1);
		usleep(100);
	}
}

int main(int argc, char **argv)
{
	// Verifica que se han pasado los argumentos requeridos
	if (argc != 3 || !ft_strlen(argv[2]))
		return (1);
	ft_putstr_fd("Sent : ", 1);
	ft_putnbr_fd(ft_strlen(argv[2]), 1); // Escribe en la salida estándar la cantidad de caracteres en la cadena a enviar
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("Received: ", 1);
	signal(SIGUSR1, signal_handler);		 // Asigna la función signal_handler a la señal SIGUSR1
	signal(SIGUSR2, signal_handler);		 // Asigna la función signal_handler a la señal SIGUSR2
	send_signals(ft_atoi(argv[1]), argv[2]); // Envía las señales
	while (1)
		pause(); // Pausa el proceso hasta que se reciba una señal
	return (0);
}
