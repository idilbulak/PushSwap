#include "../inc/checker.h"

void	init_stacks(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->head = 0;
	stack_a->next = 0;
	stack_b->head = 0;
	stack_b->next = 0;
}

int	if_number(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '-')
				j++;
			if (!ft_isdigit(argv[i][j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int	if_notdoubles(t_stack *stack, int nbr)
{
	int	i;

	i = stack->head;
	while (i != stack->next)
	{
		if (stack->numberfield[i] == nbr)
			return (-1);
		i = next_index(i);
	}
	return (1);
}

int	if_sorted(t_stack *stack)
{
	int	i;
	int	prev;

	prev = MAX_INT;
	i = stack->head;
	while (i != stack->next)
	{
		if (prev < stack->numberfield[i])
			return (-1);
		prev = stack->numberfield[i];
		i = next_index(i);
	}
	return (1);
}