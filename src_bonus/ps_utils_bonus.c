/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_utils_bonus.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/22 17:03:18 by ibulak        #+#    #+#                 */
/*   Updated: 2022/06/27 11:19:51 by ibulak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

// void	printlist(t_stack *stack)
// {
// 	int	i;

// 	i = stack->head;
// 	while (i != stack->next)
// 	{
// 		printf("%d ", stack->numberfield[i]);
// 		i = next_index(i);
// 	}
// 	printf("\n");
// }

int	stack_empty(t_stack *stack)
{
	if (stack->head == stack->next)
		return (1);
	return (0);
}

int	next_index(int index)
{
	if (index == 999)
		return (0);
	return (index + 1);
}

int	prev_index(int index)
{
	if (index == 0)
		return (999);
	return (index - 1);
}

int	stack_size(t_stack *stack)
{
	int	size;

	size = stack->next - stack->head;
	if (size < 0)
		size += 1000;
	return (size);
}

void	checker_init(t_stacks *stacks)
{
	int	i;

	while (!stack_empty(stacks->stack_b))
	{
		i = stack_prev(stacks->stack_b);
		if (if_notdoubles(stacks->stack_b, i) == -1)
			exit(EXIT_FAILURE);
		push_stack(stacks->stack_a, i);
	}
}
