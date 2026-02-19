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

void	sort3(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	if (is_sorted(*a))
		return ;
	first = (*a)-> index;
	second = (*a)-> next -> index;
	third = (*a)-> next -> next -> index;
	if (first > second && first < third)
		op_dispatch("sa");
	else if (first > second && first > third && second < third)
		op_dispatch("ra");
	else if (first < second && first > third)
		op_dispatch("rra");
	else if (first < second && first < third && third < second)
	{
		op_dispatch("rra");
		op_dispatch("sa");
	}
	else if (first > second && first > third && third < second)
	{
		op_dispatch("ra");
		op_dispatch("sa");
	}
}

void	sort2(t_stack **a)
{
	int	first;
	int	second;

	first = (*a)-> index;
	second = (*a)-> next -> index;
	if (is_sorted(*a))
		return ;
	op_dispatch("sa");
}
