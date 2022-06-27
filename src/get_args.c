/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_args.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/22 12:15:27 by ibulak        #+#    #+#                 */
/*   Updated: 2022/06/27 11:03:56 by ibulak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_isdigit(int c)
{
	if (!(c >= 48 && c <= 57))
		return (0);
	else
		return (1);
}

void	push_stack(t_stack *stack, int value)
{
	stack->numberfield[stack->next] = value;
	stack->next = next_index(stack->next);
}

int	check_sign(int nbr, int sign)
{
	if (sign == -1)
			nbr = nbr * -1;
	return (nbr);
}

int	get_args(int argc, char **argv, t_stacks *stacks)
{
	int	i;
	int	j;
	int	nbr;
	int	sign;

	i = 0;
	while (++i < argc)
	{
		sign = 1;
		nbr = 0;
		j = 0;
		if (argv[i][j] == '-')
			sign = -1;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		while (ft_isdigit(argv[i][j]))
		{
			nbr = nbr * 10 + (argv[i][j] - '0');
			j++;
		}
		nbr = check_sign(nbr, sign);
		push_stack(stacks->stack_b, nbr);
	}
	return (1);
}
