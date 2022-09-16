/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:17:31 by drosell-          #+#    #+#             */
/*   Updated: 2022/09/14 17:54:24 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBC_H
#define LIBC_H

	void			ft_bzero(void *s, unsigned int n);
	int				ft_isalnum(int c);
	int				ft_isalpha(int c);
	int				ft_isascii(int c);
	int				ft_isdigit(int c);
	int				ft_isprint(int c);
	void			*ft_memcpy(void *dest, const void *src, unsigned int n);
	void			*ft_memset(void *s, int c, unsigned int n);
	unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
	unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
	unsigned int	ft_strlen(char *s);
	int				ft_strncmp(char *s1, char *s2, unsigned int n);
	int				ft_toupper(int c);
	int				ft_tolower(int c);

#endif
