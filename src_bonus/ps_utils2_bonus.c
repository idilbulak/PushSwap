/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_utils2_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/22 17:03:38 by ibulak        #+#    #+#                 */
/*   Updated: 2022/06/27 11:22:34 by ibulak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

int	find_max(t_stack *stack)
{
	int	result;
	int	i;

	result = stack->numberfield[prev_index(stack->next)];
	i = stack->head;
	while (i != stack->next)
	{
		if (result < stack->numberfield[i])
			result = stack->numberfield[i];
		i = next_index(i);
	}
	return (result);
}

int	find_min(struct s_stack *stack)
{
	int	result;
	int	i;

	result = stack->numberfield[prev_index(stack->next)];
	i = stack->head;
	while (i != stack->next)
	{
		if (result > stack->numberfield[i])
			result = stack->numberfield[i];
		i = next_index(i);
	}
	return (result);
}

int	getmin(int x, int y)
{
	if (x < y)
		return (x);
	return (y);
}

int	getmax(int x, int y)
{
	if (x > y)
		return (x);
	return (y);
}

int	stack_prev(struct s_stack *stack)
{
	stack->next = prev_index(stack->next);
	return (stack->numberfield[stack->next]);
}
