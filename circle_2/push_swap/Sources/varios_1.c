/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   varios_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 21:13:05 by drosell-          #+#    #+#             */
/*   Updated: 2023/04/01 21:13:05 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

/*
La función liberar libera la memoria asignada dinámicamente para los campos sa,
sb, sp y la propia estructura d en caso de que se hayan asignado previamente,
y luego termina el programa imprimiendo "Error" en la salida de error estándar
y llamando a la función exit con el código de salida 0. Esta función se utiliza
para manejar errores en el programa.
*/
void	liberar(t_list *d)
{
	if (d->sa)
	{
		free(d->sa);
	}
	if (d->sb)
	{
		free(d->sb);
	}
	if (d->sp)
	{
		free(d->sp);
	}
	if (d)
	{
		free(d);
	}
	write(2, "Error\n", 6);
	exit(0);
}

/*
La función liberar2 libera la memoria de los punteros en la estructura t_list
(d) y luego sale del programa. A diferencia de liberar, después de liberar la
memoria, se establece cada puntero en NULL y la variable d se establece en NULL
para evitar errores posteriores en el programa.
*/
void	liberar2(t_list *d)
{
	if (d->sa)
	{
		free(d->sa);
		d->sa = NULL;
	}
	if (d->sb)
	{
		free(d->sb);
		d->sb = NULL;
	}
	if (d->sp)
	{
		free(d->sp);
		d->sp = NULL;
	}
	if (d)
	{
		free(d);
		d = NULL;
	}
	exit(0);
}

/*
Esta función implementa una lógica para ordenar un conjunto de números en una
pila y una pila auxiliar en una sola pila. Si el elemento superior de la pila
auxiliar es el número esperado en la posición final, lo mueve a la pila
original. Si el número no es el esperado, se mueve la pila auxiliar en
sentido horario y se repite el proceso. También tiene en cuenta ciertos casos
especiales para mover varios elementos al mismo tiempo y hacer swaps entre
elementos en la pila original.
*/
void	calcular(t_list *d)
{
	if (d->sb[0] == d->lsp - 1)
	{
		pa(d);
		d->control = 1;
	}
	if (d->sb[0] == d->lsp)
	{
		pa(d);
		d->lsp--;
		if (d->control == 1)
		{
			d->lsp--;
			d->control = 0;
			sa(d->sa);
		}
		if (d->control == 2)
		{
			d->lsp = d->lsp - 2;
			d->control = 0;
			sa(d->sa);
			rra(d);
		}
	}
	else
		rb(d);
}

/*
La función "comprueba_movimiento" verifica si el número en la parte
superior de la pila B está más cerca del fondo o del tope de la pila.
Si está más cerca del fondo, devuelve -1, lo que indica que se debe ejecutar
una rotación hacia abajo en la pila B. Si está más cerca del tope, devuelve
0, lo que indica que no es necesario realizar ninguna rotación en la pila B.
*/
int	comprueba_movimiento(t_list *d)
{
	int	i;

	i = 0;
	while (i <= d->sib - 1)
	{
		if (d->sb[i] == d->lsp)
			break ;
		i++;
	}
	if ((d->sib / 2) - i >= 0)
		return (0);
	else
		return (-1);
}

/*
La función sort recibe un puntero a una estructura t_list, la cual contiene un arreglo
de enteros sp con argc elementos a ordenar. La función ordena el arreglo utilizando
el algoritmo de ordenamiento burbuja, el cual itera sobre el arreglo varias veces,
comparando elementos adyacentes y cambiándolos de lugar si no están en la posición
correcta. Después de cada iteración, el algoritmo disminuye el tamaño del arreglo
que está siendo ordenado en una unidad. La función no devuelve nada, pero modifica
directamente el arreglo sp dentro de la estructura t_list.
*/
void	sort(t_list *d)
{
	int	i;
	int	c;
	int	j;

	i = 0;
	c = 0;
	j = d->argc;
	while (c < j)
	{
		while (i < j - 1)
		{
			if (d->sp[i] > d->sp[i + 1])
				swap(&d->sp[i], &d->sp[i + 1]);
			i++;
		}
		i = 0;
		c++;
	}
}
