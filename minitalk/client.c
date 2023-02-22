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

// Estructura para almacenar datos entre llamadas a la función de manejo de señal
typedef struct {
    int received;
    int byte_index;
    char current_byte;
} signal_data_t;

// Función que se llama cuando se recibe una señal
static void handle_signal(int sig, siginfo_t *info, void *context)
{
    signal_data_t *data = (signal_data_t *)context;
    
    if (sig == SIGUSR1) {
        data->current_byte |= (1 << data->byte_index);
        ++data->byte_index;
    } else {
        ++data->received;
        data->current_byte |= (1 << data->byte_index);
        ++data->byte_index;
    }
    
    // Si se ha recibido un byte completo, imprimirlo y reiniciar los datos
    if (data->byte_index >= 8) {
        if (data->current_byte == '\0') {
            ft_putnbr_fd(data->received, 1);
            ft_putchar_fd('\n', 1);
            exit(0);
        }
        data->byte_index = 0;
        data->current_byte = 0;
    }
}

// Envia una cadena de caracteres al proceso con PID 'pid'
static void send_string(int pid, const char *str)
{
    // Enviar longitud de la cadena al proceso receptor
    int length = ft_strlen(str);
    ft_putstr_fd("Sent    : ", 1);
    ft_putnbr_fd(length, 1);
    ft_putchar_fd('\n', 1);
    kill(pid, SIGUSR1);
    usleep(100);
    
    int i = 0;
    while (i < length) {
        // Enviar cada caracter de la cadena, uno por uno
        char c = str[i];
        int j = 0;
        while (j < 8) {
            if (c & (1 << j))
                kill(pid, SIGUSR2);
            else
                kill(pid, SIGUSR1);
            usleep(100);
            ++j;
        }
        ++i;
    }
    
    // Enviar un byte nulo para indicar el final de la cadena
    i = 0;
    while (i < 8) {
        kill(pid, SIGUSR1);
        usleep(100);
        ++i;
    }
}

int main(int argc, char **argv)
{
    if (argc != 3 || !ft_strlen(argv[2]))
        return (1);
    
    // Configurar la estructura para almacenar datos entre llamadas a la función de manejo de señal
    signal_data_t data = {0, 0, 0};
    struct sigaction action = {0};
    action.sa_sigaction = handle_signal;
    action.sa_flags = SA_SIGINFO;
    action.sa_ctx = (void *)&data;
    sigaction(SIGUSR1, &action, NULL);
    sigaction(SIGUSR2, &action, NULL);
    
    // Enviar la cadena de caracteres al proceso receptor
    send_string(ft_atoi(argv[1]), argv[2]);
    
    // Esperar señales infinitamente
    while (1)
        pause();
    
    return (0);
}
