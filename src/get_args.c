#include "../inc/push_swap.h"

int	ft_isdigit(int c)
{
	if (!(c >= 48 && c <= 57))
		return (0);
	else
		return (1);
}

void	push_stack(t_stack *stack, int value)
{
	stack->numberfield[stack->next] = value;
	stack->next = next_index(stack->next);
}

int	get_args(int argc, char **argv, t_stacks *stacks)
{
	int	i;
	int	j;
	int	nbr;
	int	sign;

	i = 1;
	while(i < argc)
	{
		sign = 1;
		nbr = 0;
		j = 0;
		if (argv[i][j] == '-')
		{
			sign = -1;
			j++;
		}
		while (ft_isdigit(argv[i][j]))
		{
			nbr = nbr * 10 + (argv[i][j] - '0');
			j++;
		}
		if (sign ==  -1)
			nbr = nbr * -1;
		push_stack(stacks->stack_b, nbr);
		i++;
	}
	return(1);
}