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
Esta función, llamada "ft_substr", toma una cadena de caracteres "s" y devuelve una subcadena que comienza en la posición "start" y tiene una longitud "len".
*/
char	*ft_substr(char *s, int start, int len)
{
	int		i;
	char	*copia;

	i = 0;
	if (!s)
		return (0);
	if (len > ft_strlen(s))
		copia = malloc(sizeof(char) * (ft_strlen(s) + 1));
	else
		copia = malloc(sizeof(char) * (len + 1));
	if (!copia)
		return (0);
	while (start < ft_strlen(s) && i < len && s[start])
	{
		copia[i] = s[start];
		i++;
		start++;
	}
	copia[i] = '\0';
	return (copia);
}

/*
Esta función, llamada "ft_strlen", toma una cadena de caracteres "s" como entrada y devuelve la longitud de la cadena.
*/
int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*
Esta función, llamada "ft_isdigit", toma un entero "i" como entrada y devuelve 1 si el valor representa un dígito y 0 en caso contrario.
*/
int	ft_isdigit(int i)
{
	if (i < 48 || i > 57)
		return (0);
	return (1);
}

/*
Esta función, llamada "ft_free", libera la memoria asignada por la estructura "t_list" y es llamada en caso de que ocurra algún error.
*/
void	ft_free(t_list *d)
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
Esta función, llamada "ft_free2", libera la memoria asignada por la estructura "t_list" y es llamada en caso de que ocurra algún error.
*/
void	ft_free2(t_list *d)
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
Esta función, llamada "changenum", cambia los valores numéricos de una cadena de caracteres "sa" en una estructura "t_list" por valores que indican la posición que ocupan en otra cadena de caracteres "sp" dentro de la misma estructura.
*/
void	changenum(t_list *d)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (j < d->argc)
	{
		if (d->sa[j] != d->sp[i])
			i++;
		else
		{
			d->sa[j] = i;
			j++;
			i = 0;
		}
	}
}

/*
Esta función, llamada "check_args", comprueba si los argumentos recibidos son válidos para ser utilizados en un programa determinado.
*/
int	check_args(char **args, int argc)
{
	int	i;

	i = -1;
	while (++i < argc)
	{
		if (check_num(args[i + 1]) == -1 || *args[i + 1] == '\0')
		{
			return (-1);
		}
	}
	return (0);
}

/*
Esta función, llamada "check_num", comprueba si una cadena de caracteres "s" es un número válido.
*/
int	check_num(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (
		(s[j] == '-' && (s[j + 1] >= '0' && s[j + 1] <= '9'))
		|| (s[j] >= '0' && s[j] <= '9'))
	{
		i++;
	j++;
		while (s[j])
		{
			if (s[j] >= '0' && s[j] <= '9')
				i++;
			j++;
		}
	}
	if (i == ft_strlen(s))
		return (0);
	return (-1);
}

/*
Esta función, llamada "check_order", comprueba si la pila de enteros "sa" en una estructura "t_list" está ordenada de manera ascendente.
*/
int	check_order(t_list *d)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < d->argc - 1)
	{
		if (d->sa[j] < d->sa[j + 1])
			i++;
		j++;
	}
	if (i == j)
		return (-1);
	else
		return (0);
}

/*
Esta es una función estática llamada "ft_check" que verifica si un número entero "num" ya existe en la pila "sa" de la estructura "t_list" hasta la posición "j" (no inclusivo).
*/
static	int	ft_check(t_list *d, int num, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		if (d->sa[i] == num)
			return (0);
		i++;
	}
	return (1);
}

/*
Esta función, llamada "check_same_nums", comprueba si hay números repetidos en la pila "sa" de la estructura "t_list".
*/
int	check_same_nums(t_list *d)
{
	int	i;

	i = 0;
	while (i <= d->sia - 1)
	{
		if (ft_check(d, d->sa[i], i) == 1)
			i++;
		else
			return (-1);
	}
	return (0);
}

/*
Esta función, llamada "check_same_nums", comprueba si hay números repetidos en la pila "sa" de la estructura "t_list".
*/
int	check_same_nums(t_list *d)
{
	int	i;

	i = 0;
	while (i <= d->sia - 1)
	{
		if (ft_check(d, d->sa[i], i) == 1)
			i++;
		else
			return (-1);
	}
	return (0);
}

