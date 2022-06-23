/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse_rotate_functions.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/22 17:04:31 by ibulak        #+#    #+#                 */
/*   Updated: 2022/06/22 17:04:37 by ibulak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

void	reverse_rotate(struct s_stack *stack)
{
	push_stack(stack, stack->numberfield[stack->head]);
	stack->head = next_index(stack->head);
}

int	rra(t_stacks *stacks, int n)
{
	if (stack_size(stacks->stack_a) < 2)
		return (0);
	reverse_rotate(stacks->stack_a);
	if (n == 1)
		write(1, "rra\n", 4);
	return (1);
}

int	rrb(t_stacks *stacks, int n)
{
	if (stack_size(stacks->stack_b) < 2)
		return (0);
	reverse_rotate(stacks->stack_b);
	if (n == 1)
		write(1, "rrb\n", 4);
	return (1);
}

int	rrr(t_stacks *stacks, int n)
{
	if (stack_size(stacks->stack_a) > 1 && stack_size(stacks->stack_b) > 1)
	{
		rra(stacks, 0);
		rrb(stacks, 0);
		if (n == 1)
			write(1, "rrr\n", 4);
		return (1);
	}
	return (0);
}
