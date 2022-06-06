#include "../inc/push_swap.h"

void	rotate(t_stack *stack)
{
	stack->head = prev_index(stack->head);
	stack->numberfield[stack->head] = stack_prev(stack);
}

int	ra(t_stacks *stacks, int n)
{
	if (stack_size(stacks->stack_a) < 2)
		return (0);
	rotate(stacks->stack_a);
	if (n == 1)
		write(1, "ra\n", 3);
	return (1);
}

int	rb(t_stacks *stacks, int n)
{
	if (stack_size(stacks->stack_b) < 2)
		return (0);
	rotate(stacks->stack_b);
	if (n == 1)
		write(1, "rb\n", 3);
	return (1);
}

int	rr(t_stacks *stacks, int n)
{
	if (stack_size(stacks->stack_a) > 1 && stack_size(stacks->stack_b) > 1)
	{
		ra(stacks, 0);
		rb(stacks, 0);
		if (n == 1)
			write(1, "rr\n", 3);
		return (1);
	}
	return (0);
}
