/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:21:56 by drosell-          #+#    #+#             */
/*   Updated: 2022/10/14 12:36:24 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE	2000
# include	<stdlib.h>
# include	<unistd.h>

# include	<stdarg.h>
# include	<fcntl.h>

# include	<stdio.h>

//get_next_line.c
char	*get_next_line(int fd);
char	*resize(char *input, int add_size);
char	*push_to_output(char *input, char *output);


//get_next_line_utils.c
int		ft_strlen(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);

#endif