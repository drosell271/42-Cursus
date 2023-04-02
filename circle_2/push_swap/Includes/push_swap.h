/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 21:16:02 by drosell-          #+#    #+#             */
/*   Updated: 2023/04/01 21:16:02 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include<unistd.h>
# include<stdlib.h>
# include<limits.h>

typedef struct s_list
{
	int	*sa;
	int	*sb;
	int	*sp;
	int	sia;
	int	sib;
	int	sip;
	int	argc;
	int	percentage;
	int	lsp;
	int	control;
	int	cont;
	int	error;
	int	atoierror;
	int	jatoi;
	int	size_block;
	int	argmax;
	int	arguments;
}	t_list;

/*
+++++++++++++++++++
AUXILIARES
+++++++++++++++++++
*/
char	*ft_substr(char *s, int start, int len);
int		ft_strlen(char *s);
int		ft_isdigit(int i);
int		ft_atoi(const char *str, t_list *d);

/*
+++++++++++++++++++
CHECKEOS
+++++++++++++++++++
*/
int		check_input(char **args, int argc);
int		check_num(char *s);
int		check_order(t_list *d);
int		checkeos(t_list *d, int num, int j);
int		check_iguales(t_list *d);

/*
+++++++++++++++++++
MOVES 1
+++++++++++++++++++
*/
void	pa(t_list *d);
void	ra(t_list *d);
void	rra(t_list *d);
void	sa(int *sa);

/*
+++++++++++++++++++
MOVES 2
+++++++++++++++++++
*/
void	pb(t_list *d);
void	rb(t_list *d);
void	rrb(t_list *d);
void	sb(int *sb);

/*
+++++++++++++++++++
MOVES 3
+++++++++++++++++++
*/
void	rr(t_list *d);
void	rrr(t_list *d);
void	swap(int *argv1, int *argv2);

/*
+++++++++++++++++++
ORDENAR
+++++++++++++++++++
*/
void	ordenenar_sbr(t_list *d);
void	ordenenar_sb(t_list *d);
void	ordenenar(t_list *d);
void	ordenenar_s_sb(t_list *d);

/*
+++++++++++++++++++
ORDENAR SMALL
+++++++++++++++++++
*/
void	ordenenar_3(t_list *d, int i);
void	ordenenar_2(t_list *d);
void	ordenenar_s(t_list *d);

/*
+++++++++++++++++++
PUSH SWAP
+++++++++++++++++++
*/
int		main(int arc, char **args);

/*
+++++++++++++++++++
TAMANO BIG
+++++++++++++++++++
*/
void	tamano_100(t_list *d);
void	tamano_500(t_list *d);

/*
+++++++++++++++++++
TAMANO SMALL
+++++++++++++++++++
*/
void	tamano_3(int *s, t_list *d);
void	tamano_4(int *s, t_list *d);
void	tamano_5_1(int *s, t_list *d);
int		tamano_5_2(int *s, t_list *d, int i);

/*
+++++++++++++++++++
VARIOS 1
+++++++++++++++++++
*/
void	liberar(t_list *d);
void	liberar2(t_list *d);
void	calcular(t_list *d);
int		comprueba_movimiento(t_list *d);
void	sort(t_list *d);

/*
+++++++++++++++++++
VARIOS 2
+++++++++++++++++++
*/
void	newnum(t_list *d);
int		gestion_errores(t_list *d, int nbr);
int		elige_size(int arc, t_list *d);
int		input_process(t_list *d, int arc, char **args);
int		preparar(t_list *d);

#endif