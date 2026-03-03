#include "../includes/push_swap.h"

int	find_min_pos(t_node *stack)
{
	int	min;
	int	pos;
	int	best;
	int	i;

	if (!stack)
		return (-1);
	min = stack->value;
	pos = 0;
	best = 0;
	i = 0;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			best = i;
		}
		stack = stack->next;
		i++;
	}
	return (best);
}