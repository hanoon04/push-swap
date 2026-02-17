/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-tawa <hal-tawa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 16:20:19 by hal-tawa          #+#    #+#             */
/*   Updated: 2026/02/15 16:20:19 by hal-tawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	push(s_stack *src, s_stack *dst)
{
	s_node	*src_first;

	if (!src || !dst || src -> size == 0)
		return ;
	src_first = src -> top;
	src -> top = src -> top -> next;
	src_first -> next = dst -> top;
	dst -> top = src_first;
	dst -> size++;
	src -> size--;
}

void	pb(s_stack *a, s_stack *b)
{
	push(a, b);
	write(1, "pb\n", 3);
}

void	pa(s_stack *a, s_stack *b)
{
	push(b, a);
	write(1, "pa\n", 3);
}
