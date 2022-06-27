/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap_functions_bonus.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/22 17:05:02 by ibulak        #+#    #+#                 */
/*   Updated: 2022/06/27 11:24:19 by ibulak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

int	swap(t_stack *stack)
{
	int	next;
	int	prev;

	if (stack_size(stack) < 2)
		return (0);
	next = stack_prev(stack);
	prev = stack_prev(stack);
	push_stack(stack, next);
	push_stack(stack, prev);
	return (1);
}

int	sa(t_stacks *stacks, int n)
{
	swap(stacks->stack_a);
	if (n == 1)
		write(1, "sa\n", 3);
	return (1);
}

int	sb(t_stacks *stacks, int n)
{
	swap(stacks->stack_b);
	if (n == 1)
		write(1, "sb\n", 3);
	return (1);
}

int	ss(t_stacks *stacks, int n)
{
	swap(stacks->stack_a);
	swap(stacks->stack_b);
	if (n == 1)
		write(1, "ss\n", 3);
	return (1);
}
