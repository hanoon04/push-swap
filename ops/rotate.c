/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hal-tawa <hal-tawa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 16:20:33 by hal-tawa          #+#    #+#             */
/*   Updated: 2026/02/15 16:20:33 by hal-tawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rotate(s_stack *s)
{
	s_node	*last;
	s_node	*first;

	if (!s || s -> size < 2)
		return ;
	first = s -> top;
	last = last_node(s);
	s -> top = s -> top -> next;
	last -> next = first;
	first -> next = NULL;
}

void	rotate_printer(s_stack *s, char c)
{
	rotate(s);
	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
}

void	rr(s_stack *a, s_stack *b)
{
	rotate(a);
	rotate(b);
	write(1,"rr\n", 3);
}
