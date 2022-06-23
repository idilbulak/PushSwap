/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_large.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/22 18:14:39 by ibulak        #+#    #+#                 */
/*   Updated: 2022/06/22 20:01:46 by ibulak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	if_insertion(t_stacks *s, int i, int j)
{
	int	if_push;
	int	push_max;
	int	push_min;
	int	next;

	next = next_index(j);
	if (next == s->stack_b->next)
		next = s->stack_b->head;
	if_push = s->stack_a->numberfield[i] > s->stack_b->numberfield[j] & \
		s->stack_b->numberfield[next] > s->stack_a->numberfield[i];
	push_max = s->stack_a->numberfield[i] > s->stack_bmax & \
		s->stack_b->numberfield[j] == s->stack_bmax;
	push_min = s->stack_a->numberfield[i] < s->stack_bmin & \
		s->stack_b->numberfield[j] == s->stack_bmax;
	return (if_push || push_max || push_min);
}

void	insertion(t_stacks *stacks, t_rotation rot)
{
	if (rot.method == 2)
	{
		repeat(rr, stacks, getmin(rot.cost_ra, rot.cost_rb));
		repeat(ra, stacks, getmax(0, rot.cost_ra - rot.cost_rb));
		repeat(rb, stacks, getmax(0, rot.cost_rb - rot.cost_ra));
	}
	else if (rot.method == 3)
	{
		repeat(rrr, stacks, getmin(rot.cost_rra, rot.cost_rrb));
		repeat(rra, stacks, getmax(0, rot.cost_rra - rot.cost_rrb));
		repeat(rrb, stacks, getmax(0, rot.cost_rrb - rot.cost_rra));
	}
	else if (rot.method == 4)
	{
		repeat(ra, stacks, rot.cost_ra);
		repeat(rrb, stacks, rot.cost_rrb);
	}
	else if (rot.method == 5)
	{
		repeat(rra, stacks, rot.cost_rra);
		repeat(rb, stacks, rot.cost_rb);
	}
}

void	bring_min_to_top(t_stacks *stacks)
{
	int			min;
	int			i;
	t_rotation	rot;

	min = find_min(stacks->stack_b);
	rot.cost_rb = stack_size(stacks->stack_b);
	rot.cost_rrb = 0;
	i = stacks->stack_b->head;
	while (i != stacks->stack_b->next)
	{
		if (stacks->stack_b->numberfield[i] == min)
		{
			if (rot.cost_rb < rot.cost_rrb)
				repeat(rb, stacks, rot.cost_rb);
			else
				repeat(rrb, stacks, rot.cost_rrb);
			break ;
		}
		rot.cost_rb--;
		rot.cost_rrb++;
		i = next_index(i);
	}
}
