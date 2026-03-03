#include "../includes/push_swap.h"

int	find_max_pos_index(t_node *stack)
{
	int	max;
	int	best;
	int	i;

	if (!stack)
		return (-1);
	max = stack->index;
	best = 0;
	i = 0;
	while (stack)
	{
		if (stack->index > max)
		{
			max = stack->index;
			best = i;
		}
		stack = stack->next;
		i++;
	}
	return (best);
}