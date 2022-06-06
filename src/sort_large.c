#include "../inc/push_swap.h"

int		if_swap(t_stack *stack)
{
	int	first;
	int	second;
	int	i;

	i = prev_index(stack->head);
	first = stack->numberfield[i];
	i = prev_index(i);
	second = stack->numberfield[i];
	if (first < second)
		return (-1);
	else
		return (1);
}

int	if_insertion(t_stacks *stacks, int i, int j)
{
	int	if_push;
	int	push_max;
	int	push_min;
	int	next;

	next = next_index(j);
	if (next == stacks->stack_b->next)
		next = stacks->stack_b->head;
	if_push = stacks->stack_a->numberfield[i] > stacks->stack_b->numberfield[j] \
						&& stacks->stack_b->numberfield[next] > stacks->stack_a->numberfield[i];
	push_max = stacks->stack_a->numberfield[i] > stacks->stack_bmax && stacks->stack_b->numberfield[j] == stacks->stack_bmax;
	push_min = stacks->stack_a->numberfield[i] < stacks->stack_bmin && stacks->stack_b->numberfield[j] == stacks->stack_bmax;
	return (if_push || push_max || push_min);
}

void	insertion(t_stacks *stacks, t_rotation rot)
{
	if (rot.method == 2)
	{
		repeat_fn(rr, stacks, getmin(rot.cost_ra,rot.cost_rb));
		repeat_fn(ra, stacks, getmax(0, rot.cost_ra - rot.cost_rb));
		repeat_fn(rb, stacks, getmax(0, rot.cost_rb - rot.cost_ra));
	}
	else if (rot.method == 3)
	{
		repeat_fn(rrr, stacks, getmin(rot.cost_rra, rot.cost_rrb));
		repeat_fn(rra, stacks, getmax(0, rot.cost_rra - rot.cost_rrb));
		repeat_fn(rrb, stacks, getmax(0, rot.cost_rrb - rot.cost_rra));
	}
	else if (rot.method == 4)
	{
		repeat_fn(ra, stacks, rot.cost_ra);
		repeat_fn(rrb, stacks, rot.cost_rrb);
	}
	else if (rot.method == 5)
	{
		repeat_fn(rra, stacks, rot.cost_rra);
		repeat_fn(rb, stacks, rot.cost_rb);
	}
}

void	bring_min_to_top(t_stacks *stacks)
{
	int						min;
	int						i;
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
				repeat_fn(rb, stacks, rot.cost_rb);
			else
				repeat_fn(rrb, stacks, rot.cost_rrb);
			break ;
		}
		rot.cost_rb--;
		rot.cost_rrb++;
		i = next_index(i);
	}
}