#include "../inc/push_swap.h"

void	init_stacks(t_stack *stack)
{
	stack->head = 0;
	stack->next = 0;
}

int	if_number(char **argv)
{
	int i;
	int j;

	i = 1;
	while(argv[i])
	{
		j = 0;
		while(argv[i][j])
		{
			if(argv[i][j] == '-')
				j++;
			if(!ft_isdigit(argv[i][j]))
				return(-1);
			j++;
		}
		i++;
	}
	return(1);
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

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	t_stack		stack_a;
	t_stack		stack_b;
	int			i;

	if (argc > 1)
	{
		if (if_number(argv) == -1)
			exit(EXIT_FAILURE);
		init_stacks(&stack_a);
		init_stacks(&stack_b);
		stacks.stack_a = &stack_a;
		stacks.stack_b = &stack_b;
		if (get_args(argc, argv, &stacks) == -1)
			exit(EXIT_FAILURE);
		while(!stack_empty(stacks.stack_b))
		{
			i = stack_prev(stacks.stack_b);
			if(if_notdoubles(stacks.stack_b, i) == -1)
				exit(EXIT_FAILURE);
			push_stack(stacks.stack_a, i);
		}
		if (if_sorted(stacks.stack_a) == -1)
			sort(&stacks);
	}
	return (0);
}