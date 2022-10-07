/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:43:46 by drosell-          #+#    #+#             */
/*   Updated: 2022/10/07 19:55:24 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

# include <stdio.h>

//ft_printf.c
int	ft_printf(const char *input, ...);
int	select_mode(char input_2, va_list ptr);

//ft_printf_utils_1.c
int	mode_c(va_list ptr);
int	mode_s(va_list ptr);
int mode_d_i(int n, int output);
int mode_u(unsigned int n , int output);
int	mode_x(int n , int output, char *base);

//ft_printf_utils_2.c
int	mode_X(int n , int output, char *base);
int	mode_percent();
int	mode_p(int num , int output, char *base);
#endif
