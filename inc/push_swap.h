/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/22 18:07:09 by ibulak        #+#    #+#                 */
/*   Updated: 2022/06/22 18:07:10 by ibulak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

# define MAX_INT 2147483647
# define MIN_INT -2147483648
# define INF 0x3f3f3f3f

typedef struct s_stack
{
	int				numberfield[1000];
	int				head;
	int				next;
}	t_stack;

typedef struct s_stacks
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	int			stack_bmax;
	int			stack_bmin;
}	t_stacks;

typedef struct s_rotation
{
	int	cost_ra;
	int	cost_rb;
	int	cost_rra;
	int	cost_rrb;
	int	method;	
}	t_rotation;

typedef int	(*t_repeat_fn)(t_stacks *stacks, int value);

// main
void		init_stacks(t_stack *stack_a, t_stack *stack_b);
int			if_number(char **argv);
int			if_notdoubles(t_stack *stack, int nbr);
int			if_sorted(t_stack *stack);
void		push_stack(t_stack *stack, int value);

//getargs
int			get_args(int argc, char **argv, t_stacks *stacks);
int			ft_isdigit(int c);

//arrayutils
void		printlist(t_stack *stack);
int			stack_empty(t_stack *stack);
int			next_index(int index);
int			prev_index(int index);
int			stack_size(t_stack *stack);
int			find_max(t_stack *stack);
int			find_min(t_stack *stack);
int			getmin(int x, int y);
int			getmax(int x, int y);
int			stack_prev(struct s_stack *stack);

//sort
int			compare_ab(t_stacks *stacks);
int			compare_bc(t_stacks *stacks);
int			compare_ac(t_stacks *stacks);
void		sort_3(t_stacks *stacks);
void		sort(t_stacks *stacks);
void		sort_4(t_stacks *stacks);
void		sort_5(t_stacks *stacks);

// sortutils
void		repeat_fn(t_repeat_fn fn, t_stacks *stacks, int n);
int			update_best(t_rotation *rot, int method, int best_cost);
int			rotation_cost(t_stacks *stacks, t_rotation *rot, int i, int j);
int			rotation_stack_b(t_stacks *stacks, t_rotation *rot, int i);
t_rotation	rotation_stack_a_b(t_stacks *stacks);

//sortlarge
int			if_swap(t_stack *stack);
int			if_insertion(t_stacks *stacks, int i, int j);
void		insertion(t_stacks *stacks, t_rotation rot);
void		bring_min_to_top(t_stacks *stacks);

//swap
int			swap(t_stack *stack);
int			sa(t_stack *stack);
int			sb(t_stack *stack);
int			check_sa(t_stack *stack);
int			check_sb(t_stack *stack);
int			ss(t_stacks *stacks);

// rotate
void		rotate(t_stack *stack);
int			ra(t_stacks *stacks, int n);
int			rb(t_stacks *stacks, int n);
int			rr(t_stacks *stacks, int n);

// reverse rotate
void		reverse_rotate(t_stack *stack);
int			rra(t_stacks *stacks, int n);
int			rrb(t_stacks *stacks, int n);
int			rrr(t_stacks *stacks, int n);

// push
int			pa(t_stacks *stacks, int n);
int			pb(t_stacks *stacks, int n);

#endif