/*
La función "ft_atoi" convierte una cadena de caracteres "str" en un número entero. La función también recibe una estructura "t_list" como argumento.
*/
int	ft_atoi(const char *str, t_list *d)
{
	int				i;
	int				valorfinal;
	long long int	nbr;

	nbr = 0;
	i = 0;
	valorfinal = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			valorfinal = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
		if (nbr > ((long long int)INT_MAX + 1) && valorfinal == -1)
			return (ft_error(d, nbr));
		if (nbr > INT_MAX && valorfinal == 1)
			return (ft_error(d, nbr));
	}
	return (nbr * valorfinal);
}


/*
La función "ft_error" probablemente se utiliza para manejar errores en un programa que utiliza la función "ft_atoi" para convertir una cadena de caracteres en un número entero. La función recibe una estructura "t_list" y un número entero "nbr".

La función establece el valor de "nbr" a cero, lo que probablemente indica que se ha producido un error al convertir la cadena en un número entero.
*/
int	ft_error(t_list *d, int nbr)
{
	nbr = 0;
	d->atoierror = 1;
	return (nbr);
}

/*
La función "pa" se utiliza para mover el primer elemento de la pila "sb" a la pila "sa" en la estructura "t_list". La función no devuelve ningún valor.
*/
void	pa(t_list *d)
{
	int	i;

	i = d->sia;
	d->sib = d->sib - 1;
	d->sia = d->sia + 1;
	while (i > 0)
	{
		swap(&d->sa[i], &d->sa[i - 1]);
		i--;
	}
	d->sa[0] = d->sb[0];
	i = 0;
	while (i <= d->sib)
	{
		d->sb[i] = d->sb[i + 1];
		i++;
	}
	write(1, "pa\n", 3);
}

/*
La función "ra" se utiliza para rotar hacia arriba los elementos de la pila "sa" en la estructura "t_list". La función no devuelve ningún valor.
*/
void	ra(t_list *d)
{
	int	i;

	i = 0;
	while (i + 1 < d->sia)
	{
		swap(&d->sa[i], &d->sa[i + 1]);
		i++;
	}
	write(1, "ra\n", 3);
}

/*
La función "rra" se utiliza para rotar hacia abajo los elementos de la pila "sa" en la estructura "t_list". La función no devuelve ningún valor.
*/

void	rra(t_list *d)
{
	int	i;

	i = d->sia - 1;
	while (i > 0)
	{
		swap(&d->sa[i], &d->sa[i - 1]);
		i--;
	}
	write(1, "rra\n", 4);
}

/*
La función "sa" se utiliza para intercambiar los dos primeros elementos de la pila "sa". La función recibe un puntero a la pila "sa" como argumento y no devuelve ningún valor.
*/
void	sa(int *sa)
{
	int	temp;

	temp = sa[0];
	sa[0] = sa[1];
	sa[1] = temp;
	write(1, "sa\n", 3);
}

/*
La función "pb" se utiliza para mover el primer elemento de la pila "sa" a la pila "sb" en la estructura "t_list". La función no devuelve ningún valor.
*/
void	pb(t_list *d)
{
	int	i;

	i = d->sib;
	d->sib = d->sib + 1;
	d->sia = d->sia - 1;
	while (i > 0)
	{
		swap(&d->sb[i], &d->sb[i - 1]);
		i--;
	}
	d->sb[0] = d->sa[0];
	i = 0;
	while (i <= d->sia - 1)
	{
		d->sa[i] = d->sa[i + 1];
		i++;
	}
	write(1, "pb\n", 3);
}

/*
La función "rb" se utiliza para rotar hacia arriba los elementos de la pila "sb" en la estructura "t_list". La función no devuelve ningún valor.
*/
void	rb(t_list *d)
{
	int	i;

	i = 0;
	while (i + 1 < d->sib)
	{
		swap(&d->sb[i], &d->sb[i + 1]);
		i++;
	}
	write(1, "rb\n", 3);
}

/*
La función "rrb" se utiliza para rotar hacia abajo los elementos de la pila "sb" en la estructura "t_list". La función no devuelve ningún valor.
*/
void	rrb(t_list *d)
{
	int	i;
	int	j;

	i = d->sib - 1;
	j = 0;
	while (i - 1 >= 0)
	{
		swap(&d->sb[i], &d->sb[i - 1]);
		i--;
	}
	write(1, "rrb\n", 4);
}

/*
La función "sb" se utiliza para intercambiar los dos primeros elementos de la pila "sb" en la estructura "t_list". La función recibe un puntero a la pila "sb" como argumento y no devuelve ningún valor.
*/
void	sb(int *sb)
{
	int	temp;

	temp = sb[0];
	sb[0] = sb[1];
	sb[1] = temp;
	write(1, "sb\n", 3);
}

