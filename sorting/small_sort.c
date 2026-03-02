/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-tawa <hal-tawa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 01:17:22 by hal-tawa          #+#    #+#             */
/*   Updated: 2026/02/20 01:17:22 by hal-tawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort3(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	if (is_sorted(a))
		return ;
	first = a -> index;
	second = a -> next -> index;
	third = a -> next -> next -> index;
	if (first == 0 && second == 2 && third == 1)
	{
		op_dispatch("rra", a, NULL);
		op_dispatch("sa", a, NULL);
	}
	else if (first == 2 && second == 1 && third == 0)
	{
		op_dispatch("sa", a, NULL);
		op_dispatch("rra", a, NULL);
	}
	else if (first == 1 && second == 0 && third == 2)
		op_dispatch("sa", a, NULL);
	else if (first == 1 && second == 2 && third == 0)
		op_dispatch("rra", a, NULL);
	else if (first == 2 && second == 0 && third == 1)
		op_dispatch("ra", a, NULL);
}

void	sort2(t_stack **a)
{
	int	first;
	int	second;

	first = (*a)-> index;
	second = (*a)-> next -> index;
	if (is_sorted(*a))
		return ;
	op_dispatch("sa", *a, NULL);
}
