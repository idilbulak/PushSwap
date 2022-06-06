#include <stdlib.h>
#include "../inc/push_swap.h"
#include "get_next_line.h"

void	init_moves(char *moves)
{
	moves[0] = "sa\n";
	moves[1] = "sb\n";
	moves[3] = "ss\n";
	moves[4] = "pa\n";
	moves[5] = "pb\n";
	moves[6] = "ra\n";
	moves[7] = "rb\n";
	moves[8] = "rr\n";
	moves[9] = "rra\n";
	moves[10] = "rrb\n";
	moves[11] = "rrr\n";
}

int	which_move(char *mv)
{
	int			i;
	const char	*moves[11];
	

	init_moves(moves);
	i = 0;
	while (i < 11)
	{
		if (ft_strncmp(mv, moves[i], ft_strlen(moves[i])) == 0)
			return (i);
		i++;
	}
	return (-1);
}

void	init_moves(t_repeat_fn *functions)
{
	functions[0] = sa;
	functions[1] = sb;
	functions[3] = ss;
	functions[4] = pa;
	functions[5] = pb;
	functions[6] = ra;
	functions[7] = rb;
	functions[8] = rr;
	functions[9] = rra;
	functions[10] = rrb;
	functions[11] = rrr;
}

int	checker(t_stacks *stacks)
{
	char			*mv;
	int				next_fn;
	t_repeat_fn		*functions[11];

	init_funstions(functions);
	mv = get_next_line(0);
	while (mv)
	{
		// next_fn = which_move(mv);
		// free(mv);
		// if (next_fn == -1)
		// 	return (-1);
		// repeat_fn[next_fn](next_fn, stacks, 0);
		// mv = get_next_line(0);
	}
	return (1);
}

int	main(int argc, const char **argv)
{
	t_stacks	stacks;
	t_stack		stack_a;
	t_stack		stack_b;

	init_stacks(&stack_a);
	init_stacks(&stack_b);
	stacks.stack_a = &stack_a;
	stacks.stack_b = &stack_b;
	if (argc < 2)
		return (0);
	if (get_args(argc, argv, &stacks) == -1)
		exit(EXIT_FAILURE);
	if (checker(&stacks) == -1)
	{
		printf("Error");
		return (1);
	}
	if (!if_sorted(stacks.stack_a) || !stack_empty(stacks.stack_b))
		printf("KO");
	else
		printf("OK");
	return (0);
}
