/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-tawa <hal-tawa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 01:05:44 by hal-tawa          #+#    #+#             */
/*   Updated: 2026/03/02 01:05:44 by hal-tawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insertion_sort(t_stack *a, t_stack *b)
{
	t_node	*current;
	int		value;
	int		rb_count;

	while (a -> op)
	{
		current = a -> top;
		value = current -> value;
		rb_count = 0;
		if (b -> top && b -> top -> value > value)
		{
			op_dispatch("rb", a, b);
			rb_count++;
		}
		op_dispatch("pb", a, b);
		while (rb_count--)
			op_dispatch("rrb", a, b);
	}
	while (b -> top)
		op_dispatch("pa", a, b);
}
