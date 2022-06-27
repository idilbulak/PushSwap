/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_utils5.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/27 10:35:40 by ibulak        #+#    #+#                 */
/*   Updated: 2022/06/27 10:46:50 by ibulak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rot_2(t_stacks *stacks, t_rotation rot)
{
	repeat(rr, stacks, getmin(rot.cost_ra, rot.cost_rb));
	repeat(ra, stacks, getmax(0, rot.cost_ra - rot.cost_rb));
	repeat(rb, stacks, getmax(0, rot.cost_rb - rot.cost_ra));
}

void	rot_3(t_stacks *stacks, t_rotation rot)
{
	repeat(rrr, stacks, getmin(rot.cost_rra, rot.cost_rrb));
	repeat(rra, stacks, getmax(0, rot.cost_rra - rot.cost_rrb));
	repeat(rrb, stacks, getmax(0, rot.cost_rrb - rot.cost_rra));
}

void	rot_4(t_stacks *stacks, t_rotation rot)
{
	repeat(ra, stacks, rot.cost_ra);
	repeat(rrb, stacks, rot.cost_rrb);
}

void	rot_5(t_stacks *stacks, t_rotation rot)
{
	repeat(rra, stacks, rot.cost_rra);
	repeat(rb, stacks, rot.cost_rb);
}
