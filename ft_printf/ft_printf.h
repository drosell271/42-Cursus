/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:43:46 by drosell-          #+#    #+#             */
/*   Updated: 2022/10/08 17:04:19 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

//ft_printf.c
int					ft_printf(const char *input, ...);
int					select_mode(char input_2, va_list ptr);

//ft_printf_utils_1.c
int					mode_c(va_list ptr);
int					mode_s(va_list ptr);
int					mode_d_i(int n, int output);
int					mode_u(unsigned int n, int output);

//ft_printf_utils_2.c
int					mode_xx(int n, int output, char *base);
int					mode_percent(void);
unsigned long long	mode_p(unsigned long long n, int output, char *base);

#endif
