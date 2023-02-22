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

// Definición de la función que maneja la señal recibida
static void handler(int sig, siginfo_t *info, void *context)
{
  static int bit_index = 0;           // Índice del bit actual
  static pid_t client_pid = 0;        // PID del cliente
  static unsigned char message = 0;   // Mensaje recibido

  (void)context;  // Evita advertencias sobre la variable no utilizada

  if (!client_pid)
    client_pid = info->si_pid;

  // Lee el bit recibido
  message |= (sig == SIGUSR2);

  // Verifica si ya se leyeron los 8 bits del mensaje
  if (++bit_index == 8)
  {
    bit_index = 0;

    // Si el mensaje es el carácter nulo, indica que se ha terminado la transmisión
    if (!message)
    {
      // Envia la señal SIGUSR2 al cliente para indicar que se ha terminado la transmisión
      kill(client_pid, SIGUSR2);
      client_pid = 0;
      return ;
    }

    // Muestra el carácter recibido por la salida estándar
    ft_putchar_fd(message, 1);
    message = 0;

    // Envia la señal SIGUSR1 al cliente para indicar que está listo para recibir el siguiente carácter
    kill(client_pid, SIGUSR1);
  }
  else
    message <<= 1;
}

int	main(void)
{
  struct sigaction signal_action;

  // Muestra el PID del servidor
  ft_putstr_fd("Server PID: ", 1);
  ft_putnbr_fd(getpid(), 1);
  ft_putchar_fd('\n', 1);

  // Registra la función manejadora de señales
  signal_action.sa_sigaction = handler;
  signal_action.sa_flags = SA_SIGINFO;
  sigaction(SIGUSR1, &signal_action, 0);
  sigaction(SIGUSR2, &signal_action, 0);

  // Espera a que lleguen señales
  while (1)
    pause();

  return (0);
}
