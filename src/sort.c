/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/22 17:06:23 by ibulak        #+#    #+#                 */
/*   Updated: 2022/06/22 17:29:14 by ibulak        ########   odam.nl         */
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
	repeat_fn(pa, stacks, stack_size(stacks->stack_b));
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
