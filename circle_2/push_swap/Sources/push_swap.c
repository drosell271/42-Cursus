/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosell- <drosell-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 21:12:35 by drosell-          #+#    #+#             */
/*   Updated: 2023/04/01 21:12:35 by drosell-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

/*
Esta función es la función principal del programa. En resumen, lo que hace es:

1. Crea una estructura t_list llamada d con memoria dinámica y comprueba que
se haya creado correctamente.

2. Comprueba que la entrada del programa sea válida mediante la función
check_input y libera la memoria si no lo es.

3. Establece el número de argumentos (sin contar el nombre del programa)
y el valor de error en 0.

4. Prepara la estructura d llamando a la función preparar. Si esta función
devuelve -1, libera la memoria y sale del programa.

5. Procesa la entrada del usuario y guarda los valores en la estructura d.
Si la función input_process devuelve -1, libera la memoria y sale del
programa.

6. Comprueba que los números estén desordenados llamando a la función
check_order. Si devuelve -1, libera la memoria y sale del programa.

7. Elige el tamaño del bloque y guarda el resultado en la estructura d.
Si devuelve -1, libera la memoria y sale del programa.

8. Libera la memoria y termina el programa.
*/
int	main(int arc, char **args)
{
	t_list	*d;

	if (arc == 1)
		return (0);
	d = malloc(sizeof(t_list));
	if (!d)
		return (0);
	if (check_input(args, arc - 1) == -1)
		liberar(d);
	d->argc = arc - 1;
	d->error = 0;
	if (preparar(d) == -1)
		liberar(d);
	if (input_process(d, arc, args) == -1)
	{
		liberar(d);
		return (0);
	}
	if (check_order(d) == -1)
		liberar2(d);
	if (elige_size(arc, d) == -1)
		liberar(d);
	liberar2(d);
	return (0);
}
