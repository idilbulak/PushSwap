/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/22 18:07:42 by ibulak        #+#    #+#                 */
/*   Updated: 2022/06/22 18:09:37 by ibulak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

void	repeat(t_repeat fn, t_stacks *stacks, int n)
{
	while (n--)
		fn(stacks, 1);
}
