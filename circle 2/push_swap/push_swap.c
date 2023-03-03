#include "./libft/libft.h"
#include <stdio.h>

typedef struct	s_stack
{
	int			*array;
	int			top;
}				t_stack;

void	swap(t_stack *stack)
{
	int	tmp;

	if (stack->top > 0)
	{
		tmp = stack->array[stack->top];
		stack->array[stack->top] = stack->array[stack->top - 1];
		stack->array[stack->top - 1] = tmp;
	}
}

void	push(t_stack *stack_from, t_stack *stack_to)
{
	if (stack_from->top >= 0)
	{
		stack_to->top++;
		stack_to->array[stack_to->top] = stack_from->array[stack_from->top];
		stack_from->top--;
	}
}

void	rotate(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->top > 0)
	{
		tmp = stack->array[stack->top];
		i = stack->top;
		while (i > 0)
		{
			stack->array[i] = stack->array[i - 1];
			i--;
		}
		stack->array[0] = tmp;
	}
}

void	reverse_rotate(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->top > 0)
	{
		tmp = stack->array[0];
		i = 0;
		while (i < stack->top)
		{
			stack->array[i] = stack->array[i + 1];
			i++;
		}
		stack->array[stack->top] = tmp;
	}
}

int		main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		i;

	if (argc < 2)
		return (0);
	stack_a.array = (int*)malloc(sizeof(int) * argc - 1);
	stack_a.top = argc - 2;
	stack_b.array = (int*)malloc(sizeof(int) * argc - 1);
	stack_b.top = -1;
	i = 1;
	while (i < argc)
	{
		stack_a.array[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	// AQUÍ VA TU CÓDIGO PARA ORDENAR LOS NÚMEROS EN EL STACK A
	free(stack_a.array);
	free(stack_b.array);
	return (0);
}