/*
La función "calc" se utiliza para calcular la próxima operación en la secuencia de operaciones a realizar en las pilas "sa" y "sb" en la estructura "t_list". La función recibe un puntero a la estructura "t_list" como argumento y no devuelve ningún valor.

La función utiliza una estructura de control "if-else" para determinar qué operación realizar a continuación en función del valor del primer elemento de la pila "sb" y de los valores de las variables de control "lsp" y "control".

Si el primer elemento de la pila "sb" es igual al valor de "lsp" - 1, la función realiza la operación "pa" en las pilas y establece la variable de control "control" en 1.

Si el primer elemento de la pila "sb" es igual al valor de "lsp", la función realiza la operación "pa" en las pilas y reduce el valor de "lsp" en 1. A continuación, la función utiliza la variable de control "control" para determinar la siguiente operación a realizar en las pilas:

Si "control" es igual a 1, la función reduce el valor de "lsp" en 1, establece "control" en 0 y realiza la operación "sa" en la pila "sa".
Si "control" es igual a 2, la función reduce el valor de "lsp" en 2, establece "control" en 0, realiza la operación "sa" en la pila "sa" y la operación "rra" en la pila "sa".
Si el primer elemento de la pila "sb" no coincide con ninguno de los valores anteriores, la función realiza la operación "rb" en la pila "sb".

En resumen, la función "calc" se utiliza para calcular la próxima operación en la secuencia de operaciones a realizar en las pilas "sa" y "sb" en la estructura "t_list", en función del valor del primer elemento de la pila "sb" y de los valores de las variables de control "lsp" y "control".
*/
void	calc(t_list *d)
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
La función "check_mov" se utiliza para comprobar si la operación "rb" o "rrb" en la pila "sb" debería ser utilizada para optimizar la secuencia de operaciones en las pilas "sa" y "sb" en la estructura "t_list". La función recibe un puntero a la estructura "t_list" como argumento y devuelve un entero.

La función utiliza una estructura de control "if-else" para determinar si la operación "rb" o "rrb" debería ser utilizada en la pila "sb". Para ello, la función calcula la distancia entre el valor de "lsp" y la posición del primer elemento de la pila "sb" que es igual a "lsp", y compara esta distancia con la mitad de la longitud de la pila "sb". Si la distancia es menor o igual que la mitad de la longitud de la pila "sb", la función devuelve 0, lo que indica que la operación "rb" debería ser utilizada. Si la distancia es mayor que la mitad de la longitud de la pila "sb", la función devuelve -1, lo que indica que la operación "rrb" debería ser utilizada.

En resumen, la función "check_mov" se utiliza para determinar si la operación "rb" o "rrb" debería ser utilizada en la pila "sb" para optimizar la secuencia de operaciones en las pilas "sa" y "sb" en la estructura "t_list", en función de la posición del primer elemento de la pila "sb" que es igual a "lsp" y la longitud de la pila "sb".
*/
int	check_mov(t_list *d)
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
La función "ordernums_sb_rotate" es una función que se utiliza para ordenar la pila "sb" en la estructura "t_list" cuando se está implementando el algoritmo de ordenamiento "push_swap". La función recibe un puntero a la estructura "t_list" como argumento y no devuelve ningún valor.

La función utiliza una estructura de control "if-else" para comprobar el valor del primer elemento de la pila "sb" ("d->sb[0]") en comparación con el valor de "lsp" en la estructura "t_list". Si el valor del primer elemento de la pila "sb" es igual a "lsp-2" y "control" es igual a 1, la función realiza las operaciones "pa", "ra" y "rrb" en las pilas "sa" y "sb" para colocar el valor en la posición correcta. Si el valor del primer elemento de la pila "sb" es igual a "lsp-1", la función realiza la operación "pa" en la pila "sa" para mover el valor de la pila "sb" a la pila "sa". Si el valor del primer elemento de la pila "sb" es igual a "lsp", la función realiza las operaciones "pa" y "sa" en la pila "sa" para colocar el valor en la posición correcta.

Si el valor del primer elemento de la pila "sb" no es igual a "lsp-2", "lsp-1" o "lsp", la función realiza la operación "rrb" en la pila "sb" para rotar la pila y posiblemente mover el valor a una posición donde se pueda aplicar otra operación para colocarlo en la posición correcta.

