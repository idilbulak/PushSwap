#include "../inc/push_swap.h"

void	sort_3(t_stacks *stacks)
{
	int	cmp_ab;
	int	cmp_ac;
	int	cmp_bc;

	cmp_ab = stacks->stack_a->numberfield[stacks->stack_a->head] < stacks->stack_a->numberfield[next_index(stacks->stack_a->head)];
	cmp_bc = stacks->stack_a->numberfield[next_index(stacks->stack_a->head)] < stacks->stack_a->numberfield[prev_index(stacks->stack_a->next)];
	cmp_ac = stacks->stack_a->numberfield[prev_index(stacks->stack_a->next)] < stacks->stack_a->numberfield[stacks->stack_a->head];
	if (cmp_ab && cmp_bc && !cmp_ac)
	{
		ra(stacks, 1);
		sa(stacks->stack_a);
	}
	if (!cmp_ab && cmp_bc && cmp_ac)
		sa(stacks->stack_a);
	if (cmp_ab && !cmp_bc && cmp_ac)
	{
		rra(stacks, 1);
		sa(stacks->stack_a);
	}
	if (!cmp_ab && cmp_bc && !cmp_ac)
		ra(stacks, 1);
	if (cmp_ab && !cmp_bc && !cmp_ac)
		rra(stacks, 1);
}

void	sort_4(t_stacks *stacks)
{
	int	b;
	int	c;
	int	d;

	b = stacks->stack_a->numberfield[next_index(next_index(stacks->stack_a->head))];
	c = stacks->stack_a->numberfield[next_index(stacks->stack_a->head)];
	d = stacks->stack_a->numberfield[stacks->stack_a->head];
	if (b == find_min(stacks->stack_a))
		sa(stacks->stack_a);
	if (c == find_min(stacks->stack_a))
	{
		ra(stacks, 1);
		sa(stacks->stack_a);
	}
	if (d == find_min(stacks->stack_a))
		rra(stacks, 1);
	if (if_sorted(stacks->stack_a) == -1)
	{
		pb(stacks, 1);
		sort_3(stacks);
		pa(stacks, 1);
	}
}

void	sort_5(t_stacks *stacks)
{
	int	b;
	int	c;
	int	d;
	int	e;

	b = stacks->stack_a->numberfield[3];
	c = stacks->stack_a->numberfield[2];
	d = stacks->stack_a->numberfield[1];
	e = stacks->stack_a->numberfield[0];
	if (b == find_min(stacks->stack_a))
		sa(stacks->stack_a);
	if (c == find_min(stacks->stack_a))
	{
		ra(stacks, 1);
		sa(stacks->stack_a);
	}
	if (d == find_min(stacks->stack_a))
	{
		rra(stacks, 1);
		rra(stacks, 1);
	}
	if (e == find_min(stacks->stack_a))
		rra(stacks, 1);
	pb(stacks, 1);
	sort_4(stacks);
	pb(stacks, 1);
	sort_3(stacks);
	pa(stacks,1 );
	pa(stacks, 1);
}

void	sort_large(t_stacks *stacks)
{
	t_rotation	rot;

	if(if_swap(stacks->stack_a))
		sa(stacks->stack_a);
	pb(stacks, 1);
	pb(stacks, 1);
	while(stack_size(stacks->stack_a) != 0)
	{
		// if(stacks->stack_a->numberfield[stacks->stack_a->head] > stacks->stack_a->numberfield[next_index(stacks->stack_a->head)])
		// {
		// 	if(stacks->stack_b->numberfield[stacks->stack_b->head] < stacks->stack_b->numberfield[next_index(stacks->stack_b->head)])
		// 		ss(stacks);
		// 	else
		// 		sa(stacks->stack_a);
		// }
		stacks->stack_bmax = find_max(stacks->stack_b);
		stacks->stack_bmin = find_min(stacks->stack_b);
		rot = rotation_stack_a_b(stacks);
		insertion(stacks, rot);
		pb(stacks, 1);
	}
	bring_min_to_top(stacks);
	repeat_fn(pa, stacks, stack_size(stacks->stack_b));
}

void	sort(t_stacks *stacks)
{
	if(stack_size(stacks->stack_a) == 2)
	{
		if(stacks->stack_a->numberfield[1] > stacks->stack_a->numberfield[0])
			sa(stacks->stack_a);
	}
	else if(stack_size(stacks->stack_a) == 3)
		sort_3(stacks);
	else if (stack_size(stacks->stack_a) == 4)
		sort_4(stacks);
	else if(stack_size(stacks->stack_a) == 5)
		sort_5(stacks);
	else if(stack_size(stacks->stack_a) > 5)
		sort_large(stacks);
}