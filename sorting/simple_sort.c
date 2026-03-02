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
	t_node	*a_top;
	t_node	*b_top;

	a_top = a -> top;
	while (a_top)
	{
		pb(a, b);
		b_top = b -> top;
		while (a_top -> value < b_top -> value)
		{
			rb(b);
			b_top = b_top -> next;
		}
		a_top = a_top -> next;
	}

	b_top = b -> top;
	while (b_top)
	{
		pa(a, b);
		b_top = b_top -> next;
	}
}

