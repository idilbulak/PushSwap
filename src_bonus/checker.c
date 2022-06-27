/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/22 20:07:34 by ibulak        #+#    #+#                 */
/*   Updated: 2022/06/27 11:19:30 by ibulak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

void	init_moves(const char **moves)
{
	moves[0] = "sa\n";
	moves[1] = "sb\n";
	moves[2] = "ss\n";
	moves[3] = "pa\n";
	moves[4] = "pb\n";
	moves[5] = "ra\n";
	moves[6] = "rb\n";
	moves[7] = "rr\n";
	moves[8] = "rra\n";
	moves[9] = "rrb\n";
	moves[10] = "rrr\n";
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

void	init_functions(t_repeat *functions)
{
	functions[0] = sa;
	functions[1] = sb;
	functions[2] = ss;
	functions[3] = pa;
	functions[4] = pb;
	functions[5] = ra;
	functions[6] = rb;
	functions[7] = rr;
	functions[8] = rra;
	functions[9] = rrb;
	functions[10] = rrr;
}

int	checker(t_stacks *stacks)
{
	char			*mv;
	int				next_fn;
	t_repeat		functions[11];

	init_functions(functions);
	mv = get_next_line(0);
	while (mv)
	{
		next_fn = which_move(mv);
		free(mv);
		if (next_fn == -1)
			return (-1);
		functions[next_fn](stacks, 0);
		mv = get_next_line(0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	t_stack		stack_a;
	t_stack		stack_b;

	init_stacks(&stack_a, &stack_b);
	stacks.stack_a = &stack_a;
	stacks.stack_b = &stack_b;
	if (argc < 2)
		return (0);
	if (if_number(argv) == -1 || get_args(argc, argv, &stacks) == -1)
	{
		write(1, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	checker_init(&stacks);
	if (checker(&stacks) == -1)
	{
		write(1, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	if (if_sorted(stacks.stack_a) == -1)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	return (0);
}
