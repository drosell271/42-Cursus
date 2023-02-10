/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:46:56 by drosell-          #+#    #+#             */
/*   Updated: 2023/01/26 15:25:00 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char *argv[])
{
	t_data	data;
	int		pid;
	int		count;

	count = 0;
	pid = 0;
	if (check_num_of_params(argc) == -1)
		return (1);
	if (check_pid(argv[2]) == -1)
		return (1);
	data.lenght = ft_strlen(argv[3]);
	data.data = ft_calloc(data.lenght, sizeof(char));
	pid = ft_atoi(argv[1]);
	while (data.data[count])
		send(pid, argv[3][count]);
	return (1);
}

int	check_num_of_params(int argc)
{
	if (argc != 3)
	{
		ft_printf("Error en los parametros");
		return (-1);
	}
	return (1);
}

int	check_pid(char *input)
{
	int	counter;
	int	input_lenght;

	counter = 0;
	input_lenght = ft_strlen(input);
	while (counter <= input_lenght)
	{
		if (ft_isdigit(input[counter]) == 0)
		{
			ft_printf("Error en el PID");
			return (-1);
		}
		counter++;
	}
	return (1);
}

void	send(int pid, char input)
{
	int	count;

	count = 0;
	while (8 > count)
	{
		usleep(100);
		if (input & 128)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		input = input & 127;
		input = input << 1;
		count++;
	}
}
