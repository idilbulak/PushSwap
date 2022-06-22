/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap_functions.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/22 17:05:02 by ibulak        #+#    #+#                 */
/*   Updated: 2022/06/22 17:06:00 by ibulak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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

int	sa(t_stack *stack)
{
	swap(stack);
	write(1, "sa\n", 3);
	return (1);
}

int	sb(t_stack *stack)
{
	swap(stack);
	write(1, "sb\n", 3);
	return (1);
}

int	check_sa(t_stack *stack)
{
	swap(stack);
	return (1);
}

int	check_sb(t_stack *stack)
{
	swap(stack);
	return (1);
}

// int	ss(t_stacks *stacks)
// {
// 	check_sa(stacks->stack_a);
// 	check_sb(stacks->stack_b);
// 	write(1, "ss\n", 3);
// 	return(1);
// }