En resumen, la función "ordernums_sb_rotate" se utiliza para ordenar la pila "sb" en la estructura "t_list" cuando se está implementando el algoritmo de ordenamiento "push_swap", mediante la realización de operaciones "pa", "ra", "sa" y "rrb" en las pilas "sa" y "sb", según el valor del primer elemento de la pila "sb" y la posición en la que debe ser colocado.
*/
void	ordernums_sb_rotate(t_list *d)
{
	if (d->sb[0] == d->lsp -2 && d->control == 1)
	{
		pa(d);
		ra(d);
		d->control = 2;
	}
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
	}
	else
		rrb(d);
}

/*
Esta función ordena los números de la pila b en orden ascendente y los va pasando uno por uno a la pila a. Primero, se entra en un bucle mientras que la cantidad de elementos en la pila a sea menor al total de elementos que se deben ordenar. Luego, se verifican tres casos diferentes:

1 Si el primer elemento de la pila b es igual al número que debería ser el siguiente en la pila a, entonces se pasa ese número de la pila b a la pila a y se decrementa la variable lsp (la cual representa el número más grande que aún debe ser ordenado).
2 Si el primer elemento de la pila b es igual al número que debería ser el siguiente en la pila a - 2, y la variable control es igual a 1, entonces se pasa ese número de la pila b a la pila a, se rota la pila a hacia arriba, y se cambia el valor de control a 2.
3 Si el primer elemento de la pila b no está en su posición correcta, entonces se ejecuta la función calc(d), que intenta colocar ese número en su posición correcta mediante rotaciones de la pila b y la pila a.
La función check_mov(d) se utiliza para verificar si es más eficiente rotar la pila b hacia arriba o hacia abajo para colocar el número en su posición correcta. Si el número está en la mitad superior de la pila b, entonces se girará hacia abajo para acercarlo a su posición correcta en la parte inferior de la pila b, y viceversa.
*/
void	ordernums_sb(t_list *d)
{
	while (d->sia < d->argc)
	{
		if (d->sb[0] == d->lsp && d->control == 0)
		{
			pa(d);
			d->lsp--;
		}
		if (d->sb[0] == d->lsp -2 && d->control == 1)
		{
			pa(d);
			ra(d);
			d->control = 2;
		}
		if (check_mov(d) == -1)
			ordernums_sb_rotate(d);
		else
			calc(d);
	}
}

/*
Esta función implementa un algoritmo de ordenamiento para una pila de enteros utilizando el método de "quick sort". La función divide la pila en bloques más pequeños, ordena los bloques individualmente y luego combina los bloques para obtener la pila ordenada completa.

El parámetro "d" es una estructura que contiene información relevante para el algoritmo de ordenamiento, como las pilas a ordenar y los límites de los bloques. La función utiliza operaciones como "pb" y "ra" para mover elementos de una pila a otra o rotarlos en una pila.

En general, la función divide la pila en bloques de tamaño "arguments", los ordena y luego utiliza una pila auxiliar "sb" para combinar los bloques ordenados en la pila original. La función utiliza también varias técnicas para optimizar el ordenamiento, como el uso de una variable "lsp" para guardar el valor más alto de un bloque y el uso de un control "control" para identificar la posición de un bloque en relación a otro.

En resumen, la función implementa un algoritmo eficiente de ordenamiento para pilas de enteros utilizando el método de "quick sort" y varias técnicas de optimización.
*/
void	ordernums(t_list *d)
{
	d->arguments = (d->argc / d->cont) * (d->percentage);
	if (d->percentage == d->cont)
		d->arguments = d->argmax - 3;
	while (d->sib < d->arguments && d->percentage <= d->cont)
	{
		if (d->sa[0] < d->arguments)
		{
			pb(d);
			if (d->sb[0] > d->arguments - d->size_block && d->sib > 1)
				rb(d);
		}
		else
			ra(d);
	}
	d->percentage++;
	if (d->sib == d->argmax - 3)
	{
		size3(d->sa, d);
		d->lsp = d->lsp - 3;
	}
	if (d->percentage <= d->cont)
		ordernums(d);
	while (d->percentage-- > 0)
		ordernums_sb(d);
}

/*
La función "ordernums_peq_sb" se encarga de ordenar los números que quedan en la pila "sb" cuando se ha llegado al final del algoritmo y ésta tiene un tamaño menor a un cierto umbral determinado. Básicamente, mueve los números de la pila "sb" a la pila "sa" de forma ordenada, usando las operaciones "pa", "sa" y "rb" según corresponda.
*/
void	ordernums_peq_sb(t_list *d)
{
	while (d->sib > 0)
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
		}
		else
			rb(d);
	}
}

