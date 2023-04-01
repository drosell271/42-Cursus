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

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	char	*temp;

	i = 0;
	if (!s)
		return (0);
	if (len > ft_strlen(s))
		temp = malloc(sizeof(char) * (ft_strlen(s) + 1));
	else
		temp = malloc(sizeof(char) * (len + 1));
	if (!temp)
		return (0);
	while (start < ft_strlen(s) && i < len && s[start])
	{
		temp[i] = s[start];
		i++;
		start++;
	}
	temp[i] = '\0';
	return (temp);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_isdigit(int i)
{
	if (i < 48 || i > 57)
		return (0);
	return (1);
}

void	liberar(t_list *d)
{
	if (d->sa)
	{
		liberar(d->sa);
	}
	if (d->sb)
	{
		liberar(d->sb);
	}
	if (d->sp)
	{
		liberar(d->sp);
	}
	if (d)
	{
		liberar(d);
	}
	write(2, "Error\n", 6);
	exit(0);
}

void	liberar2(t_list *d)
{
	if (d->sa)
	{
		liberar(d->sa);
		d->sa = NULL;
	}
	if (d->sb)
	{
		liberar(d->sb);
		d->sb = NULL;
	}
	if (d->sp)
	{
		liberar(d->sp);
		d->sp = NULL;
	}
	if (d)
	{
		liberar(d);
		d = NULL;
	}
	exit(0);
}

void	newnum(t_list *d)
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

int	check_input(char **args, int argc)
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

static	int	checkeos(t_list *d, int num, int j)
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

int	check_iguales(t_list *d)
{
	int	i;

	i = 0;
	while (i <= d->sia - 1)
	{
		if (checkeos(d, d->sa[i], i) == 1)
			i++;
		else
			return (-1);
	}
	return (0);
}

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
			return (gestion_errores(d, nbr));
		if (nbr > INT_MAX && valorfinal == 1)
			return (gestion_errores(d, nbr));
	}
	return (nbr * valorfinal);
}

int	gestion_errores(t_list *d, int nbr)
{
	nbr = 0;
	d->atoierror = 1;
	return (nbr);
}

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

void	sa(int *sa)
{
	int	temp;

	temp = sa[0];
	sa[0] = sa[1];
	sa[1] = temp;
	write(1, "sa\n", 3);
}

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

void	sb(int *sb)
{
	int	temp;

	temp = sb[0];
	sb[0] = sb[1];
	sb[1] = temp;
	write(1, "sb\n", 3);
}

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

void ordenenar_sbr(t_list *d)
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

void	ordenenar_sb(t_list *d)
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
		if (comprueba_movimiento(d) == -1)
			ordenenar_sbr(d);
		else
			calcular(d);
	}
}

void	ordenenar(t_list *d)
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
		tamano_3(d->sa, d);
		d->lsp = d->lsp - 3;
	}
	if (d->percentage <= d->cont)
		ordenenar(d);
	while (d->percentage-- > 0)
		ordenenar_sb(d);
}

void	ordenenar_s_sb(t_list *d)
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

void	ordenenar_3(t_list *d, int i)
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
	ordenenar_s_sb(d);
}

void	ordenenar_2(t_list *d)
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

void	ordenenar_s(t_list *d)
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
	ordenenar_s_sb(d);
	ordenenar_3(d, i);
}

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

void	swap(int *argv1, int *argv2)
{
	int	temp;
	
	temp = *argv1;
	*argv1 = *argv2;
	*argv2 = temp;
}
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

int	elige_size(int arc, t_list *d)
{
	if (check_iguales(d) == -1)
		return (-1);
	else
	{
		if (arc == 3 || arc == 4)
			tamano_3(d->sa, d);
		if (arc < 7 && arc > 4)
			tamano_5_1(d->sa, d);
		if (arc < 102 && arc > 6)
			tamano_100(d);
		if (arc > 101)
			tamano_500(d);
	}
	return (0);
}

int	input_process(t_list *d, int arc, char **args)
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

int	preparar(t_list *d)
{
	d->sa = malloc(sizeof(int) * d->argc);
	if (!d->sa)
	{
		liberar(d);
		return (-1);
	}
	d->sp = malloc(sizeof(int) * d->argc);
	if (!d->sp)
	{
		liberar(d->sa);
		liberar(d);
		return (-1);
	}
	d->sb = malloc(sizeof(int) * d->argc);
	if (!d->sb)
	{
		liberar(d->sp);
		liberar(d->sa);
		liberar(d);
		return (-1);
	}
	d->sia = d->argc;
	d->sib = 0;
	d->sip = d->argc;
	return (0);
}

void	tamano_3(int *s, t_list *d)
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

void	tamano_4(int *s, t_list *d)
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
		tamano_3(d->sa, d);
	pa(d);
}

int	tamano_5_2(int *s, t_list *d, int i)
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

void	tamano_5_1(int *s, t_list *d)
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
		i = tamano_5_2(d->sa, d, i);
	}
	tamano_4(d->sa, d);
	if (i == 1)
	{
		pa(d);
		if (s[0] > s[1])
			sa(d->sa);
	}
}

void	tamano_100(t_list *d)
{
	d->lsp = d->argc - 1;
	d->control = 0;
	d->percentage = 1;
	d->cont = 4;
	d->size_block = (d->argc / d->cont) / 2;
	d->argmax = d->argc;
	sort(d);
	newnum(d);
	if (d->argc >= 20)
		ordenenar(d);
	else
		ordenenar_s(d);
}

void	tamano_500(t_list *d)
{
	d->lsp = d->argc -1;
	d->control = 0;
	d->percentage = 1;
	d->cont = 7;
	d->size_block = (d->argc / d->cont) / 2;
	d->argmax = d->argc;
	sort(d);
	newnum(d);
	ordenenar(d);
}

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