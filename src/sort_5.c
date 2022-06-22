/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_5.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/22 17:23:47 by ibulak        #+#    #+#                 */
/*   Updated: 2022/06/22 17:24:10 by ibulak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_5_helper(t_stacks *stacks)
{
	pb(stacks, 1);
	sort_4(stacks);
	pb(stacks, 1);
	sort_3(stacks);
	pa(stacks, 1);
	pa(stacks, 1);
}

void	sort_5(t_stacks *stacks)
{
	int	b;
	int	c;
	int	d;
	int	e;

	b = stacks->stack_a->numberfield[3];
	c = stacks->stack_a->numberfield[2];
	d = stacks->stack_a->numberfield[1];
	e = stacks->stack_a->numberfield[0];
	if (b == find_min(stacks->stack_a))
		sa(stacks->stack_a);
	if (c == find_min(stacks->stack_a))
	{
		ra(stacks, 1);
		sa(stacks->stack_a);
	}
	if (d == find_min(stacks->stack_a))
	{
		rra(stacks, 1);
		rra(stacks, 1);
	}
	if (e == find_min(stacks->stack_a))
		rra(stacks, 1);
	sort_5_helper(stacks);
}