/*
Esta función recibe como parámetros un puntero a una estructura de tipo t_list y un entero i. La función es utilizada para ordenar un conjunto de números almacenados en un array sa de la estructura t_list cuando dicho array tiene como máximo 3 elementos.

La función se encarga de ordenar los elementos del array sa en el array sb utilizando las funciones pb y ra. En primer lugar, la función itera sobre los elementos del array sa desde la posición 0 hasta la posición i. Si el elemento en la posición 0 del array sa es igual a i, entonces se llama a la función pb para insertar el elemento en la posición 0 del array sb, y se decrementa el valor de i. Si el elemento en la posición 0 del array sa no es igual a i, entonces se llama a la función ra para rotar el array sa hacia arriba. Este proceso se repite hasta que todos los elementos del array sa han sido movidos al array sb.

Finalmente, se llama a la función ordernums_peq_sb para ordenar los elementos del array sb.
*/
void	ordernums_peq3(t_list *d, int i)
{
	while (i >= 0)
	{
		if (d->sa[0] == i)
		{
			pb(d);
			i--;
		}
		else
			ra(d);
	}
	ordernums_peq_sb(d);
}

/*
La función ordernums_peq2 tiene como objetivo ordenar los números en la pila sa cuando la cantidad de elementos en dicha pila es menor o igual a 2.

La función comienza declarando dos variables enteras i y j inicializadas en 0, y asigna el valor de d->lsp a la variable i.

Luego, se entra en un bucle while que continúa mientras la cantidad de elementos en la pila sb sea menor que 1.

Dentro del bucle, se verifica si el elemento en el tope de la pila sa es igual a i, y si es así se ejecuta la función pb para colocarlo en la pila sb. Si no, se ejecuta la función ra para rotar los elementos en la pila sa.

En resumen, la función coloca los elementos en la pila sa en la pila sb en orden decreciente, de manera que el elemento más grande quede en el tope de la pila sb. Sin embargo, en caso de que haya un solo elemento en la pila sa, la función no hace nada ya que no es necesario ordenarlo.
*/
void	ordernums_peq2(t_list *d)
{
	int	i;
	int	j;

	j = 0;
	i = d->lsp;
	while (d->sib < 1)
	{
		if (d->sa[0] == i)
			pb(d);
		else
			ra(d);
	}
}

/*
Esta función se encarga de ordenar los números en el caso de que la cantidad de números en la pila b sea menor o igual a la mitad de la cantidad total de números.

Lo que hace la función es mover los elementos mayores a la mitad de la pila a a la pila b hasta que la cantidad de elementos en la pila b sea mayor a la mitad de la cantidad total de elementos.

Luego, llama a la función ordernums_peq_sb para ordenar la pila b.

Finalmente, llama a la función ordernums_peq3 para ordenar los últimos 3 elementos de la pila a.Esta función se encarga de ordenar los números en el caso de que la cantidad de números en la pila b sea menor o igual a la mitad de la cantidad total de números.

Lo que hace la función es mover los elementos mayores a la mitad de la pila a a la pila b hasta que la cantidad de elementos en la pila b sea mayor a la mitad de la cantidad total de elementos.

Luego, llama a la función ordernums_peq_sb para ordenar la pila b.

Finalmente, llama a la función ordernums_peq3 para ordenar los últimos 3 elementos de la pila a.
*/
void	ordernums_peq(t_list *d)
{
	int	i;
	int	j;

	j = 0;
	i = d->lsp;
	while (d->sib <= (d->argc / 2))
	{
		if (d->sa[0] == i)
		{
			pb(d);
			i--;
		}
		else
			ra(d);
	}
	ordernums_peq_sb(d);
	ordernums_peq3(d, i);
}

/*
La función rr realiza un intercambio circular en ambas pilas, es decir, desplaza todos los elementos una posición hacia arriba. Primero se realiza el intercambio en la pila a y luego en la pila b. Al final, se escribe en la salida estándar el mensaje "rr\n".
*/
void	rr(t_list *d)
{
	int	i;

	i = 0;
	while (i + 1 < d->sia)
	{
		swap(&d->sa[i], &d->sa[i + 1]);
		i++;
	}
	i = 0;
	while (i + 1 < d->sib)
	{
		swap(&d->sb[i], &d->sb[i + 1]);
		i++;
	}
	write(1, "rr\n", 3);
}

