/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_3.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/22 17:14:07 by ibulak        #+#    #+#                 */
/*   Updated: 2022/06/22 17:14:19 by ibulak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	compare_ab(t_stacks *stacks)
{
	return (stacks->stack_a->numberfield[stacks->stack_a->head] < \
		stacks->stack_a->numberfield[next_index(stacks->stack_a->head)]);
}

int	compare_bc(t_stacks *stacks)
{
	return (stacks->stack_a->numberfield[next_index(stacks->stack_a->head)] < \
		stacks->stack_a->numberfield[prev_index(stacks->stack_a->next)]);
}

int	compare_ac(t_stacks *stacks)
{
	return (stacks->stack_a->numberfield[prev_index(stacks->stack_a->next)] < \
		stacks->stack_a->numberfield[stacks->stack_a->head]);
}

void	sort_3(t_stacks *stacks)
{
	int	cmp_ab;
	int	cmp_ac;
	int	cmp_bc;

	cmp_ab = compare_ab(stacks);
	cmp_bc = compare_bc(stacks);
	cmp_ac = compare_ac(stacks);
	if (cmp_ab && cmp_bc && !cmp_ac)
	{
		ra(stacks, 1);
		sa(stacks->stack_a);
	}
	if (!cmp_ab && cmp_bc && cmp_ac)
		sa(stacks->stack_a);
	if (cmp_ab && !cmp_bc && cmp_ac)
	{
		rra(stacks, 1);
		sa(stacks->stack_a);
	}
	if (!cmp_ab && cmp_bc && !cmp_ac)
		ra(stacks, 1);
	if (cmp_ab && !cmp_bc && !cmp_ac)
		rra(stacks, 1);
}
