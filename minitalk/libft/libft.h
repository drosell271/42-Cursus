/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:17:31 by drosell-          #+#    #+#             */
/*   Updated: 2022/11/11 15:17:46 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>

/*
+++++++++++++++++++
PARTES OBLIGATORIAS
+++++++++++++++++++
*/

//LIBFT
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t count, size_t size);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *s, int c, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *s1);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlen(const char *s);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *big, const char *little, \
								size_t len);
char				*ft_strrchr(const char *s, int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
char				*ft_strtrim(char const *s1, char const *set);

//FT_PRINTF
int					ft_printf(const char *input, ...);
int					select_mode(char input_2, va_list ptr);
int					ok_mode(char input_1, char *flags);
int					mode_c(va_list ptr);
int					mode_s(va_list ptr);
int					mode_d_i(int n, int output);
int					mode_u(unsigned int n, int output);
int					mode_xx(int n, int output, char *base);
int					mode_percent(void);
unsigned long long	mode_p(unsigned long long n, int output, char *base);

//GET_NEXT_LINE
char				*get_next_line(int fd);
char				*changer(char *input_1, char *input_2);
char				*reader(int fd, char *input);
char				*new_line(char *input);
char				*cleaner(char *text);

/*
++++++++++++
PARTES BONUS
++++++++++++
*/

//LIBFT
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *nuevo);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstclear(t_list **lst, void (*del)(void*));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *), \
					void (*del)(void *));

//GET_NEXT_LINE_BONUS
char				*get_next_line_bonus(int fd);

#endif