/*
La función rrr es similar a la función rr, pero en lugar de rotar hacia arriba los elementos de las pilas sa y sb, rota hacia abajo. Es decir, se toma el último elemento de cada pila y se mueve al primer lugar. Luego, se mueve el segundo elemento de cada pila al segundo lugar, y así sucesivamente hasta que se ha rotado toda la pila. La función también escribe "rrr\n" en la salida estándar para indicar que se ha ejecutado el comando rrr.
*/
void	rrr(t_list *d)
{
	int	i;

	i = d->sia - 1;
	while (i > 0)
	{
		swap(&d->sa[i], &d->sa[i - 1]);
		i--;
	}
	i = d->sib - 1;
	while (i - 1 >= 0)
	{
		swap(&d->sb[i], &d->sb[i - 1]);
		i--;
	}
	write(1, "rrr\n", 4);
}

/*
La función swap recibe dos punteros a enteros y los intercambia. Primero se guarda el valor del primer puntero en una variable temporal, luego se sobreescribe el valor del primer puntero con el valor del segundo puntero y, finalmente, se sobreescribe el valor del segundo puntero con el valor temporal. Es decir, esta función se utiliza para intercambiar dos elementos de una lista.
*/
void	swap(int *argv1, int *argv2)
{
	int	temp;
	
	temp = *argv1;
	*argv1 = *argv2;
	*argv2 = temp;
}

/*
Esta es la función principal del programa. Primero se verifica si se ingresaron argumentos, y si no es así, el programa termina. Se reserva memoria para la estructura 'd' y se inicializan algunas de sus variables.

Luego, se verifica que los argumentos sean válidos mediante la función 'check_args', que retorna -1 en caso de que se haya encontrado algún problema en los argumentos. Si esto sucede, se libera la memoria y se termina el programa.

Luego se obtiene la cantidad de argumentos y se convierten de formato de cadena de caracteres a números enteros mediante la función 'arg_to_int'. Si en algún momento se detecta un error, se libera la memoria y se termina el programa.

A continuación, se verifica si los números ya están ordenados mediante la función 'check_order'. Si no están ordenados, se procede a realizar el algoritmo de ordenamiento. Finalmente, se libera la memoria y se termina el programa.

Cabe destacar que si en cualquier momento se detecta un error, se libera la memoria y se termina el programa.
*/
int	main(int arc, char **args)
{
	t_list	*d;

	if (arc == 1)
		return (0);
	d = malloc(sizeof(t_list));
	if (!d)
		return (0);
	if (check_args(args, arc - 1) == -1)
		ft_free(d);
	d->argc = arc - 1;
	d->error = 0;
	if (init_data(d) == -1)
		ft_free(d);
	if (arg_to_int(d, arc, args) == -1)
	{
		ft_free(d);
		return (0);
	}
	if (check_order(d) == -1)
		ft_free2(d);
	if (ft_choose_size(arc, d) == -1)
		ft_free(d);
	ft_free2(d);
	return (0);
}

/*
La función ft_choose_size es llamada desde la función main y se encarga de seleccionar el tamaño del algoritmo a utilizar en función de la cantidad de elementos que se quieren ordenar. Primero, se verifica que los números de entrada no sean todos iguales utilizando la función check_same_nums. Luego, dependiendo del tamaño del arreglo, se elige el algoritmo a utilizar.

Si hay 3 o 4 elementos, se utiliza el algoritmo size3 para ordenarlos. Si hay entre 5 y 101 elementos, se utiliza el algoritmo size5 para ordenarlos. Si hay entre 102 y 500 elementos, se utiliza el algoritmo size100 para ordenarlos. Y si hay más de 500 elementos, se utiliza el algoritmo size500 para ordenarlos.

La función retorna 0 si todo el proceso se realizó correctamente o -1 en caso contrario.
*/
int	ft_choose_size(int arc, t_list *d)
{
	if (check_same_nums(d) == -1)
		return (-1);
	else
	{
		if (arc == 3 || arc == 4)
			size3(d->sa, d);
		if (arc < 7 && arc > 4)
			size5(d->sa, d);
		if (arc < 102 && arc > 6)
			size100(d);
		if (arc > 101)
			size500(d);
	}
	return (0);
}

/*
Esta función convierte los argumentos del programa, que vienen en formato de cadenas de caracteres (char **args), en números enteros (int) y los almacena en dos arreglos: d->sa y d->sp. También verifica que cada argumento sea un número válido mediante la función check_num, y que el número no cause un error de conversión con la función ft_atoi. Si se encuentra algún error en la conversión, la función retorna -1, de lo contrario retorna 0.
*/
int	arg_to_int(t_list *d, int arc, char **args)
{
	int	i;

	i = 0;
	while (i != arc - 1)
	{
		if (check_num(args[i + 1]) == -1)
			return (-1);
		d->sa[i] = ft_atoi(args[i + 1], d);
		if (d->atoierror == 1)
			return (-1);
		d->sp[i] = ft_atoi(args[i + 1], d);
		i++;
	}
	return (0);
}

