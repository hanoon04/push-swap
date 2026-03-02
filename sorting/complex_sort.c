/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-tawa <hal-tawa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:54:36 by hal-tawa          #+#    #+#             */
/*   Updated: 2026/02/25 13:54:36 by hal-tawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bits(t_stack *a)
{
	int		count;
	int		max;
	t_node	*current;

	current = a -> top;
	max = 0;
	while (current)
	{
		if (current -> index > max)
			max = current -> index;
		current = current -> next;
	}
	count = 0;
	while (max > 0)
	{
		max /= 2;
		count++;
	}
	return (count);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	max_bits;
	int	i;
	int	j;
	int	size;

	max_bits = get_max_bits(a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		size = a -> size;
		while (j < a -> size)
		{
			if (((a -> top -> index >> i) & 1) == 0)
				op_dispatch("pb", a, b);
			else
				op_dispatch("ra", a, b);
			j++;
		}
		while (b -> size > 0)
			op_dispatch("pa", a, b);
		i++;
	}
}
