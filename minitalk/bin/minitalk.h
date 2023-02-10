/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:52:17 by drosell-          #+#    #+#             */
/*   Updated: 2023/01/26 15:25:40 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../extra/libft.h"
# include <signal.h>

typedef struct data {
	int			lenght;
	char		*data;
	long		data_raw;
}	t_data;

/*
+++++++++++++++++++
CLIENT.C
+++++++++++++++++++
*/
int		check_pid(char *input);
int		check_num_of_params(int argc);
int		main(int argc, char *argv[]);
void	send(int pid, char input);

#endif