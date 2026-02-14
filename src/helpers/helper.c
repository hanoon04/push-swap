/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabuhamm <kabuhamm@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 11:55:42 by kabuhamm          #+#    #+#             */
/*   Updated: 2026/02/14 13:09:21 by kabuhamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_sorted(t_node *stack)
{
	if (!stack)
		return (0);
	while (stack -> next)
	{
		if (stack -> value < stack -> next -> value)
			return (0);
		stack = stack -> next;
	}
	return (1);
}

int	find_min_pos(t_node *stack)
{
	int	min;
	int	i;
	int	pos;

	if (!stack)
		return (-1);
	min = stack -> value;
	i = 0;
	pos = 0;
	while (stack)
	{
		if (stack -> value < min)
		{
			min = stack -> value;
			pos = i;
		}
		stack = stack -> next;
		i ++;
	}
	return (pos);
}
