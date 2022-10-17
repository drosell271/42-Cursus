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
# define BUFFER_SIZE	5
# include	<stdlib.h>
# include	<unistd.h>
# include	<limits.h>

# include	<stdarg.h>
# include	<fcntl.h>

# include	<stdio.h>

//get_next_line.c
char	*insert(char *buffer,char *output);
char	*get_next_line(int fd);

//get_next_line_utils.c
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strlcat(char *dest, const char *src, size_t size);
void	ft_bzero(void *s, int n);
void	*ft_calloc(size_t count, size_t size);

#endif