# include <stdio.h>
# include <unistd.h>
# include "./libft/libft.h"


typedef struct s_vector
{
	int	*vector;
	int	size;
	int	used_size;
}				t_vector;

typedef struct s_stacks
{
	t_vector	stack_a;
	t_vector	stack_b;
}				t_stacks;

int	ft_isnumber(char *number)
{
	int	i;

	i = 0;
	if (number[i] == '-')
		i++;
	while (number[i])
	{
		if (!ft_isdigit(number[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_isduplicate(t_stacks *stacks, int number)
{
	int	size;
	int	i;

	i = 0;
	size = stacks->stack_a.used_size;
	if (size == 0)
		return (1);
	while (i < size)
	{
		if (stacks->stack_a.vector[i] == number)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_issorted(t_vector *vector)
{
	int	i;
	int	*tmp;

	i = 0;
	tmp = vector->vector;
	while (i < vector->used_size - 1)
	{
		if (tmp[i] > tmp[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_count_numbers(char *string)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (string[i])
	{
		if (string[i] == ' ')
			count++;
		i++;
	}
	return (count);
}

int	ft_put_err(t_stacks *stacks, char *message, int ret)
{
	if (stacks)
	{
		if (stacks->stack_a.vector)
			free(stacks->stack_a.vector);
		if (stacks->stack_b.vector)
			free(stacks->stack_b.vector);
	}
	if (message != NULL)
		ft_putendl_fd(message, 2);
	return (ret);
}

void	ft_sort_rest_of_numbers(t_stacks *stacks, int size)
{
	if (!ft_issorted(&stacks->stack_a))
	{
		while (stacks->stack_a.used_size >= 5)
		{
			ft_find_smallest_number_ten(stacks);
			ft_push_b(stacks, 1);
		}
		ft_sort_five_numbers(stacks);
		while (stacks->stack_a.used_size != size)
			ft_push_a(stacks, 1);
	}
}

int	ft_find_key_number(int *sorted_list, int size, int divided, int chunks)
{
	int	key_munber;

	key_munber = sorted_list[(size * divided) / chunks];
	return (key_munber);
}

int	ft_get_biggest_index(t_vector *stack_b)
{
	int	i;
	int	b_index;

	i = 0;
	b_index = i;
	while (i < stack_b->used_size)
	{
		if (stack_b->vector[b_index] < stack_b->vector[i])
			b_index = i;
		i++;
	}
	return (b_index);
}

void	ft_find_biggest_number(t_stacks *stacks)
{
	int	b_index;

	b_index = ft_get_biggest_index(&stacks->stack_b);
	while (b_index != 0)
	{
		if (b_index <= (stacks->stack_b.used_size / 2))
			ft_rotate_b(&stacks->stack_b, 1);
		else
			ft_reverse_rotate_b(&stacks->stack_b, 1);
		b_index = ft_get_biggest_index(&stacks->stack_b);
	}
}

int	ft_get_smallest_index(t_vector *stack_a)
{
	int	i;
	int	s_index;

	i = 0;
	s_index = i;
	while (i < stack_a->used_size)
	{
		if (stack_a->vector[s_index] > stack_a->vector[i])
			s_index = i;
		i++;
	}
	return (s_index);
}

void	ft_find_smallest_number(t_stacks *stacks)
{
	int	s_index;

	s_index = ft_get_smallest_index(&stacks->stack_a);
	while (s_index != 0)
	{
		if (s_index <= 2)
			ft_rotate_a(&stacks->stack_a, 1);
		else
			ft_reverse_rotate_a(&stacks->stack_a, 1);
		s_index = ft_get_smallest_index(&stacks->stack_a);
	}
}

void	ft_sort_five_numbers(t_stacks *stacks)
{
	int	i;

	i = 0;
	if (!ft_issorted(&stacks->stack_a))
	{
		if (stacks->stack_a.used_size == 5)
		{
			ft_find_smallest_number(stacks);
			ft_push_b(stacks, 1);
			i++;
		}
		if (stacks->stack_a.used_size == 4)
		{
			ft_find_smallest_number(stacks);
			ft_push_b(stacks, 1);
			i++;
		}
		ft_sort_three_numbers(&stacks->stack_a);
		while (i > 0)
		{
			ft_push_a(stacks, 1);
			i--;
		}
	}
}

int	ft_search_index(t_stacks *stacks, int key_number)
{
	int	i;

	i = 0;
	while (i < stacks->stack_a.used_size)
	{
		if (stacks->stack_a.vector[i] <= key_number)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_move_to_top(t_stacks *stacks, int index)
{
	int	divid;

	divid = stacks->stack_a.used_size / 2;
	while (index != 0)
	{
		if (index <= divid)
		{
			ft_rotate_a(&stacks->stack_a, 1);
			index--;
		}
		else
		{
			ft_reverse_rotate_a(&stacks->stack_a, 1);
			index++;
			if (index == stacks->stack_a.used_size)
				break ;
		}
	}
}

void	ft_push_index(t_stacks *stacks, int key_number)
{
	int	index;

	index = ft_search_index(stacks, key_number);
	while (index != -1)
	{
		ft_move_to_top(stacks, index);
		ft_push_b(stacks, 1);
		index = ft_search_index(stacks, key_number);
	}
}

void	ft_one_handred(t_stacks *stacks)
{
	int	i;
	int	key_number;
	int	*sorted_list;

	i = 1;
	sorted_list = ft_sort_array(&stacks->stack_a);
	while (i != 4)
	{
		key_number = ft_find_key_number(sorted_list,
				stacks->stack_a.size, i, 4);
		ft_push_index(stacks, key_number);
		i++;
	}
	free (sorted_list);
	ft_sort_rest(stacks);
	while (stacks->stack_b.used_size != 0)
	{
		ft_find_biggest_number(stacks);
		ft_push_a(stacks, 1);
	}
}

void	ft_five_handred(t_stacks *stacks)
{
	int	i;
	int	key_number;
	int	*sorted_list;

	i = 1;
	sorted_list = ft_sort_array(&stacks->stack_a);
	while (i != 8)
	{
		key_number = ft_find_key_number(sorted_list,
				stacks->stack_a.size, i, 8);
		ft_push_index(stacks, key_number);
		i++;
	}
	free (sorted_list);
	ft_sort_more_then_handred(stacks);
	while (stacks->stack_b.used_size != 0)
	{
		ft_find_biggest_number(stacks);
		ft_push_a(stacks, 1);
	}
}

void	ft_push_stack(int *vector, int used_size)
{
	while (used_size > 0)
	{
		vector[used_size] = vector[used_size - 1];
		used_size--;
	}
}

void	ft_pop_stack(int *vector, int used_size)
{
	int	i;

	i = 0;
	while (i < used_size)
	{
		vector[i] = vector[i + 1];
		i++;
	}
}

void	ft_push_a(t_stacks *stacks, int print)
{
	int	used_size_b;
	int	used_size_a;
	int	i;

	i = 0;
	used_size_b = stacks->stack_b.used_size;
	used_size_a = stacks->stack_a.used_size;
	if (print == 1)
		ft_putendl_fd("pa", 1);
	if (used_size_b == 0)
		return ;
	if (used_size_a == 0)
		stacks->stack_a.vector[0] = stacks->stack_b.vector[0];
	else
	{
		ft_push_stack(stacks->stack_a.vector, used_size_a);
		stacks->stack_a.vector[0] = stacks->stack_b.vector[0];
	}
	ft_pop_stack(stacks->stack_b.vector, used_size_b);
	stacks->stack_a.used_size++;
	stacks->stack_b.used_size--;
}

void	ft_push_b(t_stacks *stacks, int print)
{
	int	used_size_b;
	int	used_size_a;
	int	i;

	i = 0;
	used_size_b = stacks->stack_b.used_size;
	used_size_a = stacks->stack_a.used_size;
	if (print == 1)
		ft_putendl_fd("pb", 1);
	if (used_size_a == 0)
		return ;
	if (used_size_b == 0)
		stacks->stack_b.vector[0] = stacks->stack_a.vector[0];
	else
	{
		ft_push_stack(stacks->stack_b.vector, used_size_b);
		stacks->stack_b.vector[0] = stacks->stack_a.vector[0];
	}
	ft_pop_stack(stacks->stack_a.vector, used_size_a);
	stacks->stack_b.used_size++;
	stacks->stack_a.used_size--;
}

char	**ft_stacks_init(char *string, t_stacks *stacks)
{
	int		size;
	char	**numbers;

	numbers = ft_split(string, ' ');
	size = ft_count_numbers(string);
	stacks->stack_a.vector = (int *)malloc(sizeof(int) * size);
	stacks->stack_b.vector = (int *)malloc(sizeof(int) * size);
	stacks->stack_a.size = size;
	stacks->stack_b.size = size;
	stacks->stack_a.used_size = 0;
	stacks->stack_b.used_size = 0;
	free (string);
	return (numbers);
}

t_stacks	ft_store_numbers(char *string)
{
	t_stacks			stacks;
	char				**numbers;
	long long			number;
	int					i;

	i = 0;
	numbers = ft_stacks_init(string, &stacks);
	while (numbers[i])
	{
		if (!ft_isnumber(numbers[i]))
			exit(ft_put_err(&stacks, "Error", 0));
		number = ft_atoi(numbers[i]);
		if (number < -2147483648 || number > 2147483647)
			exit(ft_put_err(&stacks, "Error", 0));
		if (!ft_isduplicate(&stacks, number))
			exit(ft_put_err(&stacks, "Error", 0));
		stacks.stack_a.vector[i] = number;
		stacks.stack_a.used_size++;
		free(numbers[i]);
		i++;
	}
	free(numbers);
	return (stacks);
}

int	ft_av_size(char **av)
{
	int	size;
	int	i;

	i = 0;
	size = 0;
	while (av[i])
		size += ft_strlen(av[i++]) + 1;
	return (size);
}

int	ft_check_arg(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (ft_isdigit(av[i]))
			return (1);
		i++;
	}
	return (0);
}

char	*ft_av_to_string(char **av)
{
	char	*string;
	char	*tmp;
	int		size;
	int		i;

	i = 1;
	size = ft_av_size(av);
	string = (char *)malloc(1);
	while (av[i])
	{
		if (!ft_check_arg(av[i]))
			exit(ft_put_err(NULL, "Error", 0));
		else
		{
			tmp = ft_strjoin(string, av[i]);
			free(string);
			string = ft_strjoin(tmp, " ");
			free (tmp);
			i++;
		}
	}
	return (string);
}

void	ft_reverse_rotate_a(t_vector *stack_a, int print)
{
	int	last_element;

	if (print == 1)
		ft_putendl_fd("rra", 1);
	last_element = stack_a->vector[stack_a->used_size - 1];
	ft_push_stack(stack_a->vector, stack_a->used_size);
	stack_a->vector[0] = last_element;
}

void	ft_reverse_rotate_b(t_vector *stack_b, int print)
{
	int	last_element;

	if (print == 1)
		ft_putendl_fd("rrb", 1);
	last_element = stack_b->vector[stack_b->used_size - 1];
	ft_push_stack(stack_b->vector, stack_b->used_size);
	stack_b->vector[0] = last_element;
}

void	ft_reverse_rotate_both(t_stacks *stacks, int print)
{
	if (print == 1)
		ft_putendl_fd("rrr", 1);
	ft_reverse_rotate_a(&stacks->stack_a, 0);
	ft_reverse_rotate_b(&stacks->stack_b, 0);
}

void	ft_swap_a_or_b(t_vector *vector, int print, char stack)
{
	int	temp;

	if (print == 1 && stack == 'a')
		ft_putendl_fd("sa", 1);
	else if (print == 1 && stack == 'b')
		ft_putendl_fd("sb", 1);
	if (vector->used_size > 1)
	{
		temp = vector->vector[0];
		vector->vector[0] = vector->vector[1];
		vector->vector[1] = temp;
	}
}

void	ft_swap_both(t_stacks *stacks, int print)
{
	if (print == 1)
		ft_putendl_fd("ss", 1);
	ft_swap_a_or_b(&stacks->stack_a, 0, 'a');
	ft_swap_a_or_b(&stacks->stack_b, 0, 'b');
}

void	ft_rotate_a(t_vector *stack_a, int print)
{
	int	first_element;

	if (print == 1)
		ft_putendl_fd("ra", 1);
	first_element = stack_a->vector[0];
	ft_pop_stack(stack_a->vector, stack_a->used_size);
	stack_a->vector[stack_a->used_size - 1] = first_element;
}

void	ft_rotate_b(t_vector *stack_b, int print)
{
	int	first_element;

	if (print == 1)
		ft_putendl_fd("rb", 1);
	first_element = stack_b->vector[0];
	ft_pop_stack(stack_b->vector, stack_b->used_size);
	stack_b->vector[stack_b->used_size - 1] = first_element;
}

void	ft_rotate_both(t_stacks *stacks, int print)
{
	if (print == 1)
		ft_putendl_fd("rr", 1);
	ft_rotate_a(&stacks->stack_a, 0);
	ft_rotate_b(&stacks->stack_b, 0);
}

void	ft_swap(int *xp, int *yp)
{
	int	temp;

	temp = *xp;
	*xp = *yp;
	*yp = temp;
}

int	*ft_list_init(t_vector *stack_a)
{
	int	i;
	int	*sorted_list;

	i = 0;
	sorted_list = malloc(sizeof(int) * stack_a->size);
	while (i < stack_a->size)
	{
		sorted_list[i] = stack_a->vector[i];
		i++;
	}
	return (sorted_list);
}

int	*ft_sort_array(t_vector *stack_a)
{
	int	i;
	int	j;
	int	min_index;
	int	*sorted_list;

	i = 0;
	sorted_list = ft_list_init(stack_a);
	while (i < stack_a->size - 1)
	{
		min_index = i;
		j = i + 1;
		while (j < stack_a->size)
		{
			if (sorted_list[j] < sorted_list[min_index])
				min_index = j;
			j++;
		}
		ft_swap(&sorted_list[min_index], &sorted_list[i]);
		i++;
	}
	return (sorted_list);
}

void	ft_sort_rest(t_stacks *stacks)
{
	if (stacks->stack_a.used_size == 2)
	{
		if (!ft_issorted(&stacks->stack_a))
			ft_swap_a_or_b(&stacks->stack_a, 1, 'a');
	}
	if (stacks->stack_a.used_size == 3)
		ft_sort_three_numbers(&stacks->stack_a);
	if (stacks->stack_a.used_size == 5 || stacks->stack_a.used_size == 4)
		ft_sort_five_numbers(stacks);
	if (stacks->stack_a.used_size > 5)
		ft_sort_rest_of_numbers(stacks, stacks->stack_a.used_size);
}

void 	ft_sort_more_then_handred(t_stacks *stacks)
{
	if (stacks->stack_a.used_size == 2)
	{
		if (!ft_issorted(&stacks->stack_a))
			ft_swap_a_or_b(&stacks->stack_a, 1, 'a');
	}
	else if (stacks->stack_a.used_size == 3)
		ft_sort_three_numbers(&stacks->stack_a);
	else if (stacks->stack_a.used_size == 5 || stacks->stack_a.used_size == 4)
		ft_sort_five_numbers(stacks);
	else if (stacks->stack_a.used_size > 5 && stacks->stack_a.used_size <= 10)
		ft_sort_rest_of_numbers(stacks, stacks->stack_a.used_size);
	else if (stacks->stack_a.used_size > 10)
		ft_one_handred(stacks);
}

void	ft_find_smallest_number_ten(t_stacks *stacks)
{
	int	s_index;

	s_index = ft_get_smallest_index(&stacks->stack_a);
	while (s_index != 0)
	{
		if (s_index <= 5)
			ft_rotate_a(&stacks->stack_a, 1);
		else
			ft_reverse_rotate_a(&stacks->stack_a, 1);
		s_index = ft_get_smallest_index(&stacks->stack_a);
	}
}

void	ft_sort_ten_numbers(t_stacks *stacks)
{
	if (!ft_issorted(&stacks->stack_a))
	{
		while (stacks->stack_a.used_size != 5)
		{
			ft_find_smallest_number_ten(stacks);
			ft_push_b(stacks, 1);
		}
		ft_sort_five_numbers(stacks);
		while (stacks->stack_a.used_size != stacks->stack_a.size)
			ft_push_a(stacks, 1);
	}
}

void	ft_sort_three_numbers(t_vector *stack_a)
{
	int	*tmp;

	tmp = stack_a->vector;
	if (ft_issorted(stack_a))
		return ;
	if (tmp[0] > tmp[1] && tmp[0] < tmp[2] && tmp[1] < tmp[2])
		ft_swap_a_or_b(stack_a, 1, 'a');
	else if (tmp[0] > tmp[1] && tmp[1] > tmp[2])
	{
		ft_swap_a_or_b(stack_a, 1, 'a');
		ft_reverse_rotate_a(stack_a, 1);
	}
	else if (tmp[0] > tmp[1] && tmp[0] > tmp[2] && tmp[1] < tmp[2])
		ft_rotate_a(stack_a, 1);
	else if (tmp[0] < tmp[1] && tmp[1] > tmp[2] && tmp[0] < tmp[2])
	{
		ft_swap_a_or_b(stack_a, 1, 'a');
		ft_rotate_a(stack_a, 1);
	}
	else if (tmp[0] < tmp[1] && tmp[1] > tmp[2] && tmp[0] > tmp[2])
		ft_reverse_rotate_a(stack_a, 1);
}

int	main(int ac, char **av)
{
	t_stacks	stacks;
	char		*string;

	ac--;
	if (ac == 0)
		return (0);
	string = ft_av_to_string(av);
	stacks = ft_store_numbers(string);
	if (ft_issorted(&stacks.stack_a))
		return (ft_put_err(&stacks, NULL, 0));
	if (stacks.stack_a.size == 2)
		ft_swap_a_or_b(&stacks.stack_a, 1, 'a');
	if (stacks.stack_a.size == 3)
		ft_sort_three_numbers(&stacks.stack_a);
	if (stacks.stack_a.size == 5 || stacks.stack_a.size == 4)
		ft_sort_five_numbers(&stacks);
	if (stacks.stack_a.size > 5 && stacks.stack_a.size <= 10)
		ft_sort_ten_numbers(&stacks);
	if (stacks.stack_a.size > 10 && stacks.stack_a.size <= 100)
		ft_one_handred(&stacks);
	if (stacks.stack_a.size > 100)
		ft_five_handred(&stacks);
	return (ft_put_err(&stacks, NULL, 0));
}