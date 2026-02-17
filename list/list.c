/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabuhamm <kabuhamm@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 11:05:50 by kabuhamm          #+#    #+#             */
/*   Updated: 2026/02/14 13:06:53 by kabuhamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

s_node	*new_node(int value)
{
	s_node	*node;

	node = malloc(sizeof(s_node));
	if (!node)
		return (NULL);
	node -> value = value;
	node -> next = NULL;
	node -> index = 0;
	return (node);
}

s_node	*last_node(s_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack -> next)
		stack = stack -> next;
	return (stack);
}

int	lst_size(s_node *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack -> next;
	}
	return (i);
}

void	lst_add_back(s_node **stack, s_node *new_node)
{
	s_node	last;

	if (!stack || !new_node)
		return ;
	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	last = node_last(*stack);
	last -> next = new_node;
}

void	lst_clear(s_node **stack)
{
	s_node	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)-> next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}
