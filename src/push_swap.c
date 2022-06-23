/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/22 12:00:07 by ibulak        #+#    #+#                 */
/*   Updated: 2022/06/22 19:56:23 by ibulak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_large(t_stacks *stacks)
{
	t_rotation	rot;

	if (stacks->stack_a->numberfield[1] > stacks->stack_a->numberfield[0])
		sa(stacks->stack_a);
	pb(stacks, 1);
	pb(stacks, 1);
	while (stack_size(stacks->stack_a) != 0)
	{
		stacks->stack_bmax = find_max(stacks->stack_b);
		stacks->stack_bmin = find_min(stacks->stack_b);
		rot = rotation_stack_a_b(stacks);
		insertion(stacks, rot);
		pb(stacks, 1);
	}
	bring_min_to_top(stacks);
	repeat(pa, stacks, stack_size(stacks->stack_b));
}

void	sort(t_stacks *stacks)
{
	if (stack_size(stacks->stack_a) == 2)
	{
		if (stacks->stack_a->numberfield[1] > stacks->stack_a->numberfield[0])
			sa(stacks->stack_a);
	}
	else if (stack_size(stacks->stack_a) == 3)
		sort_3(stacks);
	else if (stack_size(stacks->stack_a) == 4)
		sort_4(stacks);
	else if (stack_size(stacks->stack_a) == 5)
		sort_5(stacks);
	else if (stack_size(stacks->stack_a) > 5)
		sort_large(stacks);
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
		init_stacks(&stack_a, &stack_b);
		stacks.stack_a = &stack_a;
		stacks.stack_b = &stack_b;
		if (get_args(argc, argv, &stacks) == -1)
			exit(EXIT_FAILURE);
		while (!stack_empty(stacks.stack_b))
		{
			i = stack_prev(stacks.stack_b);
			if (if_notdoubles(stacks.stack_b, i) == -1)
				exit(EXIT_FAILURE);
			push_stack(stacks.stack_a, i);
		}
		if (if_sorted(stacks.stack_a) == -1)
			sort(&stacks);
	}
	return (0);
}