/*
La función "init_data" inicializa la estructura de datos "t_list" para ser utilizada en el programa. En primer lugar, la función asigna memoria dinámica para tres arreglos de enteros: "sa", "sp" y "sb". "sa" almacena los números originales que se deben ordenar, "sp" es una copia de "sa" que se usará para ordenar, mientras que "sb" se usa como pila auxiliar para el algoritmo de ordenamiento.

Después, la función inicializa algunos campos de la estructura "t_list": "sia" se establece en la cantidad de argumentos recibidos, "sib" se establece en 0, y "sip" se establece en la cantidad de argumentos recibidos.

Si ocurre algún error al asignar memoria dinámica para los arreglos de enteros, la función devuelve -1 para indicar un error. En caso contrario, devuelve 0 para indicar que la estructura de datos se ha inicializado correctamente.
*/
int	init_data(t_list *d)
{
	d->sa = malloc(sizeof(int) * d->argc);
	if (!d->sa)
	{
		free(d);
		return (-1);
	}
	d->sp = malloc(sizeof(int) * d->argc);
	if (!d->sp)
	{
		free(d->sa);
		free(d);
		return (-1);
	}
	d->sb = malloc(sizeof(int) * d->argc);
	if (!d->sb)
	{
		free(d->sp);
		free(d->sa);
		free(d);
		return (-1);
	}
	d->sia = d->argc;
	d->sib = 0;
	d->sip = d->argc;
	return (0);
}

/*
La primera función size3 recibe un puntero a un array de enteros s y un puntero a una estructura t_list llamada d. Esta función se encarga de ordenar un array de 3 enteros utilizando distintas operaciones como sa, rra, ra, entre otras.
*/
void	size3(int *s, t_list *d)
{
	if (d->argc == 2)
	{
		if (s[0] > s[1])
			sa(s);
	}
	else if (s[0] < s[1] && s[0] < s[2] && s[1] < s[2])
		;
	else if (s[0] < s[1] && s[0] < s[2] && s[1] > s[2])
	{
		rra(d);
		sa(s);
	}
	else if (s[0] > s[1] && s[0] < s[2] && s[1] < s[2])
		sa(s);
	else if (s[0] < s[1] && s[0] > s[2] && s[1] > s[2])
		rra(d);
	else if (s[1] < s[2] && s[0] > s[1] && s[0] > s[2])
		ra(d);
	else if (s[1] > s[2] && s[0] > s[1] && s[0] > s[2])
	{
		ra(d);
		sa(s);
	}
}

/*
La segunda función size4 también recibe un puntero a un array de enteros s y un puntero a una estructura t_list llamada d. En esta función se ordena un array de 4 enteros utilizando distintas operaciones como sa, ra, rra, pb, entre otras.
*/
void	size4(int *s, t_list *d)
{
	if (d->sia == 4)
	{
		if (s[0] < s[1] && s[0] < s[2] && s[0] < s[3] && d->sia == 4)
			pb(d);
		if (s[0] > s[1] && s[1] < s[2] && s[1] < s[3] && d->sia == 4)
		{
			sa(d->sa);
			pb(d);
		}
		if (s[0] > s[2] && s[1] > s[2] && s[2] < s[3] && d->sia == 4)
		{
			ra(d);
			sa(d->sa);
			pb(d);
		}
		if (s[0] > s[3] && s[1] > s[3] && s[2] > s[3] && d->sia == 4)
		{
			rra(d);
			pb(d);
		}
	}
	if (d->sia == 3)
		size3(d->sa, d);
	pa(d);
}

/*
La tercera función size5_2 recibe un puntero a un array de enteros s, un puntero a una estructura t_list llamada d y un entero i. En esta función se ordena un array de 5 enteros utilizando distintas operaciones como ra, rra, pb, sa. La variable i es utilizada como un flag para determinar si ya se realizó alguna operación de intercambio en el array.
*/
int	size5_2(int *s, t_list *d, int i)
{
	if (s[0] > s[2] && s[1] > s[2] && s[2] < s[3] && s[2] < s[4] && i == 0)
	{
		ra(d);
		sa(d->sa);
		pb(d);
		i++;
	}
	if (s[0] > s[3] && s[1] > s[3] && s[2] > s[3] && s[3] < s[4] && i == 0)
	{
		rra(d);
		rra(d);
		pb(d);
		i++;
	}
	if (s[0] > s[4] && s[1] > s[4] && s[2] > s[4] && s[3] > s[4] && i == 0)
	{
		rra(d);
		pb(d);
		i++;
	}
	return (i);
}

