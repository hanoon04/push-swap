/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_dipatch.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-tawa <hal-tawa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 16:21:33 by hal-tawa          #+#    #+#             */
/*   Updated: 2026/02/15 16:21:33 by hal-tawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_dispatch(char *op, t_stack *a, t_stack *b)
{
	if (ft_strncmp(op, "pa", 3) == 0)
		pa(a, b);
	else if (ft_strncmp(op, "pb", 3) == 0)
		pb(b, a);
	else if (ft_strncmp(op, "sa", 3) == 0)
		swap_printer(a, 'a');
	else if (ft_strncmp(op, "sb", 3) == 0)
		swap_printer(b, 'b');
	else if (ft_strncmp(op, "ss", 3) == 0)
		ss(a, b);
	else if (ft_strncmp(op, "ra", 3) == 0)
		rotate_printer(a, 'a');
	else if (ft_strncmp(op, "rb", 3) == 0)
		rotate_printer(b, 'b');
	else if (ft_strncmp(op, "rr", 3) == 0)
		rr(a, b);
	else if (ft_strncmp(op, "rra", 4) == 0)
		rev_rotate_printer(a, 'a');
	else if (ft_strncmp(op, "rrb", 4) == 0)
		rev_rotate_printer(b, 'b');
	else if (ft_strncmp(op, "rrr", 4) == 0)
		rrr(a, b);
	else
		write(2, "Error\n", 6);
}
