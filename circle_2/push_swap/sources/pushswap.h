/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 01:26:42 by gemartin          #+#    #+#             */
/*   Updated: 2023/03/12 17:52:05 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define PUSHSWAP_H

# include<unistd.h>
# include<stdlib.h>
# include<limits.h>

/*
Esta es la definición de la estructura t_list. Tiene varios campos que se utilizan para almacenar información importante para el programa de ordenamiento. Algunos de los campos importantes son:

sa: un puntero a un array de enteros que contiene los números a ordenar.
sb: un puntero a un array de enteros que se utiliza como stack auxiliar en el algoritmo de ordenamiento.
sp: un puntero a un array de enteros que se utiliza para almacenar una copia del array original antes de ordenarlo.
sia, sib, sip: enteros que indican el tamaño actual de los stacks sa, sb, y sp respectivamente.
argc: un entero que indica la cantidad de argumentos (números) que se recibieron en la línea de comandos.
percentage: un entero que se utiliza para dividir el array en bloques más pequeños.
lsp: un entero que indica el número más grande que falta por ordenar.
control: un entero que se utiliza para indicar si se está ordenando un bloque de dos o tres elementos.
cont: un entero que indica el número de bloques que se van a utilizar para dividir el array original.
error: un entero que se utiliza para indicar si hubo algún error en el programa.
atoierror: un entero que se utiliza para indicar si hubo algún error al convertir un número de la línea de comandos de una cadena a un entero.
jatoi: un entero que se utiliza como índice para la conversión de números de la línea de comandos.
size_block: un entero que indica el tamaño de los bloques en los que se divide el array original.
argmax: un entero que indica el tamaño máximo del stack sb.
arguments: un entero que indica la cantidad de argumentos que se deben mover en cada bloque del algoritmo de ordenamiento.
*/
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

char	*ft_substr(char *s, int start, int len);
int		main(int argc, char **argv);
int		ft_strlen(char *s);
int		ft_atoi(const char *str, t_list *d);
int		check_same_nums(t_list *d);
int		check_order(t_list *d);
int		ft_isdigit(int i);
int		ft_space(char *s);
int		check_num(char *s);
int		ft_arg2_to_int(char *s, t_list *d);
int		check_args(char **args, int argc);
void	swap(int *argv1, int *argv2);
void	sortnum(t_list *d);
void	changenum(t_list *d);
void	ordernums(t_list *d);
void	sa(int *sa);
void	rra(t_list *d);
void	rrb(t_list *d);
void	ra(t_list *d);
void	size3(int *s, t_list *d);
void	size5(int *s, t_list *d);
void	size100(t_list *d);
void	size500(t_list *d);
void	pa(t_list *d);
void	pb(t_list *d);
void	ordernums_peq(t_list *d);
void	rb(t_list *d);
void	rr(t_list *d);
void	rrr(t_list *d);
void	ft_free(t_list *d);
void	ft_free2(t_list *d);

#endif