/*
Esta función, llamada size5, es una función que se encarga de ordenar una lista de 5 números utilizando el algoritmo de ordenamiento conocido como "sort de selección", donde se selecciona el número más pequeño y se lo coloca al principio de la lista, y se repite este proceso con los números restantes. Si la lista es de tamaño 5, la función verifica en primer lugar si el número más pequeño está en la primera posición, y si no lo está, lo mueve allí utilizando la función pb para enviar el número a la pila b. Luego, la función llama a size4 para ordenar los cuatro números restantes en la pila a. Finalmente, si el número más pequeño fue movido al principio de la lista (y por lo tanto se encuentra en la pila b), la función lo mueve de regreso a la pila a utilizando pa, y verifica si es necesario ordenar la lista utilizando la función sa para colocar los números en orden ascendente.
*/
void	size5(int *s, t_list *d)
{
	int	i;

	i = 0;
	if (d->sia == 5)
	{
		if (s[0] < s[1] && s[0] < s[2] && s[0] < s[3] && s[0] < s[4] && i == 0)
		{
			pb(d);
			i++;
		}
		if (s[0] > s[1] && s[1] < s[2] && s[1] < s[3] && s[1] < s[4] && i == 0)
		{
			sa(d->sa);
			pb(d);
			i++;
		}
		i = size5_2(d->sa, d, i);
	}
	size4(d->sa, d);
	if (i == 1)
	{
		pa(d);
		if (s[0] > s[1])
			sa(d->sa);
	}
}

/*
La función size100 ordena un array de enteros que contiene 100 o menos elementos utilizando una variedad de algoritmos de ordenamiento que se aplican en función del tamaño del array. Primero se inicializan algunas variables importantes, como lsp, control, percentage, cont, size_block y argmax. A continuación, se utiliza la función sortnum para ordenar una sección del array. Luego, se llama a la función changenum para cambiar de posición algunos números del array, con el fin de mejorar su ordenamiento. A continuación, se verifica el tamaño del array y se llama a la función ordernums si el tamaño es mayor o igual a 20, o a ordernums_peq si el tamaño es menor a 20.
*/
void	size100(t_list *d)
{
	d->lsp = d->argc - 1;
	d->control = 0;
	d->percentage = 1;
	d->cont = 4;
	d->size_block = (d->argc / d->cont) / 2;
	d->argmax = d->argc;
	sortnum(d);
	changenum(d);
	if (d->argc >= 20)
		ordernums(d);
	else
		ordernums_peq(d);
}

/*
Esta función implementa el algoritmo de ordenamiento para una lista de 500 números. En primer lugar, se inicializan algunas variables que se utilizan en el proceso de ordenamiento. A continuación, se ordenan los primeros 20 números de la lista utilizando la función sortnum(). Después, se agrupan los números en bloques de tamaño size_block y se ordenan utilizando la función changenum(). Finalmente, se ordenan los números de manera global utilizando la función ordernums().
*/
void	size500(t_list *d)
{
	d->lsp = d->argc -1;
	d->control = 0;
	d->percentage = 1;
	d->cont = 7;
	d->size_block = (d->argc / d->cont) / 2;
	d->argmax = d->argc;
	sortnum(d);
	changenum(d);
	ordernums(d);
}

/*
Esta función recibe un puntero a una estructura t_list que contiene información sobre los datos a ordenar, y se encarga de ordenar los números contenidos en el array sp de la estructura de forma ascendente utilizando el algoritmo de burbuja. Primero inicializa tres variables: i en 0, c en 0 y j en el tamaño del array sp. Luego, ejecuta un ciclo while que se ejecuta mientras c sea menor a j. Dentro de este ciclo, ejecuta otro ciclo while que se ejecuta mientras i sea menor a j - 1. Dentro de este segundo ciclo, compara el elemento i del array sp con el elemento i + 1, y si el primero es mayor que el segundo, intercambia los valores utilizando la función swap. Al final de cada iteración del ciclo while interno, incrementa i en 1. Cuando se completa un ciclo while interno, reinicia i a 0 y aumenta c en 1. Esto se repite hasta que se hayan comparado todos los elementos del array sp y estén en orden ascendente.
*/
void	sortnum(t_list *d)
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