/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/01 22:30:18 by ibulak        #+#    #+#                 */
/*   Updated: 2022/06/27 11:20:20 by ibulak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
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

typedef int	(*t_repeat)(t_stacks *stacks, int value);

// getnextline
char		*get_line(char *str);
char		*update_str(char *str);
char		*ft_read(char *str, int fd, int result);
char		*get_next_line(int fd);
char		*ft_strjoin(char *s1, char *s2);
size_t		ft_strlen(const char *s);
char		*ft_strchr(char *s, int c);
void		*ft_calloc(size_t count, size_t size);
void		*ft_memset(void *b, int c, size_t len);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

// checker
void		init_moves(const char **moves);
int			which_move(char *mv);
void		init_functions(t_repeat functions[11]);
int			checker(t_stacks *stacks);

// getargs
int			ft_isdigit(int c);
void		push_stack(t_stack *stack, int value);
int			check_sign(int nbr, int sign);
int			get_args(int argc, char **argv, t_stacks *stacks);

// arrayutils
void		init_stacks(t_stack *stack_a, t_stack *stack_b);
int			if_number(char **argv);
int			if_notdoubles(t_stack *stack, int nbr);
int			if_sorted(t_stack *stack);
// void		printlist(t_stack *stack);
int			stack_empty(t_stack *stack);
int			next_index(int index);
int			prev_index(int index);
int			stack_size(t_stack *stack);
int			find_max(t_stack *stack);
int			find_min(t_stack *stack);
int			getmin(int x, int y);
int			getmax(int x, int y);
int			stack_prev(struct s_stack *stack);
void		repeat(t_repeat fn, t_stacks *stacks, int n);
void		checker_init(t_stacks *stacks);

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

// swap
int			swap(t_stack *stack);
int			sa(t_stacks *stacks, int n);
int			sb(t_stacks *stacks, int n);
int			ss(t_stacks *stacks, int n);

#endif