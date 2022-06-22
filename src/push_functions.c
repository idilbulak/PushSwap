/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_functions.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/22 17:04:07 by ibulak        #+#    #+#                 */
/*   Updated: 2022/06/22 17:04:11 by ibulak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	pa(t_stacks *stacks, int n)
{
	if (stack_size(stacks->stack_b) == 0)
		return (0);
	push_stack(stacks->stack_a, stack_prev(stacks->stack_b));
	if (n == 1)
		write(1, "pa\n", 3);
	return (1);
}

int	pb(t_stacks *stacks, int n)
{
	if (stack_size(stacks->stack_a) == 0)
		return (0);
	push_stack(stacks->stack_b, stack_prev(stacks->stack_a));
	if (n == 1)
		write(1, "pb\n", 3);
	return (1);
}
