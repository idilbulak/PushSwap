/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_utils3.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/22 18:07:42 by ibulak        #+#    #+#                 */
/*   Updated: 2022/06/27 11:01:52 by ibulak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	repeat(t_repeat fn, t_stacks *stacks, int n)
{
	while (n--)
		fn(stacks, 1);
}

int	update_best(t_rotation *rot, int method, int best_cost)
{
	rot->method = method;
	return (best_cost);
}

int	rotation_cost(t_stacks *stacks, t_rotation *rot, int i, int j)
{
	int	a_b_rr;
	int	a_b_rrr;
	int	a_ra_b_rrb;
	int	b_rb_a_rra;
	int	best_cost;

	if (!if_insertion(stacks, i, j))
		return (INF);
	a_b_rr = getmax(rot->cost_ra, rot->cost_rb);
	a_b_rrr = getmax(rot->cost_rra, rot->cost_rrb);
	a_ra_b_rrb = rot->cost_ra + rot->cost_rrb;
	b_rb_a_rra = rot->cost_rra + rot->cost_rb;
	best_cost = INF;
	if (a_ra_b_rrb < best_cost)
		best_cost = update_best(rot, 4, a_ra_b_rrb);
	if (b_rb_a_rra < best_cost)
		best_cost = update_best(rot, 5, b_rb_a_rra);
	if (a_b_rr < best_cost)
		best_cost = update_best(rot, 2, a_b_rr);
	if (a_b_rrr < best_cost)
		best_cost = update_best(rot, 3, a_b_rrr);
	return (best_cost);
}

int	rotation_stack_b(t_stacks *stacks, t_rotation *rot, int i)
{
	int			cost_now;
	int			best_cost;
	int			j;
	t_rotation	temp;

	rot->cost_rb = stack_size(stacks->stack_b) - 1;
	rot->cost_rrb = 1;
	best_cost = INF;
	j = stacks->stack_b->head;
	while (j != stacks->stack_b->next)
	{
		cost_now = rotation_cost(stacks, rot, i, j);
		if (cost_now < best_cost)
		{
			best_cost = cost_now;
			temp = *rot;
		}
		j = next_index(j);
		rot->cost_rb--;
		rot->cost_rrb++;
	}
	*rot = temp;
	return (best_cost);
}

t_rotation	rotation_stack_a_b(t_stacks *stacks)
{
	int			cost_now;
	int			best_cost;
	int			i;
	t_rotation	rot;
	t_rotation	rot_now;

	rot_now.cost_ra = stack_size(stacks->stack_a) - 1;
	rot_now.cost_rra = 1;
	best_cost = INF;
	i = stacks->stack_a->head;
	while (i != stacks->stack_a->next)
	{
		cost_now = rotation_stack_b(stacks, &rot_now, i);
		if (cost_now < best_cost)
		{
			best_cost = cost_now;
			rot = rot_now;
		}
		i = next_index(i);
		rot_now.cost_ra--;
		rot_now.cost_rra++;
	}
	return (rot);
}
