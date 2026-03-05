#include "../includes/push_swap.h"

int	find_max_pos_index(t_stack *stack)
{
	t_node	*cur;
	int	max;
	int	best;
	int	i;

	if (!stack || !stack->top)
		return (-1);
	cur = stack->top;
	max = cur->index;
	best = 0;
	i = 0;
	while (cur)
	{
		if (cur->index > max)
		{
			max = cur->index;
			best = i;
		}
		cur = cur->next;
		i++;
	}
	return (best);
}
