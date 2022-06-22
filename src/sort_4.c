/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_4.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/22 17:21:51 by ibulak        #+#    #+#                 */
/*   Updated: 2022/06/22 17:22:06 by ibulak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_4(t_stacks *stacks)
{
	int	b;
	int	c;
	int	d;

	b = stacks->stack_a->numberfield[next_index(\
		next_index(stacks->stack_a->head))];
	c = stacks->stack_a->numberfield[next_index(stacks->stack_a->head)];
	d = stacks->stack_a->numberfield[stacks->stack_a->head];
	if (b == find_min(stacks->stack_a))
		sa(stacks->stack_a);
	if (c == find_min(stacks->stack_a))
	{
		ra(stacks, 1);
		sa(stacks->stack_a);
	}
	if (d == find_min(stacks->stack_a))
		rra(stacks, 1);
	if (if_sorted(stacks->stack_a) == -1)
	{
		pb(stacks, 1);
		sort_3(stacks);
		pa(stacks, 1);
	}
}
